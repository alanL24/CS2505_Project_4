#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits.h"

test_rec test_set[] = {
/* Copyright (C) 1991-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
 {"isTmin", (funct_t) isTmin, (funct_t) test_isTmin, 1, "! ~ & ^ | +", 10, 5,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//2
 {"implication", (funct_t) implication, (funct_t) test_implication, 2, "! ~ ^ |", 5, 10,
     {{0,1},{0,1},{TMin,TMax}}},
//3
 {"oddBits", (funct_t) oddBits, (funct_t) test_oddBits, 0,
    "! ~ & ^ | + << >>", 8, 10,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//4
 {"addOK", (funct_t) addOK, (funct_t) test_addOK, 2,
    "! ~ & ^ | + << >>", 20, 10,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//5
 {"replaceByte", (funct_t) replaceByte, (funct_t) test_replaceByte, 3,
    "! ~ & ^ | + << >>", 10, 15,
  {{TMin, TMax},{0,3},{0,255}}},
//6
 {"bitParity", (funct_t) bitParity, (funct_t) test_bitParity, 1, "! ~ & ^ | + << >>", 20, 8,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
  {"", NULL, NULL, 0, "", 0, 0,
   {{0, 0},{0,0},{0,0}}}
};
