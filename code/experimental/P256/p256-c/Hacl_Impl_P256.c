#include "Hacl_Impl_P256.h"
#include "immintrin.h"
#include <x86intrin.h>


typedef struct K___uint64_t_uint64_t_uint64_t_uint64_t_s
{
  uint64_t fst;
  uint64_t snd;
  uint64_t thd;
  uint64_t f3;
}
K___uint64_t_uint64_t_uint64_t_uint64_t;

typedef struct K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_s
{
  uint64_t fst;
  uint64_t snd;
  uint64_t thd;
  uint64_t f3;
  uint64_t f4;
  uint64_t f5;
  uint64_t f6;
  uint64_t f7;
}
K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t;

typedef struct K___uint64_t_uint64_t_s
{
  uint64_t fst;
  uint64_t snd;
}
K___uint64_t_uint64_t;

inline static K___uint64_t_uint64_t
Hacl_Spec_Curve25519_Field64_Core_addcarry(uint64_t x, uint64_t y, uint64_t cin)
{

  K___uint64_t_uint64_t res;
  res.snd = _addcarry_u64(cin,x,y,&res.fst);
  return res;

}

inline static K___uint64_t_uint64_t
Hacl_Spec_Curve25519_Field64_Core_subborrow(uint64_t y, uint64_t x, uint64_t cin)
{

  K___uint64_t_uint64_t res;
  res.snd = _subborrow_u64(cin,x,y,&res.fst);
  return res;

}

static uint64_t Hacl_Spec_P256_Core_store_high_low_u(uint32_t high, uint32_t low)
{
  uint64_t as_uint64_high = (uint64_t)high;
  uint64_t as_uint64_high1 = as_uint64_high << (uint32_t)32U;
  uint64_t as_uint64_low = (uint64_t)low;
  return as_uint64_low ^ as_uint64_high1;
}

typedef struct K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_s
{
  uint64_t fst;
  uint64_t snd;
  uint64_t thd;
  uint64_t f3;
  uint64_t f4;
}
K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t;

static K___uint64_t_uint64_t_uint64_t_uint64_t
Hacl_Spec_P256_Core_reduction_prime_2prime_with_carry(
  uint64_t carry,
  uint64_t a0,
  uint64_t a1,
  uint64_t a2,
  uint64_t a3
)
{
  K___uint64_t_uint64_t
  scrut0 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(a0,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o0 = scrut0.fst;
  uint64_t c0 = scrut0.snd;
  K___uint64_t_uint64_t
  scrut1 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a1, (uint64_t)0xffffffffU, c0);
  uint64_t o1 = scrut1.fst;
  uint64_t c1 = scrut1.snd;
  K___uint64_t_uint64_t
  scrut2 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a2, (uint64_t)0U, c1);
  uint64_t o2 = scrut2.fst;
  uint64_t c2 = scrut2.snd;
  K___uint64_t_uint64_t
  scrut3 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a3, (uint64_t)0xffffffff00000001U, c2);
  uint64_t o3 = scrut3.fst;
  uint64_t c3 = scrut3.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut4 = { .fst = c3, .snd = o0, .thd = o1, .f3 = o2, .f4 = o3 };
  uint64_t x16 = scrut4.fst;
  uint64_t r0 = scrut4.snd;
  uint64_t r1 = scrut4.thd;
  uint64_t r2 = scrut4.f3;
  uint64_t r3 = scrut4.f4;
  K___uint64_t_uint64_t
  scrut = Hacl_Spec_Curve25519_Field64_Core_subborrow(carry, (uint64_t)0U, x16);
  uint64_t c = scrut.snd;
  uint64_t mask = ~FStar_UInt64_eq_mask(c, (uint64_t)0U);
  uint64_t r01 = a0 & mask | r0 & ~mask;
  uint64_t r11 = a1 & mask | r1 & ~mask;
  uint64_t r21 = a2 & mask | r2 & ~mask;
  uint64_t r31 = a3 & mask | r3 & ~mask;
  uint64_t r_0 = r01;
  uint64_t r_1 = r11;
  uint64_t r_2 = r21;
  uint64_t r_3 = r31;
  return
    ((K___uint64_t_uint64_t_uint64_t_uint64_t){ .fst = r_0, .snd = r_1, .thd = r_2, .f3 = r_3 });
}

typedef struct
K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t_s
{
  K___uint64_t_uint64_t_uint64_t_uint64_t fst;
  K___uint64_t_uint64_t_uint64_t_uint64_t snd;
}
K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t;

typedef struct K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t_s
{
  uint64_t fst;
  K___uint64_t_uint64_t_uint64_t_uint64_t snd;
}
K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t;

static K___uint64_t_uint64_t_uint64_t_uint64_t
Hacl_Spec_P256_SolinasReduction_solinas_reduction(
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t uu____1756
)
{
  uint64_t f0 = uu____1756.fst;
  uint64_t f1 = uu____1756.snd;
  uint64_t f2 = uu____1756.thd;
  uint64_t f3 = uu____1756.f3;
  uint64_t f4 = uu____1756.f4;
  uint64_t f5 = uu____1756.f5;
  uint64_t f6 = uu____1756.f6;
  uint64_t f7 = uu____1756.f7;
  uint32_t c0 = (uint32_t)f0;
  uint32_t c1 = (uint32_t)(f0 >> (uint32_t)32U);
  uint32_t c2 = (uint32_t)f1;
  uint32_t c3 = (uint32_t)(f1 >> (uint32_t)32U);
  uint32_t c4 = (uint32_t)f2;
  uint32_t c5 = (uint32_t)(f2 >> (uint32_t)32U);
  uint32_t c6 = (uint32_t)f3;
  uint32_t c7 = (uint32_t)(f3 >> (uint32_t)32U);
  uint32_t c8 = (uint32_t)f4;
  uint32_t c9 = (uint32_t)(f4 >> (uint32_t)32U);
  uint32_t c10 = (uint32_t)f5;
  uint32_t c11 = (uint32_t)(f5 >> (uint32_t)32U);
  uint32_t c12 = (uint32_t)f6;
  uint32_t c13 = (uint32_t)(f6 >> (uint32_t)32U);
  uint32_t c14 = (uint32_t)f7;
  uint32_t c15 = (uint32_t)(f7 >> (uint32_t)32U);
  uint64_t b00 = Hacl_Spec_P256_Core_store_high_low_u(c1, c0);
  uint64_t b10 = Hacl_Spec_P256_Core_store_high_low_u(c3, c2);
  uint64_t b20 = Hacl_Spec_P256_Core_store_high_low_u(c5, c4);
  uint64_t b30 = Hacl_Spec_P256_Core_store_high_low_u(c7, c6);
  uint64_t state0_0 = b00;
  uint64_t state0_1 = b10;
  uint64_t state0_2 = b20;
  uint64_t state0_3 = b30;
  K___uint64_t_uint64_t
  scrut0 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(state0_0,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o00 = scrut0.fst;
  uint64_t c010 = scrut0.snd;
  K___uint64_t_uint64_t
  scrut1 = Hacl_Spec_Curve25519_Field64_Core_subborrow(state0_1, (uint64_t)0xffffffffU, c010);
  uint64_t o10 = scrut1.fst;
  uint64_t c160 = scrut1.snd;
  K___uint64_t_uint64_t
  scrut2 = Hacl_Spec_Curve25519_Field64_Core_subborrow(state0_2, (uint64_t)0U, c160);
  uint64_t o20 = scrut2.fst;
  uint64_t c210 = scrut2.snd;
  K___uint64_t_uint64_t
  scrut3 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(state0_3,
      (uint64_t)0xffffffff00000001U,
      c210);
  uint64_t o30 = scrut3.fst;
  uint64_t c310 = scrut3.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut4 = { .fst = c310, .snd = o00, .thd = o10, .f3 = o20, .f4 = o30 };
  uint64_t x160 = scrut4.fst;
  uint64_t r00 = scrut4.snd;
  uint64_t r10 = scrut4.thd;
  uint64_t r20 = scrut4.f3;
  uint64_t r30 = scrut4.f4;
  uint64_t mask0 = ~FStar_UInt64_eq_mask(x160, (uint64_t)0U);
  uint64_t r010 = state0_0 & mask0 | r00 & ~mask0;
  uint64_t r110 = state0_1 & mask0 | r10 & ~mask0;
  uint64_t r210 = state0_2 & mask0 | r20 & ~mask0;
  uint64_t r310 = state0_3 & mask0 | r30 & ~mask0;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut5 = { .fst = r010, .snd = r110, .thd = r210, .f3 = r310 };
  uint64_t state0_red_0 = scrut5.fst;
  uint64_t state0_red_1 = scrut5.snd;
  uint64_t state0_red_2 = scrut5.thd;
  uint64_t state0_red_3 = scrut5.f3;
  uint64_t b01 = (uint64_t)0U;
  uint64_t b11 = Hacl_Spec_P256_Core_store_high_low_u(c11, (uint32_t)0U);
  uint64_t b21 = Hacl_Spec_P256_Core_store_high_low_u(c13, c12);
  uint64_t b31 = Hacl_Spec_P256_Core_store_high_low_u(c15, c14);
  K___uint64_t_uint64_t
  scrut6 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(b01,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o01 = scrut6.fst;
  uint64_t c011 = scrut6.snd;
  K___uint64_t_uint64_t
  scrut7 = Hacl_Spec_Curve25519_Field64_Core_subborrow(b11, (uint64_t)0xffffffffU, c011);
  uint64_t o11 = scrut7.fst;
  uint64_t c161 = scrut7.snd;
  K___uint64_t_uint64_t
  scrut8 = Hacl_Spec_Curve25519_Field64_Core_subborrow(b21, (uint64_t)0U, c161);
  uint64_t o21 = scrut8.fst;
  uint64_t c211 = scrut8.snd;
  K___uint64_t_uint64_t
  scrut9 = Hacl_Spec_Curve25519_Field64_Core_subborrow(b31, (uint64_t)0xffffffff00000001U, c211);
  uint64_t o31 = scrut9.fst;
  uint64_t c311 = scrut9.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut10 = { .fst = c311, .snd = o01, .thd = o11, .f3 = o21, .f4 = o31 };
  uint64_t x161 = scrut10.fst;
  uint64_t r05 = scrut10.snd;
  uint64_t r14 = scrut10.thd;
  uint64_t r22 = scrut10.f3;
  uint64_t r32 = scrut10.f4;
  uint64_t mask1 = ~FStar_UInt64_eq_mask(x161, (uint64_t)0U);
  uint64_t r011 = b01 & mask1 | r05 & ~mask1;
  uint64_t r111 = b11 & mask1 | r14 & ~mask1;
  uint64_t r211 = b21 & mask1 | r22 & ~mask1;
  uint64_t r311 = b31 & mask1 | r32 & ~mask1;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state1 = { .fst = r011, .snd = r111, .thd = r211, .f3 = r311 };
  uint64_t b02 = (uint64_t)0U;
  uint64_t b12 = Hacl_Spec_P256_Core_store_high_low_u(c12, (uint32_t)0U);
  uint64_t b22 = Hacl_Spec_P256_Core_store_high_low_u(c14, c13);
  uint64_t b32 = Hacl_Spec_P256_Core_store_high_low_u((uint32_t)0U, c15);
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state2 = { .fst = b02, .snd = b12, .thd = b22, .f3 = b32 };
  uint64_t b03 = Hacl_Spec_P256_Core_store_high_low_u(c9, c8);
  uint64_t b13 = Hacl_Spec_P256_Core_store_high_low_u((uint32_t)0U, c10);
  uint64_t b23 = (uint64_t)0U;
  uint64_t b33 = Hacl_Spec_P256_Core_store_high_low_u(c15, c14);
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state3 = { .fst = b03, .snd = b13, .thd = b23, .f3 = b33 };
  uint64_t a00 = state3.fst;
  uint64_t a10 = state3.snd;
  uint64_t a20 = state3.thd;
  uint64_t a30 = state3.f3;
  K___uint64_t_uint64_t
  scrut11 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(a00,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o02 = scrut11.fst;
  uint64_t c012 = scrut11.snd;
  K___uint64_t_uint64_t
  scrut12 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a10, (uint64_t)0xffffffffU, c012);
  uint64_t o12 = scrut12.fst;
  uint64_t c162 = scrut12.snd;
  K___uint64_t_uint64_t
  scrut13 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a20, (uint64_t)0U, c162);
  uint64_t o22 = scrut13.fst;
  uint64_t c212 = scrut13.snd;
  K___uint64_t_uint64_t
  scrut14 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a30, (uint64_t)0xffffffff00000001U, c212);
  uint64_t o32 = scrut14.fst;
  uint64_t c312 = scrut14.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut15 = { .fst = c312, .snd = o02, .thd = o12, .f3 = o22, .f4 = o32 };
  uint64_t x162 = scrut15.fst;
  uint64_t r06 = scrut15.snd;
  uint64_t r15 = scrut15.thd;
  uint64_t r23 = scrut15.f3;
  uint64_t r33 = scrut15.f4;
  uint64_t mask2 = ~FStar_UInt64_eq_mask(x162, (uint64_t)0U);
  uint64_t r012 = a00 & mask2 | r06 & ~mask2;
  uint64_t r112 = a10 & mask2 | r15 & ~mask2;
  uint64_t r212 = a20 & mask2 | r23 & ~mask2;
  uint64_t r312 = a30 & mask2 | r33 & ~mask2;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state3_red = { .fst = r012, .snd = r112, .thd = r212, .f3 = r312 };
  uint64_t b04 = Hacl_Spec_P256_Core_store_high_low_u(c10, c9);
  uint64_t b14 = Hacl_Spec_P256_Core_store_high_low_u(c13, c11);
  uint64_t b24 = Hacl_Spec_P256_Core_store_high_low_u(c15, c14);
  uint64_t b34 = Hacl_Spec_P256_Core_store_high_low_u(c8, c13);
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state4 = { .fst = b04, .snd = b14, .thd = b24, .f3 = b34 };
  uint64_t a01 = state4.fst;
  uint64_t a11 = state4.snd;
  uint64_t a21 = state4.thd;
  uint64_t a31 = state4.f3;
  K___uint64_t_uint64_t
  scrut16 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(a01,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o03 = scrut16.fst;
  uint64_t c013 = scrut16.snd;
  K___uint64_t_uint64_t
  scrut17 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a11, (uint64_t)0xffffffffU, c013);
  uint64_t o13 = scrut17.fst;
  uint64_t c163 = scrut17.snd;
  K___uint64_t_uint64_t
  scrut18 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a21, (uint64_t)0U, c163);
  uint64_t o23 = scrut18.fst;
  uint64_t c213 = scrut18.snd;
  K___uint64_t_uint64_t
  scrut19 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a31, (uint64_t)0xffffffff00000001U, c213);
  uint64_t o33 = scrut19.fst;
  uint64_t c313 = scrut19.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut20 = { .fst = c313, .snd = o03, .thd = o13, .f3 = o23, .f4 = o33 };
  uint64_t x163 = scrut20.fst;
  uint64_t r07 = scrut20.snd;
  uint64_t r16 = scrut20.thd;
  uint64_t r24 = scrut20.f3;
  uint64_t r34 = scrut20.f4;
  uint64_t mask3 = ~FStar_UInt64_eq_mask(x163, (uint64_t)0U);
  uint64_t r013 = a01 & mask3 | r07 & ~mask3;
  uint64_t r113 = a11 & mask3 | r16 & ~mask3;
  uint64_t r213 = a21 & mask3 | r24 & ~mask3;
  uint64_t r313 = a31 & mask3 | r34 & ~mask3;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state4_red = { .fst = r013, .snd = r113, .thd = r213, .f3 = r313 };
  uint64_t b05 = Hacl_Spec_P256_Core_store_high_low_u(c12, c11);
  uint64_t b15 = Hacl_Spec_P256_Core_store_high_low_u((uint32_t)0U, c13);
  uint64_t b25 = (uint64_t)0U;
  uint64_t b35 = Hacl_Spec_P256_Core_store_high_low_u(c10, c8);
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state5 = { .fst = b05, .snd = b15, .thd = b25, .f3 = b35 };
  uint64_t a02 = state5.fst;
  uint64_t a12 = state5.snd;
  uint64_t a22 = state5.thd;
  uint64_t a32 = state5.f3;
  K___uint64_t_uint64_t
  scrut21 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(a02,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o04 = scrut21.fst;
  uint64_t c014 = scrut21.snd;
  K___uint64_t_uint64_t
  scrut22 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a12, (uint64_t)0xffffffffU, c014);
  uint64_t o14 = scrut22.fst;
  uint64_t c164 = scrut22.snd;
  K___uint64_t_uint64_t
  scrut23 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a22, (uint64_t)0U, c164);
  uint64_t o24 = scrut23.fst;
  uint64_t c214 = scrut23.snd;
  K___uint64_t_uint64_t
  scrut24 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a32, (uint64_t)0xffffffff00000001U, c214);
  uint64_t o34 = scrut24.fst;
  uint64_t c314 = scrut24.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut25 = { .fst = c314, .snd = o04, .thd = o14, .f3 = o24, .f4 = o34 };
  uint64_t x164 = scrut25.fst;
  uint64_t r08 = scrut25.snd;
  uint64_t r17 = scrut25.thd;
  uint64_t r25 = scrut25.f3;
  uint64_t r35 = scrut25.f4;
  uint64_t mask4 = ~FStar_UInt64_eq_mask(x164, (uint64_t)0U);
  uint64_t r014 = a02 & mask4 | r08 & ~mask4;
  uint64_t r114 = a12 & mask4 | r17 & ~mask4;
  uint64_t r214 = a22 & mask4 | r25 & ~mask4;
  uint64_t r314 = a32 & mask4 | r35 & ~mask4;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state5_red = { .fst = r014, .snd = r114, .thd = r214, .f3 = r314 };
  uint64_t b06 = Hacl_Spec_P256_Core_store_high_low_u(c13, c12);
  uint64_t b16 = Hacl_Spec_P256_Core_store_high_low_u(c15, c14);
  uint64_t b26 = (uint64_t)0U;
  uint64_t b36 = Hacl_Spec_P256_Core_store_high_low_u(c11, c9);
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state6 = { .fst = b06, .snd = b16, .thd = b26, .f3 = b36 };
  uint64_t a03 = state6.fst;
  uint64_t a13 = state6.snd;
  uint64_t a23 = state6.thd;
  uint64_t a33 = state6.f3;
  K___uint64_t_uint64_t
  scrut26 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(a03,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o05 = scrut26.fst;
  uint64_t c015 = scrut26.snd;
  K___uint64_t_uint64_t
  scrut27 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a13, (uint64_t)0xffffffffU, c015);
  uint64_t o15 = scrut27.fst;
  uint64_t c165 = scrut27.snd;
  K___uint64_t_uint64_t
  scrut28 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a23, (uint64_t)0U, c165);
  uint64_t o25 = scrut28.fst;
  uint64_t c215 = scrut28.snd;
  K___uint64_t_uint64_t
  scrut29 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a33, (uint64_t)0xffffffff00000001U, c215);
  uint64_t o35 = scrut29.fst;
  uint64_t c315 = scrut29.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut30 = { .fst = c315, .snd = o05, .thd = o15, .f3 = o25, .f4 = o35 };
  uint64_t x165 = scrut30.fst;
  uint64_t r09 = scrut30.snd;
  uint64_t r18 = scrut30.thd;
  uint64_t r26 = scrut30.f3;
  uint64_t r36 = scrut30.f4;
  uint64_t mask5 = ~FStar_UInt64_eq_mask(x165, (uint64_t)0U);
  uint64_t r015 = a03 & mask5 | r09 & ~mask5;
  uint64_t r115 = a13 & mask5 | r18 & ~mask5;
  uint64_t r215 = a23 & mask5 | r26 & ~mask5;
  uint64_t r315 = a33 & mask5 | r36 & ~mask5;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state6_red = { .fst = r015, .snd = r115, .thd = r215, .f3 = r315 };
  uint64_t b07 = Hacl_Spec_P256_Core_store_high_low_u(c14, c13);
  uint64_t b17 = Hacl_Spec_P256_Core_store_high_low_u(c8, c15);
  uint64_t b27 = Hacl_Spec_P256_Core_store_high_low_u(c10, c9);
  uint64_t b37 = Hacl_Spec_P256_Core_store_high_low_u(c12, (uint32_t)0U);
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state7 = { .fst = b07, .snd = b17, .thd = b27, .f3 = b37 };
  uint64_t a04 = state7.fst;
  uint64_t a14 = state7.snd;
  uint64_t a24 = state7.thd;
  uint64_t a34 = state7.f3;
  K___uint64_t_uint64_t
  scrut31 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(a04,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o06 = scrut31.fst;
  uint64_t c016 = scrut31.snd;
  K___uint64_t_uint64_t
  scrut32 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a14, (uint64_t)0xffffffffU, c016);
  uint64_t o16 = scrut32.fst;
  uint64_t c166 = scrut32.snd;
  K___uint64_t_uint64_t
  scrut33 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a24, (uint64_t)0U, c166);
  uint64_t o26 = scrut33.fst;
  uint64_t c216 = scrut33.snd;
  K___uint64_t_uint64_t
  scrut34 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a34, (uint64_t)0xffffffff00000001U, c216);
  uint64_t o36 = scrut34.fst;
  uint64_t c316 = scrut34.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut35 = { .fst = c316, .snd = o06, .thd = o16, .f3 = o26, .f4 = o36 };
  uint64_t x166 = scrut35.fst;
  uint64_t r016 = scrut35.snd;
  uint64_t r19 = scrut35.thd;
  uint64_t r27 = scrut35.f3;
  uint64_t r37 = scrut35.f4;
  uint64_t mask6 = ~FStar_UInt64_eq_mask(x166, (uint64_t)0U);
  uint64_t r017 = a04 & mask6 | r016 & ~mask6;
  uint64_t r116 = a14 & mask6 | r19 & ~mask6;
  uint64_t r216 = a24 & mask6 | r27 & ~mask6;
  uint64_t r316 = a34 & mask6 | r37 & ~mask6;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state7_red = { .fst = r017, .snd = r116, .thd = r216, .f3 = r316 };
  uint64_t b08 = Hacl_Spec_P256_Core_store_high_low_u(c15, c14);
  uint64_t b18 = Hacl_Spec_P256_Core_store_high_low_u(c9, (uint32_t)0U);
  uint64_t b28 = Hacl_Spec_P256_Core_store_high_low_u(c11, c10);
  uint64_t b38 = Hacl_Spec_P256_Core_store_high_low_u(c13, (uint32_t)0U);
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state8 = { .fst = b08, .snd = b18, .thd = b28, .f3 = b38 };
  uint64_t a05 = state8.fst;
  uint64_t a15 = state8.snd;
  uint64_t a25 = state8.thd;
  uint64_t a35 = state8.f3;
  K___uint64_t_uint64_t
  scrut36 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(a05,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o07 = scrut36.fst;
  uint64_t c017 = scrut36.snd;
  K___uint64_t_uint64_t
  scrut37 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a15, (uint64_t)0xffffffffU, c017);
  uint64_t o17 = scrut37.fst;
  uint64_t c167 = scrut37.snd;
  K___uint64_t_uint64_t
  scrut38 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a25, (uint64_t)0U, c167);
  uint64_t o27 = scrut38.fst;
  uint64_t c217 = scrut38.snd;
  K___uint64_t_uint64_t
  scrut39 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a35, (uint64_t)0xffffffff00000001U, c217);
  uint64_t o37 = scrut39.fst;
  uint64_t c317 = scrut39.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut40 = { .fst = c317, .snd = o07, .thd = o17, .f3 = o27, .f4 = o37 };
  uint64_t x167 = scrut40.fst;
  uint64_t r018 = scrut40.snd;
  uint64_t r117 = scrut40.thd;
  uint64_t r28 = scrut40.f3;
  uint64_t r38 = scrut40.f4;
  uint64_t mask7 = ~FStar_UInt64_eq_mask(x167, (uint64_t)0U);
  uint64_t r019 = a05 & mask7 | r018 & ~mask7;
  uint64_t r118 = a15 & mask7 | r117 & ~mask7;
  uint64_t r21 = a25 & mask7 | r28 & ~mask7;
  uint64_t r31 = a35 & mask7 | r38 & ~mask7;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state8_red = { .fst = r019, .snd = r118, .thd = r21, .f3 = r31 };
  uint64_t a06 = state1.fst;
  uint64_t a16 = state1.snd;
  uint64_t a26 = state1.thd;
  uint64_t a36 = state1.f3;
  uint64_t mask8 = (uint64_t)0x7fffffffffffffffU;
  uint64_t carry00;
  if (mask8 < a06)
    carry00 = (uint64_t)1U;
  else
    carry00 = (uint64_t)0U;
  uint64_t carry10;
  if (mask8 < a16)
    carry10 = (uint64_t)1U;
  else
    carry10 = (uint64_t)0U;
  uint64_t carry20;
  if (mask8 < a26)
    carry20 = (uint64_t)1U;
  else
    carry20 = (uint64_t)0U;
  uint64_t carry30;
  if (mask8 < a36)
    carry30 = (uint64_t)1U;
  else
    carry30 = (uint64_t)0U;
  uint64_t a0_updated0 = (a06 << (uint32_t)1U) + (uint64_t)0U;
  uint64_t a1_updated0 = (a16 << (uint32_t)1U) + carry00;
  uint64_t a2_updated0 = (a26 << (uint32_t)1U) + carry10;
  uint64_t a3_updated0 = (a36 << (uint32_t)1U) + carry20;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state1_2 =
    Hacl_Spec_P256_Core_reduction_prime_2prime_with_carry(carry30,
      a0_updated0,
      a1_updated0,
      a2_updated0,
      a3_updated0);
  uint64_t a07 = state2.fst;
  uint64_t a17 = state2.snd;
  uint64_t a27 = state2.thd;
  uint64_t a37 = state2.f3;
  uint64_t mask = (uint64_t)0x7fffffffffffffffU;
  uint64_t carry0;
  if (mask < a07)
    carry0 = (uint64_t)1U;
  else
    carry0 = (uint64_t)0U;
  uint64_t carry1;
  if (mask < a17)
    carry1 = (uint64_t)1U;
  else
    carry1 = (uint64_t)0U;
  uint64_t carry2;
  if (mask < a27)
    carry2 = (uint64_t)1U;
  else
    carry2 = (uint64_t)0U;
  uint64_t carry3;
  if (mask < a37)
    carry3 = (uint64_t)1U;
  else
    carry3 = (uint64_t)0U;
  uint64_t a0_updated = (a07 << (uint32_t)1U) + (uint64_t)0U;
  uint64_t a1_updated = (a17 << (uint32_t)1U) + carry0;
  uint64_t a2_updated = (a27 << (uint32_t)1U) + carry1;
  uint64_t a3_updated = (a37 << (uint32_t)1U) + carry2;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  state2_2 =
    Hacl_Spec_P256_Core_reduction_prime_2prime_with_carry(carry3,
      a0_updated,
      a1_updated,
      a2_updated,
      a3_updated);
  K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut41 =
    {
      .fst = { .fst = state0_red_0, .snd = state0_red_1, .thd = state0_red_2, .f3 = state0_red_3 },
      .snd = state1_2
    };
  uint64_t b39 = scrut41.snd.f3;
  uint64_t b29 = scrut41.snd.thd;
  uint64_t b19 = scrut41.snd.snd;
  uint64_t b09 = scrut41.snd.fst;
  uint64_t a38 = scrut41.fst.f3;
  uint64_t a28 = scrut41.fst.thd;
  uint64_t a18 = scrut41.fst.snd;
  uint64_t a08 = scrut41.fst.fst;
  K___uint64_t_uint64_t
  scrut42 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a08, b09, (uint64_t)0U);
  uint64_t o08 = scrut42.fst;
  uint64_t c018 = scrut42.snd;
  K___uint64_t_uint64_t scrut43 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a18, b19, c018);
  uint64_t o18 = scrut43.fst;
  uint64_t c168 = scrut43.snd;
  K___uint64_t_uint64_t scrut44 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a28, b29, c168);
  uint64_t o28 = scrut44.fst;
  uint64_t c218 = scrut44.snd;
  K___uint64_t_uint64_t scrut45 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a38, b39, c218);
  uint64_t o38 = scrut45.fst;
  uint64_t c318 = scrut45.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut46 = { .fst = c318, .snd = { .fst = o08, .snd = o18, .thd = o28, .f3 = o38 } };
  uint64_t x70 = scrut46.snd.f3;
  uint64_t x50 = scrut46.snd.thd;
  uint64_t x30 = scrut46.snd.snd;
  uint64_t x10 = scrut46.snd.fst;
  uint64_t x80 = scrut46.fst;
  K___uint64_t_uint64_t
  scrut47 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(x10,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o09 = scrut47.fst;
  uint64_t c019 = scrut47.snd;
  K___uint64_t_uint64_t
  scrut48 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x30, (uint64_t)0xffffffffU, c019);
  uint64_t o19 = scrut48.fst;
  uint64_t c169 = scrut48.snd;
  K___uint64_t_uint64_t
  scrut49 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x50, (uint64_t)0U, c169);
  uint64_t o29 = scrut49.fst;
  uint64_t c219 = scrut49.snd;
  K___uint64_t_uint64_t
  scrut50 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x70, (uint64_t)0xffffffff00000001U, c219);
  uint64_t o39 = scrut50.fst;
  uint64_t c319 = scrut50.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut51 = { .fst = c319, .snd = o09, .thd = o19, .f3 = o29, .f4 = o39 };
  uint64_t x168 = scrut51.fst;
  uint64_t x90 = scrut51.snd;
  uint64_t x110 = scrut51.thd;
  uint64_t x130 = scrut51.f3;
  uint64_t x150 = scrut51.f4;
  K___uint64_t_uint64_t
  scrut52 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x80, (uint64_t)0U, x168);
  uint64_t x18 = scrut52.snd;
  uint64_t mask9 = ~FStar_UInt64_eq_mask(x18, (uint64_t)0U);
  uint64_t r020 = x10 & mask9 | x90 & ~mask9;
  uint64_t r119 = x30 & mask9 | x110 & ~mask9;
  uint64_t r29 = x50 & mask9 | x130 & ~mask9;
  uint64_t r39 = x70 & mask9 | x150 & ~mask9;
  uint64_t r0 = r020;
  uint64_t r120 = r119;
  uint64_t r217 = r29;
  uint64_t r317 = r39;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  r021 = { .fst = r0, .snd = r120, .thd = r217, .f3 = r317 };
  K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut53 = { .fst = r021, .snd = state2_2 };
  uint64_t b310 = scrut53.snd.f3;
  uint64_t b210 = scrut53.snd.thd;
  uint64_t b110 = scrut53.snd.snd;
  uint64_t b010 = scrut53.snd.fst;
  uint64_t a39 = scrut53.fst.f3;
  uint64_t a29 = scrut53.fst.thd;
  uint64_t a19 = scrut53.fst.snd;
  uint64_t a09 = scrut53.fst.fst;
  K___uint64_t_uint64_t
  scrut54 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a09, b010, (uint64_t)0U);
  uint64_t o010 = scrut54.fst;
  uint64_t c0110 = scrut54.snd;
  K___uint64_t_uint64_t scrut55 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a19, b110, c0110);
  uint64_t o110 = scrut55.fst;
  uint64_t c1610 = scrut55.snd;
  K___uint64_t_uint64_t scrut56 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a29, b210, c1610);
  uint64_t o210 = scrut56.fst;
  uint64_t c2110 = scrut56.snd;
  K___uint64_t_uint64_t scrut57 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a39, b310, c2110);
  uint64_t o310 = scrut57.fst;
  uint64_t c3110 = scrut57.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut58 = { .fst = c3110, .snd = { .fst = o010, .snd = o110, .thd = o210, .f3 = o310 } };
  uint64_t x71 = scrut58.snd.f3;
  uint64_t x51 = scrut58.snd.thd;
  uint64_t x31 = scrut58.snd.snd;
  uint64_t x12 = scrut58.snd.fst;
  uint64_t x81 = scrut58.fst;
  K___uint64_t_uint64_t
  scrut59 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(x12,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o011 = scrut59.fst;
  uint64_t c0111 = scrut59.snd;
  K___uint64_t_uint64_t
  scrut60 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x31, (uint64_t)0xffffffffU, c0111);
  uint64_t o111 = scrut60.fst;
  uint64_t c1611 = scrut60.snd;
  K___uint64_t_uint64_t
  scrut61 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x51, (uint64_t)0U, c1611);
  uint64_t o211 = scrut61.fst;
  uint64_t c2111 = scrut61.snd;
  K___uint64_t_uint64_t
  scrut62 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(x71,
      (uint64_t)0xffffffff00000001U,
      c2111);
  uint64_t o311 = scrut62.fst;
  uint64_t c3111 = scrut62.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut63 = { .fst = c3111, .snd = o011, .thd = o111, .f3 = o211, .f4 = o311 };
  uint64_t x169 = scrut63.fst;
  uint64_t x91 = scrut63.snd;
  uint64_t x111 = scrut63.thd;
  uint64_t x131 = scrut63.f3;
  uint64_t x151 = scrut63.f4;
  K___uint64_t_uint64_t
  scrut64 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x81, (uint64_t)0U, x169);
  uint64_t x180 = scrut64.snd;
  uint64_t mask10 = ~FStar_UInt64_eq_mask(x180, (uint64_t)0U);
  uint64_t r0110 = x12 & mask10 | x91 & ~mask10;
  uint64_t r121 = x31 & mask10 | x111 & ~mask10;
  uint64_t r218 = x51 & mask10 | x131 & ~mask10;
  uint64_t r318 = x71 & mask10 | x151 & ~mask10;
  uint64_t r0111 = r0110;
  uint64_t r1 = r121;
  uint64_t r219 = r218;
  uint64_t r319 = r318;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  r122 = { .fst = r0111, .snd = r1, .thd = r219, .f3 = r319 };
  K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut65 = { .fst = r122, .snd = state3_red };
  uint64_t b311 = scrut65.snd.f3;
  uint64_t b211 = scrut65.snd.thd;
  uint64_t b111 = scrut65.snd.snd;
  uint64_t b011 = scrut65.snd.fst;
  uint64_t a310 = scrut65.fst.f3;
  uint64_t a210 = scrut65.fst.thd;
  uint64_t a110 = scrut65.fst.snd;
  uint64_t a010 = scrut65.fst.fst;
  K___uint64_t_uint64_t
  scrut66 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a010, b011, (uint64_t)0U);
  uint64_t o012 = scrut66.fst;
  uint64_t c0112 = scrut66.snd;
  K___uint64_t_uint64_t scrut67 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a110, b111, c0112);
  uint64_t o112 = scrut67.fst;
  uint64_t c1612 = scrut67.snd;
  K___uint64_t_uint64_t scrut68 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a210, b211, c1612);
  uint64_t o212 = scrut68.fst;
  uint64_t c2112 = scrut68.snd;
  K___uint64_t_uint64_t scrut69 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a310, b311, c2112);
  uint64_t o312 = scrut69.fst;
  uint64_t c3112 = scrut69.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut70 = { .fst = c3112, .snd = { .fst = o012, .snd = o112, .thd = o212, .f3 = o312 } };
  uint64_t x72 = scrut70.snd.f3;
  uint64_t x52 = scrut70.snd.thd;
  uint64_t x32 = scrut70.snd.snd;
  uint64_t x14 = scrut70.snd.fst;
  uint64_t x82 = scrut70.fst;
  K___uint64_t_uint64_t
  scrut71 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(x14,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o013 = scrut71.fst;
  uint64_t c0113 = scrut71.snd;
  K___uint64_t_uint64_t
  scrut72 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x32, (uint64_t)0xffffffffU, c0113);
  uint64_t o113 = scrut72.fst;
  uint64_t c1613 = scrut72.snd;
  K___uint64_t_uint64_t
  scrut73 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x52, (uint64_t)0U, c1613);
  uint64_t o213 = scrut73.fst;
  uint64_t c2113 = scrut73.snd;
  K___uint64_t_uint64_t
  scrut74 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(x72,
      (uint64_t)0xffffffff00000001U,
      c2113);
  uint64_t o313 = scrut74.fst;
  uint64_t c3113 = scrut74.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut75 = { .fst = c3113, .snd = o013, .thd = o113, .f3 = o213, .f4 = o313 };
  uint64_t x1610 = scrut75.fst;
  uint64_t x92 = scrut75.snd;
  uint64_t x112 = scrut75.thd;
  uint64_t x132 = scrut75.f3;
  uint64_t x152 = scrut75.f4;
  K___uint64_t_uint64_t
  scrut76 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x82, (uint64_t)0U, x1610);
  uint64_t x181 = scrut76.snd;
  uint64_t mask11 = ~FStar_UInt64_eq_mask(x181, (uint64_t)0U);
  uint64_t r0112 = x14 & mask11 | x92 & ~mask11;
  uint64_t r1110 = x32 & mask11 | x112 & ~mask11;
  uint64_t r220 = x52 & mask11 | x132 & ~mask11;
  uint64_t r320 = x72 & mask11 | x152 & ~mask11;
  uint64_t r01 = r0112;
  uint64_t r1111 = r1110;
  uint64_t r221 = r220;
  uint64_t r321 = r320;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  r0113 = { .fst = r01, .snd = r1111, .thd = r221, .f3 = r321 };
  K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut77 = { .fst = r0113, .snd = state4_red };
  uint64_t b312 = scrut77.snd.f3;
  uint64_t b212 = scrut77.snd.thd;
  uint64_t b112 = scrut77.snd.snd;
  uint64_t b012 = scrut77.snd.fst;
  uint64_t a311 = scrut77.fst.f3;
  uint64_t a211 = scrut77.fst.thd;
  uint64_t a111 = scrut77.fst.snd;
  uint64_t a011 = scrut77.fst.fst;
  K___uint64_t_uint64_t
  scrut78 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a011, b012, (uint64_t)0U);
  uint64_t o014 = scrut78.fst;
  uint64_t c0114 = scrut78.snd;
  K___uint64_t_uint64_t scrut79 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a111, b112, c0114);
  uint64_t o114 = scrut79.fst;
  uint64_t c1614 = scrut79.snd;
  K___uint64_t_uint64_t scrut80 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a211, b212, c1614);
  uint64_t o214 = scrut80.fst;
  uint64_t c2114 = scrut80.snd;
  K___uint64_t_uint64_t scrut81 = Hacl_Spec_Curve25519_Field64_Core_addcarry(a311, b312, c2114);
  uint64_t o314 = scrut81.fst;
  uint64_t c3114 = scrut81.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut82 = { .fst = c3114, .snd = { .fst = o014, .snd = o114, .thd = o214, .f3 = o314 } };
  uint64_t x7 = scrut82.snd.f3;
  uint64_t x5 = scrut82.snd.thd;
  uint64_t x3 = scrut82.snd.snd;
  uint64_t x1 = scrut82.snd.fst;
  uint64_t x8 = scrut82.fst;
  K___uint64_t_uint64_t
  scrut83 =
    Hacl_Spec_Curve25519_Field64_Core_subborrow(x1,
      (uint64_t)0xffffffffffffffffU,
      (uint64_t)0U);
  uint64_t o015 = scrut83.fst;
  uint64_t c0115 = scrut83.snd;
  K___uint64_t_uint64_t
  scrut84 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x3, (uint64_t)0xffffffffU, c0115);
  uint64_t o115 = scrut84.fst;
  uint64_t c1615 = scrut84.snd;
  K___uint64_t_uint64_t
  scrut85 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x5, (uint64_t)0U, c1615);
  uint64_t o215 = scrut85.fst;
  uint64_t c2115 = scrut85.snd;
  K___uint64_t_uint64_t
  scrut86 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x7, (uint64_t)0xffffffff00000001U, c2115);
  uint64_t o315 = scrut86.fst;
  uint64_t c3115 = scrut86.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut87 = { .fst = c3115, .snd = o015, .thd = o115, .f3 = o215, .f4 = o315 };
  uint64_t x16 = scrut87.fst;
  uint64_t x9 = scrut87.snd;
  uint64_t x11 = scrut87.thd;
  uint64_t x13 = scrut87.f3;
  uint64_t x15 = scrut87.f4;
  K___uint64_t_uint64_t
  scrut88 = Hacl_Spec_Curve25519_Field64_Core_subborrow(x8, (uint64_t)0U, x16);
  uint64_t x182 = scrut88.snd;
  uint64_t mask12 = ~FStar_UInt64_eq_mask(x182, (uint64_t)0U);
  uint64_t r022 = x1 & mask12 | x9 & ~mask12;
  uint64_t r1112 = x3 & mask12 | x11 & ~mask12;
  uint64_t r222 = x5 & mask12 | x13 & ~mask12;
  uint64_t r322 = x7 & mask12 | x15 & ~mask12;
  uint64_t r023 = r022;
  uint64_t r11 = r1112;
  uint64_t r223 = r222;
  uint64_t r323 = r322;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  r1113 = { .fst = r023, .snd = r11, .thd = r223, .f3 = r323 };
  K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut89 = { .fst = r1113, .snd = state5_red };
  uint64_t b313 = scrut89.snd.f3;
  uint64_t b213 = scrut89.snd.thd;
  uint64_t b113 = scrut89.snd.snd;
  uint64_t b013 = scrut89.snd.fst;
  uint64_t a312 = scrut89.fst.f3;
  uint64_t a212 = scrut89.fst.thd;
  uint64_t a112 = scrut89.fst.snd;
  uint64_t a012 = scrut89.fst.fst;
  K___uint64_t_uint64_t
  scrut90 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a012, b013, (uint64_t)0U);
  uint64_t o016 = scrut90.fst;
  uint64_t c0116 = scrut90.snd;
  K___uint64_t_uint64_t scrut91 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a112, b113, c0116);
  uint64_t o116 = scrut91.fst;
  uint64_t c1616 = scrut91.snd;
  K___uint64_t_uint64_t scrut92 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a212, b213, c1616);
  uint64_t o216 = scrut92.fst;
  uint64_t c2116 = scrut92.snd;
  K___uint64_t_uint64_t scrut93 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a312, b313, c2116);
  uint64_t o316 = scrut93.fst;
  uint64_t c3116 = scrut93.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut94 = { .fst = c3116, .snd = o016, .thd = o116, .f3 = o216, .f4 = o316 };
  uint64_t c17 = scrut94.fst;
  uint64_t r_00 = scrut94.snd;
  uint64_t r_10 = scrut94.thd;
  uint64_t r_20 = scrut94.f3;
  uint64_t r_30 = scrut94.f4;
  uint64_t x20 = ~FStar_UInt64_eq_mask(c17, (uint64_t)0U);
  uint64_t x33 = (uint64_t)0xffffffffffffffffU & x20 | (uint64_t)0U & ~x20;
  uint64_t ln0 = ~~FStar_UInt64_eq_mask(c17, (uint64_t)0U);
  uint64_t x93 = x33;
  uint64_t prime_temp_00 = (uint64_t)0xffffffffffffffffU & x93;
  uint64_t prime_temp_10 = (uint64_t)0xffffffffU & x93;
  uint64_t prime_temp_20 = (uint64_t)0U;
  uint64_t prime_temp_30 = (uint64_t)0xffffffff00000001U & x93;
  K___uint64_t_uint64_t
  scrut95 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_00, r_00, (uint64_t)0U);
  uint64_t o017 = scrut95.fst;
  uint64_t c0117 = scrut95.snd;
  K___uint64_t_uint64_t
  scrut96 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_10, r_10, c0117);
  uint64_t o117 = scrut96.fst;
  uint64_t c1617 = scrut96.snd;
  K___uint64_t_uint64_t
  scrut97 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_20, r_20, c1617);
  uint64_t o217 = scrut97.fst;
  uint64_t c2117 = scrut97.snd;
  K___uint64_t_uint64_t
  scrut98 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_30, r_30, c2117);
  uint64_t o317 = scrut98.fst;
  uint64_t c3117 = scrut98.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut99 = { .fst = c3117, .snd = { .fst = o017, .snd = o117, .thd = o217, .f3 = o317 } };
  uint64_t r324 = scrut99.snd.f3;
  uint64_t r224 = scrut99.snd.thd;
  uint64_t r123 = scrut99.snd.snd;
  uint64_t r02 = scrut99.snd.fst;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  r024 = { .fst = r02, .snd = r123, .thd = r224, .f3 = r324 };
  K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut100 = { .fst = r024, .snd = state6_red };
  uint64_t b314 = scrut100.snd.f3;
  uint64_t b214 = scrut100.snd.thd;
  uint64_t b114 = scrut100.snd.snd;
  uint64_t b014 = scrut100.snd.fst;
  uint64_t a313 = scrut100.fst.f3;
  uint64_t a213 = scrut100.fst.thd;
  uint64_t a113 = scrut100.fst.snd;
  uint64_t a013 = scrut100.fst.fst;
  K___uint64_t_uint64_t
  scrut101 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a013, b014, (uint64_t)0U);
  uint64_t o018 = scrut101.fst;
  uint64_t c0118 = scrut101.snd;
  K___uint64_t_uint64_t
  scrut102 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a113, b114, c0118);
  uint64_t o118 = scrut102.fst;
  uint64_t c1618 = scrut102.snd;
  K___uint64_t_uint64_t
  scrut103 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a213, b214, c1618);
  uint64_t o218 = scrut103.fst;
  uint64_t c2118 = scrut103.snd;
  K___uint64_t_uint64_t
  scrut104 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a313, b314, c2118);
  uint64_t o318 = scrut104.fst;
  uint64_t c3118 = scrut104.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut105 = { .fst = c3118, .snd = o018, .thd = o118, .f3 = o218, .f4 = o318 };
  uint64_t c18 = scrut105.fst;
  uint64_t r_01 = scrut105.snd;
  uint64_t r_11 = scrut105.thd;
  uint64_t r_21 = scrut105.f3;
  uint64_t r_31 = scrut105.f4;
  uint64_t x21 = ~FStar_UInt64_eq_mask(c18, (uint64_t)0U);
  uint64_t x34 = (uint64_t)0xffffffffffffffffU & x21 | (uint64_t)0U & ~x21;
  uint64_t ln1 = ~~FStar_UInt64_eq_mask(c18, (uint64_t)0U);
  uint64_t x94 = x34;
  uint64_t prime_temp_01 = (uint64_t)0xffffffffffffffffU & x94;
  uint64_t prime_temp_11 = (uint64_t)0xffffffffU & x94;
  uint64_t prime_temp_21 = (uint64_t)0U;
  uint64_t prime_temp_31 = (uint64_t)0xffffffff00000001U & x94;
  K___uint64_t_uint64_t
  scrut106 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_01, r_01, (uint64_t)0U);
  uint64_t o019 = scrut106.fst;
  uint64_t c0119 = scrut106.snd;
  K___uint64_t_uint64_t
  scrut107 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_11, r_11, c0119);
  uint64_t o119 = scrut107.fst;
  uint64_t c1619 = scrut107.snd;
  K___uint64_t_uint64_t
  scrut108 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_21, r_21, c1619);
  uint64_t o219 = scrut108.fst;
  uint64_t c2119 = scrut108.snd;
  K___uint64_t_uint64_t
  scrut109 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_31, r_31, c2119);
  uint64_t o319 = scrut109.fst;
  uint64_t c3119 = scrut109.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut110 = { .fst = c3119, .snd = { .fst = o019, .snd = o119, .thd = o219, .f3 = o319 } };
  uint64_t r325 = scrut110.snd.f3;
  uint64_t r225 = scrut110.snd.thd;
  uint64_t r12 = scrut110.snd.snd;
  uint64_t r030 = scrut110.snd.fst;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  r124 = { .fst = r030, .snd = r12, .thd = r225, .f3 = r325 };
  K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut111 = { .fst = r124, .snd = state7_red };
  uint64_t b315 = scrut111.snd.f3;
  uint64_t b215 = scrut111.snd.thd;
  uint64_t b115 = scrut111.snd.snd;
  uint64_t b015 = scrut111.snd.fst;
  uint64_t a314 = scrut111.fst.f3;
  uint64_t a214 = scrut111.fst.thd;
  uint64_t a114 = scrut111.fst.snd;
  uint64_t a014 = scrut111.fst.fst;
  K___uint64_t_uint64_t
  scrut112 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a014, b015, (uint64_t)0U);
  uint64_t o020 = scrut112.fst;
  uint64_t c0120 = scrut112.snd;
  K___uint64_t_uint64_t
  scrut113 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a114, b115, c0120);
  uint64_t o120 = scrut113.fst;
  uint64_t c1620 = scrut113.snd;
  K___uint64_t_uint64_t
  scrut114 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a214, b215, c1620);
  uint64_t o220 = scrut114.fst;
  uint64_t c2120 = scrut114.snd;
  K___uint64_t_uint64_t
  scrut115 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a314, b315, c2120);
  uint64_t o320 = scrut115.fst;
  uint64_t c3120 = scrut115.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut116 = { .fst = c3120, .snd = o020, .thd = o120, .f3 = o220, .f4 = o320 };
  uint64_t c19 = scrut116.fst;
  uint64_t r_02 = scrut116.snd;
  uint64_t r_12 = scrut116.thd;
  uint64_t r_22 = scrut116.f3;
  uint64_t r_32 = scrut116.f4;
  uint64_t x22 = ~FStar_UInt64_eq_mask(c19, (uint64_t)0U);
  uint64_t x35 = (uint64_t)0xffffffffffffffffU & x22 | (uint64_t)0U & ~x22;
  uint64_t ln2 = ~~FStar_UInt64_eq_mask(c19, (uint64_t)0U);
  uint64_t x95 = x35;
  uint64_t prime_temp_02 = (uint64_t)0xffffffffffffffffU & x95;
  uint64_t prime_temp_12 = (uint64_t)0xffffffffU & x95;
  uint64_t prime_temp_22 = (uint64_t)0U;
  uint64_t prime_temp_32 = (uint64_t)0xffffffff00000001U & x95;
  K___uint64_t_uint64_t
  scrut117 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_02, r_02, (uint64_t)0U);
  uint64_t o021 = scrut117.fst;
  uint64_t c0121 = scrut117.snd;
  K___uint64_t_uint64_t
  scrut118 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_12, r_12, c0121);
  uint64_t o121 = scrut118.fst;
  uint64_t c1621 = scrut118.snd;
  K___uint64_t_uint64_t
  scrut119 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_22, r_22, c1621);
  uint64_t o221 = scrut119.fst;
  uint64_t c2121 = scrut119.snd;
  K___uint64_t_uint64_t
  scrut120 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_32, r_32, c2121);
  uint64_t o321 = scrut120.fst;
  uint64_t c3121 = scrut120.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut121 = { .fst = c3121, .snd = { .fst = o021, .snd = o121, .thd = o221, .f3 = o321 } };
  uint64_t r326 = scrut121.snd.f3;
  uint64_t r226 = scrut121.snd.thd;
  uint64_t r130 = scrut121.snd.snd;
  uint64_t r03 = scrut121.snd.fst;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  r031 = { .fst = r03, .snd = r130, .thd = r226, .f3 = r326 };
  K___K___uint64_t_uint64_t_uint64_t_uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut122 = { .fst = r031, .snd = state8_red };
  uint64_t b3 = scrut122.snd.f3;
  uint64_t b2 = scrut122.snd.thd;
  uint64_t b1 = scrut122.snd.snd;
  uint64_t b0 = scrut122.snd.fst;
  uint64_t a3 = scrut122.fst.f3;
  uint64_t a2 = scrut122.fst.thd;
  uint64_t a1 = scrut122.fst.snd;
  uint64_t a0 = scrut122.fst.fst;
  K___uint64_t_uint64_t
  scrut123 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a0, b0, (uint64_t)0U);
  uint64_t o022 = scrut123.fst;
  uint64_t c0122 = scrut123.snd;
  K___uint64_t_uint64_t scrut124 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a1, b1, c0122);
  uint64_t o122 = scrut124.fst;
  uint64_t c1622 = scrut124.snd;
  K___uint64_t_uint64_t scrut125 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a2, b2, c1622);
  uint64_t o222 = scrut125.fst;
  uint64_t c2122 = scrut125.snd;
  K___uint64_t_uint64_t scrut126 = Hacl_Spec_Curve25519_Field64_Core_subborrow(a3, b3, c2122);
  uint64_t o322 = scrut126.fst;
  uint64_t c3122 = scrut126.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut127 = { .fst = c3122, .snd = o022, .thd = o122, .f3 = o222, .f4 = o322 };
  uint64_t c = scrut127.fst;
  uint64_t r_0 = scrut127.snd;
  uint64_t r_1 = scrut127.thd;
  uint64_t r_2 = scrut127.f3;
  uint64_t r_3 = scrut127.f4;
  uint64_t x2 = ~FStar_UInt64_eq_mask(c, (uint64_t)0U);
  uint64_t x36 = (uint64_t)0xffffffffffffffffU & x2 | (uint64_t)0U & ~x2;
  uint64_t ln = ~~FStar_UInt64_eq_mask(c, (uint64_t)0U);
  uint64_t x96 = x36;
  uint64_t prime_temp_0 = (uint64_t)0xffffffffffffffffU & x96;
  uint64_t prime_temp_1 = (uint64_t)0xffffffffU & x96;
  uint64_t prime_temp_2 = (uint64_t)0U;
  uint64_t prime_temp_3 = (uint64_t)0xffffffff00000001U & x96;
  K___uint64_t_uint64_t
  scrut = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_0, r_0, (uint64_t)0U);
  uint64_t o0 = scrut.fst;
  uint64_t c01 = scrut.snd;
  K___uint64_t_uint64_t
  scrut128 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_1, r_1, c01);
  uint64_t o1 = scrut128.fst;
  uint64_t c16 = scrut128.snd;
  K___uint64_t_uint64_t
  scrut129 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_2, r_2, c16);
  uint64_t o2 = scrut129.fst;
  uint64_t c21 = scrut129.snd;
  K___uint64_t_uint64_t
  scrut130 = Hacl_Spec_Curve25519_Field64_Core_addcarry(prime_temp_3, r_3, c21);
  uint64_t o3 = scrut130.fst;
  uint64_t c31 = scrut130.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut131 = { .fst = c31, .snd = { .fst = o0, .snd = o1, .thd = o2, .f3 = o3 } };
  uint64_t r3 = scrut131.snd.f3;
  uint64_t r2 = scrut131.snd.thd;
  uint64_t r13 = scrut131.snd.snd;
  uint64_t r04 = scrut131.snd.fst;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  result = { .fst = r04, .snd = r13, .thd = r2, .f3 = r3 };
  return result;
}


static void Hacl_Impl_Gen_p256_add(uint64_t *arg1, uint64_t *arg2, uint64_t *out)
{
  uint64_t *r0 = out;
  uint64_t *r1 = out + (uint32_t)1U;
  uint64_t *r2 = out + (uint32_t)2U;
  uint64_t *r3 = out + (uint32_t)3U;
  uint64_t cc = _addcarry_u64((uint64_t)0U, arg1[0U], arg2[0U], r0);
  uint64_t cc1 = _addcarry_u64(cc, arg1[1U], arg2[1U], r1);
  uint64_t cc2 = _addcarry_u64(cc1, arg1[2U], arg2[2U], r2);
  uint64_t cc3 = _addcarry_u64(cc2, arg1[3U], arg2[3U], r3);
  uint64_t t = cc3;
  uint64_t cc4 = _addcarry_u64(cc3, out[0U], (uint64_t)0U, r0);
  uint64_t cc5 = _addcarry_u64(cc4, out[1U], (uint64_t)0U - (t << (uint32_t)32U), r1);
  uint64_t cc6 = _addcarry_u64(cc5, out[2U], (uint64_t)0U - t, r2);
  uint64_t
  uu____0 = _addcarry_u64(cc6, out[3U], (t << (uint32_t)32U) - (t << (uint32_t)1U), r3);
}

static void Hacl_Impl_Gen_p256_sub(uint64_t *arg1, uint64_t *arg2, uint64_t *out)
{
  uint64_t *r0 = out;
  uint64_t *r1 = out + (uint32_t)1U;
  uint64_t *r2 = out + (uint32_t)2U;
  uint64_t *r3 = out + (uint32_t)3U;
  uint64_t cc = _subborrow_u64((uint64_t)0U, arg1[0U], arg2[0U], r0);
  uint64_t cc1 = _subborrow_u64(cc, arg1[1U], arg2[1U], r1);
  uint64_t cc2 = _subborrow_u64(cc1, arg1[2U], arg2[2U], r2);
  uint64_t cc3 = _subborrow_u64(cc2, arg1[3U], arg2[3U], r3);
  uint64_t t = cc3;
  uint64_t cc4 = _addcarry_u64((uint64_t)0U, out[0U], (uint64_t)0U - t, r0);
  uint64_t cc5 = _addcarry_u64(cc4, out[1U], (uint64_t)0U - t >> (uint32_t)32U, r1);
  uint64_t cc6 = _addcarry_u64(cc5, out[2U], (uint64_t)0U, r2);
  uint64_t uu____0 = _addcarry_u64(cc6, out[3U], t - (t << (uint32_t)32U), r3);
}

static uint64_t Hacl_Impl_Gen_mm_round1(uint64_t *a, uint64_t t4, uint64_t *tempBuffer)
{
  uint64_t tempBufferLocal[2U] = { 0U };
  uint64_t *temp_zl = tempBufferLocal;
  uint64_t *temp_zh = tempBufferLocal + (uint32_t)1U;
  uint64_t x = a[1U];
  uint64_t *t0_b = tempBuffer;
  uint64_t *t1_b = tempBuffer + (uint32_t)1U;
  uint64_t *t2_b = tempBuffer + (uint32_t)2U;
  uint64_t *t3_b = tempBuffer + (uint32_t)3U;
  uint64_t k = _addcarry_u64((uint64_t)0U, tempBuffer[4U], tempBuffer[0U], temp_zl);
  uint64_t f = temp_zl[0U];
  uint64_t uu____0 = _addcarry_u64(k, tempBuffer[5U], (uint64_t)0U, t0_b);
  uint128_t res = (uint128_t)x * x;
  uint64_t zl = (uint64_t)res;
  uint64_t zh = (uint64_t)(res >> (uint32_t)64U);
  uint64_t k1 = _addcarry_u64((uint64_t)0U, zl, tempBuffer[0U], temp_zl);
  uint64_t uu____1 = _addcarry_u64(k1, zh, (uint64_t)0U, temp_zh);
  uint64_t k2 = _addcarry_u64((uint64_t)0U, temp_zl[0U], tempBuffer[1U], t0_b);
  uint64_t uu____2 = _addcarry_u64(k2, temp_zh[0U], (uint64_t)0U, t1_b);
  uint128_t res0 = (uint128_t)x * a[2U];
  uint64_t zl1 = (uint64_t)res0;
  uint64_t zh1 = (uint64_t)(res0 >> (uint32_t)64U);
  tempBuffer[10U] = zl1;
  tempBuffer[11U] = zh1;
  uint64_t k3 = _addcarry_u64((uint64_t)0U, zl1, tempBuffer[1U], temp_zl);
  uint64_t uu____3 = _addcarry_u64(k3, zh1, (uint64_t)0U, temp_zh);
  uint64_t k4 = _addcarry_u64((uint64_t)0U, temp_zl[0U], tempBuffer[2U], t1_b);
  uint64_t uu____4 = _addcarry_u64(k4, temp_zh[0U], (uint64_t)0U, t2_b);
  uint128_t res1 = (uint128_t)x * a[3U];
  uint64_t zl2 = (uint64_t)res1;
  uint64_t zh2 = (uint64_t)(res1 >> (uint32_t)64U);
  tempBuffer[12U] = zl2;
  tempBuffer[13U] = zh2;
  uint64_t k5 = _addcarry_u64((uint64_t)0U, zl2, tempBuffer[2U], temp_zl);
  uint64_t uu____5 = _addcarry_u64(k5, zh2, (uint64_t)0U, temp_zh);
  uint64_t k6 = _addcarry_u64((uint64_t)0U, temp_zl[0U], tempBuffer[3U], t2_b);
  uint64_t uu____6 = _addcarry_u64(k6, temp_zh[0U], (uint64_t)0U, t3_b);
  uint64_t t41 = _addcarry_u64((uint64_t)0U, tempBuffer[3U], t4, t3_b);
  uint64_t k7 = _addcarry_u64((uint64_t)0U, tempBuffer[0U], f << (uint32_t)32U, t0_b);
  uint64_t k8 = _addcarry_u64(k7, tempBuffer[1U], f >> (uint32_t)32U, t1_b);
  uint64_t m = _subborrow_u64((uint64_t)0U, f, f << (uint32_t)32U, temp_zl);
  uint64_t uu____7 = _subborrow_u64(m, f, f >> (uint32_t)32U, temp_zh);
  uint64_t k9 = _addcarry_u64(k8, tempBuffer[2U], temp_zl[0U], t2_b);
  uint64_t k10 = _addcarry_u64(k9, tempBuffer[3U], temp_zh[0U], t3_b);
  uint64_t uu____8 = _addcarry_u64(k10, t41, (uint64_t)0U, temp_zl);
  uint64_t t42 = temp_zl[0U];
  return t42;
}

static uint64_t Hacl_Impl_Gen_mm_round2(uint64_t *a, uint64_t t4, uint64_t *tempBuffer)
{
  uint64_t tempBufferLocal[2U] = { 0U };
  uint64_t *temp_zl = tempBufferLocal;
  uint64_t *temp_zh = tempBufferLocal + (uint32_t)1U;
  uint64_t x = a[2U];
  uint64_t a3 = a[3U];
  uint64_t t0 = tempBuffer[0U];
  uint64_t t1 = tempBuffer[1U];
  uint64_t t2 = tempBuffer[2U];
  uint64_t t3 = tempBuffer[3U];
  uint64_t *t0_b = tempBuffer;
  uint64_t *t1_b = tempBuffer + (uint32_t)1U;
  uint64_t *t2_b = tempBuffer + (uint32_t)2U;
  uint64_t *t3_b = tempBuffer + (uint32_t)3U;
  uint64_t zl = tempBuffer[6U];
  uint64_t zh = tempBuffer[7U];
  uint64_t k = _addcarry_u64((uint64_t)0U, zl, t0, temp_zl);
  uint64_t f = temp_zl[0U];
  uint64_t uu____0 = _addcarry_u64(k, zh, (uint64_t)0U, t0_b);
  uint64_t zl1 = tempBuffer[10U];
  uint64_t zh1 = tempBuffer[11U];
  uint64_t t01 = t0_b[0U];
  uint64_t k1 = _addcarry_u64((uint64_t)0U, zl1, t01, temp_zl);
  uint64_t uu____1 = _addcarry_u64(k1, zh1, (uint64_t)0U, temp_zh);
  uint64_t k2 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t1, t0_b);
  uint64_t uu____2 = _addcarry_u64(k2, temp_zh[0U], (uint64_t)0U, t1_b);
  uint128_t res = (uint128_t)x * x;
  uint64_t zl2 = (uint64_t)res;
  uint64_t zh2 = (uint64_t)(res >> (uint32_t)64U);
  uint64_t t11 = t1_b[0U];
  uint64_t k3 = _addcarry_u64((uint64_t)0U, zl2, t11, temp_zl);
  uint64_t uu____3 = _addcarry_u64(k3, zh2, (uint64_t)0U, temp_zh);
  uint64_t k4 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t2, t1_b);
  uint64_t uu____4 = _addcarry_u64(k4, temp_zh[0U], (uint64_t)0U, t2_b);
  uint128_t res0 = (uint128_t)x * a3;
  uint64_t zl3 = (uint64_t)res0;
  uint64_t zh3 = (uint64_t)(res0 >> (uint32_t)64U);
  tempBuffer[14U] = zl3;
  tempBuffer[15U] = zh3;
  uint64_t t21 = t2_b[0U];
  uint64_t k5 = _addcarry_u64((uint64_t)0U, zl3, t21, temp_zl);
  uint64_t uu____5 = _addcarry_u64(k5, zh3, (uint64_t)0U, temp_zh);
  uint64_t k6 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t3, t2_b);
  uint64_t uu____6 = _addcarry_u64(k6, temp_zh[0U], (uint64_t)0U, t3_b);
  uint64_t t31 = t3_b[0U];
  uint64_t t02 = t0_b[0U];
  uint64_t t12 = t1_b[0U];
  uint64_t t41 = _addcarry_u64((uint64_t)0U, t31, t4, t3_b);
  uint64_t k7 = _addcarry_u64((uint64_t)0U, t02, f << (uint32_t)32U, t0_b);
  uint64_t k8 = _addcarry_u64(k7, t12, f >> (uint32_t)32U, t1_b);
  uint64_t m = _subborrow_u64((uint64_t)0U, f, f << (uint32_t)32U, temp_zl);
  uint64_t uu____7 = _subborrow_u64(m, f, f >> (uint32_t)32U, temp_zh);
  uint64_t t22 = t2_b[0U];
  uint64_t t32 = t3_b[0U];
  uint64_t k9 = _addcarry_u64(k8, t22, temp_zl[0U], t2_b);
  uint64_t k10 = _addcarry_u64(k9, t32, temp_zh[0U], t3_b);
  uint64_t uu____8 = _addcarry_u64(k10, t41, (uint64_t)0U, temp_zl);
  uint64_t t42 = temp_zl[0U];
  return t42;
}

static uint64_t Hacl_Impl_Gen_mm_round3(uint64_t *a, uint64_t t4, uint64_t *tempBuffer)
{
  uint64_t tempBufferLocal[2U] = { 0U };
  uint64_t *temp_zl = tempBufferLocal;
  uint64_t *temp_zh = tempBufferLocal + (uint32_t)1U;
  uint64_t x = a[3U];
  uint64_t t0 = tempBuffer[0U];
  uint64_t t1 = tempBuffer[1U];
  uint64_t t2 = tempBuffer[2U];
  uint64_t t3 = tempBuffer[3U];
  uint64_t *t0_b = tempBuffer;
  uint64_t *t1_b = tempBuffer + (uint32_t)1U;
  uint64_t *t2_b = tempBuffer + (uint32_t)2U;
  uint64_t *t3_b = tempBuffer + (uint32_t)3U;
  uint64_t zl = tempBuffer[8U];
  uint64_t zh = tempBuffer[9U];
  uint64_t k = _addcarry_u64((uint64_t)0U, zl, t0, temp_zl);
  uint64_t f = temp_zl[0U];
  uint64_t uu____0 = _addcarry_u64(k, zh, (uint64_t)0U, t0_b);
  uint64_t zl1 = tempBuffer[12U];
  uint64_t zh1 = tempBuffer[13U];
  uint64_t t01 = t0_b[0U];
  uint64_t k1 = _addcarry_u64((uint64_t)0U, zl1, t01, temp_zl);
  uint64_t uu____1 = _addcarry_u64(k1, zh1, (uint64_t)0U, temp_zh);
  uint64_t k2 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t1, t0_b);
  uint64_t uu____2 = _addcarry_u64(k2, temp_zh[0U], (uint64_t)0U, t1_b);
  uint64_t zl2 = tempBuffer[14U];
  uint64_t zh2 = tempBuffer[15U];
  uint64_t t11 = t1_b[0U];
  uint64_t k3 = _addcarry_u64((uint64_t)0U, zl2, t11, temp_zl);
  uint64_t uu____3 = _addcarry_u64(k3, zh2, (uint64_t)0U, temp_zh);
  uint64_t k4 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t2, t1_b);
  uint64_t uu____4 = _addcarry_u64(k4, temp_zh[0U], (uint64_t)0U, t2_b);
  uint128_t res = (uint128_t)x * x;
  uint64_t zl3 = (uint64_t)res;
  uint64_t zh3 = (uint64_t)(res >> (uint32_t)64U);
  uint64_t t21 = t2_b[0U];
  uint64_t k5 = _addcarry_u64((uint64_t)0U, zl3, t21, temp_zl);
  uint64_t uu____5 = _addcarry_u64(k5, zh3, (uint64_t)0U, temp_zh);
  uint64_t k6 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t3, t2_b);
  uint64_t uu____6 = _addcarry_u64(k6, temp_zh[0U], (uint64_t)0U, t3_b);
  uint64_t t31 = t3_b[0U];
  uint64_t t02 = t0_b[0U];
  uint64_t t12 = t1_b[0U];
  uint64_t t41 = _addcarry_u64((uint64_t)0U, t31, t4, t3_b);
  uint64_t k7 = _addcarry_u64((uint64_t)0U, t02, f << (uint32_t)32U, t0_b);
  uint64_t k8 = _addcarry_u64(k7, t12, f >> (uint32_t)32U, t1_b);
  uint64_t m = _subborrow_u64((uint64_t)0U, f, f << (uint32_t)32U, temp_zl);
  uint64_t uu____7 = _subborrow_u64(m, f, f >> (uint32_t)32U, temp_zh);
  uint64_t t22 = t2_b[0U];
  uint64_t t32 = t3_b[0U];
  uint64_t k9 = _addcarry_u64(k8, t22, temp_zl[0U], t2_b);
  uint64_t k10 = _addcarry_u64(k9, t32, temp_zh[0U], t3_b);
  uint64_t uu____8 = _addcarry_u64(k10, t41, (uint64_t)0U, temp_zl);
  uint64_t t42 = temp_zl[0U];
  return t42;
}

static void Hacl_Impl_Gen_montgomery_square(uint64_t *a, uint64_t *result)
{
  uint64_t tempBuffer[20U] = { 0U };
  uint64_t *temp_zl = tempBuffer;
  uint64_t *temp_zh = tempBuffer + (uint32_t)1U;
  uint64_t *t_buffer = tempBuffer + (uint32_t)2U;
  uint64_t x = a[0U];
  uint64_t a1 = a[1U];
  uint64_t a2 = a[2U];
  uint64_t a3 = a[3U];
  uint128_t res0 = (uint128_t)x * x;
  uint64_t f = (uint64_t)res0;
  uint64_t t0 = (uint64_t)(res0 >> (uint32_t)64U);
  uint128_t res1 = (uint128_t)a1 * x;
  uint64_t zl = (uint64_t)res1;
  uint64_t zh = (uint64_t)(res1 >> (uint32_t)64U);
  tempBuffer[6U] = zl;
  tempBuffer[7U] = zh;
  uint64_t k = _addcarry_u64((uint64_t)0U, zl, t0, temp_zl);
  uint64_t uu____0 = _addcarry_u64(k, zh, (uint64_t)0U, temp_zh);
  uint64_t k1 = _addcarry_u64((uint64_t)0U, temp_zl[0U], f << (uint32_t)32U, temp_zl);
  uint64_t uu____1 = _addcarry_u64(k1, temp_zh[0U], (uint64_t)0U, temp_zh);
  uint64_t t01 = temp_zl[0U];
  uint64_t t1 = temp_zh[0U];
  uint128_t res2 = (uint128_t)a2 * x;
  uint64_t zl1 = (uint64_t)res2;
  uint64_t zh1 = (uint64_t)(res2 >> (uint32_t)64U);
  tempBuffer[8U] = zl1;
  tempBuffer[9U] = zh1;
  uint64_t k2 = _addcarry_u64((uint64_t)0U, zl1, t1, temp_zl);
  uint64_t uu____2 = _addcarry_u64(k2, zh1, (uint64_t)0U, temp_zh);
  uint64_t k3 = _addcarry_u64((uint64_t)0U, temp_zl[0U], f >> (uint32_t)32U, temp_zl);
  uint64_t uu____3 = _addcarry_u64(k3, temp_zh[0U], (uint64_t)0U, temp_zh);
  uint64_t t11 = temp_zl[0U];
  uint64_t t2 = temp_zh[0U];
  uint128_t res = (uint128_t)a3 * x;
  uint64_t zl2 = (uint64_t)res;
  uint64_t zh2 = (uint64_t)(res >> (uint32_t)64U);
  tempBuffer[10U] = zl2;
  tempBuffer[11U] = zh2;
  uint64_t k4 = _addcarry_u64((uint64_t)0U, zl2, t2, temp_zl);
  uint64_t uu____4 = _addcarry_u64(k4, zh2, (uint64_t)0U, temp_zh);
  uint64_t k5 = _addcarry_u64((uint64_t)0U, temp_zl[0U], f, temp_zl);
  uint64_t uu____5 = _addcarry_u64(k5, temp_zh[0U], (uint64_t)0U, temp_zh);
  uint64_t t21 = temp_zl[0U];
  uint64_t t3 = temp_zh[0U];
  uint64_t t4 = _addcarry_u64((uint64_t)0U, t3, f, temp_zl);
  uint64_t k6 = _subborrow_u64((uint64_t)0U, t21, f << (uint32_t)32U, temp_zh);
  uint64_t t31 = temp_zl[0U];
  uint64_t t22 = temp_zh[0U];
  uint64_t k7 = _subborrow_u64(k6, t31, f >> (uint32_t)32U, temp_zl);
  uint64_t t32 = temp_zl[0U];
  uint64_t uu____6 = _subborrow_u64(k7, t4, (uint64_t)0U, temp_zh);
  uint64_t t41 = temp_zh[0U];
  t_buffer[0U] = t01;
  t_buffer[1U] = t11;
  t_buffer[2U] = t22;
  t_buffer[3U] = t32;
  uint64_t t42 = Hacl_Impl_Gen_mm_round1(a, t41, t_buffer);
  uint64_t t43 = Hacl_Impl_Gen_mm_round2(a, t42, t_buffer);
  uint64_t t44 = Hacl_Impl_Gen_mm_round3(a, t43, t_buffer);
  uint64_t *r0 = result;
  uint64_t *r1 = result + (uint32_t)1U;
  uint64_t *r2 = result + (uint32_t)2U;
  uint64_t *r3 = result + (uint32_t)3U;
  uint64_t t02 = t_buffer[0U];
  uint64_t t12 = t_buffer[1U];
  uint64_t t23 = t_buffer[2U];
  uint64_t t33 = t_buffer[3U];
  uint64_t k8 = _addcarry_u64((uint64_t)0U, t02, t44, r0);
  uint64_t k9 = _addcarry_u64(k8, t12, (uint64_t)0U - (t44 << (uint32_t)32U), r1);
  uint64_t k10 = _addcarry_u64(k9, t23, (uint64_t)0U - t44, r2);
  uint64_t
  uu____7 = _addcarry_u64(k10, t33, (t44 << (uint32_t)32U) - (t44 << (uint32_t)1U), r3);
}

static uint64_t
Hacl_Spec_P256_MontgomeryMultiplication_mm_round(
  uint64_t x,
  uint64_t *b,
  uint64_t t4,
  uint64_t *tempBuffer
)
{
  uint64_t tempBufferLocal[2U] = { 0U };
  uint64_t *temp_zl = tempBufferLocal;
  uint64_t *temp_zh = tempBufferLocal + (uint32_t)1U;
  uint64_t b0 = b[0U];
  uint64_t b1 = b[1U];
  uint64_t b2 = b[2U];
  uint64_t b3 = b[3U];
  uint64_t t0 = tempBuffer[0U];
  uint64_t t1 = tempBuffer[1U];
  uint64_t t2 = tempBuffer[2U];
  uint64_t t3 = tempBuffer[3U];
  uint64_t *t0_b = tempBuffer;
  uint64_t *t1_b = tempBuffer + (uint32_t)1U;
  uint64_t *t2_b = tempBuffer + (uint32_t)2U;
  uint64_t *t3_b = tempBuffer + (uint32_t)3U;
  uint128_t res = (uint128_t)x * b0;
  uint64_t zl = (uint64_t)res;
  uint64_t zh = (uint64_t)(res >> (uint32_t)64U);
  uint64_t k = _addcarry_u64((uint64_t)0U, zl, t0, temp_zl);
  uint64_t f = temp_zl[0U];
  uint64_t uu____0 = _addcarry_u64(k, zh, (uint64_t)0U, t0_b);
  uint128_t res0 = (uint128_t)x * b1;
  uint64_t zl1 = (uint64_t)res0;
  uint64_t zh1 = (uint64_t)(res0 >> (uint32_t)64U);
  uint64_t t01 = t0_b[0U];
  uint64_t k1 = _addcarry_u64((uint64_t)0U, zl1, t01, temp_zl);
  uint64_t uu____1 = _addcarry_u64(k1, zh1, (uint64_t)0U, temp_zh);
  uint64_t k2 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t1, t0_b);
  uint64_t uu____2 = _addcarry_u64(k2, temp_zh[0U], (uint64_t)0U, t1_b);
  uint128_t res1 = (uint128_t)x * b2;
  uint64_t zl2 = (uint64_t)res1;
  uint64_t zh2 = (uint64_t)(res1 >> (uint32_t)64U);
  uint64_t t11 = t1_b[0U];
  uint64_t k3 = _addcarry_u64((uint64_t)0U, zl2, t11, temp_zl);
  uint64_t uu____3 = _addcarry_u64(k3, zh2, (uint64_t)0U, temp_zh);
  uint64_t k4 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t2, t1_b);
  uint64_t uu____4 = _addcarry_u64(k4, temp_zh[0U], (uint64_t)0U, t2_b);
  uint128_t res2 = (uint128_t)x * b3;
  uint64_t zl3 = (uint64_t)res2;
  uint64_t zh3 = (uint64_t)(res2 >> (uint32_t)64U);
  uint64_t t21 = t2_b[0U];
  uint64_t k5 = _addcarry_u64((uint64_t)0U, zl3, t21, temp_zl);
  uint64_t uu____5 = _addcarry_u64(k5, zh3, (uint64_t)0U, temp_zh);
  uint64_t k6 = _addcarry_u64((uint64_t)0U, temp_zl[0U], t3, t2_b);
  uint64_t uu____6 = _addcarry_u64(k6, temp_zh[0U], (uint64_t)0U, t3_b);
  uint64_t t31 = t3_b[0U];
  uint64_t t02 = t0_b[0U];
  uint64_t t12 = t1_b[0U];
  uint64_t t41 = _addcarry_u64((uint64_t)0U, t31, t4, t3_b);
  uint64_t k7 = _addcarry_u64((uint64_t)0U, t02, f << (uint32_t)32U, t0_b);
  uint64_t k8 = _addcarry_u64(k7, t12, f >> (uint32_t)32U, t1_b);
  uint64_t m = _subborrow_u64((uint64_t)0U, f, f << (uint32_t)32U, temp_zl);
  uint64_t uu____7 = _subborrow_u64(m, f, f >> (uint32_t)32U, temp_zh);
  uint64_t t22 = t2_b[0U];
  uint64_t t32 = t3_b[0U];
  uint64_t k9 = _addcarry_u64(k8, t22, temp_zl[0U], t2_b);
  uint64_t k10 = _addcarry_u64(k9, t32, temp_zh[0U], t3_b);
  uint64_t uu____8 = _addcarry_u64(k10, t41, (uint64_t)0U, temp_zl);
  uint64_t t42 = temp_zl[0U];
  return t42;
}

static void
Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(
  uint64_t *a,
  uint64_t *b,
  uint64_t *result
)
{
  uint64_t tempBuffer[6U] = { 0U };
  uint64_t *temp_zl = tempBuffer;
  uint64_t *temp_zh = tempBuffer + (uint32_t)1U;
  uint64_t *t_buffer = tempBuffer + (uint32_t)2U;
  uint64_t x = a[0U];
  uint64_t a1 = a[1U];
  uint64_t a2 = a[2U];
  uint64_t a3 = a[3U];
  uint64_t b0 = b[0U];
  uint64_t b1 = b[1U];
  uint64_t b2 = b[2U];
  uint64_t b3 = b[3U];
  uint128_t res0 = (uint128_t)b0 * x;
  uint64_t f = (uint64_t)res0;
  uint64_t t0 = (uint64_t)(res0 >> (uint32_t)64U);
  uint128_t res1 = (uint128_t)b1 * x;
  uint64_t zl = (uint64_t)res1;
  uint64_t zh = (uint64_t)(res1 >> (uint32_t)64U);
  uint64_t k = _addcarry_u64((uint64_t)0U, zl, t0, temp_zl);
  uint64_t uu____0 = _addcarry_u64(k, zh, (uint64_t)0U, temp_zh);
  uint64_t k1 = _addcarry_u64((uint64_t)0U, temp_zl[0U], f << (uint32_t)32U, temp_zl);
  uint64_t uu____1 = _addcarry_u64(k1, temp_zh[0U], (uint64_t)0U, temp_zh);
  uint64_t t01 = temp_zl[0U];
  uint64_t t1 = temp_zh[0U];
  uint128_t res2 = (uint128_t)b2 * x;
  uint64_t zl1 = (uint64_t)res2;
  uint64_t zh1 = (uint64_t)(res2 >> (uint32_t)64U);
  uint64_t k2 = _addcarry_u64((uint64_t)0U, zl1, t1, temp_zl);
  uint64_t uu____2 = _addcarry_u64(k2, zh1, (uint64_t)0U, temp_zh);
  uint64_t k3 = _addcarry_u64((uint64_t)0U, temp_zl[0U], f >> (uint32_t)32U, temp_zl);
  uint64_t uu____3 = _addcarry_u64(k3, temp_zh[0U], (uint64_t)0U, temp_zh);
  uint64_t t11 = temp_zl[0U];
  uint64_t t2 = temp_zh[0U];
  uint128_t res = (uint128_t)b3 * x;
  uint64_t zl2 = (uint64_t)res;
  uint64_t zh2 = (uint64_t)(res >> (uint32_t)64U);
  uint64_t k4 = _addcarry_u64((uint64_t)0U, zl2, t2, temp_zl);
  uint64_t uu____4 = _addcarry_u64(k4, zh2, (uint64_t)0U, temp_zh);
  uint64_t k5 = _addcarry_u64((uint64_t)0U, temp_zl[0U], f, temp_zl);
  uint64_t uu____5 = _addcarry_u64(k5, temp_zh[0U], (uint64_t)0U, temp_zh);
  uint64_t t21 = temp_zl[0U];
  uint64_t t3 = temp_zh[0U];
  uint64_t t4 = _addcarry_u64((uint64_t)0U, t3, f, temp_zl);
  uint64_t k6 = _subborrow_u64((uint64_t)0U, t21, f << (uint32_t)32U, temp_zh);
  uint64_t t31 = temp_zl[0U];
  uint64_t t22 = temp_zh[0U];
  uint64_t k7 = _subborrow_u64(k6, t31, f >> (uint32_t)32U, temp_zl);
  uint64_t t32 = temp_zl[0U];
  uint64_t uu____6 = _subborrow_u64(k7, t4, (uint64_t)0U, temp_zh);
  uint64_t t41 = temp_zh[0U];
  t_buffer[0U] = t01;
  t_buffer[1U] = t11;
  t_buffer[2U] = t22;
  t_buffer[3U] = t32;
  uint64_t t42 = Hacl_Spec_P256_MontgomeryMultiplication_mm_round(a1, b, t41, t_buffer);
  uint64_t t43 = Hacl_Spec_P256_MontgomeryMultiplication_mm_round(a2, b, t42, t_buffer);
  uint64_t t44 = Hacl_Spec_P256_MontgomeryMultiplication_mm_round(a3, b, t43, t_buffer);
  uint64_t *r0 = result;
  uint64_t *r1 = result + (uint32_t)1U;
  uint64_t *r2 = result + (uint32_t)2U;
  uint64_t *r3 = result + (uint32_t)3U;
  uint64_t t02 = t_buffer[0U];
  uint64_t t12 = t_buffer[1U];
  uint64_t t23 = t_buffer[2U];
  uint64_t t33 = t_buffer[3U];
  uint64_t k8 = _addcarry_u64((uint64_t)0U, t02, t44, r0);
  uint64_t k9 = _addcarry_u64(k8, t12, (uint64_t)0U - (t44 << (uint32_t)32U), r1);
  uint64_t k10 = _addcarry_u64(k9, t23, (uint64_t)0U - t44, r2);
  uint64_t
  uu____7 = _addcarry_u64(k10, t33, (t44 << (uint32_t)32U) - (t44 << (uint32_t)1U), r3);
}

static void Hacl_Spec_P256_MontgomeryMultiplication_fsquarePowN(uint32_t n1, uint64_t *a)
{
  for (uint32_t i = (uint32_t)0U; i < n1; i = i + (uint32_t)1U)
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(a, a, a);
}

static void
Hacl_Spec_P256_MontgomeryMultiplication_fsquarePowNminusOne(
  uint32_t n1,
  uint64_t *a,
  uint64_t *b
)
{
  b[0U] = (uint64_t)1U;
  b[1U] = (uint64_t)18446744069414584320U;
  b[2U] = (uint64_t)18446744073709551615U;
  b[3U] = (uint64_t)4294967294U;
  for (uint32_t i = (uint32_t)0U; i < n1; i = i + (uint32_t)1U)
  {
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(b, a, b);
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(a, a, a);
  }
}

static void
Hacl_Spec_P256_MontgomeryMultiplication_exponent(
  uint64_t *a,
  uint64_t *result,
  uint64_t *tempBuffer
)
{
  uint64_t *buffer_norm_1 = tempBuffer;
  uint64_t *buffer_result1 = tempBuffer + (uint32_t)4U;
  uint64_t *buffer_result2 = tempBuffer + (uint32_t)8U;
  uint64_t *buffer_norm_3 = tempBuffer + (uint32_t)12U;
  uint64_t *buffer_result3 = tempBuffer + (uint32_t)16U;
  memcpy(buffer_norm_1, a, (uint32_t)4U * sizeof a[0U]);
  uint64_t *buffer_a = buffer_norm_1;
  uint64_t *buffer_b0 = buffer_norm_1 + (uint32_t)4U;
  Hacl_Spec_P256_MontgomeryMultiplication_fsquarePowNminusOne((uint32_t)32U,
    buffer_a,
    buffer_b0);
  Hacl_Spec_P256_MontgomeryMultiplication_fsquarePowN((uint32_t)224U, buffer_b0);
  memcpy(buffer_result2, a, (uint32_t)4U * sizeof a[0U]);
  Hacl_Spec_P256_MontgomeryMultiplication_fsquarePowN((uint32_t)192U, buffer_result2);
  memcpy(buffer_norm_3, a, (uint32_t)4U * sizeof a[0U]);
  uint64_t *buffer_a0 = buffer_norm_3;
  uint64_t *buffer_b = buffer_norm_3 + (uint32_t)4U;
  Hacl_Spec_P256_MontgomeryMultiplication_fsquarePowNminusOne((uint32_t)94U,
    buffer_a0,
    buffer_b);
  Hacl_Spec_P256_MontgomeryMultiplication_fsquarePowN((uint32_t)2U, buffer_b);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(buffer_result1,
    buffer_result2,
    buffer_result1);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(buffer_result1,
    buffer_result3,
    buffer_result1);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(buffer_result1,
    a,
    buffer_result1);
  memcpy(result, buffer_result1, (uint32_t)4U * sizeof buffer_result1[0U]);
}

static void
Hacl_Spec_P256_MontgomeryMultiplication_cswap(uint64_t bit, uint64_t *p1, uint64_t *p2)
{
  uint64_t mask = (uint64_t)0U - bit;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)12U; i = i + (uint32_t)1U)
  {
    uint64_t dummy = mask & (p1[i] ^ p2[i]);
    p1[i] = p1[i] ^ dummy;
    p2[i] = p2[i] ^ dummy;
  }
}

void pointToDomain(uint64_t *p, uint64_t *result)
{
  uint64_t *p_x = p;
  uint64_t *p_y = p + (uint32_t)4U;
  uint64_t *p_z = p + (uint32_t)8U;
  uint64_t *r_x = result;
  uint64_t *r_y = result + (uint32_t)4U;
  uint64_t *r_z = result + (uint32_t)8U;
  uint64_t value0 = p_x[0U];
  uint64_t value10 = p_x[1U];
  uint64_t value20 = p_x[2U];
  uint64_t value30 = p_x[3U];
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  multipliedByPow256 =
    {
      .fst = (uint64_t)0U, .snd = (uint64_t)0U, .thd = (uint64_t)0U, .f3 = (uint64_t)0U,
      .f4 = value0, .f5 = value10, .f6 = value20, .f7 = value30
    };
  K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut = Hacl_Spec_P256_SolinasReduction_solinas_reduction(multipliedByPow256);
  uint64_t r00 = scrut.fst;
  uint64_t r10 = scrut.snd;
  uint64_t r20 = scrut.thd;
  uint64_t r30 = scrut.f3;
  r_x[0U] = r00;
  r_x[1U] = r10;
  r_x[2U] = r20;
  r_x[3U] = r30;
  uint64_t value00 = p_y[0U];
  uint64_t value11 = p_y[1U];
  uint64_t value21 = p_y[2U];
  uint64_t value31 = p_y[3U];
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  multipliedByPow2560 =
    {
      .fst = (uint64_t)0U, .snd = (uint64_t)0U, .thd = (uint64_t)0U, .f3 = (uint64_t)0U,
      .f4 = value00, .f5 = value11, .f6 = value21, .f7 = value31
    };
  K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut0 = Hacl_Spec_P256_SolinasReduction_solinas_reduction(multipliedByPow2560);
  uint64_t r01 = scrut0.fst;
  uint64_t r11 = scrut0.snd;
  uint64_t r21 = scrut0.thd;
  uint64_t r31 = scrut0.f3;
  r_y[0U] = r01;
  r_y[1U] = r11;
  r_y[2U] = r21;
  r_y[3U] = r31;
  uint64_t value01 = p_z[0U];
  uint64_t value1 = p_z[1U];
  uint64_t value2 = p_z[2U];
  uint64_t value3 = p_z[3U];
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  multipliedByPow2561 =
    {
      .fst = (uint64_t)0U, .snd = (uint64_t)0U, .thd = (uint64_t)0U, .f3 = (uint64_t)0U,
      .f4 = value01, .f5 = value1, .f6 = value2, .f7 = value3
    };
  K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut1 = Hacl_Spec_P256_SolinasReduction_solinas_reduction(multipliedByPow2561);
  uint64_t r0 = scrut1.fst;
  uint64_t r1 = scrut1.snd;
  uint64_t r2 = scrut1.thd;
  uint64_t r3 = scrut1.f3;
  r_z[0U] = r0;
  r_z[1U] = r1;
  r_z[2U] = r2;
  r_z[3U] = r3;
}

typedef struct
K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_s
{
  uint64_t fst;
  uint64_t snd;
  uint64_t thd;
  uint64_t f3;
  uint64_t f4;
  uint64_t f5;
  uint64_t f6;
  uint64_t f7;
  uint64_t f8;
}
K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t;

static void fromDomain(uint64_t *f, uint64_t *result)
{
  uint64_t b0 = f[0U];
  uint64_t b1 = f[1U];
  uint64_t b2 = f[2U];
  uint64_t b3 = f[3U];
  uint128_t res0 = (uint128_t)b0 * (uint64_t)1U;
  uint64_t l00 = (uint64_t)res0;
  uint64_t h00 = (uint64_t)(res0 >> (uint32_t)64U);
  uint128_t res1 = (uint128_t)b1 * (uint64_t)1U;
  uint64_t l10 = (uint64_t)res1;
  uint64_t h10 = (uint64_t)(res1 >> (uint32_t)64U);
  uint128_t res2 = (uint128_t)b2 * (uint64_t)1U;
  uint64_t l20 = (uint64_t)res2;
  uint64_t h20 = (uint64_t)(res2 >> (uint32_t)64U);
  uint128_t res3 = (uint128_t)b3 * (uint64_t)1U;
  uint64_t l30 = (uint64_t)res3;
  uint64_t h30 = (uint64_t)(res3 >> (uint32_t)64U);
  uint64_t o04 = l00;
  K___uint64_t_uint64_t
  scrut0 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l10, h00, (uint64_t)0U);
  uint64_t o10 = scrut0.fst;
  uint64_t c00 = scrut0.snd;
  K___uint64_t_uint64_t scrut1 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l20, h10, c00);
  uint64_t o20 = scrut1.fst;
  uint64_t c10 = scrut1.snd;
  K___uint64_t_uint64_t scrut2 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l30, h20, c10);
  uint64_t o30 = scrut2.fst;
  uint64_t c20 = scrut2.snd;
  uint64_t c30 = h30 + c20;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut3 = { .fst = c30, .snd = o04, .thd = o10, .f3 = o20, .f4 = o30 };
  uint64_t c02 = scrut3.fst;
  uint64_t o00 = scrut3.snd;
  uint64_t o01 = scrut3.thd;
  uint64_t o02 = scrut3.f3;
  uint64_t o03 = scrut3.f4;
  uint128_t res4 = (uint128_t)b0 * (uint64_t)0U;
  uint64_t l01 = (uint64_t)res4;
  uint64_t h01 = (uint64_t)(res4 >> (uint32_t)64U);
  uint128_t res5 = (uint128_t)b1 * (uint64_t)0U;
  uint64_t l11 = (uint64_t)res5;
  uint64_t h11 = (uint64_t)(res5 >> (uint32_t)64U);
  uint128_t res6 = (uint128_t)b2 * (uint64_t)0U;
  uint64_t l21 = (uint64_t)res6;
  uint64_t h21 = (uint64_t)(res6 >> (uint32_t)64U);
  uint128_t res7 = (uint128_t)b3 * (uint64_t)0U;
  uint64_t l31 = (uint64_t)res7;
  uint64_t h31 = (uint64_t)(res7 >> (uint32_t)64U);
  uint64_t o05 = l01;
  K___uint64_t_uint64_t
  scrut4 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l11, h01, (uint64_t)0U);
  uint64_t o15 = scrut4.fst;
  uint64_t c010 = scrut4.snd;
  K___uint64_t_uint64_t scrut5 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l21, h11, c010);
  uint64_t o21 = scrut5.fst;
  uint64_t c12 = scrut5.snd;
  K___uint64_t_uint64_t scrut6 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l31, h21, c12);
  uint64_t o31 = scrut6.fst;
  uint64_t c22 = scrut6.snd;
  uint64_t c31 = h31 + c22;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut7 = { .fst = c31, .snd = o05, .thd = o15, .f3 = o21, .f4 = o31 };
  uint64_t c8 = scrut7.fst;
  uint64_t o06 = scrut7.snd;
  uint64_t o16 = scrut7.thd;
  uint64_t o26 = scrut7.f3;
  uint64_t o32 = scrut7.f4;
  K___uint64_t_uint64_t
  scrut8 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o01, o06, (uint64_t)0U);
  uint64_t o0_ = scrut8.fst;
  uint64_t c011 = scrut8.snd;
  K___uint64_t_uint64_t scrut9 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o02, o16, c011);
  uint64_t o1_ = scrut9.fst;
  uint64_t c13 = scrut9.snd;
  K___uint64_t_uint64_t scrut10 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o03, o26, c13);
  uint64_t o2_ = scrut10.fst;
  uint64_t c23 = scrut10.snd;
  K___uint64_t_uint64_t scrut11 = Hacl_Spec_Curve25519_Field64_Core_addcarry(c02, o32, c23);
  uint64_t o3_ = scrut11.fst;
  uint64_t c32 = scrut11.snd;
  uint64_t c40 = c8 + c32;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut12 = { .fst = c40, .snd = o0_, .thd = o1_, .f3 = o2_, .f4 = o3_ };
  uint64_t c14 = scrut12.fst;
  uint64_t o11 = scrut12.snd;
  uint64_t o12 = scrut12.thd;
  uint64_t o13 = scrut12.f3;
  uint64_t o14 = scrut12.f4;
  uint128_t res8 = (uint128_t)b0 * (uint64_t)0U;
  uint64_t l02 = (uint64_t)res8;
  uint64_t h02 = (uint64_t)(res8 >> (uint32_t)64U);
  uint128_t res9 = (uint128_t)b1 * (uint64_t)0U;
  uint64_t l12 = (uint64_t)res9;
  uint64_t h12 = (uint64_t)(res9 >> (uint32_t)64U);
  uint128_t res10 = (uint128_t)b2 * (uint64_t)0U;
  uint64_t l22 = (uint64_t)res10;
  uint64_t h22 = (uint64_t)(res10 >> (uint32_t)64U);
  uint128_t res11 = (uint128_t)b3 * (uint64_t)0U;
  uint64_t l32 = (uint64_t)res11;
  uint64_t h32 = (uint64_t)(res11 >> (uint32_t)64U);
  uint64_t o07 = l02;
  K___uint64_t_uint64_t
  scrut13 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l12, h02, (uint64_t)0U);
  uint64_t o17 = scrut13.fst;
  uint64_t c012 = scrut13.snd;
  K___uint64_t_uint64_t scrut14 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l22, h12, c012);
  uint64_t o27 = scrut14.fst;
  uint64_t c110 = scrut14.snd;
  K___uint64_t_uint64_t scrut15 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l32, h22, c110);
  uint64_t o37 = scrut15.fst;
  uint64_t c24 = scrut15.snd;
  uint64_t c33 = h32 + c24;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut16 = { .fst = c33, .snd = o07, .thd = o17, .f3 = o27, .f4 = o37 };
  uint64_t c9 = scrut16.fst;
  uint64_t o08 = scrut16.snd;
  uint64_t o18 = scrut16.thd;
  uint64_t o28 = scrut16.f3;
  uint64_t o38 = scrut16.f4;
  K___uint64_t_uint64_t
  scrut17 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o12, o08, (uint64_t)0U);
  uint64_t o0_0 = scrut17.fst;
  uint64_t c013 = scrut17.snd;
  K___uint64_t_uint64_t scrut18 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o13, o18, c013);
  uint64_t o1_0 = scrut18.fst;
  uint64_t c111 = scrut18.snd;
  K___uint64_t_uint64_t scrut19 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o14, o28, c111);
  uint64_t o2_0 = scrut19.fst;
  uint64_t c25 = scrut19.snd;
  K___uint64_t_uint64_t scrut20 = Hacl_Spec_Curve25519_Field64_Core_addcarry(c14, o38, c25);
  uint64_t o3_0 = scrut20.fst;
  uint64_t c34 = scrut20.snd;
  uint64_t c41 = c9 + c34;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut21 = { .fst = c41, .snd = o0_0, .thd = o1_0, .f3 = o2_0, .f4 = o3_0 };
  uint64_t c26 = scrut21.fst;
  uint64_t o22 = scrut21.snd;
  uint64_t o23 = scrut21.thd;
  uint64_t o24 = scrut21.f3;
  uint64_t o25 = scrut21.f4;
  uint128_t res12 = (uint128_t)b0 * (uint64_t)0U;
  uint64_t l03 = (uint64_t)res12;
  uint64_t h03 = (uint64_t)(res12 >> (uint32_t)64U);
  uint128_t res13 = (uint128_t)b1 * (uint64_t)0U;
  uint64_t l13 = (uint64_t)res13;
  uint64_t h1 = (uint64_t)(res13 >> (uint32_t)64U);
  uint128_t res14 = (uint128_t)b2 * (uint64_t)0U;
  uint64_t l2 = (uint64_t)res14;
  uint64_t h2 = (uint64_t)(res14 >> (uint32_t)64U);
  uint128_t res15 = (uint128_t)b3 * (uint64_t)0U;
  uint64_t l33 = (uint64_t)res15;
  uint64_t h33 = (uint64_t)(res15 >> (uint32_t)64U);
  uint64_t o09 = l03;
  K___uint64_t_uint64_t
  scrut22 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l13, h03, (uint64_t)0U);
  uint64_t o19 = scrut22.fst;
  uint64_t c014 = scrut22.snd;
  K___uint64_t_uint64_t scrut23 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l2, h1, c014);
  uint64_t o29 = scrut23.fst;
  uint64_t c112 = scrut23.snd;
  K___uint64_t_uint64_t scrut24 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l33, h2, c112);
  uint64_t o39 = scrut24.fst;
  uint64_t c210 = scrut24.snd;
  uint64_t c35 = h33 + c210;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut25 = { .fst = c35, .snd = o09, .thd = o19, .f3 = o29, .f4 = o39 };
  uint64_t c15 = scrut25.fst;
  uint64_t o010 = scrut25.snd;
  uint64_t o110 = scrut25.thd;
  uint64_t o210 = scrut25.f3;
  uint64_t o310 = scrut25.f4;
  K___uint64_t_uint64_t
  scrut26 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o23, o010, (uint64_t)0U);
  uint64_t o0_1 = scrut26.fst;
  uint64_t c01 = scrut26.snd;
  K___uint64_t_uint64_t scrut27 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o24, o110, c01);
  uint64_t o1_1 = scrut27.fst;
  uint64_t c11 = scrut27.snd;
  K___uint64_t_uint64_t scrut28 = Hacl_Spec_Curve25519_Field64_Core_addcarry(o25, o210, c11);
  uint64_t o2_1 = scrut28.fst;
  uint64_t c21 = scrut28.snd;
  K___uint64_t_uint64_t scrut29 = Hacl_Spec_Curve25519_Field64_Core_addcarry(c26, o310, c21);
  uint64_t o3_1 = scrut29.fst;
  uint64_t c36 = scrut29.snd;
  uint64_t c42 = c15 + c36;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut30 = { .fst = c42, .snd = o0_1, .thd = o1_1, .f3 = o2_1, .f4 = o3_1 };
  uint64_t c37 = scrut30.fst;
  uint64_t o33 = scrut30.snd;
  uint64_t o34 = scrut30.thd;
  uint64_t o35 = scrut30.f3;
  uint64_t o36 = scrut30.f4;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut31 =
    { .fst = o00, .snd = o11, .thd = o22, .f3 = o33, .f4 = o34, .f5 = o35, .f6 = o36, .f7 = c37 };
  uint64_t t_0 = scrut31.fst;
  uint64_t t_1 = scrut31.snd;
  uint64_t t_2 = scrut31.thd;
  uint64_t t_3 = scrut31.f3;
  uint64_t t_4 = scrut31.f4;
  uint64_t t_5 = scrut31.f5;
  uint64_t t_6 = scrut31.f6;
  uint64_t t_7 = scrut31.f7;
  uint64_t t1 = t_0;
  uint64_t mask0 = ~FStar_UInt64_eq_mask(t1, (uint64_t)0U);
  uint64_t h04 = t1 - (uint64_t)(krml_checked_int_t)1 & mask0;
  uint64_t l04 = (uint64_t)(krml_checked_int_t)0 - (t1 & mask0);
  uint64_t l1_0 = t1 << (uint32_t)32U & (uint64_t)0xffffffff00000000U;
  K___uint64_t_uint64_t
  scrut32 = Hacl_Spec_Curve25519_Field64_Core_subborrow(l1_0, t1, (uint64_t)0U);
  uint64_t l14 = scrut32.fst;
  uint64_t c16 = scrut32.snd;
  uint64_t h13 = (t1 >> (uint32_t)32U & (uint64_t)0xffffffffU) - c16;
  uint128_t res16 = (uint128_t)(uint64_t)0xffffffff00000001U * t1;
  uint64_t l34 = (uint64_t)res16;
  uint64_t h34 = (uint64_t)(res16 >> (uint32_t)64U);
  uint64_t res17 = l14 + h04;
  uint64_t c17;
  if (res17 < l14)
    c17 = (uint64_t)1U;
  else
    c17 = (uint64_t)0U;
  uint64_t o111 = res17;
  uint64_t c03 = c17;
  uint64_t o211 = h13 + c03;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut33 =
    {
      .fst = l04, .snd = o111, .thd = o211, .f3 = l34, .f4 = h34, .f5 = (uint64_t)0U,
      .f6 = (uint64_t)0U, .f7 = (uint64_t)0U
    };
  uint64_t t2_0 = scrut33.fst;
  uint64_t t2_1 = scrut33.snd;
  uint64_t t2_2 = scrut33.thd;
  uint64_t t2_3 = scrut33.f3;
  uint64_t t2_4 = scrut33.f4;
  uint64_t t2_5 = scrut33.f5;
  uint64_t t2_6 = scrut33.f6;
  uint64_t t2_7 = scrut33.f7;
  K___uint64_t_uint64_t
  scrut34 = Hacl_Spec_Curve25519_Field64_Core_addcarry(t_0, t2_0, (uint64_t)0U);
  uint64_t o011 = scrut34.fst;
  uint64_t c04 = scrut34.snd;
  K___uint64_t_uint64_t scrut35 = Hacl_Spec_Curve25519_Field64_Core_addcarry(t_1, t2_1, c04);
  uint64_t o112 = scrut35.fst;
  uint64_t c18 = scrut35.snd;
  K___uint64_t_uint64_t scrut36 = Hacl_Spec_Curve25519_Field64_Core_addcarry(t_2, t2_2, c18);
  uint64_t o212 = scrut36.fst;
  uint64_t c27 = scrut36.snd;
  K___uint64_t_uint64_t scrut37 = Hacl_Spec_Curve25519_Field64_Core_addcarry(t_3, t2_3, c27);
  uint64_t o311 = scrut37.fst;
  uint64_t c38 = scrut37.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut38 = { .fst = c38, .snd = { .fst = o011, .snd = o112, .thd = o212, .f3 = o311 } };
  uint64_t o312 = scrut38.snd.f3;
  uint64_t o213 = scrut38.snd.thd;
  uint64_t o113 = scrut38.snd.snd;
  uint64_t o012 = scrut38.snd.fst;
  uint64_t c39 = scrut38.fst;
  K___uint64_t_uint64_t scrut39 = Hacl_Spec_Curve25519_Field64_Core_addcarry(t_4, t2_4, c39);
  uint64_t o40 = scrut39.fst;
  uint64_t c43 = scrut39.snd;
  K___uint64_t_uint64_t scrut40 = Hacl_Spec_Curve25519_Field64_Core_addcarry(t_5, t2_5, c43);
  uint64_t o50 = scrut40.fst;
  uint64_t c50 = scrut40.snd;
  K___uint64_t_uint64_t scrut41 = Hacl_Spec_Curve25519_Field64_Core_addcarry(t_6, t2_6, c50);
  uint64_t o60 = scrut41.fst;
  uint64_t c60 = scrut41.snd;
  K___uint64_t_uint64_t scrut42 = Hacl_Spec_Curve25519_Field64_Core_addcarry(t_7, t2_7, c60);
  uint64_t o70 = scrut42.fst;
  uint64_t c70 = scrut42.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut43 =
    {
      .fst = c70, .snd = o012, .thd = o113, .f3 = o213, .f4 = o312, .f5 = o40, .f6 = o50, .f7 = o60,
      .f8 = o70
    };
  uint64_t t3_8 = scrut43.fst;
  uint64_t t3_1 = scrut43.thd;
  uint64_t t3_2 = scrut43.f3;
  uint64_t t3_3 = scrut43.f4;
  uint64_t t3_4 = scrut43.f5;
  uint64_t t3_5 = scrut43.f6;
  uint64_t t3_6 = scrut43.f7;
  uint64_t t3_7 = scrut43.f8;
  uint64_t st0 = t3_1;
  uint64_t st1 = t3_2;
  uint64_t st2 = t3_3;
  uint64_t st3 = t3_4;
  uint64_t st4 = t3_5;
  uint64_t st5 = t3_6;
  uint64_t st6 = t3_7;
  uint64_t st7 = t3_8;
  uint64_t t110 = st0;
  uint64_t mask1 = ~FStar_UInt64_eq_mask(t110, (uint64_t)0U);
  uint64_t h05 = t110 - (uint64_t)(krml_checked_int_t)1 & mask1;
  uint64_t l05 = (uint64_t)(krml_checked_int_t)0 - (t110 & mask1);
  uint64_t l1_1 = t110 << (uint32_t)32U & (uint64_t)0xffffffff00000000U;
  K___uint64_t_uint64_t
  scrut44 = Hacl_Spec_Curve25519_Field64_Core_subborrow(l1_1, t110, (uint64_t)0U);
  uint64_t l15 = scrut44.fst;
  uint64_t c19 = scrut44.snd;
  uint64_t h14 = (t110 >> (uint32_t)32U & (uint64_t)0xffffffffU) - c19;
  uint128_t res18 = (uint128_t)(uint64_t)0xffffffff00000001U * t110;
  uint64_t l35 = (uint64_t)res18;
  uint64_t h35 = (uint64_t)(res18 >> (uint32_t)64U);
  uint64_t res19 = l15 + h05;
  uint64_t c113;
  if (res19 < l15)
    c113 = (uint64_t)1U;
  else
    c113 = (uint64_t)0U;
  uint64_t o114 = res19;
  uint64_t c05 = c113;
  uint64_t o214 = h14 + c05;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut45 =
    {
      .fst = l05, .snd = o114, .thd = o214, .f3 = l35, .f4 = h35, .f5 = (uint64_t)0U,
      .f6 = (uint64_t)0U, .f7 = (uint64_t)0U
    };
  uint64_t t2_010 = scrut45.fst;
  uint64_t t2_110 = scrut45.snd;
  uint64_t t2_210 = scrut45.thd;
  uint64_t t2_310 = scrut45.f3;
  uint64_t t2_410 = scrut45.f4;
  uint64_t t2_510 = scrut45.f5;
  uint64_t t2_610 = scrut45.f6;
  uint64_t t2_710 = scrut45.f7;
  K___uint64_t_uint64_t
  scrut46 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st0, t2_010, (uint64_t)0U);
  uint64_t o013 = scrut46.fst;
  uint64_t c06 = scrut46.snd;
  K___uint64_t_uint64_t scrut47 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st1, t2_110, c06);
  uint64_t o115 = scrut47.fst;
  uint64_t c114 = scrut47.snd;
  K___uint64_t_uint64_t scrut48 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st2, t2_210, c114);
  uint64_t o215 = scrut48.fst;
  uint64_t c28 = scrut48.snd;
  K___uint64_t_uint64_t scrut49 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st3, t2_310, c28);
  uint64_t o313 = scrut49.fst;
  uint64_t c310 = scrut49.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut50 = { .fst = c310, .snd = { .fst = o013, .snd = o115, .thd = o215, .f3 = o313 } };
  uint64_t o314 = scrut50.snd.f3;
  uint64_t o216 = scrut50.snd.thd;
  uint64_t o116 = scrut50.snd.snd;
  uint64_t o014 = scrut50.snd.fst;
  uint64_t c311 = scrut50.fst;
  K___uint64_t_uint64_t scrut51 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st4, t2_410, c311);
  uint64_t o41 = scrut51.fst;
  uint64_t c44 = scrut51.snd;
  K___uint64_t_uint64_t scrut52 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st5, t2_510, c44);
  uint64_t o51 = scrut52.fst;
  uint64_t c51 = scrut52.snd;
  K___uint64_t_uint64_t scrut53 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st6, t2_610, c51);
  uint64_t o61 = scrut53.fst;
  uint64_t c61 = scrut53.snd;
  K___uint64_t_uint64_t scrut54 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st7, t2_710, c61);
  uint64_t o71 = scrut54.fst;
  uint64_t c71 = scrut54.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut55 =
    {
      .fst = c71, .snd = o014, .thd = o116, .f3 = o216, .f4 = o314, .f5 = o41, .f6 = o51, .f7 = o61,
      .f8 = o71
    };
  uint64_t r00 = scrut55.snd;
  uint64_t r10 = scrut55.thd;
  uint64_t r20 = scrut55.f3;
  uint64_t r30 = scrut55.f4;
  uint64_t r40 = scrut55.f5;
  uint64_t r50 = scrut55.f6;
  uint64_t r60 = scrut55.f7;
  uint64_t r70 = scrut55.f8;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut56 =
    { .fst = r00, .snd = r10, .thd = r20, .f3 = r30, .f4 = r40, .f5 = r50, .f6 = r60, .f7 = r70 };
  uint64_t t3_110 = scrut56.snd;
  uint64_t t3_210 = scrut56.thd;
  uint64_t t3_310 = scrut56.f3;
  uint64_t t3_410 = scrut56.f4;
  uint64_t t3_510 = scrut56.f5;
  uint64_t t3_610 = scrut56.f6;
  uint64_t t3_710 = scrut56.f7;
  uint64_t r_00 = t3_110;
  uint64_t r_10 = t3_210;
  uint64_t r_20 = t3_310;
  uint64_t r_30 = t3_410;
  uint64_t r_40 = t3_510;
  uint64_t r_50 = t3_610;
  uint64_t r_60 = t3_710;
  uint64_t r_70 = (uint64_t)0U;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut57 =
    {
      .fst = r_00, .snd = r_10, .thd = r_20, .f3 = r_30, .f4 = r_40, .f5 = r_50, .f6 = r_60,
      .f7 = r_70
    };
  uint64_t st10 = scrut57.fst;
  uint64_t st11 = scrut57.snd;
  uint64_t st12 = scrut57.thd;
  uint64_t st13 = scrut57.f3;
  uint64_t st14 = scrut57.f4;
  uint64_t st15 = scrut57.f5;
  uint64_t st16 = scrut57.f6;
  uint64_t st17 = scrut57.f7;
  uint64_t t111 = st10;
  uint64_t mask2 = ~FStar_UInt64_eq_mask(t111, (uint64_t)0U);
  uint64_t h06 = t111 - (uint64_t)(krml_checked_int_t)1 & mask2;
  uint64_t l06 = (uint64_t)(krml_checked_int_t)0 - (t111 & mask2);
  uint64_t l1_2 = t111 << (uint32_t)32U & (uint64_t)0xffffffff00000000U;
  K___uint64_t_uint64_t
  scrut58 = Hacl_Spec_Curve25519_Field64_Core_subborrow(l1_2, t111, (uint64_t)0U);
  uint64_t l16 = scrut58.fst;
  uint64_t c29 = scrut58.snd;
  uint64_t h15 = (t111 >> (uint32_t)32U & (uint64_t)0xffffffffU) - c29;
  uint128_t res20 = (uint128_t)(uint64_t)0xffffffff00000001U * t111;
  uint64_t l36 = (uint64_t)res20;
  uint64_t h36 = (uint64_t)(res20 >> (uint32_t)64U);
  uint64_t res21 = l16 + h06;
  uint64_t c115;
  if (res21 < l16)
    c115 = (uint64_t)1U;
  else
    c115 = (uint64_t)0U;
  uint64_t o117 = res21;
  uint64_t c07 = c115;
  uint64_t o217 = h15 + c07;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut59 =
    {
      .fst = l06, .snd = o117, .thd = o217, .f3 = l36, .f4 = h36, .f5 = (uint64_t)0U,
      .f6 = (uint64_t)0U, .f7 = (uint64_t)0U
    };
  uint64_t t2_011 = scrut59.fst;
  uint64_t t2_111 = scrut59.snd;
  uint64_t t2_211 = scrut59.thd;
  uint64_t t2_311 = scrut59.f3;
  uint64_t t2_411 = scrut59.f4;
  uint64_t t2_511 = scrut59.f5;
  uint64_t t2_611 = scrut59.f6;
  uint64_t t2_711 = scrut59.f7;
  K___uint64_t_uint64_t
  scrut60 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st10, t2_011, (uint64_t)0U);
  uint64_t o015 = scrut60.fst;
  uint64_t c08 = scrut60.snd;
  K___uint64_t_uint64_t scrut61 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st11, t2_111, c08);
  uint64_t o118 = scrut61.fst;
  uint64_t c116 = scrut61.snd;
  K___uint64_t_uint64_t scrut62 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st12, t2_211, c116);
  uint64_t o218 = scrut62.fst;
  uint64_t c211 = scrut62.snd;
  K___uint64_t_uint64_t scrut63 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st13, t2_311, c211);
  uint64_t o315 = scrut63.fst;
  uint64_t c312 = scrut63.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut64 = { .fst = c312, .snd = { .fst = o015, .snd = o118, .thd = o218, .f3 = o315 } };
  uint64_t o316 = scrut64.snd.f3;
  uint64_t o219 = scrut64.snd.thd;
  uint64_t o119 = scrut64.snd.snd;
  uint64_t o016 = scrut64.snd.fst;
  uint64_t c313 = scrut64.fst;
  K___uint64_t_uint64_t scrut65 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st14, t2_411, c313);
  uint64_t o42 = scrut65.fst;
  uint64_t c45 = scrut65.snd;
  K___uint64_t_uint64_t scrut66 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st15, t2_511, c45);
  uint64_t o52 = scrut66.fst;
  uint64_t c52 = scrut66.snd;
  K___uint64_t_uint64_t scrut67 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st16, t2_611, c52);
  uint64_t o62 = scrut67.fst;
  uint64_t c62 = scrut67.snd;
  K___uint64_t_uint64_t scrut68 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st17, t2_711, c62);
  uint64_t o72 = scrut68.fst;
  uint64_t c72 = scrut68.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut69 =
    {
      .fst = c72, .snd = o016, .thd = o119, .f3 = o219, .f4 = o316, .f5 = o42, .f6 = o52, .f7 = o62,
      .f8 = o72
    };
  uint64_t r01 = scrut69.snd;
  uint64_t r11 = scrut69.thd;
  uint64_t r21 = scrut69.f3;
  uint64_t r31 = scrut69.f4;
  uint64_t r41 = scrut69.f5;
  uint64_t r51 = scrut69.f6;
  uint64_t r61 = scrut69.f7;
  uint64_t r71 = scrut69.f8;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut70 =
    { .fst = r01, .snd = r11, .thd = r21, .f3 = r31, .f4 = r41, .f5 = r51, .f6 = r61, .f7 = r71 };
  uint64_t t3_111 = scrut70.snd;
  uint64_t t3_211 = scrut70.thd;
  uint64_t t3_311 = scrut70.f3;
  uint64_t t3_411 = scrut70.f4;
  uint64_t t3_511 = scrut70.f5;
  uint64_t t3_611 = scrut70.f6;
  uint64_t t3_711 = scrut70.f7;
  uint64_t r_01 = t3_111;
  uint64_t r_11 = t3_211;
  uint64_t r_21 = t3_311;
  uint64_t r_31 = t3_411;
  uint64_t r_41 = t3_511;
  uint64_t r_51 = t3_611;
  uint64_t r_61 = t3_711;
  uint64_t r_71 = (uint64_t)0U;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut71 =
    {
      .fst = r_01, .snd = r_11, .thd = r_21, .f3 = r_31, .f4 = r_41, .f5 = r_51, .f6 = r_61,
      .f7 = r_71
    };
  uint64_t st20 = scrut71.fst;
  uint64_t st21 = scrut71.snd;
  uint64_t st22 = scrut71.thd;
  uint64_t st23 = scrut71.f3;
  uint64_t st24 = scrut71.f4;
  uint64_t st25 = scrut71.f5;
  uint64_t st26 = scrut71.f6;
  uint64_t st27 = scrut71.f7;
  uint64_t t11 = st20;
  uint64_t mask = ~FStar_UInt64_eq_mask(t11, (uint64_t)0U);
  uint64_t h0 = t11 - (uint64_t)(krml_checked_int_t)1 & mask;
  uint64_t l0 = (uint64_t)(krml_checked_int_t)0 - (t11 & mask);
  uint64_t l1_ = t11 << (uint32_t)32U & (uint64_t)0xffffffff00000000U;
  K___uint64_t_uint64_t
  scrut72 = Hacl_Spec_Curve25519_Field64_Core_subborrow(l1_, t11, (uint64_t)0U);
  uint64_t l1 = scrut72.fst;
  uint64_t c = scrut72.snd;
  uint64_t h16 = (t11 >> (uint32_t)32U & (uint64_t)0xffffffffU) - c;
  uint128_t res22 = (uint128_t)(uint64_t)0xffffffff00000001U * t11;
  uint64_t l3 = (uint64_t)res22;
  uint64_t h3 = (uint64_t)(res22 >> (uint32_t)64U);
  uint64_t res = l1 + h0;
  uint64_t c117;
  if (res < l1)
    c117 = (uint64_t)1U;
  else
    c117 = (uint64_t)0U;
  uint64_t o120 = res;
  uint64_t c09 = c117;
  uint64_t o220 = h16 + c09;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut73 =
    {
      .fst = l0, .snd = o120, .thd = o220, .f3 = l3, .f4 = h3, .f5 = (uint64_t)0U,
      .f6 = (uint64_t)0U, .f7 = (uint64_t)0U
    };
  uint64_t t2_01 = scrut73.fst;
  uint64_t t2_11 = scrut73.snd;
  uint64_t t2_21 = scrut73.thd;
  uint64_t t2_31 = scrut73.f3;
  uint64_t t2_41 = scrut73.f4;
  uint64_t t2_51 = scrut73.f5;
  uint64_t t2_61 = scrut73.f6;
  uint64_t t2_71 = scrut73.f7;
  K___uint64_t_uint64_t
  scrut = Hacl_Spec_Curve25519_Field64_Core_addcarry(st20, t2_01, (uint64_t)0U);
  uint64_t o017 = scrut.fst;
  uint64_t c0 = scrut.snd;
  K___uint64_t_uint64_t scrut74 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st21, t2_11, c0);
  uint64_t o121 = scrut74.fst;
  uint64_t c1 = scrut74.snd;
  K___uint64_t_uint64_t scrut75 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st22, t2_21, c1);
  uint64_t o221 = scrut75.fst;
  uint64_t c2 = scrut75.snd;
  K___uint64_t_uint64_t scrut76 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st23, t2_31, c2);
  uint64_t o317 = scrut76.fst;
  uint64_t c314 = scrut76.snd;
  K___uint64_t_K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut77 = { .fst = c314, .snd = { .fst = o017, .snd = o121, .thd = o221, .f3 = o317 } };
  uint64_t o3 = scrut77.snd.f3;
  uint64_t o2 = scrut77.snd.thd;
  uint64_t o1 = scrut77.snd.snd;
  uint64_t o0 = scrut77.snd.fst;
  uint64_t c3 = scrut77.fst;
  K___uint64_t_uint64_t scrut78 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st24, t2_41, c3);
  uint64_t o4 = scrut78.fst;
  uint64_t c4 = scrut78.snd;
  K___uint64_t_uint64_t scrut79 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st25, t2_51, c4);
  uint64_t o5 = scrut79.fst;
  uint64_t c5 = scrut79.snd;
  K___uint64_t_uint64_t scrut80 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st26, t2_61, c5);
  uint64_t o6 = scrut80.fst;
  uint64_t c6 = scrut80.snd;
  K___uint64_t_uint64_t scrut81 = Hacl_Spec_Curve25519_Field64_Core_addcarry(st27, t2_71, c6);
  uint64_t o7 = scrut81.fst;
  uint64_t c7 = scrut81.snd;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut82 =
    { .fst = c7, .snd = o0, .thd = o1, .f3 = o2, .f4 = o3, .f5 = o4, .f6 = o5, .f7 = o6, .f8 = o7 };
  uint64_t r02 = scrut82.snd;
  uint64_t r12 = scrut82.thd;
  uint64_t r22 = scrut82.f3;
  uint64_t r32 = scrut82.f4;
  uint64_t r4 = scrut82.f5;
  uint64_t r5 = scrut82.f6;
  uint64_t r6 = scrut82.f7;
  uint64_t r7 = scrut82.f8;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut83 =
    { .fst = r02, .snd = r12, .thd = r22, .f3 = r32, .f4 = r4, .f5 = r5, .f6 = r6, .f7 = r7 };
  uint64_t t3_11 = scrut83.snd;
  uint64_t t3_21 = scrut83.thd;
  uint64_t t3_31 = scrut83.f3;
  uint64_t t3_41 = scrut83.f4;
  uint64_t t3_51 = scrut83.f5;
  uint64_t t3_61 = scrut83.f6;
  uint64_t t3_71 = scrut83.f7;
  uint64_t r_0 = t3_11;
  uint64_t r_1 = t3_21;
  uint64_t r_2 = t3_31;
  uint64_t r_3 = t3_41;
  uint64_t r_4 = t3_51;
  uint64_t r_5 = t3_61;
  uint64_t r_6 = t3_71;
  uint64_t r_7 = (uint64_t)0U;
  K___uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t_uint64_t
  scrut84 =
    { .fst = r_0, .snd = r_1, .thd = r_2, .f3 = r_3, .f4 = r_4, .f5 = r_5, .f6 = r_6, .f7 = r_7 };
  uint64_t st30 = scrut84.fst;
  uint64_t st31 = scrut84.snd;
  uint64_t st32 = scrut84.thd;
  uint64_t st33 = scrut84.f3;
  uint64_t st34 = scrut84.f4;
  K___uint64_t_uint64_t_uint64_t_uint64_t
  scrut85 = Hacl_Spec_P256_Core_reduction_prime_2prime_with_carry(st34, st30, st31, st32, st33);
  uint64_t r0 = scrut85.fst;
  uint64_t r1 = scrut85.snd;
  uint64_t r2 = scrut85.thd;
  uint64_t r3 = scrut85.f3;
  result[0U] = r0;
  result[1U] = r1;
  result[2U] = r2;
  result[3U] = r3;
}

void pointFromDomain(uint64_t *p, uint64_t *result)
{
  uint64_t *p_x = p;
  uint64_t *p_y = p + (uint32_t)4U;
  uint64_t *p_z = p + (uint32_t)8U;
  uint64_t *r_x = result;
  uint64_t *r_y = result + (uint32_t)4U;
  uint64_t *r_z = result + (uint32_t)8U;
  fromDomain(p_x, r_x);
  fromDomain(p_y, r_y);
  fromDomain(p_z, r_z);
}

static void quatre(uint64_t *a, uint64_t *result)
{
  Hacl_Impl_Gen_montgomery_square(a, result);
  Hacl_Impl_Gen_montgomery_square(result, result);
}

static void multByTwo(uint64_t *a, uint64_t *out)
{
  uint64_t a0 = a[0U];
  uint64_t a1 = a[1U];
  uint64_t a2 = a[2U];
  uint64_t a3 = a[3U];
  uint64_t *r0 = out;
  uint64_t *r1 = out + (uint32_t)1U;
  uint64_t *r2 = out + (uint32_t)2U;
  uint64_t *r3 = out + (uint32_t)3U;
  uint64_t cc = _addcarry_u64((uint64_t)0U, a0, a0, r0);
  uint64_t cc1 = _addcarry_u64(cc, a1, a1, r1);
  uint64_t cc2 = _addcarry_u64(cc1, a2, a2, r2);
  uint64_t cc3 = _addcarry_u64(cc2, a3, a3, r3);
  uint64_t t = cc3;
  uint64_t cc4 = _addcarry_u64(cc3, r0[0U], (uint64_t)0U, r0);
  uint64_t cc5 = _addcarry_u64(cc4, r1[0U], (uint64_t)0U - (t << (uint32_t)32U), r1);
  uint64_t cc6 = _addcarry_u64(cc5, r2[0U], (uint64_t)0U - t, r2);
  uint64_t
  uu____0 = _addcarry_u64(cc6, r3[0U], (t << (uint32_t)32U) - (t << (uint32_t)1U), r3);
}

static uint64_t isZero_uint64(uint64_t *f)
{
  uint64_t a0 = f[0U];
  uint64_t a1 = f[1U];
  uint64_t a2 = f[2U];
  uint64_t a3 = f[3U];
  uint64_t r0 = FStar_UInt64_eq_mask(a0, (uint64_t)0U);
  uint64_t r1 = FStar_UInt64_eq_mask(a1, (uint64_t)0U);
  uint64_t r2 = FStar_UInt64_eq_mask(a2, (uint64_t)0U);
  uint64_t r3 = FStar_UInt64_eq_mask(a3, (uint64_t)0U);
  uint64_t r01 = r0 & r1;
  uint64_t r23 = r2 & r3;
  return r01 & r23;
}

void point_double(uint64_t *p, uint64_t *result, uint64_t *tempBuffer)
{
  uint64_t *s1 = tempBuffer;
  uint64_t *m = tempBuffer + (uint32_t)4U;
  uint64_t *buffer_for_s_m = tempBuffer + (uint32_t)8U;
  uint64_t *buffer_for_x3 = tempBuffer + (uint32_t)32U;
  uint64_t *buffer_for_y3 = tempBuffer + (uint32_t)40U;
  uint64_t *pypz = tempBuffer + (uint32_t)56U;
  uint64_t *x3 = tempBuffer + (uint32_t)60U;
  uint64_t *y3 = tempBuffer + (uint32_t)64U;
  uint64_t *z3 = tempBuffer + (uint32_t)68U;
  uint64_t *p_y = p + (uint32_t)4U;
  uint64_t *p_z = p + (uint32_t)8U;
  uint64_t *px = p;
  uint64_t *py = p + (uint32_t)4U;
  uint64_t *pz = p + (uint32_t)8U;
  uint64_t *yy = buffer_for_s_m;
  uint64_t *xyy = buffer_for_s_m + (uint32_t)4U;
  uint64_t *zzzz = buffer_for_s_m + (uint32_t)8U;
  uint64_t *minThreeZzzz = buffer_for_s_m + (uint32_t)12U;
  uint64_t *xx = buffer_for_s_m + (uint32_t)16U;
  uint64_t *threeXx = buffer_for_s_m + (uint32_t)20U;
  Hacl_Impl_Gen_montgomery_square(py, yy);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(px, yy, xyy);
  multByTwo(xyy, s1);
  multByTwo(s1, s1);
  quatre(pz, zzzz);
  multByTwo(zzzz, minThreeZzzz);
  Hacl_Impl_Gen_p256_add(zzzz, minThreeZzzz, minThreeZzzz);
  uint64_t zeros[4U] = { 0U };
  Hacl_Impl_Gen_p256_sub(zeros, minThreeZzzz, minThreeZzzz);
  Hacl_Impl_Gen_montgomery_square(px, xx);
  multByTwo(xx, threeXx);
  Hacl_Impl_Gen_p256_add(xx, threeXx, threeXx);
  Hacl_Impl_Gen_p256_add(minThreeZzzz, threeXx, m);
  uint64_t *twoS = buffer_for_x3;
  uint64_t *mm = buffer_for_x3 + (uint32_t)4U;
  multByTwo(s1, twoS);
  Hacl_Impl_Gen_montgomery_square(m, mm);
  Hacl_Impl_Gen_p256_sub(mm, twoS, x3);
  uint64_t *yyyy = buffer_for_y3;
  uint64_t *eightYyyy = buffer_for_y3 + (uint32_t)4U;
  uint64_t *sx3 = buffer_for_y3 + (uint32_t)8U;
  uint64_t *msx3 = buffer_for_y3 + (uint32_t)12U;
  quatre(p_y, yyyy);
  multByTwo(yyyy, eightYyyy);
  multByTwo(eightYyyy, eightYyyy);
  multByTwo(eightYyyy, eightYyyy);
  Hacl_Impl_Gen_p256_sub(s1, x3, sx3);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(m, sx3, msx3);
  Hacl_Impl_Gen_p256_sub(msx3, eightYyyy, y3);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(p_y, p_z, pypz);
  multByTwo(pypz, z3);
  memcpy(result, x3, (uint32_t)4U * sizeof x3[0U]);
  memcpy(result + (uint32_t)4U, y3, (uint32_t)4U * sizeof y3[0U]);
  memcpy(result + (uint32_t)8U, z3, (uint32_t)4U * sizeof z3[0U]);
}

static void
copy_point_conditional(
  uint64_t *x3_out,
  uint64_t *y3_out,
  uint64_t *z3_out,
  uint64_t *p,
  uint64_t *maskPoint
)
{
  uint64_t *z = maskPoint + (uint32_t)8U;
  uint64_t mask = isZero_uint64(z);
  uint64_t *p_x = p;
  uint64_t *p_y = p + (uint32_t)4U;
  uint64_t *p_z = p + (uint32_t)8U;
  uint64_t out_0 = x3_out[0U];
  uint64_t out_10 = x3_out[1U];
  uint64_t out_20 = x3_out[2U];
  uint64_t out_30 = x3_out[3U];
  uint64_t x_00 = p_x[0U];
  uint64_t x_10 = p_x[1U];
  uint64_t x_20 = p_x[2U];
  uint64_t x_30 = p_x[3U];
  uint64_t out_010 = out_0;
  uint64_t out_110 = out_10;
  uint64_t out_210 = out_20;
  uint64_t out_310 = out_30;
  uint64_t x_010 = x_00;
  uint64_t x_110 = x_10;
  uint64_t x_210 = x_20;
  uint64_t x_310 = x_30;
  uint64_t r_00 = out_010 ^ mask & (out_010 ^ x_010);
  uint64_t r_10 = out_110 ^ mask & (out_110 ^ x_110);
  uint64_t r_20 = out_210 ^ mask & (out_210 ^ x_210);
  uint64_t r_30 = out_310 ^ mask & (out_310 ^ x_310);
  uint64_t temp_00 = r_00;
  uint64_t temp_10 = r_10;
  uint64_t temp_20 = r_20;
  uint64_t temp_30 = r_30;
  x3_out[0U] = temp_00;
  x3_out[1U] = temp_10;
  x3_out[2U] = temp_20;
  x3_out[3U] = temp_30;
  uint64_t out_00 = y3_out[0U];
  uint64_t out_12 = y3_out[1U];
  uint64_t out_22 = y3_out[2U];
  uint64_t out_32 = y3_out[3U];
  uint64_t x_02 = p_y[0U];
  uint64_t x_12 = p_y[1U];
  uint64_t x_22 = p_y[2U];
  uint64_t x_32 = p_y[3U];
  uint64_t out_011 = out_00;
  uint64_t out_111 = out_12;
  uint64_t out_211 = out_22;
  uint64_t out_311 = out_32;
  uint64_t x_011 = x_02;
  uint64_t x_111 = x_12;
  uint64_t x_211 = x_22;
  uint64_t x_311 = x_32;
  uint64_t r_01 = out_011 ^ mask & (out_011 ^ x_011);
  uint64_t r_11 = out_111 ^ mask & (out_111 ^ x_111);
  uint64_t r_21 = out_211 ^ mask & (out_211 ^ x_211);
  uint64_t r_31 = out_311 ^ mask & (out_311 ^ x_311);
  uint64_t temp_01 = r_01;
  uint64_t temp_11 = r_11;
  uint64_t temp_21 = r_21;
  uint64_t temp_31 = r_31;
  y3_out[0U] = temp_01;
  y3_out[1U] = temp_11;
  y3_out[2U] = temp_21;
  y3_out[3U] = temp_31;
  uint64_t out_02 = z3_out[0U];
  uint64_t out_1 = z3_out[1U];
  uint64_t out_2 = z3_out[2U];
  uint64_t out_3 = z3_out[3U];
  uint64_t x_0 = p_z[0U];
  uint64_t x_1 = p_z[1U];
  uint64_t x_2 = p_z[2U];
  uint64_t x_3 = p_z[3U];
  uint64_t out_01 = out_02;
  uint64_t out_11 = out_1;
  uint64_t out_21 = out_2;
  uint64_t out_31 = out_3;
  uint64_t x_01 = x_0;
  uint64_t x_11 = x_1;
  uint64_t x_21 = x_2;
  uint64_t x_31 = x_3;
  uint64_t r_0 = out_01 ^ mask & (out_01 ^ x_01);
  uint64_t r_1 = out_11 ^ mask & (out_11 ^ x_11);
  uint64_t r_2 = out_21 ^ mask & (out_21 ^ x_21);
  uint64_t r_3 = out_31 ^ mask & (out_31 ^ x_31);
  uint64_t temp_0 = r_0;
  uint64_t temp_1 = r_1;
  uint64_t temp_2 = r_2;
  uint64_t temp_3 = r_3;
  z3_out[0U] = temp_0;
  z3_out[1U] = temp_1;
  z3_out[2U] = temp_2;
  z3_out[3U] = temp_3;
}

static uint64_t compare_felem(uint64_t *a, uint64_t *b)
{
  uint64_t a_0 = a[0U];
  uint64_t a_1 = a[1U];
  uint64_t a_2 = a[2U];
  uint64_t a_3 = a[3U];
  uint64_t b_0 = b[0U];
  uint64_t b_1 = b[1U];
  uint64_t b_2 = b[2U];
  uint64_t b_3 = b[3U];
  uint64_t r_0 = FStar_UInt64_eq_mask(a_0, b_0);
  uint64_t r_1 = FStar_UInt64_eq_mask(a_1, b_1);
  uint64_t r_2 = FStar_UInt64_eq_mask(a_2, b_2);
  uint64_t r_3 = FStar_UInt64_eq_mask(a_3, b_3);
  uint64_t r01 = r_0 & r_1;
  uint64_t r23 = r_2 & r_3;
  return r01 & r23;
}

void point_add(uint64_t *p, uint64_t *q, uint64_t *result, uint64_t *tempBuffer)
{
  uint64_t *z1 = p + (uint32_t)8U;
  uint64_t *z2 = q + (uint32_t)8U;
  uint64_t *tempBuffer16 = tempBuffer;
  uint64_t *u11 = tempBuffer + (uint32_t)16U;
  uint64_t *u2 = tempBuffer + (uint32_t)20U;
  uint64_t *s1 = tempBuffer + (uint32_t)24U;
  uint64_t *s2 = tempBuffer + (uint32_t)28U;
  uint64_t *h = tempBuffer + (uint32_t)32U;
  uint64_t *r = tempBuffer + (uint32_t)36U;
  uint64_t *uh = tempBuffer + (uint32_t)40U;
  uint64_t *hCube = tempBuffer + (uint32_t)44U;
  uint64_t *tempBuffer28 = tempBuffer + (uint32_t)60U;
  uint64_t *x1 = p;
  uint64_t *y1 = p + (uint32_t)4U;
  uint64_t *z11 = p + (uint32_t)8U;
  uint64_t *x2 = q;
  uint64_t *y2 = q + (uint32_t)4U;
  uint64_t *z210 = q + (uint32_t)8U;
  uint64_t *z2Square = tempBuffer16;
  uint64_t *z1Square = tempBuffer16 + (uint32_t)4U;
  uint64_t *z2Cube = tempBuffer16 + (uint32_t)8U;
  uint64_t *z1Cube = tempBuffer16 + (uint32_t)12U;
  Hacl_Impl_Gen_montgomery_square(z210, z2Square);
  Hacl_Impl_Gen_montgomery_square(z11, z1Square);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(z2Square,
    z210,
    z2Cube);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(z1Square,
    z11,
    z1Cube);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(x1, z2Square, u11);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(x2, z1Square, u2);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(y1, z2Cube, s1);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(y2, z1Cube, s2);
  uint64_t one1 = compare_felem(u11, u2);
  uint64_t two = compare_felem(s1, s2);
  uint64_t z1notZero = isZero_uint64(z1);
  uint64_t z2notZero = isZero_uint64(z2);
  uint64_t pointsInf = ~z1notZero & ~z2notZero;
  uint64_t onetwo = one1 & two;
  uint64_t result1 = onetwo & pointsInf;
  bool flag = result1 == (uint64_t)0xffffffffffffffffU;
  if (flag)
    point_double(p, result, tempBuffer);
  else
  {
    uint64_t *temp = tempBuffer16;
    Hacl_Impl_Gen_p256_sub(u2, u11, h);
    Hacl_Impl_Gen_p256_sub(s2, s1, r);
    Hacl_Impl_Gen_montgomery_square(h, temp);
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(u11, temp, uh);
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(h, temp, hCube);
    uint64_t *z11 = p + (uint32_t)8U;
    uint64_t *z21 = q + (uint32_t)8U;
    uint64_t *tempBuffer161 = tempBuffer28;
    uint64_t *x3_out1 = tempBuffer28 + (uint32_t)16U;
    uint64_t *y3_out1 = tempBuffer28 + (uint32_t)20U;
    uint64_t *z3_out1 = tempBuffer28 + (uint32_t)24U;
    uint64_t *rSquare = tempBuffer161;
    uint64_t *r_h = tempBuffer161 + (uint32_t)4U;
    uint64_t *twouh = tempBuffer161 + (uint32_t)8U;
    Hacl_Impl_Gen_montgomery_square(r, rSquare);
    Hacl_Impl_Gen_p256_sub(rSquare, hCube, r_h);
    multByTwo(uh, twouh);
    Hacl_Impl_Gen_p256_sub(r_h, twouh, x3_out1);
    uint64_t *s1hCube = tempBuffer161;
    uint64_t *u1hx3 = tempBuffer161 + (uint32_t)4U;
    uint64_t *ru1hx3 = tempBuffer161 + (uint32_t)8U;
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(s1, hCube, s1hCube);
    Hacl_Impl_Gen_p256_sub(uh, x3_out1, u1hx3);
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(r, u1hx3, ru1hx3);
    Hacl_Impl_Gen_p256_sub(ru1hx3, s1hCube, y3_out1);
    uint64_t *z1z2 = tempBuffer161;
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(z11, z21, z1z2);
    Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(h, z1z2, z3_out1);
    copy_point_conditional(x3_out1, y3_out1, z3_out1, q, p);
    copy_point_conditional(x3_out1, y3_out1, z3_out1, p, q);
    memcpy(result, x3_out1, (uint32_t)4U * sizeof x3_out1[0U]);
    memcpy(result + (uint32_t)4U, y3_out1, (uint32_t)4U * sizeof y3_out1[0U]);
    memcpy(result + (uint32_t)8U, z3_out1, (uint32_t)4U * sizeof z3_out1[0U]);
  }
}

void norm(uint64_t *p, uint64_t *resultPoint, uint64_t *tempBuffer)
{
  uint64_t *xf = p;
  uint64_t *yf = p + (uint32_t)4U;
  uint64_t *zf = p + (uint32_t)8U;
  uint64_t *resultX = resultPoint;
  uint64_t *resultY = resultPoint + (uint32_t)4U;
  uint64_t *resultZ = resultPoint + (uint32_t)8U;
  uint64_t *z2f = tempBuffer + (uint32_t)4U;
  uint64_t *z3f = tempBuffer + (uint32_t)8U;
  uint64_t *tempBuffer20 = tempBuffer + (uint32_t)12U;
  Hacl_Impl_Gen_montgomery_square(zf, z2f);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(z2f, zf, z3f);
  Hacl_Spec_P256_MontgomeryMultiplication_exponent(z2f, z2f, tempBuffer20);
  Hacl_Spec_P256_MontgomeryMultiplication_exponent(z3f, z3f, tempBuffer20);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(xf, z2f, z2f);
  Hacl_Spec_P256_MontgomeryMultiplication_montgomery_multiplication_buffer(yf, z3f, z3f);
  fromDomain(z2f, resultX);
  fromDomain(z3f, resultY);
  resultZ[0U] = (uint64_t)1U;
  resultZ[1U] = (uint64_t)0U;
  resultZ[2U] = (uint64_t)0U;
  resultZ[3U] = (uint64_t)0U;
}

void
montgomery_ladder(
  uint64_t *p,
  uint64_t *q,
  uint32_t scalarSize,
  uint8_t *scalar,
  uint64_t *tempBuffer
)
{
  for (uint32_t i = (uint32_t)0U; i < scalarSize; i = i + (uint32_t)1U)
  {
    uint32_t bit = scalarSize - i - (uint32_t)(krml_checked_int_t)1;
    uint64_t bit1 = (uint64_t)(scalar[bit / (uint32_t)8U] >> bit % (uint32_t)8U & (uint8_t)1U);
    Hacl_Spec_P256_MontgomeryMultiplication_cswap(bit1, p, q);
    point_add(q, p, q, tempBuffer);
    point_double(p, p, tempBuffer);
    Hacl_Spec_P256_MontgomeryMultiplication_cswap(bit1, p, q);
  }
}

void
scalarMultiplication(
  uint64_t *p,
  uint64_t *result,
  uint32_t scalarSize,
  uint8_t *scalar,
  uint64_t *tempBuffer
)
{
  uint32_t scalarSize1 = scalarSize * (uint32_t)(krml_checked_int_t)8;
  pointToDomain(p, result);
  uint64_t *q = tempBuffer;
  uint64_t *buff = tempBuffer + (uint32_t)12U;
  montgomery_ladder(q, result, scalarSize1, scalar, buff);
  norm(q, result, buff);
}

