/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: /home/nkulatov/new2/kremlin/kremlin/krml -fbuiltin-uint128 -fnocompound-literals -fc89-scope -fparentheses -fcurly-braces -funroll-loops 4 -warn-error +9 -add-include "kremlib.h" -add-include "FStar_UInt_8_16_32_64.h" /dist/minimal/testlib.c -skip-compilation -no-prefix Hacl.Impl.P256 -bundle Lib.* -bundle Spec.* -bundle C=C.Endianness -bundle Hacl.Hash.SHA2=Hacl.Hash.*,Spec.Hash.* -bundle Hacl.Impl.P256=Hacl.Impl.P256,Hacl.Impl.LowLevel,Hacl.Impl.SolinasReduction,Hacl.Spec.P256.*,Hacl.Spec.Curve25519.*,Hacl.Impl.Curve25519.* -bundle Hacl.Impl.ECDSA.P256SHA256.Verification=Hacl.Impl.MontgomeryMultiplication,Hacl.Impl.ECDSA.P256SHA256.Verification,Hacl.Impl.MM.Exponent -library C,FStar -drop LowStar,Spec,Prims,Lib,C.Loops.*,Hacl.Spec.P256.Lemmas,Hacl.Spec.P256,Hacl.Spec.ECDSA -add-include "c/Lib_PrintBuffer.h" -add-include "FStar_UInt_8_16_32_64.h" -tmpdir ecdsap256-c .output/prims.krml .output/FStar_Pervasives_Native.krml .output/FStar_Pervasives.krml .output/FStar_Squash.krml .output/FStar_Classical.krml .output/FStar_StrongExcludedMiddle.krml .output/FStar_FunctionalExtensionality.krml .output/FStar_List_Tot_Base.krml .output/FStar_List_Tot_Properties.krml .output/FStar_List_Tot.krml .output/FStar_Mul.krml .output/FStar_Math_Lib.krml .output/FStar_Math_Lemmas.krml .output/FStar_Seq_Base.krml .output/FStar_Seq_Properties.krml .output/FStar_Seq.krml .output/FStar_Set.krml .output/FStar_Preorder.krml .output/FStar_Ghost.krml .output/FStar_ErasedLogic.krml .output/FStar_PropositionalExtensionality.krml .output/FStar_PredicateExtensionality.krml .output/FStar_TSet.krml .output/FStar_Monotonic_Heap.krml .output/FStar_Heap.krml .output/FStar_Map.krml .output/FStar_Monotonic_Witnessed.krml .output/FStar_Monotonic_HyperHeap.krml .output/FStar_Monotonic_HyperStack.krml .output/FStar_HyperStack.krml .output/FStar_HyperStack_ST.krml .output/FStar_Calc.krml .output/FStar_BitVector.krml .output/FStar_UInt.krml .output/FStar_UInt32.krml .output/FStar_Universe.krml .output/FStar_GSet.krml .output/FStar_ModifiesGen.krml .output/FStar_Range.krml .output/FStar_Reflection_Types.krml .output/FStar_Tactics_Types.krml .output/FStar_Tactics_Result.krml .output/FStar_Tactics_Effect.krml .output/FStar_Tactics_Util.krml .output/FStar_Reflection_Data.krml .output/FStar_Reflection_Const.krml .output/FStar_Char.krml .output/FStar_Exn.krml .output/FStar_ST.krml .output/FStar_All.krml .output/FStar_List.krml .output/FStar_String.krml .output/FStar_Order.krml .output/FStar_Reflection_Basic.krml .output/FStar_Reflection_Derived.krml .output/FStar_Tactics_Builtins.krml .output/FStar_Reflection_Formula.krml .output/FStar_Reflection_Derived_Lemmas.krml .output/FStar_Reflection.krml .output/FStar_Tactics_Derived.krml .output/FStar_Tactics_Logic.krml .output/FStar_Tactics.krml .output/FStar_BigOps.krml .output/LowStar_Monotonic_Buffer.krml .output/LowStar_Buffer.krml .output/LowStar_BufferOps.krml .output/Spec_Loops.krml .output/FStar_UInt64.krml .output/C_Loops.krml .output/FStar_Int.krml .output/FStar_Int64.krml .output/FStar_Int63.krml .output/FStar_Int32.krml .output/FStar_Int16.krml .output/FStar_Int8.krml .output/FStar_UInt63.krml .output/FStar_UInt16.krml .output/FStar_UInt8.krml .output/FStar_Int_Cast.krml .output/FStar_UInt128.krml .output/FStar_Int_Cast_Full.krml .output/FStar_Int128.krml .output/Lib_IntTypes.krml .output/Lib_Loops.krml .output/Lib_LoopCombinators.krml .output/Lib_RawIntTypes.krml .output/Lib_Sequence.krml .output/Lib_ByteSequence.krml .output/LowStar_ImmutableBuffer.krml .output/Lib_Buffer.krml .output/FStar_HyperStack_All.krml .output/Hacl_Spec_ECDSAP256_Definition.krml .output/Lib_IntTypes_Compatibility.krml .output/Spec_Hash_Definitions.krml .output/Spec_Hash_Lemmas0.krml .output/Spec_Hash_PadFinish.krml .output/Spec_SHA1.krml .output/Spec_MD5.krml .output/Spec_SHA2_Constants.krml .output/Spec_SHA2.krml .output/Spec_Hash.krml .output/Spec_Curve25519_Lemmas.krml .output/FStar_Reflection_Arith.krml .output/FStar_Tactics_Canon.krml .output/Hacl_Spec_P256_Definitions.krml .output/Hacl_Impl_Curve25519_Lemmas.krml .output/Spec_Curve25519.krml .output/Hacl_Spec_Curve25519_Field64_Definition.krml .output/Hacl_Spec_Curve25519_Field64_Lemmas.krml .output/Hacl_Spec_P256_Basic.krml .output/Hacl_Spec_P256_Lemmas.krml .output/Hacl_Spec_P256_Core.krml .output/Hacl_Spec_P256_MontgomeryMultiplication.krml .output/Hacl_Impl_LowLevel.krml .output/Hacl_Spec_P256_SolinasReduction.krml .output/Hacl_Impl_SolinasReduction.krml .output/FStar_Kremlin_Endianness.krml .output/C_Endianness.krml .output/C.krml .output/Lib_ByteBuffer.krml .output/Spec_Hash_Incremental.krml .output/Spec_Hash_Lemmas.krml .output/Hacl_Hash_Lemmas.krml .output/LowStar_Modifies.krml .output/Hacl_Hash_Definitions.krml .output/Hacl_Hash_PadFinish.krml .output/Hacl_Hash_MD.krml .output/Hacl_Impl_ECDSA_MontgomeryMultiplication.krml .output/Hacl_Spec_P256.krml .output/Hacl_Spec_P256_MontgomeryMultiplication_PointDouble.krml .output/Hacl_Spec_P256_MontgomeryMultiplication_PointAdd.krml .output/Hacl_Spec_P256_Ladder.krml .output/Hacl_Spec_ECDSA.krml .output/Hacl_Impl_ECDSA_MM_Exponent.krml .output/Hacl_Hash_Core_SHA2_Constants.krml .output/Hacl_Hash_Core_SHA2.krml .output/Hacl_Spec_P256_Normalisation.krml .output/Hacl_Impl_P256.krml .output/Hacl_Hash_SHA2.krml .output/Hacl_Impl_ECDSA_P256SHA256_Verification.krml
  F* version: ea91ae8c
  KreMLin version: 27ce15c8
 */

#include "Hacl_Impl_ECDSA_MontgomeryMultiplication.h"

uint64_t
Hacl_Impl_ECDSA_MontgomeryMultiplication_prime256order_buffer[4U] =
  {
    (uint64_t)17562291160714782033U,
    (uint64_t)13611842547513532036U,
    (uint64_t)18446744073709551615U,
    (uint64_t)18446744069414584320U
  };

inline static void
Hacl_Impl_ECDSA_MontgomeryMultiplication_mul(uint64_t *f1, uint64_t *r, uint64_t *out)
{
  uint64_t f10 = f1[0U];
  uint64_t f11 = f1[1U];
  uint64_t f12 = f1[2U];
  uint64_t f13 = f1[3U];
  uint64_t r0 = r[0U];
  uint64_t r1 = r[1U];
  uint64_t r2 = r[2U];
  uint64_t r3 = r[3U];
  uint128_t res0 = (uint128_t)r0 * f10;
  uint64_t l00 = (uint64_t)res0;
  uint64_t h00 = (uint64_t)(res0 >> (uint32_t)64U);
  uint128_t res1 = (uint128_t)r1 * f10;
  uint64_t l10 = (uint64_t)res1;
  uint64_t h10 = (uint64_t)(res1 >> (uint32_t)64U);
  uint128_t res2 = (uint128_t)r2 * f10;
  uint64_t l20 = (uint64_t)res2;
  uint64_t h20 = (uint64_t)(res2 >> (uint32_t)64U);
  uint128_t res3 = (uint128_t)r3 * f10;
  uint64_t l30 = (uint64_t)res3;
  uint64_t h30 = (uint64_t)(res3 >> (uint32_t)64U);
  uint64_t o04 = l00;
  K___uint64_t_uint64_t scrut0 = Hacl_Spec_P256_Basic_addcarry(l10, h00, (uint64_t)0U);
  uint64_t o10 = scrut0.fst;
  uint64_t c00 = scrut0.snd;
  K___uint64_t_uint64_t scrut1 = Hacl_Spec_P256_Basic_addcarry(l20, h10, c00);
  uint64_t o20 = scrut1.fst;
  uint64_t c10 = scrut1.snd;
  K___uint64_t_uint64_t scrut2 = Hacl_Spec_P256_Basic_addcarry(l30, h20, c10);
  uint64_t o30 = scrut2.fst;
  uint64_t c20 = scrut2.snd;
  uint64_t c30 = h30 + c20;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit0;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut3;
  uint64_t o03;
  uint64_t o02;
  uint64_t o01;
  uint64_t o00;
  uint64_t c0;
  uint128_t res4;
  uint64_t l01;
  uint64_t h01;
  uint128_t res5;
  uint64_t l11;
  uint64_t h11;
  uint128_t res6;
  uint64_t l21;
  uint64_t h21;
  uint128_t res7;
  uint64_t l31;
  uint64_t h31;
  uint64_t o05;
  K___uint64_t_uint64_t scrut4;
  uint64_t o15;
  uint64_t c010;
  K___uint64_t_uint64_t scrut5;
  uint64_t o21;
  uint64_t c12;
  K___uint64_t_uint64_t scrut6;
  uint64_t o31;
  uint64_t c22;
  uint64_t c31;
  lit0.fst = c30;
  lit0.snd.fst = o04;
  lit0.snd.snd = o10;
  lit0.snd.thd = o20;
  lit0.snd.f3 = o30;
  scrut3 = lit0;
  o03 = scrut3.snd.f3;
  o02 = scrut3.snd.thd;
  o01 = scrut3.snd.snd;
  o00 = scrut3.snd.fst;
  c0 = scrut3.fst;
  res4 = (uint128_t)r0 * f11;
  l01 = (uint64_t)res4;
  h01 = (uint64_t)(res4 >> (uint32_t)64U);
  res5 = (uint128_t)r1 * f11;
  l11 = (uint64_t)res5;
  h11 = (uint64_t)(res5 >> (uint32_t)64U);
  res6 = (uint128_t)r2 * f11;
  l21 = (uint64_t)res6;
  h21 = (uint64_t)(res6 >> (uint32_t)64U);
  res7 = (uint128_t)r3 * f11;
  l31 = (uint64_t)res7;
  h31 = (uint64_t)(res7 >> (uint32_t)64U);
  o05 = l01;
  scrut4 = Hacl_Spec_P256_Basic_addcarry(l11, h01, (uint64_t)0U);
  o15 = scrut4.fst;
  c010 = scrut4.snd;
  scrut5 = Hacl_Spec_P256_Basic_addcarry(l21, h11, c010);
  o21 = scrut5.fst;
  c12 = scrut5.snd;
  scrut6 = Hacl_Spec_P256_Basic_addcarry(l31, h21, c12);
  o31 = scrut6.fst;
  c22 = scrut6.snd;
  c31 = h31 + c22;
  {
    K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit1;
    K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut7;
    uint64_t c5;
    K___uint64_t_uint64_t_uint64_t_uint64_t out00;
    uint64_t o06;
    uint64_t o16;
    uint64_t o26;
    uint64_t o32;
    uint64_t f300;
    uint64_t f310;
    uint64_t f320;
    uint64_t f330;
    K___uint64_t_uint64_t scrut8;
    uint64_t o0_;
    uint64_t c011;
    K___uint64_t_uint64_t scrut9;
    uint64_t o1_;
    uint64_t c13;
    K___uint64_t_uint64_t scrut10;
    uint64_t o2_;
    uint64_t c23;
    K___uint64_t_uint64_t scrut11;
    uint64_t o3_;
    uint64_t c32;
    lit1.fst = c31;
    lit1.snd.fst = o05;
    lit1.snd.snd = o15;
    lit1.snd.thd = o21;
    lit1.snd.f3 = o31;
    scrut7 = lit1;
    c5 = scrut7.fst;
    out00 = scrut7.snd;
    o06 = out00.fst;
    o16 = out00.snd;
    o26 = out00.thd;
    o32 = out00.f3;
    f300 = o01;
    f310 = o02;
    f320 = o03;
    f330 = c0;
    scrut8 = Hacl_Spec_P256_Basic_addcarry(f300, o06, (uint64_t)0U);
    o0_ = scrut8.fst;
    c011 = scrut8.snd;
    scrut9 = Hacl_Spec_P256_Basic_addcarry(f310, o16, c011);
    o1_ = scrut9.fst;
    c13 = scrut9.snd;
    scrut10 = Hacl_Spec_P256_Basic_addcarry(f320, o26, c13);
    o2_ = scrut10.fst;
    c23 = scrut10.snd;
    scrut11 = Hacl_Spec_P256_Basic_addcarry(f330, o32, c23);
    o3_ = scrut11.fst;
    c32 = scrut11.snd;
    {
      K___uint64_t_uint64_t_uint64_t_uint64_t out10;
      uint64_t c40;
      out10.fst = o0_;
      out10.snd = o1_;
      out10.thd = o2_;
      out10.f3 = o3_;
      c40 = c5 + c32;
      {
        K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit2;
        K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut12;
        uint64_t o14;
        uint64_t o13;
        uint64_t o12;
        uint64_t o11;
        uint64_t c1;
        uint128_t res8;
        uint64_t l02;
        uint64_t h02;
        uint128_t res9;
        uint64_t l12;
        uint64_t h12;
        uint128_t res10;
        uint64_t l22;
        uint64_t h22;
        uint128_t res11;
        uint64_t l32;
        uint64_t h32;
        uint64_t o07;
        K___uint64_t_uint64_t scrut13;
        uint64_t o17;
        uint64_t c012;
        K___uint64_t_uint64_t scrut14;
        uint64_t o27;
        uint64_t c110;
        K___uint64_t_uint64_t scrut15;
        uint64_t o37;
        uint64_t c24;
        uint64_t c33;
        lit2.fst = c40;
        lit2.snd = out10;
        scrut12 = lit2;
        o14 = scrut12.snd.f3;
        o13 = scrut12.snd.thd;
        o12 = scrut12.snd.snd;
        o11 = scrut12.snd.fst;
        c1 = scrut12.fst;
        res8 = (uint128_t)r0 * f12;
        l02 = (uint64_t)res8;
        h02 = (uint64_t)(res8 >> (uint32_t)64U);
        res9 = (uint128_t)r1 * f12;
        l12 = (uint64_t)res9;
        h12 = (uint64_t)(res9 >> (uint32_t)64U);
        res10 = (uint128_t)r2 * f12;
        l22 = (uint64_t)res10;
        h22 = (uint64_t)(res10 >> (uint32_t)64U);
        res11 = (uint128_t)r3 * f12;
        l32 = (uint64_t)res11;
        h32 = (uint64_t)(res11 >> (uint32_t)64U);
        o07 = l02;
        scrut13 = Hacl_Spec_P256_Basic_addcarry(l12, h02, (uint64_t)0U);
        o17 = scrut13.fst;
        c012 = scrut13.snd;
        scrut14 = Hacl_Spec_P256_Basic_addcarry(l22, h12, c012);
        o27 = scrut14.fst;
        c110 = scrut14.snd;
        scrut15 = Hacl_Spec_P256_Basic_addcarry(l32, h22, c110);
        o37 = scrut15.fst;
        c24 = scrut15.snd;
        c33 = h32 + c24;
        {
          K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit3;
          K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut16;
          uint64_t c6;
          K___uint64_t_uint64_t_uint64_t_uint64_t out01;
          uint64_t o08;
          uint64_t o18;
          uint64_t o28;
          uint64_t o38;
          uint64_t f301;
          uint64_t f311;
          uint64_t f321;
          uint64_t f331;
          K___uint64_t_uint64_t scrut17;
          uint64_t o0_0;
          uint64_t c013;
          K___uint64_t_uint64_t scrut18;
          uint64_t o1_0;
          uint64_t c111;
          K___uint64_t_uint64_t scrut19;
          uint64_t o2_0;
          uint64_t c25;
          K___uint64_t_uint64_t scrut20;
          uint64_t o3_0;
          uint64_t c34;
          lit3.fst = c33;
          lit3.snd.fst = o07;
          lit3.snd.snd = o17;
          lit3.snd.thd = o27;
          lit3.snd.f3 = o37;
          scrut16 = lit3;
          c6 = scrut16.fst;
          out01 = scrut16.snd;
          o08 = out01.fst;
          o18 = out01.snd;
          o28 = out01.thd;
          o38 = out01.f3;
          f301 = o12;
          f311 = o13;
          f321 = o14;
          f331 = c1;
          scrut17 = Hacl_Spec_P256_Basic_addcarry(f301, o08, (uint64_t)0U);
          o0_0 = scrut17.fst;
          c013 = scrut17.snd;
          scrut18 = Hacl_Spec_P256_Basic_addcarry(f311, o18, c013);
          o1_0 = scrut18.fst;
          c111 = scrut18.snd;
          scrut19 = Hacl_Spec_P256_Basic_addcarry(f321, o28, c111);
          o2_0 = scrut19.fst;
          c25 = scrut19.snd;
          scrut20 = Hacl_Spec_P256_Basic_addcarry(f331, o38, c25);
          o3_0 = scrut20.fst;
          c34 = scrut20.snd;
          {
            K___uint64_t_uint64_t_uint64_t_uint64_t out11;
            uint64_t c41;
            out11.fst = o0_0;
            out11.snd = o1_0;
            out11.thd = o2_0;
            out11.f3 = o3_0;
            c41 = c6 + c34;
            {
              K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit4;
              K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut21;
              uint64_t o25;
              uint64_t o24;
              uint64_t o23;
              uint64_t o22;
              uint64_t c2;
              uint128_t res12;
              uint64_t l0;
              uint64_t h0;
              uint128_t res13;
              uint64_t l1;
              uint64_t h1;
              uint128_t res14;
              uint64_t l2;
              uint64_t h2;
              uint128_t res;
              uint64_t l3;
              uint64_t h3;
              uint64_t o09;
              K___uint64_t_uint64_t scrut22;
              uint64_t o19;
              uint64_t c014;
              K___uint64_t_uint64_t scrut23;
              uint64_t o29;
              uint64_t c112;
              K___uint64_t_uint64_t scrut24;
              uint64_t o39;
              uint64_t c210;
              uint64_t c35;
              lit4.fst = c41;
              lit4.snd = out11;
              scrut21 = lit4;
              o25 = scrut21.snd.f3;
              o24 = scrut21.snd.thd;
              o23 = scrut21.snd.snd;
              o22 = scrut21.snd.fst;
              c2 = scrut21.fst;
              res12 = (uint128_t)r0 * f13;
              l0 = (uint64_t)res12;
              h0 = (uint64_t)(res12 >> (uint32_t)64U);
              res13 = (uint128_t)r1 * f13;
              l1 = (uint64_t)res13;
              h1 = (uint64_t)(res13 >> (uint32_t)64U);
              res14 = (uint128_t)r2 * f13;
              l2 = (uint64_t)res14;
              h2 = (uint64_t)(res14 >> (uint32_t)64U);
              res = (uint128_t)r3 * f13;
              l3 = (uint64_t)res;
              h3 = (uint64_t)(res >> (uint32_t)64U);
              o09 = l0;
              scrut22 = Hacl_Spec_P256_Basic_addcarry(l1, h0, (uint64_t)0U);
              o19 = scrut22.fst;
              c014 = scrut22.snd;
              scrut23 = Hacl_Spec_P256_Basic_addcarry(l2, h1, c014);
              o29 = scrut23.fst;
              c112 = scrut23.snd;
              scrut24 = Hacl_Spec_P256_Basic_addcarry(l3, h2, c112);
              o39 = scrut24.fst;
              c210 = scrut24.snd;
              c35 = h3 + c210;
              {
                K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit5;
                K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut25;
                uint64_t c;
                K___uint64_t_uint64_t_uint64_t_uint64_t out0;
                uint64_t o010;
                uint64_t o110;
                uint64_t o210;
                uint64_t o310;
                uint64_t f30;
                uint64_t f31;
                uint64_t f32;
                uint64_t f33;
                K___uint64_t_uint64_t scrut26;
                uint64_t o0_1;
                uint64_t c01;
                K___uint64_t_uint64_t scrut27;
                uint64_t o1_1;
                uint64_t c11;
                K___uint64_t_uint64_t scrut28;
                uint64_t o2_1;
                uint64_t c21;
                K___uint64_t_uint64_t scrut29;
                uint64_t o3_1;
                uint64_t c36;
                lit5.fst = c35;
                lit5.snd.fst = o09;
                lit5.snd.snd = o19;
                lit5.snd.thd = o29;
                lit5.snd.f3 = o39;
                scrut25 = lit5;
                c = scrut25.fst;
                out0 = scrut25.snd;
                o010 = out0.fst;
                o110 = out0.snd;
                o210 = out0.thd;
                o310 = out0.f3;
                f30 = o23;
                f31 = o24;
                f32 = o25;
                f33 = c2;
                scrut26 = Hacl_Spec_P256_Basic_addcarry(f30, o010, (uint64_t)0U);
                o0_1 = scrut26.fst;
                c01 = scrut26.snd;
                scrut27 = Hacl_Spec_P256_Basic_addcarry(f31, o110, c01);
                o1_1 = scrut27.fst;
                c11 = scrut27.snd;
                scrut28 = Hacl_Spec_P256_Basic_addcarry(f32, o210, c11);
                o2_1 = scrut28.fst;
                c21 = scrut28.snd;
                scrut29 = Hacl_Spec_P256_Basic_addcarry(f33, o310, c21);
                o3_1 = scrut29.fst;
                c36 = scrut29.snd;
                {
                  K___uint64_t_uint64_t_uint64_t_uint64_t out1;
                  uint64_t c4;
                  out1.fst = o0_1;
                  out1.snd = o1_1;
                  out1.thd = o2_1;
                  out1.f3 = o3_1;
                  c4 = c + c36;
                  {
                    K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit6;
                    K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut30;
                    uint64_t o36;
                    uint64_t o35;
                    uint64_t o34;
                    uint64_t o33;
                    uint64_t c3;
                    lit6.fst = c4;
                    lit6.snd = out1;
                    scrut30 = lit6;
                    o36 = scrut30.snd.f3;
                    o35 = scrut30.snd.thd;
                    o34 = scrut30.snd.snd;
                    o33 = scrut30.snd.fst;
                    c3 = scrut30.fst;
                    {
                      K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
                      lit;
                      K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
                      scrut;
                      uint64_t o0;
                      uint64_t o1;
                      uint64_t o2;
                      uint64_t o3;
                      uint64_t o4;
                      uint64_t o5;
                      uint64_t o6;
                      uint64_t o7;
                      lit.fst = o00;
                      lit.snd = o11;
                      lit.thd = o22;
                      lit.f3 = o33;
                      lit.f4 = o34;
                      lit.f5 = o35;
                      lit.f6 = o36;
                      lit.f7 = c3;
                      scrut = lit;
                      o0 = scrut.fst;
                      o1 = scrut.snd;
                      o2 = scrut.thd;
                      o3 = scrut.f3;
                      o4 = scrut.f4;
                      o5 = scrut.f5;
                      o6 = scrut.f6;
                      o7 = scrut.f7;
                      out[0U] = o0;
                      out[1U] = o1;
                      out[2U] = o2;
                      out[3U] = o3;
                      out[4U] = o4;
                      out[5U] = o5;
                      out[6U] = o6;
                      out[7U] = o7;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

static void
Hacl_Impl_ECDSA_MontgomeryMultiplication_shortened_mul(
  uint64_t *a,
  uint64_t b,
  uint64_t *result
)
{
  uint64_t a0 = a[0U];
  uint64_t a1 = a[1U];
  uint64_t a2 = a[2U];
  uint64_t a3 = a[3U];
  uint128_t res0 = (uint128_t)a0 * b;
  uint64_t l0 = (uint64_t)res0;
  uint64_t h0 = (uint64_t)(res0 >> (uint32_t)64U);
  uint128_t res1 = (uint128_t)a1 * b;
  uint64_t l1 = (uint64_t)res1;
  uint64_t h1 = (uint64_t)(res1 >> (uint32_t)64U);
  uint128_t res2 = (uint128_t)a2 * b;
  uint64_t l2 = (uint64_t)res2;
  uint64_t h2 = (uint64_t)(res2 >> (uint32_t)64U);
  uint128_t res = (uint128_t)a3 * b;
  uint64_t l3 = (uint64_t)res;
  uint64_t h3 = (uint64_t)(res >> (uint32_t)64U);
  uint64_t o0 = l0;
  K___uint64_t_uint64_t scrut0 = Hacl_Spec_P256_Basic_addcarry(l1, h0, (uint64_t)0U);
  uint64_t o1 = scrut0.fst;
  uint64_t c0 = scrut0.snd;
  K___uint64_t_uint64_t scrut1 = Hacl_Spec_P256_Basic_addcarry(l2, h1, c0);
  uint64_t o2 = scrut1.fst;
  uint64_t c1 = scrut1.snd;
  K___uint64_t_uint64_t scrut2 = Hacl_Spec_P256_Basic_addcarry(l3, h2, c1);
  uint64_t o3 = scrut2.fst;
  uint64_t c2 = scrut2.snd;
  uint64_t c3 = h3 + c2;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit0;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut3;
  uint64_t f30;
  uint64_t f20;
  uint64_t f10;
  uint64_t f00;
  uint64_t c;
  lit0.fst = c3;
  lit0.snd.fst = o0;
  lit0.snd.snd = o1;
  lit0.snd.thd = o2;
  lit0.snd.f3 = o3;
  scrut3 = lit0;
  f30 = scrut3.snd.f3;
  f20 = scrut3.snd.thd;
  f10 = scrut3.snd.snd;
  f00 = scrut3.snd.fst;
  c = scrut3.fst;
  {
    K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t lit;
    K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t scrut;
    uint64_t f0;
    uint64_t f1;
    uint64_t f2;
    uint64_t f3;
    uint64_t f4;
    uint64_t f5;
    uint64_t f6;
    uint64_t f7;
    lit.fst = f00;
    lit.snd = f10;
    lit.thd = f20;
    lit.f3 = f30;
    lit.f4 = c;
    lit.f5 = (uint64_t)0U;
    lit.f6 = (uint64_t)0U;
    lit.f7 = (uint64_t)0U;
    scrut = lit;
    f0 = scrut.fst;
    f1 = scrut.snd;
    f2 = scrut.thd;
    f3 = scrut.f3;
    f4 = scrut.f4;
    f5 = scrut.f5;
    f6 = scrut.f6;
    f7 = scrut.f7;
    result[0U] = f0;
    result[1U] = f1;
    result[2U] = f2;
    result[3U] = f3;
    result[4U] = f4;
    result[5U] = f5;
    result[6U] = f6;
    result[7U] = f7;
  }
}

static void
Hacl_Impl_ECDSA_MontgomeryMultiplication_add8_without_carry1(
  uint64_t *t,
  uint64_t *r,
  uint64_t *result
)
{
  uint64_t t0 = t[0U];
  uint64_t t1 = t[1U];
  uint64_t t2 = t[2U];
  uint64_t t3 = t[3U];
  uint64_t t4 = t[4U];
  uint64_t t5 = t[5U];
  uint64_t t6 = t[6U];
  uint64_t t7 = t[7U];
  uint64_t r0 = r[0U];
  uint64_t r1 = r[1U];
  uint64_t r2 = r[2U];
  uint64_t r3 = r[3U];
  uint64_t r4 = r[4U];
  uint64_t r5 = r[5U];
  uint64_t r6 = r[6U];
  uint64_t r7 = r[7U];
  K___uint64_t_uint64_t scrut0 = Hacl_Spec_P256_Basic_addcarry(t0, r0, (uint64_t)0U);
  uint64_t o00 = scrut0.fst;
  uint64_t c0 = scrut0.snd;
  K___uint64_t_uint64_t scrut1 = Hacl_Spec_P256_Basic_addcarry(t1, r1, c0);
  uint64_t o10 = scrut1.fst;
  uint64_t c1 = scrut1.snd;
  K___uint64_t_uint64_t scrut2 = Hacl_Spec_P256_Basic_addcarry(t2, r2, c1);
  uint64_t o20 = scrut2.fst;
  uint64_t c2 = scrut2.snd;
  K___uint64_t_uint64_t scrut3 = Hacl_Spec_P256_Basic_addcarry(t3, r3, c2);
  uint64_t o30 = scrut3.fst;
  uint64_t c30 = scrut3.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t lit0;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t scrut4;
  uint64_t o3;
  uint64_t o2;
  uint64_t o1;
  uint64_t o0;
  uint64_t c3;
  K___uint64_t_uint64_t scrut5;
  uint64_t o4;
  uint64_t c4;
  K___uint64_t_uint64_t scrut6;
  uint64_t o5;
  uint64_t c5;
  K___uint64_t_uint64_t scrut7;
  uint64_t o6;
  uint64_t c6;
  K___uint64_t_uint64_t scrut8;
  uint64_t o7;
  uint64_t c7;
  lit0.fst = c30;
  lit0.snd.fst = o00;
  lit0.snd.snd = o10;
  lit0.snd.thd = o20;
  lit0.snd.f3 = o30;
  scrut4 = lit0;
  o3 = scrut4.snd.f3;
  o2 = scrut4.snd.thd;
  o1 = scrut4.snd.snd;
  o0 = scrut4.snd.fst;
  c3 = scrut4.fst;
  scrut5 = Hacl_Spec_P256_Basic_addcarry(t4, r4, c3);
  o4 = scrut5.fst;
  c4 = scrut5.snd;
  scrut6 = Hacl_Spec_P256_Basic_addcarry(t5, r5, c4);
  o5 = scrut6.fst;
  c5 = scrut6.snd;
  scrut7 = Hacl_Spec_P256_Basic_addcarry(t6, r6, c5);
  o6 = scrut7.fst;
  c6 = scrut7.snd;
  scrut8 = Hacl_Spec_P256_Basic_addcarry(t7, r7, c6);
  o7 = scrut8.fst;
  c7 = scrut8.snd;
  {
    K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t lit1;
    K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t scrut9;
    uint64_t r010;
    uint64_t r110;
    uint64_t r210;
    uint64_t r310;
    uint64_t r410;
    uint64_t r510;
    uint64_t r610;
    uint64_t r710;
    lit1.fst = c7;
    lit1.snd = o0;
    lit1.thd = o1;
    lit1.f3 = o2;
    lit1.f4 = o3;
    lit1.f5 = o4;
    lit1.f6 = o5;
    lit1.f7 = o6;
    lit1.f8 = o7;
    scrut9 = lit1;
    r010 = scrut9.snd;
    r110 = scrut9.thd;
    r210 = scrut9.f3;
    r310 = scrut9.f4;
    r410 = scrut9.f5;
    r510 = scrut9.f6;
    r610 = scrut9.f7;
    r710 = scrut9.f8;
    {
      K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t lit;
      K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t scrut;
      uint64_t r01;
      uint64_t r11;
      uint64_t r21;
      uint64_t r31;
      uint64_t r41;
      uint64_t r51;
      uint64_t r61;
      uint64_t r71;
      lit.fst = r010;
      lit.snd = r110;
      lit.thd = r210;
      lit.f3 = r310;
      lit.f4 = r410;
      lit.f5 = r510;
      lit.f6 = r610;
      lit.f7 = r710;
      scrut = lit;
      r01 = scrut.fst;
      r11 = scrut.snd;
      r21 = scrut.thd;
      r31 = scrut.f3;
      r41 = scrut.f4;
      r51 = scrut.f5;
      r61 = scrut.f6;
      r71 = scrut.f7;
      result[0U] = r01;
      result[1U] = r11;
      result[2U] = r21;
      result[3U] = r31;
      result[4U] = r41;
      result[5U] = r51;
      result[6U] = r61;
      result[7U] = r71;
    }
  }
}

static void Hacl_Impl_ECDSA_MontgomeryMultiplication_shift8(uint64_t *t, uint64_t *out)
{
  uint64_t t1 = t[1U];
  uint64_t t2 = t[2U];
  uint64_t t3 = t[3U];
  uint64_t t4 = t[4U];
  uint64_t t5 = t[5U];
  uint64_t t6 = t[6U];
  uint64_t t7 = t[7U];
  out[0U] = t1;
  out[1U] = t2;
  out[2U] = t3;
  out[3U] = t4;
  out[4U] = t5;
  out[5U] = t6;
  out[6U] = t7;
  out[7U] = (uint64_t)0U;
}

static void
Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_round(
  uint64_t *t,
  uint64_t *round,
  uint64_t k0
)
{
  uint64_t yBuffer[8U] = { 0U };
  uint64_t t2[8U] = { 0U };
  uint64_t t3[8U] = { 0U };
  uint64_t t1 = t[0U];
  uint128_t res = (uint128_t)t1 * k0;
  K___uint64_t_uint64_t scrut;
  uint64_t y;
  scrut.fst = (uint64_t)res;
  scrut.snd = (uint64_t)(res >> (uint32_t)64U);
  y = scrut.fst;
  Hacl_Impl_ECDSA_MontgomeryMultiplication_shortened_mul(Hacl_Impl_ECDSA_MontgomeryMultiplication_prime256order_buffer,
    y,
    t2);
  Hacl_Impl_ECDSA_MontgomeryMultiplication_add8_without_carry1(t, t2, t3);
  Hacl_Impl_ECDSA_MontgomeryMultiplication_shift8(t3, round);
}

void
Hacl_Impl_ECDSA_MontgomeryMultiplication_reduction_prime_2prime_order(
  uint64_t *x,
  uint64_t *result
)
{
  uint64_t tempBuffer[4U] = { 0U };
  uint64_t
  c =
    Hacl_Impl_LowLevel_sub4_il(x,
      Hacl_Impl_ECDSA_MontgomeryMultiplication_prime256order_buffer,
      tempBuffer);
  Hacl_Impl_LowLevel_cmovznz4(c, tempBuffer, x, result);
}

static uint64_t Hacl_Impl_ECDSA_MontgomeryMultiplication_upload_k0()
{
  return (uint64_t)14758798090332847183U;
}

void
Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_ecdsa_module(
  uint64_t *a,
  uint64_t *b,
  uint64_t *result
)
{
  uint64_t t[8U] = { 0U };
  uint64_t round2[8U] = { 0U };
  uint64_t round4[8U] = { 0U };
  uint64_t prime_p256_orderBuffer[4U] = { 0U };
  uint64_t k0 = Hacl_Impl_ECDSA_MontgomeryMultiplication_upload_k0();
  Hacl_Impl_ECDSA_MontgomeryMultiplication_mul(a, b, t);
  {
    uint64_t tempRound[8U] = { 0U };
    Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_round(t, tempRound, k0);
    Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_round(tempRound,
      round2,
      k0);
    {
      uint64_t tempRound0[8U] = { 0U };
      Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_round(round2,
        tempRound0,
        k0);
      Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_round(tempRound0,
        round4,
        k0);
      {
        uint64_t tempBuffer[4U] = { 0U };
        uint64_t tempBufferForSubborrow = (uint64_t)0U;
        uint64_t cin = round4[4U];
        uint64_t *x = round4;
        uint64_t
        c =
          Hacl_Impl_LowLevel_sub4_il(x,
            Hacl_Impl_ECDSA_MontgomeryMultiplication_prime256order_buffer,
            tempBuffer);
        uint64_t
        carry = Hacl_Impl_LowLevel_sub_borrow(c, cin, (uint64_t)0U, &tempBufferForSubborrow);
        Hacl_Impl_LowLevel_cmovznz4(carry, tempBuffer, x, result);
      }
    }
  }
}

