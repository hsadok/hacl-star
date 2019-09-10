/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: /home/nkulatov/new2/kremlin/kremlin/krml -fbuiltin-uint128 -fnocompound-literals -fc89-scope -fparentheses -fcurly-braces -funroll-loops 4 -warn-error +9 -add-include "kremlib.h" -add-include "FStar_UInt_8_16_32_64.h" /dist/minimal/testlib.c -skip-compilation -no-prefix Hacl.Impl.P256 -bundle Lib.* -bundle Spec.* -bundle C=C.Endianness -bundle Hacl.Hash.SHA2=Hacl.Hash.*,Spec.Hash.* -bundle Hacl.Impl.P256=Hacl.Impl.P256,Hacl.Impl.LowLevel,Hacl.Impl.SolinasReduction,Hacl.Spec.P256.*,Hacl.Spec.Curve25519.*,Hacl.Impl.Curve25519.* -bundle Hacl.Impl.ECDSA.P256SHA256.Verification=Hacl.Impl.MontgomeryMultiplication,Hacl.Impl.ECDSA.P256SHA256.Verification,Hacl.Impl.MM.Exponent -library C,FStar -drop LowStar,Spec,Prims,Lib,C.Loops.*,Hacl.Spec.P256.Lemmas,Hacl.Spec.P256,Hacl.Spec.ECDSA -add-include "c/Lib_PrintBuffer.h" -add-include "FStar_UInt_8_16_32_64.h" -tmpdir ecdsap256-c .output/prims.krml .output/FStar_Pervasives_Native.krml .output/FStar_Pervasives.krml .output/FStar_Squash.krml .output/FStar_Classical.krml .output/FStar_StrongExcludedMiddle.krml .output/FStar_FunctionalExtensionality.krml .output/FStar_List_Tot_Base.krml .output/FStar_List_Tot_Properties.krml .output/FStar_List_Tot.krml .output/FStar_Mul.krml .output/FStar_Math_Lib.krml .output/FStar_Math_Lemmas.krml .output/FStar_Seq_Base.krml .output/FStar_Seq_Properties.krml .output/FStar_Seq.krml .output/FStar_Set.krml .output/FStar_Preorder.krml .output/FStar_Ghost.krml .output/FStar_ErasedLogic.krml .output/FStar_PropositionalExtensionality.krml .output/FStar_PredicateExtensionality.krml .output/FStar_TSet.krml .output/FStar_Monotonic_Heap.krml .output/FStar_Heap.krml .output/FStar_Map.krml .output/FStar_Monotonic_Witnessed.krml .output/FStar_Monotonic_HyperHeap.krml .output/FStar_Monotonic_HyperStack.krml .output/FStar_HyperStack.krml .output/FStar_HyperStack_ST.krml .output/FStar_Calc.krml .output/FStar_BitVector.krml .output/FStar_UInt.krml .output/FStar_UInt32.krml .output/FStar_Universe.krml .output/FStar_GSet.krml .output/FStar_ModifiesGen.krml .output/FStar_Range.krml .output/FStar_Reflection_Types.krml .output/FStar_Tactics_Types.krml .output/FStar_Tactics_Result.krml .output/FStar_Tactics_Effect.krml .output/FStar_Tactics_Util.krml .output/FStar_Reflection_Data.krml .output/FStar_Reflection_Const.krml .output/FStar_Char.krml .output/FStar_Exn.krml .output/FStar_ST.krml .output/FStar_All.krml .output/FStar_List.krml .output/FStar_String.krml .output/FStar_Order.krml .output/FStar_Reflection_Basic.krml .output/FStar_Reflection_Derived.krml .output/FStar_Tactics_Builtins.krml .output/FStar_Reflection_Formula.krml .output/FStar_Reflection_Derived_Lemmas.krml .output/FStar_Reflection.krml .output/FStar_Tactics_Derived.krml .output/FStar_Tactics_Logic.krml .output/FStar_Tactics.krml .output/FStar_BigOps.krml .output/LowStar_Monotonic_Buffer.krml .output/LowStar_Buffer.krml .output/LowStar_BufferOps.krml .output/Spec_Loops.krml .output/FStar_UInt64.krml .output/C_Loops.krml .output/FStar_Int.krml .output/FStar_Int64.krml .output/FStar_Int63.krml .output/FStar_Int32.krml .output/FStar_Int16.krml .output/FStar_Int8.krml .output/FStar_UInt63.krml .output/FStar_UInt16.krml .output/FStar_UInt8.krml .output/FStar_Int_Cast.krml .output/FStar_UInt128.krml .output/FStar_Int_Cast_Full.krml .output/FStar_Int128.krml .output/Lib_IntTypes.krml .output/Lib_Loops.krml .output/Lib_LoopCombinators.krml .output/Lib_RawIntTypes.krml .output/Lib_Sequence.krml .output/Lib_ByteSequence.krml .output/LowStar_ImmutableBuffer.krml .output/Lib_Buffer.krml .output/FStar_HyperStack_All.krml .output/Hacl_Spec_ECDSAP256_Definition.krml .output/Lib_IntTypes_Compatibility.krml .output/Spec_Hash_Definitions.krml .output/Spec_Hash_Lemmas0.krml .output/Spec_Hash_PadFinish.krml .output/Spec_SHA1.krml .output/Spec_MD5.krml .output/Spec_SHA2_Constants.krml .output/Spec_SHA2.krml .output/Spec_Hash.krml .output/Spec_Curve25519_Lemmas.krml .output/FStar_Reflection_Arith.krml .output/FStar_Tactics_Canon.krml .output/Hacl_Spec_P256_Definitions.krml .output/Hacl_Impl_Curve25519_Lemmas.krml .output/Spec_Curve25519.krml .output/Hacl_Spec_Curve25519_Field64_Definition.krml .output/Hacl_Spec_Curve25519_Field64_Lemmas.krml .output/Hacl_Spec_P256_Basic.krml .output/Hacl_Spec_P256_Lemmas.krml .output/Hacl_Spec_P256_Core.krml .output/Hacl_Spec_P256_MontgomeryMultiplication.krml .output/Hacl_Impl_LowLevel.krml .output/Hacl_Spec_P256_SolinasReduction.krml .output/Hacl_Impl_SolinasReduction.krml .output/FStar_Kremlin_Endianness.krml .output/C_Endianness.krml .output/C.krml .output/Lib_ByteBuffer.krml .output/Spec_Hash_Incremental.krml .output/Spec_Hash_Lemmas.krml .output/Hacl_Hash_Lemmas.krml .output/LowStar_Modifies.krml .output/Hacl_Hash_Definitions.krml .output/Hacl_Hash_PadFinish.krml .output/Hacl_Hash_MD.krml .output/Hacl_Impl_ECDSA_MontgomeryMultiplication.krml .output/Hacl_Spec_P256.krml .output/Hacl_Spec_P256_MontgomeryMultiplication_PointDouble.krml .output/Hacl_Spec_P256_MontgomeryMultiplication_PointAdd.krml .output/Hacl_Spec_P256_Ladder.krml .output/Hacl_Spec_ECDSA.krml .output/Hacl_Impl_ECDSA_MM_Exponent.krml .output/Hacl_Hash_Core_SHA2_Constants.krml .output/Hacl_Hash_Core_SHA2.krml .output/Hacl_Spec_P256_Normalisation.krml .output/Hacl_Impl_P256.krml .output/Hacl_Hash_SHA2.krml .output/Hacl_Impl_ECDSA_P256SHA256_Verification.krml
  F* version: ea91ae8c
  KreMLin version: 27ce15c8
 */

#include "Hacl_Impl_ECDSA_MM_Exponent.h"

uint8_t
Hacl_Impl_ECDSA_MM_Exponent_order_inverse_buffer[32U] =
  {
    (uint8_t)79U, (uint8_t)37U, (uint8_t)99U, (uint8_t)252U, (uint8_t)194U, (uint8_t)202U,
    (uint8_t)185U, (uint8_t)243U, (uint8_t)132U, (uint8_t)158U, (uint8_t)23U, (uint8_t)167U,
    (uint8_t)173U, (uint8_t)250U, (uint8_t)230U, (uint8_t)188U, (uint8_t)255U, (uint8_t)255U,
    (uint8_t)255U, (uint8_t)255U, (uint8_t)255U, (uint8_t)255U, (uint8_t)255U, (uint8_t)255U,
    (uint8_t)0U, (uint8_t)0U, (uint8_t)0U, (uint8_t)0U, (uint8_t)255U, (uint8_t)255U, (uint8_t)255U,
    (uint8_t)255U
  };

uint8_t
Hacl_Impl_ECDSA_MM_Exponent_order_buffer[32U] =
  {
    (uint8_t)81U, (uint8_t)37U, (uint8_t)99U, (uint8_t)252U, (uint8_t)194U, (uint8_t)202U,
    (uint8_t)185U, (uint8_t)243U, (uint8_t)132U, (uint8_t)158U, (uint8_t)23U, (uint8_t)167U,
    (uint8_t)173U, (uint8_t)250U, (uint8_t)230U, (uint8_t)188U, (uint8_t)255U, (uint8_t)255U,
    (uint8_t)255U, (uint8_t)255U, (uint8_t)255U, (uint8_t)255U, (uint8_t)255U, (uint8_t)255U,
    (uint8_t)0U, (uint8_t)0U, (uint8_t)0U, (uint8_t)0U, (uint8_t)255U, (uint8_t)255U, (uint8_t)255U,
    (uint8_t)255U
  };

static void Hacl_Impl_ECDSA_MM_Exponent_cswap(uint64_t bit, uint64_t *p1, uint64_t *p2)
{
  uint64_t mask = (uint64_t)0U - bit;
  uint32_t i;
  for (i = (uint32_t)0U; i < (uint32_t)4U; i = i + (uint32_t)1U)
  {
    uint64_t dummy = mask & (p1[i] ^ p2[i]);
    p1[i] = p1[i] ^ dummy;
    p2[i] = p2[i] ^ dummy;
  }
}

void Hacl_Impl_ECDSA_MM_Exponent_montgomery_ladder_exponent(uint64_t *r)
{
  uint64_t p[4U] = { 0U };
  p[0U] = (uint64_t)884452912994769583U;
  p[1U] = (uint64_t)4834901526196019579U;
  p[2U] = (uint64_t)0U;
  p[3U] = (uint64_t)4294967295U;
  {
    uint32_t i;
    for (i = (uint32_t)0U; i < (uint32_t)256U; i = i + (uint32_t)1U)
    {
      uint32_t bit0 = (uint32_t)255U - i;
      uint64_t
      bit =
        (uint64_t)(Hacl_Impl_ECDSA_MM_Exponent_order_inverse_buffer[bit0
        / (uint32_t)8U]
        >> bit0 % (uint32_t)8U
        & (uint8_t)1U);
      Hacl_Impl_ECDSA_MM_Exponent_cswap(bit, p, r);
      Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_ecdsa_module(p, r, r);
      Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_ecdsa_module(p, p, p);
      Hacl_Impl_ECDSA_MM_Exponent_cswap(bit, p, r);
    }
  }
  memcpy(r, p, (uint32_t)4U * sizeof p[0U]);
}

void Hacl_Impl_ECDSA_MM_Exponent_fromDomainImpl(uint64_t *a, uint64_t *result)
{
  uint64_t one1[4U] = { 0U };
  one1[0U] = (uint64_t)1U;
  one1[1U] = (uint64_t)0U;
  one1[2U] = (uint64_t)0U;
  one1[3U] = (uint64_t)0U;
  Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_ecdsa_module(one1,
    a,
    result);
}

void Hacl_Impl_ECDSA_MM_Exponent_multPower(uint64_t *a, uint64_t *b, uint64_t *result)
{
  uint64_t tempB1[4U] = { 0U };
  uint64_t buffFromDB[4U] = { 0U };
  Hacl_Impl_ECDSA_MM_Exponent_fromDomainImpl(a, tempB1);
  Hacl_Impl_ECDSA_MM_Exponent_fromDomainImpl(b, buffFromDB);
  Hacl_Impl_ECDSA_MM_Exponent_fromDomainImpl(buffFromDB, buffFromDB);
  Hacl_Impl_ECDSA_MM_Exponent_montgomery_ladder_exponent(tempB1);
  Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_ecdsa_module(tempB1,
    buffFromDB,
    result);
}

void
Hacl_Impl_ECDSA_MM_Exponent_multPowerPartial(
  uint64_t *s1,
  uint64_t *a,
  uint64_t *b,
  uint64_t *result
)
{
  uint64_t buffFromDB[4U] = { 0U };
  Hacl_Impl_ECDSA_MM_Exponent_fromDomainImpl(b, buffFromDB);
  Hacl_Impl_ECDSA_MM_Exponent_fromDomainImpl(buffFromDB, buffFromDB);
  Hacl_Impl_ECDSA_MontgomeryMultiplication_montgomery_multiplication_ecdsa_module(a,
    buffFromDB,
    result);
}

