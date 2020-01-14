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

#include "libintvector.h"
#include "kremlin/internal/types.h"
#include "kremlin/lowstar_endianness.h"
#include <string.h>
#include "kremlin/internal/target.h"

#ifndef __Hacl_Kremlib_H
#define __Hacl_Kremlib_H




inline static u8 FStar_UInt8_eq_mask(u8 a, u8 b);

inline static u64 FStar_UInt64_eq_mask(u64 a, u64 b);

inline static u64 FStar_UInt64_gte_mask(u64 a, u64 b);

inline static uint128_t FStar_UInt128_add(uint128_t a, uint128_t b);

inline static uint128_t FStar_UInt128_add_mod(uint128_t a, uint128_t b);

inline static uint128_t FStar_UInt128_logor(uint128_t a, uint128_t b);

inline static uint128_t FStar_UInt128_shift_left(uint128_t a, u32 s);

inline static uint128_t FStar_UInt128_shift_right(uint128_t a, u32 s);

inline static uint128_t FStar_UInt128_uint64_to_uint128(u64 a);

inline static u64 FStar_UInt128_uint128_to_uint64(uint128_t a);

inline static uint128_t FStar_UInt128_mul_wide(u64 x, u64 y);

inline static void store128_be(u8 *x0, uint128_t x1);

inline static uint128_t load128_be(u8 *x0);

#define __Hacl_Kremlib_H_DEFINED
#endif
