/* MIT License
 *
 * Copyright (c) 2016-2020 INRIA, CMU and Microsoft Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "Hacl_Curve25519_64_Slow.h"

typedef struct K___u64_u64_u64_u64_s
{
  u64 fst;
  u64 snd;
  u64 thd;
  u64 f3;
}
K___u64_u64_u64_u64;

typedef struct K___u64_u64_u64_u64_u64_u64_u64_u64_s
{
  u64 fst;
  u64 snd;
  u64 thd;
  u64 f3;
  u64 f4;
  u64 f5;
  u64 f6;
  u64 f7;
}
K___u64_u64_u64_u64_u64_u64_u64_u64;

typedef struct K___u64_u64_s
{
  u64 fst;
  u64 snd;
}
K___u64_u64;

inline static K___u64_u64 Hacl_Spec_Curve25519_Field64_Core_addcarry(u64 x, u64 y, u64 cin)
{
  u64 res1 = x + cin;
  u64 c;
  if (res1 < cin)
    c = (u64)1U;
  else
    c = (u64)0U;
  {
    u64 res = res1 + y;
    u64 c1;
    if (res < res1)
      c1 = c + (u64)1U;
    else
      c1 = c;
    return ((K___u64_u64){ .fst = res, .snd = c1 });
  }
}

inline static K___u64_u64 Hacl_Spec_Curve25519_Field64_Core_subborrow(u64 x, u64 y, u64 cin)
{
  u64 res = x - y - cin;
  u64 c;
  if (cin == (u64)1U)
    if (x <= y)
      c = (u64)1U;
    else
      c = (u64)0U;
  else if (x < y)
    c = (u64)1U;
  else
    c = (u64)0U;
  return ((K___u64_u64){ .fst = res, .snd = c });
}

inline static K___u64_u64 Hacl_Spec_Curve25519_Field64_Core_mul64(u64 x, u64 y)
{
  uint128_t res = (uint128_t)x * y;
  return ((K___u64_u64){ .fst = (uint64_t)res, .snd = (uint64_t)(res >> (u32)64U) });
}

inline static K___u64_u64 Hacl_Spec_Curve25519_Field64_Core_add0carry(u64 x, u64 y)
{
  u64 res = x + y;
  u64 c;
  if (res < x)
    c = (u64)1U;
  else
    c = (u64)0U;
  return ((K___u64_u64){ .fst = res, .snd = c });
}

typedef struct K___u64_K___u64_u64_u64_u64_s
{
  u64 fst;
  K___u64_u64_u64_u64 snd;
}
K___u64_K___u64_u64_u64_u64;

static K___u64_K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_add1(K___u64_u64_u64_u64 f, u64 cin)
{
  u64 f0 = f.fst;
  u64 f1 = f.snd;
  u64 f2 = f.thd;
  u64 f3 = f.f3;
  K___u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_add0carry(f0, cin);
  u64 o0 = scrut.fst;
  u64 c0 = scrut.snd;
  K___u64_u64 scrut0 = Hacl_Spec_Curve25519_Field64_Core_add0carry(f1, c0);
  u64 o1 = scrut0.fst;
  u64 c1 = scrut0.snd;
  K___u64_u64 scrut1 = Hacl_Spec_Curve25519_Field64_Core_add0carry(f2, c1);
  u64 o2 = scrut1.fst;
  u64 c2 = scrut1.snd;
  K___u64_u64 scrut2 = Hacl_Spec_Curve25519_Field64_Core_add0carry(f3, c2);
  u64 o3 = scrut2.fst;
  u64 c3 = scrut2.snd;
  K___u64_u64_u64_u64 out = { .fst = o0, .snd = o1, .thd = o2, .f3 = o3 };
  return ((K___u64_K___u64_u64_u64_u64){ .fst = c3, .snd = out });
}

static K___u64_K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_sub1(K___u64_u64_u64_u64 f, u64 cin)
{
  u64 f0 = f.fst;
  u64 f1 = f.snd;
  u64 f2 = f.thd;
  u64 f3 = f.f3;
  K___u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_subborrow(f0, cin, (u64)0U);
  u64 o0 = scrut.fst;
  u64 c0 = scrut.snd;
  K___u64_u64 scrut0 = Hacl_Spec_Curve25519_Field64_Core_subborrow(f1, (u64)0U, c0);
  u64 o1 = scrut0.fst;
  u64 c1 = scrut0.snd;
  K___u64_u64 scrut1 = Hacl_Spec_Curve25519_Field64_Core_subborrow(f2, (u64)0U, c1);
  u64 o2 = scrut1.fst;
  u64 c2 = scrut1.snd;
  K___u64_u64 scrut2 = Hacl_Spec_Curve25519_Field64_Core_subborrow(f3, (u64)0U, c2);
  u64 o3 = scrut2.fst;
  u64 c3 = scrut2.snd;
  K___u64_u64_u64_u64 out = { .fst = o0, .snd = o1, .thd = o2, .f3 = o3 };
  return ((K___u64_K___u64_u64_u64_u64){ .fst = c3, .snd = out });
}

static K___u64_K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_mul1(K___u64_u64_u64_u64 f, u64 u)
{
  u64 f0 = f.fst;
  u64 f1 = f.snd;
  u64 f2 = f.thd;
  u64 f3 = f.f3;
  K___u64_u64 scrut0 = Hacl_Spec_Curve25519_Field64_Core_mul64(f0, u);
  u64 l0 = scrut0.fst;
  u64 h0 = scrut0.snd;
  K___u64_u64 scrut1 = Hacl_Spec_Curve25519_Field64_Core_mul64(f1, u);
  u64 l1 = scrut1.fst;
  u64 h1 = scrut1.snd;
  K___u64_u64 scrut2 = Hacl_Spec_Curve25519_Field64_Core_mul64(f2, u);
  u64 l2 = scrut2.fst;
  u64 h2 = scrut2.snd;
  K___u64_u64 scrut3 = Hacl_Spec_Curve25519_Field64_Core_mul64(f3, u);
  u64 l3 = scrut3.fst;
  u64 h3 = scrut3.snd;
  u64 o0 = l0;
  K___u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_addcarry(l1, h0, (u64)0U);
  u64 o1 = scrut.fst;
  u64 c0 = scrut.snd;
  K___u64_u64 scrut4 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l2, h1, c0);
  u64 o2 = scrut4.fst;
  u64 c1 = scrut4.snd;
  K___u64_u64 scrut5 = Hacl_Spec_Curve25519_Field64_Core_addcarry(l3, h2, c1);
  u64 o3 = scrut5.fst;
  u64 c2 = scrut5.snd;
  K___u64_u64_u64_u64 out = { .fst = o0, .snd = o1, .thd = o2, .f3 = o3 };
  u64 c3 = h3 + c2;
  return ((K___u64_K___u64_u64_u64_u64){ .fst = c3, .snd = out });
}

static K___u64_K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_mul1_add(
  K___u64_u64_u64_u64 f1,
  u64 u2,
  K___u64_u64_u64_u64 f3
)
{
  K___u64_K___u64_u64_u64_u64 scrut0 = Hacl_Spec_Curve25519_Field64_Core_mul1(f1, u2);
  u64 c = scrut0.fst;
  K___u64_u64_u64_u64 out0 = scrut0.snd;
  u64 o0 = out0.fst;
  u64 o1 = out0.snd;
  u64 o2 = out0.thd;
  u64 o3 = out0.f3;
  u64 f30 = f3.fst;
  u64 f31 = f3.snd;
  u64 f32 = f3.thd;
  u64 f33 = f3.f3;
  K___u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_addcarry(f30, o0, (u64)0U);
  u64 o0_ = scrut.fst;
  u64 c0 = scrut.snd;
  K___u64_u64 scrut1 = Hacl_Spec_Curve25519_Field64_Core_addcarry(f31, o1, c0);
  u64 o1_ = scrut1.fst;
  u64 c1 = scrut1.snd;
  K___u64_u64 scrut2 = Hacl_Spec_Curve25519_Field64_Core_addcarry(f32, o2, c1);
  u64 o2_ = scrut2.fst;
  u64 c2 = scrut2.snd;
  K___u64_u64 scrut3 = Hacl_Spec_Curve25519_Field64_Core_addcarry(f33, o3, c2);
  u64 o3_ = scrut3.fst;
  u64 c3 = scrut3.snd;
  K___u64_u64_u64_u64 out = { .fst = o0_, .snd = o1_, .thd = o2_, .f3 = o3_ };
  u64 c4 = c + c3;
  return ((K___u64_K___u64_u64_u64_u64){ .fst = c4, .snd = out });
}

static K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_carry_pass(K___u64_u64_u64_u64 f, u64 cin)
{
  K___u64_K___u64_u64_u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_add1(f, cin * (u64)38U);
  u64 carry = scrut.fst;
  K___u64_u64_u64_u64 out0 = scrut.snd;
  u64 o0 = out0.fst;
  u64 o1 = out0.snd;
  u64 o2 = out0.thd;
  u64 o3 = out0.f3;
  u64 o0_ = o0 + carry * (u64)38U;
  return ((K___u64_u64_u64_u64){ .fst = o0_, .snd = o1, .thd = o2, .f3 = o3 });
}

static K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_carry_wide(K___u64_u64_u64_u64_u64_u64_u64_u64 f)
{
  u64 f0 = f.fst;
  u64 f1 = f.snd;
  u64 f2 = f.thd;
  u64 f3 = f.f3;
  u64 f4 = f.f4;
  u64 f5 = f.f5;
  u64 f6 = f.f6;
  u64 f7 = f.f7;
  K___u64_K___u64_u64_u64_u64
  scrut =
    Hacl_Spec_Curve25519_Field64_Core_mul1_add((
        (K___u64_u64_u64_u64){ .fst = f4, .snd = f5, .thd = f6, .f3 = f7 }
      ),
      (u64)38U,
      ((K___u64_u64_u64_u64){ .fst = f0, .snd = f1, .thd = f2, .f3 = f3 }));
  u64 c0 = scrut.fst;
  K___u64_u64_u64_u64 out0 = scrut.snd;
  K___u64_u64_u64_u64 out1 = Hacl_Spec_Curve25519_Field64_Core_carry_pass(out0, c0);
  return out1;
}

static K___u64_K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_add4(K___u64_u64_u64_u64 f1, K___u64_u64_u64_u64 f2)
{
  u64 f10 = f1.fst;
  u64 f11 = f1.snd;
  u64 f12 = f1.thd;
  u64 f13 = f1.f3;
  u64 f20 = f2.fst;
  u64 f21 = f2.snd;
  u64 f22 = f2.thd;
  u64 f23 = f2.f3;
  K___u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_addcarry(f10, f20, (u64)0U);
  u64 o0 = scrut.fst;
  u64 c0 = scrut.snd;
  K___u64_u64 scrut0 = Hacl_Spec_Curve25519_Field64_Core_addcarry(f11, f21, c0);
  u64 o1 = scrut0.fst;
  u64 c1 = scrut0.snd;
  K___u64_u64 scrut1 = Hacl_Spec_Curve25519_Field64_Core_addcarry(f12, f22, c1);
  u64 o2 = scrut1.fst;
  u64 c2 = scrut1.snd;
  K___u64_u64 scrut2 = Hacl_Spec_Curve25519_Field64_Core_addcarry(f13, f23, c2);
  u64 o3 = scrut2.fst;
  u64 c3 = scrut2.snd;
  K___u64_u64_u64_u64 out = { .fst = o0, .snd = o1, .thd = o2, .f3 = o3 };
  return ((K___u64_K___u64_u64_u64_u64){ .fst = c3, .snd = out });
}

static K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_fadd4(K___u64_u64_u64_u64 f1, K___u64_u64_u64_u64 f2)
{
  K___u64_K___u64_u64_u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_add4(f1, f2);
  u64 c0 = scrut.fst;
  K___u64_u64_u64_u64 out0 = scrut.snd;
  K___u64_u64_u64_u64 out = Hacl_Spec_Curve25519_Field64_Core_carry_pass(out0, c0);
  return out;
}

static K___u64_K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_sub4(K___u64_u64_u64_u64 f1, K___u64_u64_u64_u64 f2)
{
  u64 f10 = f1.fst;
  u64 f11 = f1.snd;
  u64 f12 = f1.thd;
  u64 f13 = f1.f3;
  u64 f20 = f2.fst;
  u64 f21 = f2.snd;
  u64 f22 = f2.thd;
  u64 f23 = f2.f3;
  K___u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_subborrow(f10, f20, (u64)0U);
  u64 o0 = scrut.fst;
  u64 c0 = scrut.snd;
  K___u64_u64 scrut0 = Hacl_Spec_Curve25519_Field64_Core_subborrow(f11, f21, c0);
  u64 o1 = scrut0.fst;
  u64 c1 = scrut0.snd;
  K___u64_u64 scrut1 = Hacl_Spec_Curve25519_Field64_Core_subborrow(f12, f22, c1);
  u64 o2 = scrut1.fst;
  u64 c2 = scrut1.snd;
  K___u64_u64 scrut2 = Hacl_Spec_Curve25519_Field64_Core_subborrow(f13, f23, c2);
  u64 o3 = scrut2.fst;
  u64 c3 = scrut2.snd;
  K___u64_u64_u64_u64 out = { .fst = o0, .snd = o1, .thd = o2, .f3 = o3 };
  return ((K___u64_K___u64_u64_u64_u64){ .fst = c3, .snd = out });
}

static K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_fsub4(K___u64_u64_u64_u64 f1, K___u64_u64_u64_u64 f2)
{
  K___u64_K___u64_u64_u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_sub4(f1, f2);
  u64 c0 = scrut.fst;
  K___u64_u64_u64_u64 out0 = scrut.snd;
  K___u64_K___u64_u64_u64_u64
  scrut0 = Hacl_Spec_Curve25519_Field64_Core_sub1(out0, c0 * (u64)38U);
  u64 c1 = scrut0.fst;
  K___u64_u64_u64_u64 out1 = scrut0.snd;
  u64 o0 = out1.fst;
  u64 o1 = out1.snd;
  u64 o2 = out1.thd;
  u64 o3 = out1.f3;
  u64 o0_ = o0 - c1 * (u64)38U;
  return ((K___u64_u64_u64_u64){ .fst = o0_, .snd = o1, .thd = o2, .f3 = o3 });
}

static K___u64_u64_u64_u64_u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_mul4(K___u64_u64_u64_u64 f, K___u64_u64_u64_u64 r)
{
  u64 f0 = f.fst;
  u64 f1 = f.snd;
  u64 f2 = f.thd;
  u64 f3 = f.f3;
  K___u64_K___u64_u64_u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_mul1(r, f0);
  u64 c0 = scrut.fst;
  K___u64_u64_u64_u64 out0 = scrut.snd;
  u64 o00 = out0.fst;
  u64 o01 = out0.snd;
  u64 o02 = out0.thd;
  u64 o03 = out0.f3;
  K___u64_K___u64_u64_u64_u64
  scrut0 =
    Hacl_Spec_Curve25519_Field64_Core_mul1_add(r,
      f1,
      ((K___u64_u64_u64_u64){ .fst = o01, .snd = o02, .thd = o03, .f3 = c0 }));
  u64 c1 = scrut0.fst;
  K___u64_u64_u64_u64 out1 = scrut0.snd;
  u64 o11 = out1.fst;
  u64 o12 = out1.snd;
  u64 o13 = out1.thd;
  u64 o14 = out1.f3;
  K___u64_K___u64_u64_u64_u64
  scrut1 =
    Hacl_Spec_Curve25519_Field64_Core_mul1_add(r,
      f2,
      ((K___u64_u64_u64_u64){ .fst = o12, .snd = o13, .thd = o14, .f3 = c1 }));
  u64 c2 = scrut1.fst;
  K___u64_u64_u64_u64 out2 = scrut1.snd;
  u64 o22 = out2.fst;
  u64 o23 = out2.snd;
  u64 o24 = out2.thd;
  u64 o25 = out2.f3;
  K___u64_K___u64_u64_u64_u64
  scrut2 =
    Hacl_Spec_Curve25519_Field64_Core_mul1_add(r,
      f3,
      ((K___u64_u64_u64_u64){ .fst = o23, .snd = o24, .thd = o25, .f3 = c2 }));
  u64 c3 = scrut2.fst;
  K___u64_u64_u64_u64 out3 = scrut2.snd;
  u64 o33 = out3.fst;
  u64 o34 = out3.snd;
  u64 o35 = out3.thd;
  u64 o36 = out3.f3;
  u64 o37 = c3;
  return
    (
      (K___u64_u64_u64_u64_u64_u64_u64_u64){
        .fst = o00,
        .snd = o11,
        .thd = o22,
        .f3 = o33,
        .f4 = o34,
        .f5 = o35,
        .f6 = o36,
        .f7 = o37
      }
    );
}

static K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_fmul4(K___u64_u64_u64_u64 f1, K___u64_u64_u64_u64 r)
{
  K___u64_u64_u64_u64_u64_u64_u64_u64 tmp = Hacl_Spec_Curve25519_Field64_Core_mul4(f1, r);
  K___u64_u64_u64_u64 out = Hacl_Spec_Curve25519_Field64_Core_carry_wide(tmp);
  return out;
}

static K___u64_u64_u64_u64
Hacl_Spec_Curve25519_Field64_Core_fmul14(K___u64_u64_u64_u64 f1, u64 f2)
{
  K___u64_K___u64_u64_u64_u64 scrut = Hacl_Spec_Curve25519_Field64_Core_mul1(f1, f2);
  u64 c0 = scrut.fst;
  K___u64_u64_u64_u64 out0 = scrut.snd;
  K___u64_u64_u64_u64 out1 = Hacl_Spec_Curve25519_Field64_Core_carry_pass(out0, c0);
  return out1;
}

inline static u64 Hacl_Impl_Curve25519_Field64_Hacl_add1(u64 *out, u64 *f1, u64 f2)
{
  u64 f10 = f1[0U];
  u64 f11 = f1[1U];
  u64 f12 = f1[2U];
  u64 f13 = f1[3U];
  K___u64_K___u64_u64_u64_u64
  scrut =
    Hacl_Spec_Curve25519_Field64_Core_add1((
        (K___u64_u64_u64_u64){ .fst = f10, .snd = f11, .thd = f12, .f3 = f13 }
      ),
      f2);
  u64 o3 = scrut.snd.f3;
  u64 o2 = scrut.snd.thd;
  u64 o1 = scrut.snd.snd;
  u64 o0 = scrut.snd.fst;
  u64 carry = scrut.fst;
  out[0U] = o0;
  out[1U] = o1;
  out[2U] = o2;
  out[3U] = o3;
  return carry;
}

inline static void Hacl_Impl_Curve25519_Field64_Hacl_fadd(u64 *out, u64 *f1, u64 *f2)
{
  u64 f10 = f1[0U];
  u64 f11 = f1[1U];
  u64 f12 = f1[2U];
  u64 f13 = f1[3U];
  u64 f20 = f2[0U];
  u64 f21 = f2[1U];
  u64 f22 = f2[2U];
  u64 f23 = f2[3U];
  K___u64_u64_u64_u64
  scrut =
    Hacl_Spec_Curve25519_Field64_Core_fadd4((
        (K___u64_u64_u64_u64){ .fst = f10, .snd = f11, .thd = f12, .f3 = f13 }
      ),
      ((K___u64_u64_u64_u64){ .fst = f20, .snd = f21, .thd = f22, .f3 = f23 }));
  u64 o0 = scrut.fst;
  u64 o1 = scrut.snd;
  u64 o2 = scrut.thd;
  u64 o3 = scrut.f3;
  out[0U] = o0;
  out[1U] = o1;
  out[2U] = o2;
  out[3U] = o3;
}

inline static void Hacl_Impl_Curve25519_Field64_Hacl_fsub(u64 *out, u64 *f1, u64 *f2)
{
  u64 f10 = f1[0U];
  u64 f11 = f1[1U];
  u64 f12 = f1[2U];
  u64 f13 = f1[3U];
  u64 f20 = f2[0U];
  u64 f21 = f2[1U];
  u64 f22 = f2[2U];
  u64 f23 = f2[3U];
  K___u64_u64_u64_u64
  scrut =
    Hacl_Spec_Curve25519_Field64_Core_fsub4((
        (K___u64_u64_u64_u64){ .fst = f10, .snd = f11, .thd = f12, .f3 = f13 }
      ),
      ((K___u64_u64_u64_u64){ .fst = f20, .snd = f21, .thd = f22, .f3 = f23 }));
  u64 o0 = scrut.fst;
  u64 o1 = scrut.snd;
  u64 o2 = scrut.thd;
  u64 o3 = scrut.f3;
  out[0U] = o0;
  out[1U] = o1;
  out[2U] = o2;
  out[3U] = o3;
}

inline static void Hacl_Impl_Curve25519_Field64_Hacl_fmul(u64 *out, u64 *f1, u64 *f2, u64 *tmp)
{
  u64 f10 = f1[0U];
  u64 f11 = f1[1U];
  u64 f12 = f1[2U];
  u64 f13 = f1[3U];
  u64 f20 = f2[0U];
  u64 f21 = f2[1U];
  u64 f22 = f2[2U];
  u64 f23 = f2[3U];
  K___u64_u64_u64_u64
  scrut =
    Hacl_Spec_Curve25519_Field64_Core_fmul4((
        (K___u64_u64_u64_u64){ .fst = f10, .snd = f11, .thd = f12, .f3 = f13 }
      ),
      ((K___u64_u64_u64_u64){ .fst = f20, .snd = f21, .thd = f22, .f3 = f23 }));
  u64 o0 = scrut.fst;
  u64 o1 = scrut.snd;
  u64 o2 = scrut.thd;
  u64 o3 = scrut.f3;
  out[0U] = o0;
  out[1U] = o1;
  out[2U] = o2;
  out[3U] = o3;
}

inline static void
Hacl_Impl_Curve25519_Field64_Hacl_fmul2(u64 *out, u64 *f1, u64 *f2, u64 *tmp)
{
  u64 *out1 = out;
  u64 *out2 = out + (u32)4U;
  u64 *f11 = f1;
  u64 *f12 = f1 + (u32)4U;
  u64 *f21 = f2;
  u64 *f22 = f2 + (u32)4U;
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(out1, f11, f21, tmp);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(out2, f12, f22, tmp);
}

inline static void Hacl_Impl_Curve25519_Field64_Hacl_fmul1(u64 *out, u64 *f1, u64 f2)
{
  u64 f10 = f1[0U];
  u64 f11 = f1[1U];
  u64 f12 = f1[2U];
  u64 f13 = f1[3U];
  K___u64_u64_u64_u64
  scrut =
    Hacl_Spec_Curve25519_Field64_Core_fmul14((
        (K___u64_u64_u64_u64){ .fst = f10, .snd = f11, .thd = f12, .f3 = f13 }
      ),
      f2);
  u64 o0 = scrut.fst;
  u64 o1 = scrut.snd;
  u64 o2 = scrut.thd;
  u64 o3 = scrut.f3;
  out[0U] = o0;
  out[1U] = o1;
  out[2U] = o2;
  out[3U] = o3;
}

inline static void Hacl_Impl_Curve25519_Field64_Hacl_fsqr(u64 *out, u64 *f1, u64 *tmp)
{
  u64 tmp1[16U] = { 0U };
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(out, f1, f1, tmp1);
}

inline static void Hacl_Impl_Curve25519_Field64_Hacl_fsqr2(u64 *out, u64 *f, u64 *tmp)
{
  Hacl_Impl_Curve25519_Field64_Hacl_fmul2(out, f, f, tmp);
}

inline static void Hacl_Impl_Curve25519_Field64_Hacl_cswap2(u64 bit, u64 *p1, u64 *p2)
{
  u64 mask = (u64)0U - bit;
  u32 i;
  for (i = (u32)0U; i < (u32)8U; i = i + (u32)1U)
  {
    u64 dummy = mask & (p1[i] ^ p2[i]);
    p1[i] = p1[i] ^ dummy;
    p2[i] = p2[i] ^ dummy;
  }
}

static u8
Hacl_Curve25519_64_Slow_g25519[32U] =
  {
    (u8)9U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U,
    (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U,
    (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U, (u8)0U
  };

static void Hacl_Curve25519_64_Slow_point_add_and_double(u64 *q, u64 *p01_tmp1, u64 *tmp2)
{
  u64 *nq = p01_tmp1;
  u64 *nq_p1 = p01_tmp1 + (u32)8U;
  u64 *tmp1 = p01_tmp1 + (u32)16U;
  u64 *x1 = q;
  u64 *x2 = nq;
  u64 *z2 = nq + (u32)4U;
  u64 *z3 = nq_p1 + (u32)4U;
  u64 *a = tmp1;
  u64 *b = tmp1 + (u32)4U;
  u64 *ab = tmp1;
  u64 *dc = tmp1 + (u32)8U;
  u64 *x3;
  u64 *z31;
  u64 *d0;
  u64 *c0;
  u64 *a1;
  u64 *b1;
  u64 *d;
  u64 *c;
  u64 *ab1;
  u64 *dc1;
  Hacl_Impl_Curve25519_Field64_Hacl_fadd(a, x2, z2);
  Hacl_Impl_Curve25519_Field64_Hacl_fsub(b, x2, z2);
  x3 = nq_p1;
  z31 = nq_p1 + (u32)4U;
  d0 = dc;
  c0 = dc + (u32)4U;
  Hacl_Impl_Curve25519_Field64_Hacl_fadd(c0, x3, z31);
  Hacl_Impl_Curve25519_Field64_Hacl_fsub(d0, x3, z31);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul2(dc, dc, ab, tmp2);
  Hacl_Impl_Curve25519_Field64_Hacl_fadd(x3, d0, c0);
  Hacl_Impl_Curve25519_Field64_Hacl_fsub(z31, d0, c0);
  a1 = tmp1;
  b1 = tmp1 + (u32)4U;
  d = tmp1 + (u32)8U;
  c = tmp1 + (u32)12U;
  ab1 = tmp1;
  dc1 = tmp1 + (u32)8U;
  Hacl_Impl_Curve25519_Field64_Hacl_fsqr2(dc1, ab1, tmp2);
  Hacl_Impl_Curve25519_Field64_Hacl_fsqr2(nq_p1, nq_p1, tmp2);
  a1[0U] = c[0U];
  a1[1U] = c[1U];
  a1[2U] = c[2U];
  a1[3U] = c[3U];
  Hacl_Impl_Curve25519_Field64_Hacl_fsub(c, d, c);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul1(b1, c, (u64)121665U);
  Hacl_Impl_Curve25519_Field64_Hacl_fadd(b1, b1, d);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul2(nq, dc1, ab1, tmp2);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(z3, z3, x1, tmp2);
}

static void Hacl_Curve25519_64_Slow_point_double(u64 *nq, u64 *tmp1, u64 *tmp2)
{
  u64 *x2 = nq;
  u64 *z2 = nq + (u32)4U;
  u64 *a = tmp1;
  u64 *b = tmp1 + (u32)4U;
  u64 *d = tmp1 + (u32)8U;
  u64 *c = tmp1 + (u32)12U;
  u64 *ab = tmp1;
  u64 *dc = tmp1 + (u32)8U;
  Hacl_Impl_Curve25519_Field64_Hacl_fadd(a, x2, z2);
  Hacl_Impl_Curve25519_Field64_Hacl_fsub(b, x2, z2);
  Hacl_Impl_Curve25519_Field64_Hacl_fsqr2(dc, ab, tmp2);
  a[0U] = c[0U];
  a[1U] = c[1U];
  a[2U] = c[2U];
  a[3U] = c[3U];
  Hacl_Impl_Curve25519_Field64_Hacl_fsub(c, d, c);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul1(b, c, (u64)121665U);
  Hacl_Impl_Curve25519_Field64_Hacl_fadd(b, b, d);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul2(nq, dc, ab, tmp2);
}

static void Hacl_Curve25519_64_Slow_montgomery_ladder(u64 *out, u8 *key, u64 *init1)
{
  u64 tmp2[16U] = { 0U };
  u64 p01_tmp1_swap[33U] = { 0U };
  u64 *p0 = p01_tmp1_swap;
  u64 *p01 = p01_tmp1_swap;
  u64 *p03 = p01;
  u64 *p11 = p01 + (u32)8U;
  u64 *x0;
  u64 *z0;
  u64 *p01_tmp1;
  u64 *p01_tmp11;
  u64 *nq10;
  u64 *nq_p11;
  u64 *swap1;
  u64 sw0;
  u64 *nq1;
  u64 *tmp1;
  memcpy(p11, init1, (u32)8U * sizeof init1[0U]);
  x0 = p03;
  z0 = p03 + (u32)4U;
  x0[0U] = (u64)1U;
  x0[1U] = (u64)0U;
  x0[2U] = (u64)0U;
  x0[3U] = (u64)0U;
  z0[0U] = (u64)0U;
  z0[1U] = (u64)0U;
  z0[2U] = (u64)0U;
  z0[3U] = (u64)0U;
  p01_tmp1 = p01_tmp1_swap;
  p01_tmp11 = p01_tmp1_swap;
  nq10 = p01_tmp1_swap;
  nq_p11 = p01_tmp1_swap + (u32)8U;
  swap1 = p01_tmp1_swap + (u32)32U;
  Hacl_Impl_Curve25519_Field64_Hacl_cswap2((u64)1U, nq10, nq_p11);
  Hacl_Curve25519_64_Slow_point_add_and_double(init1, p01_tmp11, tmp2);
  swap1[0U] = (u64)1U;
  {
    u32 i;
    for (i = (u32)0U; i < (u32)251U; i = i + (u32)1U)
    {
      u64 *p01_tmp12 = p01_tmp1_swap;
      u64 *swap2 = p01_tmp1_swap + (u32)32U;
      u64 *nq2 = p01_tmp12;
      u64 *nq_p12 = p01_tmp12 + (u32)8U;
      u64 bit = (u64)(key[((u32)253U - i) / (u32)8U] >> ((u32)253U - i) % (u32)8U & (u8)1U);
      u64 sw = swap2[0U] ^ bit;
      Hacl_Impl_Curve25519_Field64_Hacl_cswap2(sw, nq2, nq_p12);
      Hacl_Curve25519_64_Slow_point_add_and_double(init1, p01_tmp12, tmp2);
      swap2[0U] = bit;
    }
  }
  sw0 = swap1[0U];
  Hacl_Impl_Curve25519_Field64_Hacl_cswap2(sw0, nq10, nq_p11);
  nq1 = p01_tmp1;
  tmp1 = p01_tmp1 + (u32)16U;
  Hacl_Curve25519_64_Slow_point_double(nq1, tmp1, tmp2);
  Hacl_Curve25519_64_Slow_point_double(nq1, tmp1, tmp2);
  Hacl_Curve25519_64_Slow_point_double(nq1, tmp1, tmp2);
  memcpy(out, p0, (u32)8U * sizeof p0[0U]);
}

static void Hacl_Curve25519_64_Slow_fsquare_times(u64 *o, u64 *inp, u64 *tmp, u32 n1)
{
  u32 i;
  Hacl_Impl_Curve25519_Field64_Hacl_fsqr(o, inp, tmp);
  for (i = (u32)0U; i < n1 - (u32)1U; i = i + (u32)1U)
    Hacl_Impl_Curve25519_Field64_Hacl_fsqr(o, o, tmp);
}

static void Hacl_Curve25519_64_Slow_finv(u64 *o, u64 *i, u64 *tmp)
{
  u64 t1[16U] = { 0U };
  u64 *a0 = t1;
  u64 *b = t1 + (u32)4U;
  u64 *c = t1 + (u32)8U;
  u64 *t00 = t1 + (u32)12U;
  u64 *tmp1 = tmp;
  u64 *a;
  u64 *t0;
  Hacl_Curve25519_64_Slow_fsquare_times(a0, i, tmp1, (u32)1U);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, a0, tmp1, (u32)2U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(b, t00, i, tmp);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(a0, b, a0, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, a0, tmp1, (u32)1U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(b, t00, b, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, b, tmp1, (u32)5U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(b, t00, b, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, b, tmp1, (u32)10U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(c, t00, b, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, c, tmp1, (u32)20U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(t00, t00, c, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, t00, tmp1, (u32)10U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(b, t00, b, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, b, tmp1, (u32)50U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(c, t00, b, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, c, tmp1, (u32)100U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(t00, t00, c, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, t00, tmp1, (u32)50U);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(t00, t00, b, tmp);
  Hacl_Curve25519_64_Slow_fsquare_times(t00, t00, tmp1, (u32)5U);
  a = t1;
  t0 = t1 + (u32)12U;
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(o, t0, a, tmp);
}

static void Hacl_Curve25519_64_Slow_store_felem(u64 *b, u64 *f)
{
  u64 f30 = f[3U];
  u64 top_bit0 = f30 >> (u32)63U;
  u64 carry0;
  u64 f31;
  u64 top_bit;
  u64 carry;
  u64 f0;
  u64 f1;
  u64 f2;
  u64 f3;
  u64 m0;
  u64 m1;
  u64 m2;
  u64 m3;
  u64 mask;
  u64 f0_;
  u64 f1_;
  u64 f2_;
  u64 f3_;
  u64 o0;
  u64 o1;
  u64 o2;
  u64 o3;
  f[3U] = f30 & (u64)0x7fffffffffffffffU;
  carry0 = Hacl_Impl_Curve25519_Field64_Hacl_add1(f, f, (u64)19U * top_bit0);
  f31 = f[3U];
  top_bit = f31 >> (u32)63U;
  f[3U] = f31 & (u64)0x7fffffffffffffffU;
  carry = Hacl_Impl_Curve25519_Field64_Hacl_add1(f, f, (u64)19U * top_bit);
  f0 = f[0U];
  f1 = f[1U];
  f2 = f[2U];
  f3 = f[3U];
  m0 = FStar_UInt64_gte_mask(f0, (u64)0xffffffffffffffedU);
  m1 = FStar_UInt64_eq_mask(f1, (u64)0xffffffffffffffffU);
  m2 = FStar_UInt64_eq_mask(f2, (u64)0xffffffffffffffffU);
  m3 = FStar_UInt64_eq_mask(f3, (u64)0x7fffffffffffffffU);
  mask = ((m0 & m1) & m2) & m3;
  f0_ = f0 - (mask & (u64)0xffffffffffffffedU);
  f1_ = f1 - (mask & (u64)0xffffffffffffffffU);
  f2_ = f2 - (mask & (u64)0xffffffffffffffffU);
  f3_ = f3 - (mask & (u64)0x7fffffffffffffffU);
  o0 = f0_;
  o1 = f1_;
  o2 = f2_;
  o3 = f3_;
  b[0U] = o0;
  b[1U] = o1;
  b[2U] = o2;
  b[3U] = o3;
}

static void Hacl_Curve25519_64_Slow_encode_point(u8 *o, u64 *i)
{
  u64 *x = i;
  u64 *z = i + (u32)4U;
  u64 tmp[4U] = { 0U };
  u64 u64s[4U] = { 0U };
  u64 tmp_w[16U] = { 0U };
  Hacl_Curve25519_64_Slow_finv(tmp, z, tmp_w);
  Hacl_Impl_Curve25519_Field64_Hacl_fmul(tmp, tmp, x, tmp_w);
  Hacl_Curve25519_64_Slow_store_felem(u64s, tmp);
  {
    u32 i0;
    for (i0 = (u32)0U; i0 < (u32)4U; i0 = i0 + (u32)1U)
      store64_le(o + i0 * (u32)8U, u64s[i0]);
  }
}

void Hacl_Curve25519_64_Slow_scalarmult(u8 *out, u8 *priv, u8 *pub)
{
  u64 init1[8U] = { 0U };
  u64 tmp[4U] = { 0U };
  u64 tmp3;
  u64 *x;
  u64 *z;
  {
    u32 i;
    for (i = (u32)0U; i < (u32)4U; i = i + (u32)1U)
    {
      u64 *os = tmp;
      u8 *bj = pub + i * (u32)8U;
      u64 u = load64_le(bj);
      u64 r = u;
      u64 x0 = r;
      os[i] = x0;
    }
  }
  tmp3 = tmp[3U];
  tmp[3U] = tmp3 & (u64)0x7fffffffffffffffU;
  x = init1;
  z = init1 + (u32)4U;
  z[0U] = (u64)1U;
  z[1U] = (u64)0U;
  z[2U] = (u64)0U;
  z[3U] = (u64)0U;
  x[0U] = tmp[0U];
  x[1U] = tmp[1U];
  x[2U] = tmp[2U];
  x[3U] = tmp[3U];
  Hacl_Curve25519_64_Slow_montgomery_ladder(init1, priv, init1);
  Hacl_Curve25519_64_Slow_encode_point(out, init1);
}

void Hacl_Curve25519_64_Slow_secret_to_public(u8 *pub, u8 *priv)
{
  u8 basepoint[32U] = { 0U };
  {
    u32 i;
    for (i = (u32)0U; i < (u32)32U; i = i + (u32)1U)
    {
      u8 *os = basepoint;
      u8 x = Hacl_Curve25519_64_Slow_g25519[i];
      os[i] = x;
    }
  }
  Hacl_Curve25519_64_Slow_scalarmult(pub, priv, basepoint);
}

bool Hacl_Curve25519_64_Slow_ecdh(u8 *out, u8 *priv, u8 *pub)
{
  u8 zeros1[32U] = { 0U };
  Hacl_Curve25519_64_Slow_scalarmult(out, priv, pub);
  {
    u8 res = (u8)255U;
    u8 z;
    bool r;
    {
      u32 i;
      for (i = (u32)0U; i < (u32)32U; i = i + (u32)1U)
      {
        u8 uu____0 = FStar_UInt8_eq_mask(out[i], zeros1[i]);
        res = uu____0 & res;
      }
    }
    z = res;
    r = z == (u8)255U;
    return !r;
  }
}

