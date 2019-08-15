/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: /home/nkulatov/new2/kremlin/kremlin/krml -fbuiltin-uint128 -funroll-loops 8 -add-include "TestLib.h" /dist/generic/testlib.c -skip-compilation -no-prefix Hacl.Impl.P256 -bundle Lib.* -bundle Spec.* -bundle Hacl.Impl.P256=Hacl.Impl.P256,Hacl.Impl.LowLevel,Hacl.Impl.SolinasReduction,Hacl.Spec.P256.*,Hacl.Spec.Curve25519.*,Hacl.Impl.Curve25519.* -bundle Hacl.Impl.ECDSA.P256SHA256.Verification=Hacl.Impl.MontgomeryMultiplication,Hacl.Impl.ECDSA.P256SHA256.Verification,Hacl.Impl.MM.Exponent -library C,FStar -drop LowStar,Spec,Prims,Lib,C.Loops.*,Hacl.Spec.P256.Lemmas,Hacl.Spec.P256,Hacl.Spec.ECDSA -add-include "c/Lib_PrintBuffer.h" -add-include "FStar_UInt_8_16_32_64.h" -tmpdir p256-c .output/prims.krml .output/FStar_Pervasives_Native.krml .output/FStar_Pervasives.krml .output/FStar_Squash.krml .output/FStar_Classical.krml .output/FStar_StrongExcludedMiddle.krml .output/FStar_FunctionalExtensionality.krml .output/FStar_List_Tot_Base.krml .output/FStar_List_Tot_Properties.krml .output/FStar_List_Tot.krml .output/FStar_Mul.krml .output/FStar_Math_Lib.krml .output/FStar_Math_Lemmas.krml .output/FStar_Seq_Base.krml .output/FStar_Seq_Properties.krml .output/FStar_Seq.krml .output/FStar_Set.krml .output/FStar_Preorder.krml .output/FStar_Ghost.krml .output/FStar_ErasedLogic.krml .output/FStar_PropositionalExtensionality.krml .output/FStar_PredicateExtensionality.krml .output/FStar_TSet.krml .output/FStar_Monotonic_Heap.krml .output/FStar_Heap.krml .output/FStar_Map.krml .output/FStar_Monotonic_Witnessed.krml .output/FStar_Monotonic_HyperHeap.krml .output/FStar_Monotonic_HyperStack.krml .output/FStar_HyperStack.krml .output/FStar_HyperStack_ST.krml .output/FStar_Calc.krml .output/FStar_BitVector.krml .output/FStar_UInt.krml .output/FStar_UInt32.krml .output/FStar_Universe.krml .output/FStar_GSet.krml .output/FStar_ModifiesGen.krml .output/FStar_Range.krml .output/FStar_Reflection_Types.krml .output/FStar_Tactics_Types.krml .output/FStar_Tactics_Result.krml .output/FStar_Tactics_Effect.krml .output/FStar_Tactics_Util.krml .output/FStar_Reflection_Data.krml .output/FStar_Reflection_Const.krml .output/FStar_Char.krml .output/FStar_Exn.krml .output/FStar_ST.krml .output/FStar_All.krml .output/FStar_List.krml .output/FStar_String.krml .output/FStar_Order.krml .output/FStar_Reflection_Basic.krml .output/FStar_Reflection_Derived.krml .output/FStar_Tactics_Builtins.krml .output/FStar_Reflection_Formula.krml .output/FStar_Reflection_Derived_Lemmas.krml .output/FStar_Reflection.krml .output/FStar_Tactics_Derived.krml .output/FStar_Tactics_Logic.krml .output/FStar_Tactics.krml .output/FStar_BigOps.krml .output/LowStar_Monotonic_Buffer.krml .output/LowStar_Buffer.krml .output/LowStar_BufferOps.krml .output/Spec_Loops.krml .output/FStar_UInt64.krml .output/C_Loops.krml .output/FStar_Int.krml .output/FStar_Int64.krml .output/FStar_Int63.krml .output/FStar_Int32.krml .output/FStar_Int16.krml .output/FStar_Int8.krml .output/FStar_UInt63.krml .output/FStar_UInt16.krml .output/FStar_UInt8.krml .output/FStar_Int_Cast.krml .output/FStar_UInt128.krml .output/FStar_Int_Cast_Full.krml .output/FStar_Int128.krml .output/Lib_IntTypes.krml .output/Lib_Loops.krml .output/Lib_LoopCombinators.krml .output/Lib_RawIntTypes.krml .output/Lib_Sequence.krml .output/Lib_ByteSequence.krml .output/LowStar_ImmutableBuffer.krml .output/Lib_Buffer.krml .output/FStar_HyperStack_All.krml .output/Hacl_Spec_ECDSAP256_Definition.krml .output/Lib_IntTypes_Compatibility.krml .output/Spec_Hash_Definitions.krml .output/Spec_Hash_Lemmas0.krml .output/Spec_Hash_PadFinish.krml .output/Spec_SHA1.krml .output/Spec_MD5.krml .output/Spec_SHA2_Constants.krml .output/Spec_SHA2.krml .output/Spec_Hash.krml .output/Spec_Curve25519_Lemmas.krml .output/FStar_Reflection_Arith.krml .output/FStar_Tactics_Canon.krml .output/Hacl_Spec_P256_Definitions.krml .output/Hacl_Impl_Curve25519_Lemmas.krml .output/Spec_Curve25519.krml .output/Hacl_Spec_Curve25519_Field64_Definition.krml .output/Hacl_Spec_Curve25519_Field64_Lemmas.krml .output/Hacl_Spec_P256_Basic.krml .output/Hacl_Spec_P256_Lemmas.krml .output/Hacl_Spec_P256_Core.krml .output/Hacl_Spec_P256_MontgomeryMultiplication.krml .output/Hacl_Impl_LowLevel.krml .output/Hacl_Spec_P256_SolinasReduction.krml .output/Hacl_Impl_SolinasReduction.krml .output/FStar_Kremlin_Endianness.krml .output/C_Endianness.krml .output/C.krml .output/Lib_ByteBuffer.krml .output/Spec_Hash_Incremental.krml .output/Spec_Hash_Lemmas.krml .output/Hacl_Hash_Lemmas.krml .output/LowStar_Modifies.krml .output/Hacl_Hash_Definitions.krml .output/Hacl_Hash_PadFinish.krml .output/Hacl_Hash_MD.krml .output/Hacl_Impl_MontgomeryMultiplication.krml .output/Hacl_Spec_P256.krml .output/Hacl_Spec_P256_MontgomeryMultiplication_PointDouble.krml .output/Hacl_Spec_P256_MontgomeryMultiplication_PointAdd.krml .output/Hacl_Spec_P256_Ladder.krml .output/Hacl_Spec_ECDSA.krml .output/Hacl_Impl_MM_Exponent.krml .output/Hacl_Hash_Core_SHA2_Constants.krml .output/Hacl_Hash_Core_SHA2.krml .output/Hacl_Hash_SHA2.krml .output/Hacl_Spec_P256_Normalisation.krml .output/Hacl_Impl_P256.krml .output/Hacl_Impl_ECDSA_P256SHA256_Verification.krml
  F* version: ea91ae8c
  KreMLin version: 27ce15c8
 */

#include "Hacl_Hash_Core_SHA2.h"

static uint32_t
Hacl_Hash_Core_SHA2_h224[8U] =
  {
    (uint32_t)0xc1059ed8U, (uint32_t)0x367cd507U, (uint32_t)0x3070dd17U, (uint32_t)0xf70e5939U,
    (uint32_t)0xffc00b31U, (uint32_t)0x68581511U, (uint32_t)0x64f98fa7U, (uint32_t)0xbefa4fa4U
  };

static uint32_t
Hacl_Hash_Core_SHA2_h256[8U] =
  {
    (uint32_t)0x6a09e667U, (uint32_t)0xbb67ae85U, (uint32_t)0x3c6ef372U, (uint32_t)0xa54ff53aU,
    (uint32_t)0x510e527fU, (uint32_t)0x9b05688cU, (uint32_t)0x1f83d9abU, (uint32_t)0x5be0cd19U
  };

static uint64_t
Hacl_Hash_Core_SHA2_h384[8U] =
  {
    (uint64_t)0xcbbb9d5dc1059ed8U, (uint64_t)0x629a292a367cd507U, (uint64_t)0x9159015a3070dd17U,
    (uint64_t)0x152fecd8f70e5939U, (uint64_t)0x67332667ffc00b31U, (uint64_t)0x8eb44a8768581511U,
    (uint64_t)0xdb0c2e0d64f98fa7U, (uint64_t)0x47b5481dbefa4fa4U
  };

static uint64_t
Hacl_Hash_Core_SHA2_h512[8U] =
  {
    (uint64_t)0x6a09e667f3bcc908U, (uint64_t)0xbb67ae8584caa73bU, (uint64_t)0x3c6ef372fe94f82bU,
    (uint64_t)0xa54ff53a5f1d36f1U, (uint64_t)0x510e527fade682d1U, (uint64_t)0x9b05688c2b3e6c1fU,
    (uint64_t)0x1f83d9abfb41bd6bU, (uint64_t)0x5be0cd19137e2179U
  };

void Hacl_Hash_Core_SHA2_init_224(uint32_t *s)
{
  {
    s[0U] = Hacl_Hash_Core_SHA2_h224[0U];
  }
  {
    s[1U] = Hacl_Hash_Core_SHA2_h224[1U];
  }
  {
    s[2U] = Hacl_Hash_Core_SHA2_h224[2U];
  }
  {
    s[3U] = Hacl_Hash_Core_SHA2_h224[3U];
  }
  {
    s[4U] = Hacl_Hash_Core_SHA2_h224[4U];
  }
  {
    s[5U] = Hacl_Hash_Core_SHA2_h224[5U];
  }
  {
    s[6U] = Hacl_Hash_Core_SHA2_h224[6U];
  }
  {
    s[7U] = Hacl_Hash_Core_SHA2_h224[7U];
  }
}

void Hacl_Hash_Core_SHA2_init_256(uint32_t *s)
{
  {
    s[0U] = Hacl_Hash_Core_SHA2_h256[0U];
  }
  {
    s[1U] = Hacl_Hash_Core_SHA2_h256[1U];
  }
  {
    s[2U] = Hacl_Hash_Core_SHA2_h256[2U];
  }
  {
    s[3U] = Hacl_Hash_Core_SHA2_h256[3U];
  }
  {
    s[4U] = Hacl_Hash_Core_SHA2_h256[4U];
  }
  {
    s[5U] = Hacl_Hash_Core_SHA2_h256[5U];
  }
  {
    s[6U] = Hacl_Hash_Core_SHA2_h256[6U];
  }
  {
    s[7U] = Hacl_Hash_Core_SHA2_h256[7U];
  }
}

void Hacl_Hash_Core_SHA2_init_384(uint64_t *s)
{
  {
    s[0U] = Hacl_Hash_Core_SHA2_h384[0U];
  }
  {
    s[1U] = Hacl_Hash_Core_SHA2_h384[1U];
  }
  {
    s[2U] = Hacl_Hash_Core_SHA2_h384[2U];
  }
  {
    s[3U] = Hacl_Hash_Core_SHA2_h384[3U];
  }
  {
    s[4U] = Hacl_Hash_Core_SHA2_h384[4U];
  }
  {
    s[5U] = Hacl_Hash_Core_SHA2_h384[5U];
  }
  {
    s[6U] = Hacl_Hash_Core_SHA2_h384[6U];
  }
  {
    s[7U] = Hacl_Hash_Core_SHA2_h384[7U];
  }
}

void Hacl_Hash_Core_SHA2_init_512(uint64_t *s)
{
  {
    s[0U] = Hacl_Hash_Core_SHA2_h512[0U];
  }
  {
    s[1U] = Hacl_Hash_Core_SHA2_h512[1U];
  }
  {
    s[2U] = Hacl_Hash_Core_SHA2_h512[2U];
  }
  {
    s[3U] = Hacl_Hash_Core_SHA2_h512[3U];
  }
  {
    s[4U] = Hacl_Hash_Core_SHA2_h512[4U];
  }
  {
    s[5U] = Hacl_Hash_Core_SHA2_h512[5U];
  }
  {
    s[6U] = Hacl_Hash_Core_SHA2_h512[6U];
  }
  {
    s[7U] = Hacl_Hash_Core_SHA2_h512[7U];
  }
}

void Hacl_Hash_Core_SHA2_update_224(uint32_t *hash1, uint8_t *block)
{
  uint32_t hash11[8U] = { 0U };
  uint32_t computed_ws[64U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)64U; i = i + (uint32_t)1U)
    if (i < (uint32_t)16U)
    {
      uint8_t *b = block + i * (uint32_t)4U;
      uint32_t u = load32_be(b);
      computed_ws[i] = u;
    }
    else
    {
      uint32_t t16 = computed_ws[i - (uint32_t)16U];
      uint32_t t15 = computed_ws[i - (uint32_t)15U];
      uint32_t t7 = computed_ws[i - (uint32_t)7U];
      uint32_t t2 = computed_ws[i - (uint32_t)2U];
      uint32_t
      s1 =
        (t2 >> (uint32_t)17U | t2 << (uint32_t)15U)
        ^ (t2 >> (uint32_t)19U | t2 << (uint32_t)13U) ^ t2 >> (uint32_t)10U;
      uint32_t
      s0 =
        (t15 >> (uint32_t)7U | t15 << (uint32_t)25U)
        ^ (t15 >> (uint32_t)18U | t15 << (uint32_t)14U) ^ t15 >> (uint32_t)3U;
      uint32_t w = s1 + t7 + s0 + t16;
      computed_ws[i] = w;
    }
  memcpy(hash11, hash1, (uint32_t)8U * sizeof hash1[0U]);
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)64U; i = i + (uint32_t)1U)
  {
    uint32_t a0 = hash11[0U];
    uint32_t b0 = hash11[1U];
    uint32_t c0 = hash11[2U];
    uint32_t d0 = hash11[3U];
    uint32_t e0 = hash11[4U];
    uint32_t f0 = hash11[5U];
    uint32_t g0 = hash11[6U];
    uint32_t h03 = hash11[7U];
    uint32_t w = computed_ws[i];
    uint32_t
    t1 =
      h03
      +
        ((e0 >> (uint32_t)6U | e0 << (uint32_t)26U)
        ^ (e0 >> (uint32_t)11U | e0 << (uint32_t)21U) ^ (e0 >> (uint32_t)25U | e0 << (uint32_t)7U))
      + (e0 & f0 ^ ~e0 & g0)
      + Hacl_Hash_Core_SHA2_Constants_k224_256[i]
      + w;
    uint32_t
    t2 =
      ((a0 >> (uint32_t)2U | a0 << (uint32_t)30U)
      ^ (a0 >> (uint32_t)13U | a0 << (uint32_t)19U) ^ (a0 >> (uint32_t)22U | a0 << (uint32_t)10U))
      + (a0 & b0 ^ a0 & c0 ^ b0 & c0);
    hash11[0U] = t1 + t2;
    hash11[1U] = a0;
    hash11[2U] = b0;
    hash11[3U] = c0;
    hash11[4U] = d0 + t1;
    hash11[5U] = e0;
    hash11[6U] = f0;
    hash11[7U] = g0;
  }
  {
    uint32_t xi = hash1[0U];
    uint32_t yi = hash11[0U];
    hash1[0U] = xi + yi;
  }
  {
    uint32_t xi = hash1[1U];
    uint32_t yi = hash11[1U];
    hash1[1U] = xi + yi;
  }
  {
    uint32_t xi = hash1[2U];
    uint32_t yi = hash11[2U];
    hash1[2U] = xi + yi;
  }
  {
    uint32_t xi = hash1[3U];
    uint32_t yi = hash11[3U];
    hash1[3U] = xi + yi;
  }
  {
    uint32_t xi = hash1[4U];
    uint32_t yi = hash11[4U];
    hash1[4U] = xi + yi;
  }
  {
    uint32_t xi = hash1[5U];
    uint32_t yi = hash11[5U];
    hash1[5U] = xi + yi;
  }
  {
    uint32_t xi = hash1[6U];
    uint32_t yi = hash11[6U];
    hash1[6U] = xi + yi;
  }
  {
    uint32_t xi = hash1[7U];
    uint32_t yi = hash11[7U];
    hash1[7U] = xi + yi;
  }
}

void Hacl_Hash_Core_SHA2_update_256(uint32_t *hash1, uint8_t *block)
{
  uint32_t hash11[8U] = { 0U };
  uint32_t computed_ws[64U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)64U; i = i + (uint32_t)1U)
    if (i < (uint32_t)16U)
    {
      uint8_t *b = block + i * (uint32_t)4U;
      uint32_t u = load32_be(b);
      computed_ws[i] = u;
    }
    else
    {
      uint32_t t16 = computed_ws[i - (uint32_t)16U];
      uint32_t t15 = computed_ws[i - (uint32_t)15U];
      uint32_t t7 = computed_ws[i - (uint32_t)7U];
      uint32_t t2 = computed_ws[i - (uint32_t)2U];
      uint32_t
      s1 =
        (t2 >> (uint32_t)17U | t2 << (uint32_t)15U)
        ^ (t2 >> (uint32_t)19U | t2 << (uint32_t)13U) ^ t2 >> (uint32_t)10U;
      uint32_t
      s0 =
        (t15 >> (uint32_t)7U | t15 << (uint32_t)25U)
        ^ (t15 >> (uint32_t)18U | t15 << (uint32_t)14U) ^ t15 >> (uint32_t)3U;
      uint32_t w = s1 + t7 + s0 + t16;
      computed_ws[i] = w;
    }
  memcpy(hash11, hash1, (uint32_t)8U * sizeof hash1[0U]);
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)64U; i = i + (uint32_t)1U)
  {
    uint32_t a0 = hash11[0U];
    uint32_t b0 = hash11[1U];
    uint32_t c0 = hash11[2U];
    uint32_t d0 = hash11[3U];
    uint32_t e0 = hash11[4U];
    uint32_t f0 = hash11[5U];
    uint32_t g0 = hash11[6U];
    uint32_t h03 = hash11[7U];
    uint32_t w = computed_ws[i];
    uint32_t
    t1 =
      h03
      +
        ((e0 >> (uint32_t)6U | e0 << (uint32_t)26U)
        ^ (e0 >> (uint32_t)11U | e0 << (uint32_t)21U) ^ (e0 >> (uint32_t)25U | e0 << (uint32_t)7U))
      + (e0 & f0 ^ ~e0 & g0)
      + Hacl_Hash_Core_SHA2_Constants_k224_256[i]
      + w;
    uint32_t
    t2 =
      ((a0 >> (uint32_t)2U | a0 << (uint32_t)30U)
      ^ (a0 >> (uint32_t)13U | a0 << (uint32_t)19U) ^ (a0 >> (uint32_t)22U | a0 << (uint32_t)10U))
      + (a0 & b0 ^ a0 & c0 ^ b0 & c0);
    hash11[0U] = t1 + t2;
    hash11[1U] = a0;
    hash11[2U] = b0;
    hash11[3U] = c0;
    hash11[4U] = d0 + t1;
    hash11[5U] = e0;
    hash11[6U] = f0;
    hash11[7U] = g0;
  }
  {
    uint32_t xi = hash1[0U];
    uint32_t yi = hash11[0U];
    hash1[0U] = xi + yi;
  }
  {
    uint32_t xi = hash1[1U];
    uint32_t yi = hash11[1U];
    hash1[1U] = xi + yi;
  }
  {
    uint32_t xi = hash1[2U];
    uint32_t yi = hash11[2U];
    hash1[2U] = xi + yi;
  }
  {
    uint32_t xi = hash1[3U];
    uint32_t yi = hash11[3U];
    hash1[3U] = xi + yi;
  }
  {
    uint32_t xi = hash1[4U];
    uint32_t yi = hash11[4U];
    hash1[4U] = xi + yi;
  }
  {
    uint32_t xi = hash1[5U];
    uint32_t yi = hash11[5U];
    hash1[5U] = xi + yi;
  }
  {
    uint32_t xi = hash1[6U];
    uint32_t yi = hash11[6U];
    hash1[6U] = xi + yi;
  }
  {
    uint32_t xi = hash1[7U];
    uint32_t yi = hash11[7U];
    hash1[7U] = xi + yi;
  }
}

void Hacl_Hash_Core_SHA2_update_384(uint64_t *hash1, uint8_t *block)
{
  uint64_t hash11[8U] = { 0U };
  uint64_t computed_ws[80U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)80U; i = i + (uint32_t)1U)
    if (i < (uint32_t)16U)
    {
      uint8_t *b = block + i * (uint32_t)8U;
      uint64_t u = load64_be(b);
      computed_ws[i] = u;
    }
    else
    {
      uint64_t t16 = computed_ws[i - (uint32_t)16U];
      uint64_t t15 = computed_ws[i - (uint32_t)15U];
      uint64_t t7 = computed_ws[i - (uint32_t)7U];
      uint64_t t2 = computed_ws[i - (uint32_t)2U];
      uint64_t
      s1 =
        (t2 >> (uint32_t)19U | t2 << (uint32_t)45U)
        ^ (t2 >> (uint32_t)61U | t2 << (uint32_t)3U) ^ t2 >> (uint32_t)6U;
      uint64_t
      s0 =
        (t15 >> (uint32_t)1U | t15 << (uint32_t)63U)
        ^ (t15 >> (uint32_t)8U | t15 << (uint32_t)56U) ^ t15 >> (uint32_t)7U;
      uint64_t w = s1 + t7 + s0 + t16;
      computed_ws[i] = w;
    }
  memcpy(hash11, hash1, (uint32_t)8U * sizeof hash1[0U]);
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)80U; i = i + (uint32_t)1U)
  {
    uint64_t a0 = hash11[0U];
    uint64_t b0 = hash11[1U];
    uint64_t c0 = hash11[2U];
    uint64_t d0 = hash11[3U];
    uint64_t e0 = hash11[4U];
    uint64_t f0 = hash11[5U];
    uint64_t g0 = hash11[6U];
    uint64_t h03 = hash11[7U];
    uint64_t w = computed_ws[i];
    uint64_t
    t1 =
      h03
      +
        ((e0 >> (uint32_t)14U | e0 << (uint32_t)50U)
        ^ (e0 >> (uint32_t)18U | e0 << (uint32_t)46U) ^ (e0 >> (uint32_t)41U | e0 << (uint32_t)23U))
      + (e0 & f0 ^ ~e0 & g0)
      + Hacl_Hash_Core_SHA2_Constants_k384_512[i]
      + w;
    uint64_t
    t2 =
      ((a0 >> (uint32_t)28U | a0 << (uint32_t)36U)
      ^ (a0 >> (uint32_t)34U | a0 << (uint32_t)30U) ^ (a0 >> (uint32_t)39U | a0 << (uint32_t)25U))
      + (a0 & b0 ^ a0 & c0 ^ b0 & c0);
    hash11[0U] = t1 + t2;
    hash11[1U] = a0;
    hash11[2U] = b0;
    hash11[3U] = c0;
    hash11[4U] = d0 + t1;
    hash11[5U] = e0;
    hash11[6U] = f0;
    hash11[7U] = g0;
  }
  {
    uint64_t xi = hash1[0U];
    uint64_t yi = hash11[0U];
    hash1[0U] = xi + yi;
  }
  {
    uint64_t xi = hash1[1U];
    uint64_t yi = hash11[1U];
    hash1[1U] = xi + yi;
  }
  {
    uint64_t xi = hash1[2U];
    uint64_t yi = hash11[2U];
    hash1[2U] = xi + yi;
  }
  {
    uint64_t xi = hash1[3U];
    uint64_t yi = hash11[3U];
    hash1[3U] = xi + yi;
  }
  {
    uint64_t xi = hash1[4U];
    uint64_t yi = hash11[4U];
    hash1[4U] = xi + yi;
  }
  {
    uint64_t xi = hash1[5U];
    uint64_t yi = hash11[5U];
    hash1[5U] = xi + yi;
  }
  {
    uint64_t xi = hash1[6U];
    uint64_t yi = hash11[6U];
    hash1[6U] = xi + yi;
  }
  {
    uint64_t xi = hash1[7U];
    uint64_t yi = hash11[7U];
    hash1[7U] = xi + yi;
  }
}

void Hacl_Hash_Core_SHA2_update_512(uint64_t *hash1, uint8_t *block)
{
  uint64_t hash11[8U] = { 0U };
  uint64_t computed_ws[80U] = { 0U };
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)80U; i = i + (uint32_t)1U)
    if (i < (uint32_t)16U)
    {
      uint8_t *b = block + i * (uint32_t)8U;
      uint64_t u = load64_be(b);
      computed_ws[i] = u;
    }
    else
    {
      uint64_t t16 = computed_ws[i - (uint32_t)16U];
      uint64_t t15 = computed_ws[i - (uint32_t)15U];
      uint64_t t7 = computed_ws[i - (uint32_t)7U];
      uint64_t t2 = computed_ws[i - (uint32_t)2U];
      uint64_t
      s1 =
        (t2 >> (uint32_t)19U | t2 << (uint32_t)45U)
        ^ (t2 >> (uint32_t)61U | t2 << (uint32_t)3U) ^ t2 >> (uint32_t)6U;
      uint64_t
      s0 =
        (t15 >> (uint32_t)1U | t15 << (uint32_t)63U)
        ^ (t15 >> (uint32_t)8U | t15 << (uint32_t)56U) ^ t15 >> (uint32_t)7U;
      uint64_t w = s1 + t7 + s0 + t16;
      computed_ws[i] = w;
    }
  memcpy(hash11, hash1, (uint32_t)8U * sizeof hash1[0U]);
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)80U; i = i + (uint32_t)1U)
  {
    uint64_t a0 = hash11[0U];
    uint64_t b0 = hash11[1U];
    uint64_t c0 = hash11[2U];
    uint64_t d0 = hash11[3U];
    uint64_t e0 = hash11[4U];
    uint64_t f0 = hash11[5U];
    uint64_t g0 = hash11[6U];
    uint64_t h03 = hash11[7U];
    uint64_t w = computed_ws[i];
    uint64_t
    t1 =
      h03
      +
        ((e0 >> (uint32_t)14U | e0 << (uint32_t)50U)
        ^ (e0 >> (uint32_t)18U | e0 << (uint32_t)46U) ^ (e0 >> (uint32_t)41U | e0 << (uint32_t)23U))
      + (e0 & f0 ^ ~e0 & g0)
      + Hacl_Hash_Core_SHA2_Constants_k384_512[i]
      + w;
    uint64_t
    t2 =
      ((a0 >> (uint32_t)28U | a0 << (uint32_t)36U)
      ^ (a0 >> (uint32_t)34U | a0 << (uint32_t)30U) ^ (a0 >> (uint32_t)39U | a0 << (uint32_t)25U))
      + (a0 & b0 ^ a0 & c0 ^ b0 & c0);
    hash11[0U] = t1 + t2;
    hash11[1U] = a0;
    hash11[2U] = b0;
    hash11[3U] = c0;
    hash11[4U] = d0 + t1;
    hash11[5U] = e0;
    hash11[6U] = f0;
    hash11[7U] = g0;
  }
  {
    uint64_t xi = hash1[0U];
    uint64_t yi = hash11[0U];
    hash1[0U] = xi + yi;
  }
  {
    uint64_t xi = hash1[1U];
    uint64_t yi = hash11[1U];
    hash1[1U] = xi + yi;
  }
  {
    uint64_t xi = hash1[2U];
    uint64_t yi = hash11[2U];
    hash1[2U] = xi + yi;
  }
  {
    uint64_t xi = hash1[3U];
    uint64_t yi = hash11[3U];
    hash1[3U] = xi + yi;
  }
  {
    uint64_t xi = hash1[4U];
    uint64_t yi = hash11[4U];
    hash1[4U] = xi + yi;
  }
  {
    uint64_t xi = hash1[5U];
    uint64_t yi = hash11[5U];
    hash1[5U] = xi + yi;
  }
  {
    uint64_t xi = hash1[6U];
    uint64_t yi = hash11[6U];
    hash1[6U] = xi + yi;
  }
  {
    uint64_t xi = hash1[7U];
    uint64_t yi = hash11[7U];
    hash1[7U] = xi + yi;
  }
}

void Hacl_Hash_Core_SHA2_pad_224(uint64_t len, uint8_t *dst)
{
  uint8_t *dst1 = dst;
  dst1[0U] = (uint8_t)0x80U;
  uint8_t *dst2 = dst + (uint32_t)1U;
  for
  (uint32_t
    i = (uint32_t)0U;
    i
    < ((uint32_t)128U - ((uint32_t)9U + (uint32_t)(len % (uint64_t)(uint32_t)64U))) % (uint32_t)64U;
    i = i + (uint32_t)1U)
    dst2[i] = (uint8_t)0U;
  uint8_t
  *dst3 =
    dst
    +
      (uint32_t)1U
      +
        ((uint32_t)128U - ((uint32_t)9U + (uint32_t)(len % (uint64_t)(uint32_t)64U)))
        % (uint32_t)64U;
  store64_be(dst3, len << (uint32_t)3U);
}

void Hacl_Hash_Core_SHA2_pad_256(uint64_t len, uint8_t *dst)
{
  uint8_t *dst1 = dst;
  dst1[0U] = (uint8_t)0x80U;
  uint8_t *dst2 = dst + (uint32_t)1U;
  for
  (uint32_t
    i = (uint32_t)0U;
    i
    < ((uint32_t)128U - ((uint32_t)9U + (uint32_t)(len % (uint64_t)(uint32_t)64U))) % (uint32_t)64U;
    i = i + (uint32_t)1U)
    dst2[i] = (uint8_t)0U;
  uint8_t
  *dst3 =
    dst
    +
      (uint32_t)1U
      +
        ((uint32_t)128U - ((uint32_t)9U + (uint32_t)(len % (uint64_t)(uint32_t)64U)))
        % (uint32_t)64U;
  store64_be(dst3, len << (uint32_t)3U);
}

void Hacl_Hash_Core_SHA2_pad_384(uint128_t len, uint8_t *dst)
{
  uint8_t *dst1 = dst;
  dst1[0U] = (uint8_t)0x80U;
  uint8_t *dst2 = dst + (uint32_t)1U;
  uint32_t
  len_zero =
    ((uint32_t)256U - ((uint32_t)17U + (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U)))
    % (uint32_t)128U;
  for
  (uint32_t
    i = (uint32_t)0U;
    i
    <
      ((uint32_t)256U - ((uint32_t)17U + (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U)))
      % (uint32_t)128U;
    i = i + (uint32_t)1U)
    dst2[i] = (uint8_t)0U;
  uint8_t
  *dst3 =
    dst
    +
      (uint32_t)1U
      +
        ((uint32_t)256U - ((uint32_t)17U + (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U)))
        % (uint32_t)128U;
  uint128_t len_ = len << (uint32_t)3U;
  store128_be(dst3, len_);
}

void Hacl_Hash_Core_SHA2_pad_512(uint128_t len, uint8_t *dst)
{
  uint8_t *dst1 = dst;
  dst1[0U] = (uint8_t)0x80U;
  uint8_t *dst2 = dst + (uint32_t)1U;
  uint32_t
  len_zero =
    ((uint32_t)256U - ((uint32_t)17U + (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U)))
    % (uint32_t)128U;
  for
  (uint32_t
    i = (uint32_t)0U;
    i
    <
      ((uint32_t)256U - ((uint32_t)17U + (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U)))
      % (uint32_t)128U;
    i = i + (uint32_t)1U)
    dst2[i] = (uint8_t)0U;
  uint8_t
  *dst3 =
    dst
    +
      (uint32_t)1U
      +
        ((uint32_t)256U - ((uint32_t)17U + (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U)))
        % (uint32_t)128U;
  uint128_t len_ = len << (uint32_t)3U;
  store128_be(dst3, len_);
}

void Hacl_Hash_Core_SHA2_finish_224(uint32_t *s, uint8_t *dst)
{
  uint32_t *uu____0 = s;
  {
    store32_be(dst + (uint32_t)0U * (uint32_t)4U, uu____0[0U]);
  }
  {
    store32_be(dst + (uint32_t)1U * (uint32_t)4U, uu____0[1U]);
  }
  {
    store32_be(dst + (uint32_t)2U * (uint32_t)4U, uu____0[2U]);
  }
  {
    store32_be(dst + (uint32_t)3U * (uint32_t)4U, uu____0[3U]);
  }
  {
    store32_be(dst + (uint32_t)4U * (uint32_t)4U, uu____0[4U]);
  }
  {
    store32_be(dst + (uint32_t)5U * (uint32_t)4U, uu____0[5U]);
  }
  {
    store32_be(dst + (uint32_t)6U * (uint32_t)4U, uu____0[6U]);
  }
}

void Hacl_Hash_Core_SHA2_finish_256(uint32_t *s, uint8_t *dst)
{
  uint32_t *uu____0 = s;
  {
    store32_be(dst + (uint32_t)0U * (uint32_t)4U, uu____0[0U]);
  }
  {
    store32_be(dst + (uint32_t)1U * (uint32_t)4U, uu____0[1U]);
  }
  {
    store32_be(dst + (uint32_t)2U * (uint32_t)4U, uu____0[2U]);
  }
  {
    store32_be(dst + (uint32_t)3U * (uint32_t)4U, uu____0[3U]);
  }
  {
    store32_be(dst + (uint32_t)4U * (uint32_t)4U, uu____0[4U]);
  }
  {
    store32_be(dst + (uint32_t)5U * (uint32_t)4U, uu____0[5U]);
  }
  {
    store32_be(dst + (uint32_t)6U * (uint32_t)4U, uu____0[6U]);
  }
  {
    store32_be(dst + (uint32_t)7U * (uint32_t)4U, uu____0[7U]);
  }
}

void Hacl_Hash_Core_SHA2_finish_384(uint64_t *s, uint8_t *dst)
{
  uint64_t *uu____0 = s;
  {
    store64_be(dst + (uint32_t)0U * (uint32_t)8U, uu____0[0U]);
  }
  {
    store64_be(dst + (uint32_t)1U * (uint32_t)8U, uu____0[1U]);
  }
  {
    store64_be(dst + (uint32_t)2U * (uint32_t)8U, uu____0[2U]);
  }
  {
    store64_be(dst + (uint32_t)3U * (uint32_t)8U, uu____0[3U]);
  }
  {
    store64_be(dst + (uint32_t)4U * (uint32_t)8U, uu____0[4U]);
  }
  {
    store64_be(dst + (uint32_t)5U * (uint32_t)8U, uu____0[5U]);
  }
}

void Hacl_Hash_Core_SHA2_finish_512(uint64_t *s, uint8_t *dst)
{
  uint64_t *uu____0 = s;
  {
    store64_be(dst + (uint32_t)0U * (uint32_t)8U, uu____0[0U]);
  }
  {
    store64_be(dst + (uint32_t)1U * (uint32_t)8U, uu____0[1U]);
  }
  {
    store64_be(dst + (uint32_t)2U * (uint32_t)8U, uu____0[2U]);
  }
  {
    store64_be(dst + (uint32_t)3U * (uint32_t)8U, uu____0[3U]);
  }
  {
    store64_be(dst + (uint32_t)4U * (uint32_t)8U, uu____0[4U]);
  }
  {
    store64_be(dst + (uint32_t)5U * (uint32_t)8U, uu____0[5U]);
  }
  {
    store64_be(dst + (uint32_t)6U * (uint32_t)8U, uu____0[6U]);
  }
  {
    store64_be(dst + (uint32_t)7U * (uint32_t)8U, uu____0[7U]);
  }
}
