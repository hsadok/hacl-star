module Hacl.Impl.ECDSA.P256SHA256.Signature

open FStar.HyperStack.All
open FStar.HyperStack
module ST = FStar.HyperStack.ST

open Lib.IntTypes
open Lib.Buffer
open Lib.ByteSequence

open Hacl.Hash.SHA2
open Hacl.Spec.P256.Definitions

open Hacl.Spec.P256.Lemmas
open Hacl.Spec.ECDSAP256.Definition
open Hacl.Impl.LowLevel

open Hacl.Impl.ECDSA.MontgomeryMultiplication
open Hacl.Impl.ECDSA.MM.Exponent
open Hacl.Impl.P256.LowLevel
open Hacl.Impl.LowLevel
open Hacl.Impl.P256

open Hacl.Spec.P256

open Hacl.Spec.ECDSAP256.Definition
open FStar.Math.Lemmas

open Hacl.Impl.ECDSA.P256SHA256.Common
open FStar.Mul

#set-options "--z3rlimit 100"

val ecdsa_signature_step12: hashAsFelem: felem -> mLen: size_t -> m: lbuffer uint8 mLen {uint_v mLen < pow2 61} -> 
  Stack unit 
    (requires fun h -> live h hashAsFelem /\ live h m)
    (ensures fun h0 _ h1 -> modifies (loc hashAsFelem) h0 h1 /\
      (
	let hashM = Spec.Hash.hash Spec.Hash.Definitions.SHA2_256 (as_seq h0 m) in 
	let hashChanged = Hacl.Spec.ECDSA.changeEndian (Lib.ByteSequence.uints_from_bytes_be hashM) in 
	as_nat h1 hashAsFelem == (Lib.ByteSequence.nat_from_intseq_le hashChanged) % prime_p256_order
      ) 
  ) 

let ecdsa_signature_step12 hashAsFelem mLen m  = 
  push_frame(); 
    let mHash = create (size 32) (u8 0) in  
      let h0 = ST.get() in 
    hash_256 m mLen mHash;
    toUint64ChangeEndian mHash hashAsFelem;
      let h1 = ST.get() in 
      lemma_core_0 hashAsFelem h1;
    reduction_prime_2prime_order hashAsFelem hashAsFelem;
  pop_frame()


val ecdsa_signature_step45: x: felem ->  k: lbuffer uint8 (size 32) -> tempBuffer: lbuffer uint64 (size 100) -> 
  Stack bool 
    (requires fun h -> 
      live h x /\ live h k /\ live h tempBuffer /\ 
      LowStar.Monotonic.Buffer.all_disjoint [loc tempBuffer; loc k; loc x]
    )
    (ensures fun h0 r h1 -> modifies (loc x |+| loc tempBuffer) h0 h1 /\
      as_nat h1 x < prime_p256_order /\ 
      (
	let basePoint = (0x6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296, 0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5, 1) in
	let (rxN, ryN, rzN), _ = montgomery_ladder_spec (as_seq h0 k) ((0,0,0), basePoint) in 
	let (xN, _, _) = _norm (rxN, ryN, rzN) in 
	as_nat h1 x == xN % prime_p256_order /\ 
	(if as_nat h1 x = 0 then r == true else r == false)
      )
    )

let ecdsa_signature_step45 x k tempBuffer= 
  push_frame();
      let result = create (size 12) (u64 0) in 
      let tempForNorm = sub tempBuffer (size 0) (size 88) in 
    secretToPublicWithoutNorm result k tempBuffer; 
    normX result x tempForNorm;
    reduction_prime_2prime_order x x;
  pop_frame();
    isZero_bool x


val lemma_power_step6: kInv: nat -> Lemma 
  (Hacl.Spec.ECDSA.exponent_spec (fromDomain_ kInv) == toDomain_ (pow kInv (prime_p256_order - 2)))

let lemma_power_step6 kInv = 
  let a = Hacl.Spec.ECDSA.exponent_spec (fromDomain_ kInv) in 
  lemmaFromDomain kInv;

  power_distributivity (kInv * modp_inv2_prime (pow2 256) prime_p256_order) (prime_p256_order - 2) prime_p256_order;
  power_distributivity_2 kInv (modp_inv2_prime (pow2 256) prime_p256_order % prime_p256_order) (prime_p256_order - 2);
  lemma_mod_mul_distr_r (pow kInv (prime_p256_order - 2)) (pow (modp_inv2_prime (pow2 256) prime_p256_order) (prime_p256_order - 2)) prime_p256_order;

  lemma_pow_mod_n_is_fpow prime_p256_order (pow2 256 % prime_p256_order) (prime_p256_order - 2);
  assert_norm(modp_inv2_prime (pow2 256) prime_p256_order = 43790243014242295660885426880012836369732278457577312309071968676491870960761); 

  lemma_pow_mod_n_is_fpow prime_p256_order 43790243014242295660885426880012836369732278457577312309071968676491870960761 (prime_p256_order - 2);
  assert_norm(exp #prime_p256_order 43790243014242295660885426880012836369732278457577312309071968676491870960761 (prime_p256_order - 2) == pow2 256 % prime_p256_order);

  lemma_mod_mul_distr_r (pow kInv (prime_p256_order - 2)) (pow2 256) prime_p256_order;
  lemmaToDomain (pow kInv (prime_p256_order - 2))


#reset-options "--z3rlimit 300"

val ecdsa_signature_step6: result: felem -> kFelem: felem -> z: felem -> r: felem -> da: felem -> Stack unit
  (requires fun h -> live h result /\ live h kFelem /\ live h z /\ live h r /\ live h da /\
    as_nat h kFelem < prime_p256_order /\ as_nat h z < prime_p256_order /\ as_nat h r < prime_p256_order /\ 
    as_nat h da < prime_p256_order
  )
  (ensures fun h0 _ h1 -> modifies (loc result) h0 h1 /\
    as_nat h1 result = (as_nat h0 z + as_nat h0 r * as_nat h0 da) * pow (as_nat h0 kFelem) (prime_p256_order - 2) % prime_p256_order)


let ecdsa_signature_step6 result kFelem z r da = 
  let open FStar.Tactics in 
  let open FStar.Tactics.Canon in 
  push_frame();
    let rda = create (size 4) (u64 0) in 
    let zBuffer = create (size 4) (u64 0) in 
    let kInv = create (size 4) (u64 0) in 
	let h0 = ST.get() in 
    montgomery_multiplication_ecdsa_module r da rda;
    fromDomainImpl z zBuffer;
    felem_add rda zBuffer zBuffer;  
    copy kInv kFelem;
    montgomery_ladder_exponent kInv;
    montgomery_multiplication_ecdsa_module zBuffer kInv result;
       pop_frame();

       let br0 = as_nat h0 z + as_nat h0 r * as_nat h0 da in
       let br1 = pow (as_nat h0 kFelem) (prime_p256_order - 2) in 
       
       lemmaFromDomain (as_nat h0 r * as_nat h0 da); 
       lemma_felem_add (as_nat h0 r * as_nat h0 da) (as_nat h0 z);
       lemma_power_step6 (as_nat h0 kFelem);

       lemmaFromDomain (fromDomain_ br0);
       lemmaToDomain br1;
       assert_norm ((modp_inv2_prime (pow2 256) prime_p256_order * pow2 256) % prime_p256_order = 1);
       
       lemma_mod_mul_distr_l (fromDomain_ br0 * modp_inv2_prime (pow2 256) prime_p256_order) (br1 * pow2 256 % prime_p256_order) prime_p256_order;
       lemma_mod_mul_distr_r (fromDomain_ br0 * modp_inv2_prime (pow2 256) prime_p256_order) (br1 * pow2 256) prime_p256_order;
       
       assert_by_tactic (fromDomain_ br0 * modp_inv2_prime (pow2 256) prime_p256_order * (br1 * pow2 256) == fromDomain_ br0 * modp_inv2_prime (pow2 256) prime_p256_order * br1 * pow2 256) canon;
       assert_by_tactic (fromDomain_ br0 * br1 * (modp_inv2_prime (pow2 256) prime_p256_order * pow2 256) == fromDomain_ br0 * modp_inv2_prime (pow2 256) prime_p256_order * br1 * pow2 256) canon;
       
       lemma_mod_mul_distr_r (fromDomain_ br0 * br1) (modp_inv2_prime (pow2 256) prime_p256_order * pow2 256) prime_p256_order;
       lemmaToDomain ((fromDomain_ br0 * br1) % prime_p256_order);
       lemmaFromDomain br0;
       
       lemma_mod_mul_distr_l (br0 * modp_inv2_prime (pow2 256) prime_p256_order) br1 prime_p256_order;
       lemma_mod_mul_distr_l (br0 * modp_inv2_prime (pow2 256) prime_p256_order * br1) (pow2 256) prime_p256_order;
       
       assert_by_tactic (br0 * modp_inv2_prime (pow2 256) prime_p256_order * br1 * pow2 256 = br0 * br1 * (modp_inv2_prime (pow2 256) prime_p256_order * pow2 256)) canon;
       lemma_mod_mul_distr_r (br0 * br1) (modp_inv2_prime (pow2 256) prime_p256_order * pow2 256) prime_p256_order;
       lemma_mod_mul_distr_r br0 br1 prime_p256_order


val ecdsa_signature_core_nist_compliant: r: felem -> s: felem -> m: lbuffer uint8 (size 32) -> privKeyAsFelem: felem -> 
  k: lbuffer uint8 (size 32) -> 
  Stack bool  
  (requires fun h -> live h r /\ live h s /\ live h m /\ live h privKeyAsFelem /\ live h k /\ 
    disjoint privKeyAsFelem r /\ disjoint k r /\ disjoint r s /\
    Lib.ByteSequence.nat_from_bytes_le (as_seq h m) < prime_p256_order /\
    as_nat h privKeyAsFelem < prime_p256_order /\
    Lib.ByteSequence.nat_from_bytes_le (as_seq h k) < prime_p256_order
  )
  (ensures fun h0 flag h1 -> modifies (loc r |+| loc s) h0 h1 /\
    (
      let basePoint = (0x6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296, 0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5, 1) in
      let (rxN, ryN, rzN), _ = montgomery_ladder_spec (as_seq h0 k) ((0,0,0), basePoint) in 
      let (xN, _, _) = _norm (rxN, ryN, rzN) in 
      let z = Lib.ByteSequence.nat_from_bytes_le (as_seq h0 m) in 
      let kFelem = Lib.ByteSequence.nat_from_bytes_le (as_seq h0 k) in 
      as_nat h1 r == xN % prime_p256_order /\
      (
	if as_nat h1 r = 0 then flag = false else
	  as_nat h1 s == (z + (as_nat h1 r) * as_nat h0 privKeyAsFelem) * pow kFelem (prime_p256_order - 2) % prime_p256_order /\
	(
	  if (as_nat h1 s = 0) then flag = false else flag = true
	)
      )
    )
  )

let ecdsa_signature_core_nist_compliant r s m privKeyAsFelem k = 
  push_frame();
  let h0 = ST.get() in 
    let hashAsFelem = create (size 4) (u64 0) in     
    let tempBuffer = create (size 100) (u64 0) in 
    let kAsFelem = create (size 4) (u64 0) in 
    let hashAsFelem = create (size 4) (u64 0) in 
    toUint64 m hashAsFelem;
    toUint64 k kAsFelem;
  let h1 = ST.get() in 
      lemma_core_0 kAsFelem h1;
      uints_from_bytes_le_nat_lemma #U64 #_ #4 (as_seq h0 k);

      lemma_core_0 hashAsFelem h1;
      uints_from_bytes_le_nat_lemma #U64 #_ #4 (as_seq h0 m);
  let step5Flag = ecdsa_signature_step45 r k tempBuffer in 
    if not step5Flag then 
      begin
	ecdsa_signature_step6 s kAsFelem hashAsFelem r privKeyAsFelem;
	pop_frame();
	let step6Flag = isZero_bool s in 
	not step6Flag
      end 
    else 
      begin
	pop_frame();
	false
      end   

val ecdsa_signature_nist_compliant: result: lbuffer uint8 (size 64) -> m: lbuffer uint8 (size 32) -> 
  privKey: lbuffer uint8 (size 32) -> 
  k: lbuffer uint8 (size 32) -> 
  Stack bool
  (requires fun h -> live h privKey /\ live h k /\ live h result /\ live h m /\ 
    LowStar.Monotonic.Buffer.all_disjoint [loc m; loc privKey; loc k; loc result] /\
    
    Lib.ByteSequence.nat_from_bytes_le (as_seq h privKey) < prime_p256_order /\
    Lib.ByteSequence.nat_from_bytes_le (as_seq h m) < prime_p256_order /\
    Lib.ByteSequence.nat_from_bytes_le (as_seq h k) < prime_p256_order
  )
  (ensures fun h0 flag h1 -> modifies (loc result) h0 h1 /\
    (
      let resultR = gsub result (size 0) (size 32) in 
      let resultS = gsub result (size 32) (size 32) in 
      

    let basePoint = (0x6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296, 0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5, 1) in
      let (rxN, ryN, rzN), _ = montgomery_ladder_spec (as_seq h0 k) ((0,0,0), basePoint) in 
      let (xN, _, _) = _norm (rxN, ryN, rzN) in 
      let z = Lib.ByteSequence.nat_from_bytes_le (as_seq h0 m) in 
      let kFelem = Lib.ByteSequence.nat_from_bytes_le (as_seq h0 k) in 
      let privateKey = Lib.ByteSequence.nat_from_bytes_le (as_seq h0 privKey) in 
      let resultR = nat_from_bytes_le (as_seq h1 resultR) in 
      let resultS = nat_from_bytes_le (as_seq h1 resultS) in 
      resultR == xN % prime_p256_order /\
      (
	if resultR = 0 then flag = false else
	   resultS == (z + resultR * privateKey) * pow kFelem (prime_p256_order - 2) % prime_p256_order /\
	(
	  if (resultS = 0) then flag = false else flag = true
	)
      )
  )
)


let ecdsa_signature_nist_compliant result m privKey k = 
  push_frame();
    let h0 = ST.get() in 
    
    let privKeyAsFelem = create (size 4) (u64 0) in 
    let r = create (size 4) (u64 0) in 
    let s = create (size 4) (u64 0) in  

    let resultR = sub result (size 0) (size 32) in 
    let resultS = sub result (size 32) (size 32) in 
      toUint64 privKey privKeyAsFelem;
	let h1 = ST.get() in 
	    lemma_core_0 privKeyAsFelem h1;
	    Lib.ByteSequence.uints_from_bytes_le_nat_lemma #U64 #_ #4 (as_seq h1 privKey);

    let flag = ecdsa_signature_core_nist_compliant r s m privKeyAsFelem k in 
      let h2 = ST.get() in 

      toUint8 r resultR; 
      toUint8 s resultS;
      

      lemma_core_1 r h2;
      lemma_core_1 s h2;

      pop_frame();
      
    flag  

    

val ecdsa_signature_core: mLen: size_t -> m: lbuffer uint8 mLen {uint_v mLen < pow2 61} ->  
  privKeyAsFelem: felem  -> 
  k: lbuffer uint8 (size 32) -> 
  r: felem -> 
  s: felem -> 
  Stack bool  
  (requires fun h -> live h m /\ live h privKeyAsFelem /\ live h k /\ live h r /\ live h s /\ 
    disjoint privKeyAsFelem r /\ disjoint k r /\ disjoint r s /\
    as_nat h privKeyAsFelem < prime_p256_order /\
    Lib.ByteSequence.nat_from_bytes_le (as_seq h k) < prime_p256_order
  )
  (ensures fun h0 flag h1 -> modifies (loc r |+| loc s) h0 h1 /\
    (
      let hashM = Spec.Hash.hash Spec.Hash.Definitions.SHA2_256 (as_seq h0 m) in 
      let hashChanged = Hacl.Spec.ECDSA.changeEndian (Lib.ByteSequence.uints_from_bytes_be hashM) in
      let z = (Lib.ByteSequence.nat_from_intseq_le hashChanged) % prime_p256_order in 
      
      let basePoint = (0x6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296, 0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5, 1) in
      let (rxN, ryN, rzN), _ = montgomery_ladder_spec (as_seq h0 k) ((0,0,0), basePoint) in 
      let (xN, _, _) = _norm (rxN, ryN, rzN) in 
      
      let kFelem = Lib.ByteSequence.nat_from_bytes_le (as_seq h0 k) in 
      as_nat h1 r == xN % prime_p256_order /\
      (
	if as_nat h1 r = 0 then flag = false else
	  as_nat h1 s == (z + (as_nat h1 r) * as_nat h0 privKeyAsFelem) * pow kFelem (prime_p256_order - 2) % prime_p256_order /\
	(
	  if (as_nat h1 s = 0) then flag = false else flag = true
	)
      )
    )    
)


let ecdsa_signature_core mLen m privKeyAsFelem k r s = 
  push_frame();
    let h0 = ST.get() in 
      let hashAsFelem = create (size 4) (u64 0) in     
      let tempBuffer = create (size 100) (u64 0) in 
      let kAsFelem = create (size 4) (u64 0) in 
    toUint64 k kAsFelem;  
    ecdsa_signature_step12 hashAsFelem mLen m;

  let h1 = ST.get() in 
      lemma_core_0 kAsFelem h1;
      uints_from_bytes_le_nat_lemma #U64 #_ #4 (as_seq h0 k);
    let step5Flag = ecdsa_signature_step45 r k tempBuffer in 
      if not step5Flag then begin
	ecdsa_signature_step6 s kAsFelem hashAsFelem r privKeyAsFelem;
	pop_frame(); 
	let step6Flag = isZero_bool s in 
	not step6Flag
      end
      else 
	begin
	  pop_frame();
	  false
      end   


val ecdsa_signature:  mLen: size_t -> m: lbuffer uint8 mLen {uint_v mLen < pow2 61} ->
  privKey: lbuffer uint8 (size 32) -> 
  k: lbuffer uint8 (size 32) -> 
  result: lbuffer uint8 (size 64) -> Stack bool
  (requires fun h -> live h privKey /\ live h k /\ live h result /\ live h m /\
    LowStar.Monotonic.Buffer.all_disjoint [loc m; loc privKey; loc k; loc result] /\
    
    Lib.ByteSequence.nat_from_bytes_le (as_seq h privKey) < prime_p256_order /\
    Lib.ByteSequence.nat_from_bytes_le (as_seq h m) < prime_p256_order /\
    Lib.ByteSequence.nat_from_bytes_le (as_seq h k) < prime_p256_order
  )
  (ensures fun h0 flag h1 -> modifies (loc result) h0 h1 /\
     (
       
      let resultR = gsub result (size 0) (size 32) in 
      let resultS = gsub result (size 32) (size 32) in 
      

      let hashM = Spec.Hash.hash Spec.Hash.Definitions.SHA2_256 (as_seq h0 m) in 
      let hashChanged = Hacl.Spec.ECDSA.changeEndian (Lib.ByteSequence.uints_from_bytes_be hashM) in
      let z = (Lib.ByteSequence.nat_from_intseq_le hashChanged) % prime_p256_order in 

      let privateKey = Lib.ByteSequence.nat_from_bytes_le (as_seq h0 privKey) in 

      let basePoint = (0x6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296, 0x4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5, 1) in
      let (rxN, ryN, rzN), _ = montgomery_ladder_spec (as_seq h0 k) ((0,0,0), basePoint) in 
      let (xN, _, _) = _norm (rxN, ryN, rzN) in 
      
      let kFelem = Lib.ByteSequence.nat_from_bytes_le (as_seq h0 k) in 
     
      let resultR = nat_from_bytes_le (as_seq h1 resultR) in 
      let resultS = nat_from_bytes_le (as_seq h1 resultS) in 

      resultR == xN % prime_p256_order /\
      (
	if resultR = 0 then flag = false else
	  resultS == (z + resultR * privateKey) * pow kFelem (prime_p256_order - 2) % prime_p256_order /\
	(
	  if (resultS = 0) then flag = false else flag = true
	)
      )
    )    
)


let ecdsa_signature mLen m privKey k result = 
  push_frame();
    let h0 = ST.get() in 
      let privKeyAsFelem = create (size 4) (u64 0) in 
      let r = create (size 4) (u64 0) in 
      let s = create (size 4) (u64 0) in 

      let resultR = sub result (size 0) (size 32) in 
      let resultS = sub result (size 32) (size 32) in 
	toUint64 privKey privKeyAsFelem;

    let h1 = ST.get() in 
      lemma_core_0 privKeyAsFelem h1;
      Lib.ByteSequence.uints_from_bytes_le_nat_lemma #U64 #_ #4 (as_seq h1 privKey);
      
    let flag = ecdsa_signature_core mLen m privKeyAsFelem k r s in 
      let h2 = ST.get() in 

      toUint8 r resultR;
      toUint8 s resultS;

      lemma_core_1 r h2;
      lemma_core_1 s h2;

      pop_frame();

    flag  

    
