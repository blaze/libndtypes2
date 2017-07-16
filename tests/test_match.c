/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2017, plures
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <stdio.h>
#include "test.h"


const match_testcase_t match_tests[] = {
  { "2395344366 * Any",
    "2395344366 * Any",
    1 },

  { "10 * 2395344366 * Any",
    "10 * ... * Any",
    0 },

  { "N * 10 * 2395344366 * Any",
    "10 * 10 * 2395344366 * Any",
    1 },

  { "N * N * 2395344366 * Any",
    "10 * 10 * 2395344366 * Any",
    1 },

  { "N * M * 2395344366 * Any",
    "10 * 10 * 2395344366 * Any",
    1 },

  { "N * M * N * Any",
    "10 * 10 * 2395344366 * Any",
    0 },

  { "N * M * P * Any",
    "... * 10 * 2395344366 * Any",
    0 },

  { "N * M * P * Any",
    "10 * ... * 2395344366 * Any",
    0 },

  { "N * M * P * Any",
    "10 * ... * 2395344366 * Any",
    0 },

  { "L * Any",
    "L * Any",
    1 },

  { "10 * L * Any",
    "100 * L * Any",
    0 },

  { "var * Any",
    "var * Any",
    1 },

  { "var * Any",
    "10 * Any",
    0 },

  { "10 * Any",
    "var * Any",
    0 },

  { "?var * Any",
    "?var * Any",
    1 },

  { "10 * var * Any",
    "10 * var * Any",
    1 },

  { "10 * N * Any",
    "10 * var * Any",
    0 },

  { "10 * 10 * var * Any",
    "10 * 10 * var * Any",
    1 },

  { "... * Any",
    "... * Any",
    1 },

  { "... * Any",
    "10 * 20 * 30 * Any",
    1 },

  { "... * Any",
    "10 * ... *  30 * Any",
    1 },

  { "10 * ... * Any",
    "10 * ... * Any",
    1 },

  { "10 * N * ... * Any",
    "10 * 10 * ... * Any",
    1 },

  { "N * 10 * ... * Any",
    "10 * 10 * ... * Any",
    1 },

  { "N * 20 * ... * Any",
    "10 * 10 * ... * Any",
    0 },

  { "N * N * ... * Any",
    "10 * 10 * ... * Any",
    1 },

  { "N * N * ... * Any",
    "10 * 10 * ... * 20 * Z * Any",
    1 },

  { "Any",
    "10 * Any",
    1 },

  { "Any",
    "10 * (...) -> int64",
    1 },

  { "Any",
    "?Any",
    1 },

  { "?Any",
    "?Any",
    1 },

  { "10 * Scalar",
    "10 * Scalar",
    1 },

  { "10 * Scalar",
    "10 * (...)",
    0 },

  { "Scalar",
    "Scalar",
    1 },

  { "Scalar",
    "void",
    1 },

  { "Scalar",
    "string",
    1 },

  { "?Scalar",
    "?uint64",
    1 },

  { "10 * void",
    "10 * void",
    1 },

  { "void",
    "void",
    1 },

  { "void",
    "(...)",
    0 },

  { "?void",
    "?void",
    1 },

  { "10 * bool",
    "10 * bool",
    1 },

  { "bool",
    "bool",
    1 },

  { "complex128",
    "bool",
    0 },

  { "?bool",
    "?bool",
    1 },

  { "10 * Signed",
    "10 * Signed",
    1 },

  { "Signed",
    "Signed",
    1 },

  { "Signed",
    "int64",
    1 },

  { "?Signed",
    "?int16",
    1 },

  { "10 * int8",
    "10 * int8",
    1 },

  { "int8",
    "int8",
    1 },

  { "?int8",
    "?Signed",
    0 },

  { "10 * int16",
    "10 * int16",
    1 },

  { "int16",
    "{...}",
    0 },

  { "?int16",
    "?int16",
    1 },

  { "10 * int32",
    "10 * int32",
    1 },

  { "int32",
    "int32",
    1 },

  { "?int32",
    "?int32",
    1 },

  { "10 * int64",
    "10 * float64",
    0 },

  { "int64",
    "int64",
    1 },

  { "?int64",
    "?int64",
    1 },

  { "10 * Unsigned",
    "10 * Unsigned",
    1 },

  { "10 * Unsigned",
    "10 * uint8",
    1 },

  { "Unsigned",
    "Unsigned",
    1 },

  { "?Unsigned",
    "?Unsigned",
    1 },

  { "10 * uint8",
    "10 * uint8",
    1 },

  { "uint32",
    "uint8",
    0 },

  { "?uint8",
    "?uint8",
    1 },

  { "10 * uint16",
    "10 * uint16",
    1 },

  { "uint16",
    "uint16",
    1 },

  { "?uint16",
    "?int16",
    0 },

  { "10 * uint32",
    "10 * uint32",
    1 },

  { "uint32",
    "uint32",
    1 },

  { "?uint32",
    "?uint32",
    1 },

  { "10 * uint64",
    "10 * uint64",
    1 },

  { "uint64",
    "uint64",
    1 },

  { "?uint64",
    "?uint64",
    1 },

  { "10 * Float",
    "10 * Float",
    1 },

  { "float64",
    "float64",
    1 },

  { "?float64",
    "?float64",
    1 },

  { "10 * Complex",
    "10 * complex128",
    1 },

  { "10 * Complex",
    "10 * complex64",
    1 },

  { "Complex",
    "Complex",
    1 },

  { "?Complex",
    "?X",
    0 },

  { "?X",
    "?Complex",
    1 },

  { "10 * complex64",
    "10 * complex64",
    1 },

  { "complex64",
    "complex64",
    1 },

  { "?complex64",
    "?complex64",
    1 },

  { "10 * complex128",
    "10 * complex128",
    1 },

  { "complex128",
    "complex64",
    0 },

  { "?complex128",
    "?float64",
    0 },

  { "10 * char('ascii')",
    "10 * char('ascii')",
    1 },

  { "char('ascii')",
    "char('ascii')",
    1 },

  { "?char('ascii')",
    "?char('ascii')",
    1 },

  { "10 * char('utf8')",
    "10 * char('utf16')",
    0 },

  { "char('utf8')",
    "char('utf8')",
    1 },

  { "?char('utf8')",
    "?char('utf16')",
    0 },

  { "10 * char('utf16')",
    "10 * char('utf16')",
    1 },

  { "char('utf16')",
    "char('utf16')",
    1 },

  { "?char('utf16')",
    "?char('utf16')",
    1 },

  { "10 * char('utf32')",
    "10 * char('utf32')",
    1 },

  { "char('utf32')",
    "10 * char('utf32')",
    0 },

  { "?char('utf32')",
    "?char('utf32')",
    1 },

  { "10 * char('ucs2')",
    "10 * char('ucs2')",
    1 },

  { "char('ucs2')",
    "char('ucs2')",
    1 },

  { "?char('ucs2')",
    "char('ucs2')",
    0 },

  { "10 * string",
    "10 * string",
    1 },

  { "string",
    "string",
    1 },

  { "?string",
    "?string",
    1 },

  { "10 * FixedString",
    "10 * FixedString",
    1 },

  { "10 * FixedString",
    "10 * fixed_string(100)",
    1 },

  { "FixedString",
    "fixed_bytes(size=200, align=2)",
    0 },

  { "?FixedString",
    "?string",
    0 },

  { "10 * fixed_string(729742655, 'ascii')",
    "10 * fixed_string(729742655, 'ascii')",
    1 },

  { "fixed_string(729742655, 'ascii')",
    "fixed_string(729742655, 'utf32')",
    0 },

  { "?fixed_string(729742655, 'ascii')",
    "?fixed_string(729742655, 'ascii')",
    1 },

  { "10 * fixed_string(3952068488, 'utf8')",
    "10 * fixed_bytes(size=3952068488, align=2)",
    0 },

  { "fixed_string(3952068488, 'utf8')",
    "fixed_string(3952068488, 'utf8')",
    1 },

  { "?fixed_string(3952068488, 'utf8')",
    "?fixed_string(3952068488, 'utf8')",
    1 },

  { "10 * fixed_string(2949183030, 'utf16')",
    "10 * string",
    0 },

  { "fixed_string(2949183030, 'utf16')",
    "fixed_string(2949183030, 'utf16')",
    1 },

  { "?fixed_string(2949183030, 'utf16')",
    "?fixed_string(2949183030, 'ascii')",
    0 },

  { "10 * fixed_string(375133997, 'utf32')",
    "10 * fixed_string(375133997, 'utf32')",
    1 },

  { "fixed_string(375133997, 'utf32')",
    "fixed_string(375133997, 'utf32')",
    1 },

  { "?fixed_string(375133997, 'utf32')",
    "?fixed_string(375133997, 'utf32')",
    1 },

  { "10 * fixed_string(969064578, 'ucs2')",
    "10 * fixed_string(969064578, 'ucs2')",
    1 },

  { "fixed_string(969064578, 'ucs2')",
    "fixed_string(969064578, 'ucs2')",
    1 },

  { "?fixed_string(969064578, 'ucs2')",
    "?fixed_string(969064578, 'ucs2')",
    1 },

  { "10 * bytes(align=16)",
    "10 * bytes(align=16)",
    1 },

  { "bytes(align=16)",
    "bytes(align=16)",
    1 },

  { "?bytes(align=16)",
    "?bytes(align=16)",
    1 },

  { "10 * FixedBytes",
    "10 * FixedBytes",
    1 },

  { "FixedBytes",
    "bytes(align=16)",
    0 },

  { "?FixedBytes",
    "?fixed_bytes(size=100, align=2)",
    1 },

  { "10 * fixed_bytes(size=1904128733, align=4)",
    "10 * fixed_bytes(size=1904128733, align=4)",
    1 },

  { "fixed_bytes(size=1904128733, align=4)",
    "fixed_bytes(size=1904128733, align=2)",
    0 },

  { "?fixed_bytes(size=1904128733, align=4)",
    "?fixed_bytes(size=1904128732, align=4)",
    0 },

  { "10 * categorical(63 : int8)",
    "10 * categorical(63 : int8)",
    1 },

  { "categorical(63 : int8)",
    "categorical(63 : int8)",
    1 },

  { "?categorical(63 : int8)",
    "?categorical(63 : int8)",
    1 },

  { "categorical(63 : int16)",
    "categorical(63 : int8)",
    0 },

  { "categorical(8 : int8)",
    "categorical(10 : int8)",
    0 },

  { "10 * categorical(10 : int64, 63 : int8)",
    "10 * categorical(10 : int64, 63 : int8)",
    1 },

  { "10 * categorical(10 : int64, 63 : int8)",
    "10 * categorical(63 : int8, 10 : int64)",
    1 },

  { "10 * categorical(10 : int64, 63 : int8)",
    "10 * categorical(63 : int8, 10 : int32)",
    0 },

  { "categorical(10 : int64, 63 : int8)",
    "categorical(10 : int64, 63 : int8)",
    1 },

  { "?categorical(10 : int64, 63 : int8)",
    "?categorical(10 : int64, 63 : int8)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 63 : int8)",
    "10 * categorical(10 : int64, 20 : int64, 63 : int8)",
    1 },

  { "categorical(10 : int64, 20 : int64, 63 : int8)",
    "categorical(10 : int64, 20 : int64, 63 : int8)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 63 : int8)",
    "?categorical(10 : int64, 20 : int64, 63 : int8)",
    1 },

  { "10 * categorical(18514 : int16)",
    "10 * categorical(18514 : int16)",
    1 },

  { "categorical(18514 : int16)",
    "categorical(18514 : int16)",
    1 },

  { "?categorical(18514 : int16)",
    "?categorical(18514 : int16)",
    1 },

  { "10 * categorical(10 : int64, 18514 : int16)",
    "10 * categorical(10 : int64, 18514 : int16)",
    1 },

  { "categorical(10 : int64, 18514 : int16)",
    "categorical(10 : int64, 18514 : int16)",
    1 },

  { "?categorical(10 : int64, 18514 : int16)",
    "?categorical(10 : int64, 18514 : int16)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 18514 : int16)",
    "10 * categorical(10 : int64, 20 : int64, 18514 : int16)",
    1 },

  { "categorical(10 : int64, 20 : int64, 18514 : int16)",
    "categorical(10 : int64, 20 : int64, 18514 : int16)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 18514 : int16)",
    "?categorical(10 : int64, 20 : int64, 18514 : int16)",
    1 },

  { "10 * categorical(-176354404 : int32)",
    "10 * categorical(-176354404 : int32)",
    1 },

  { "categorical(-176354404 : int32)",
    "categorical(-176354404 : int32)",
    1 },

  { "?categorical(-176354404 : int32)",
    "?categorical(-176354404 : int32)",
    1 },

  { "10 * categorical(10 : int64, -176354404 : int32)",
    "10 * categorical(10 : int64, -176354404 : int32)",
    1 },

  { "categorical(10 : int64, -176354404 : int32)",
    "categorical(10 : int64, -176354404 : int32)",
    1 },

  { "?categorical(10 : int64, -176354404 : int32)",
    "?categorical(10 : int64, -176354404 : int32)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, -176354404 : int32)",
    "10 * categorical(10 : int64, 20 : int64, -176354404 : int32)",
    1 },

  { "categorical(10 : int64, 20 : int64, -176354404 : int32)",
    "categorical(10 : int64, 20 : int64, -176354404 : int32)",
    1 },

  { "?categorical(10 : int64, 20 : int64, -176354404 : int32)",
    "?categorical(10 : int64, 20 : int64, -176354404 : int32)",
    1 },

  { "10 * categorical(500601201 : int64)",
    "10 * categorical(500601201 : int64)",
    1 },

  { "categorical(500601201 : int64)",
    "categorical(500601201 : int64)",
    1 },

  { "?categorical(500601201 : int64)",
    "?categorical(500601201 : int64)",
    1 },

  { "10 * categorical(10 : int64, 500601201 : int64)",
    "10 * categorical(10 : int64, 500601201 : int64)",
    1 },

  { "categorical(10 : int64, 500601201 : int64)",
    "categorical(10 : int64, 500601201 : int64)",
    1 },

  { "?categorical(10 : int64, 500601201 : int64)",
    "?categorical(10 : int64, 500601201 : int64)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 500601201 : int64)",
    "10 * categorical(10 : int64, 20 : int64, 500601201 : int64)",
    1 },

  { "categorical(10 : int64, 20 : int64, 500601201 : int64)",
    "categorical(10 : int64, 20 : int64, 500601201 : int64)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 500601201 : int64)",
    "?categorical(10 : int64, 20 : int64, 500601201 : int64)",
    1 },

  { "10 * categorical(135 : uint8)",
    "10 * categorical(135 : uint8)",
    1 },

  { "categorical(135 : uint8)",
    "categorical(135 : uint8)",
    1 },

  { "?categorical(135 : uint8)",
    "?categorical(135 : uint8)",
    1 },

  { "10 * categorical(10 : int64, 135 : uint8)",
    "10 * categorical(10 : int64, 135 : uint8)",
    1 },

  { "categorical(10 : int64, 135 : uint8)",
    "categorical(10 : int64, 135 : uint8)",
    1 },

  { "?categorical(10 : int64, 135 : uint8)",
    "?categorical(10 : int64, 135 : uint8)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 135 : uint8)",
    "10 * categorical(10 : int64, 20 : int64, 135 : uint8)",
    1 },

  { "categorical(10 : int64, 20 : int64, 135 : uint8)",
    "categorical(10 : int64, 20 : int64, 135 : uint8)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 135 : uint8)",
    "?categorical(10 : int64, 20 : int64, 135 : uint8)",
    1 },

  { "10 * categorical(22234 : uint16)",
    "10 * categorical(22234 : uint16)",
    1 },

  { "categorical(22234 : uint16)",
    "categorical(22234 : uint16)",
    1 },

  { "?categorical(22234 : uint16)",
    "?categorical(22234 : uint16)",
    1 },

  { "10 * categorical(10 : int64, 22234 : uint16)",
    "10 * categorical(10 : int64, 22234 : uint16)",
    1 },

  { "categorical(10 : int64, 22234 : uint16)",
    "categorical(10 : int64, 22234 : uint16)",
    1 },

  { "?categorical(10 : int64, 22234 : uint16)",
    "?categorical(10 : int64, 22234 : uint16)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 22234 : uint16)",
    "10 * categorical(10 : int64, 20 : int64, 22234 : uint16)",
    1 },

  { "categorical(10 : int64, 20 : int64, 22234 : uint16)",
    "categorical(10 : int64, 20 : int64, 22234 : uint16)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 22234 : uint16)",
    "?categorical(10 : int64, 20 : int64, 22234 : uint16)",
    1 },

  { "10 * categorical(3761672407 : uint32)",
    "10 * categorical(3761672407 : uint32)",
    1 },

  { "categorical(3761672407 : uint32)",
    "categorical(3761672407 : uint32)",
    1 },

  { "?categorical(3761672407 : uint32)",
    "?categorical(3761672407 : uint32)",
    1 },

  { "10 * categorical(10 : int64, 3761672407 : uint32)",
    "10 * categorical(10 : int64, 3761672407 : uint32)",
    1 },

  { "categorical(10 : int64, 3761672407 : uint32)",
    "categorical(10 : int64, 3761672407 : uint32)",
    1 },

  { "?categorical(10 : int64, 3761672407 : uint32)",
    "?categorical(10 : int64, 3761672407 : uint32)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 3761672407 : uint32)",
    "10 * categorical(10 : int64, 20 : int64, 3761672407 : uint32)",
    1 },

  { "categorical(10 : int64, 20 : int64, 3761672407 : uint32)",
    "categorical(10 : int64, 20 : int64, 3761672407 : uint32)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 3761672407 : uint32)",
    "?categorical(10 : int64, 20 : int64, 3761672407 : uint32)",
    1 },

  { "10 * categorical(2339269771 : uint64)",
    "10 * categorical(2339269771 : uint64)",
    1 },

  { "categorical(2339269771 : uint64)",
    "categorical(2339269771 : uint64)",
    1 },

  { "?categorical(2339269771 : uint64)",
    "?categorical(2339269771 : uint64)",
    1 },

  { "10 * categorical(10 : int64, 2339269771 : uint64)",
    "10 * categorical(10 : int64, 2339269771 : uint64)",
    1 },

  { "categorical(10 : int64, 2339269771 : uint64)",
    "categorical(10 : int64, 2339269771 : uint64)",
    1 },

  { "?categorical(10 : int64, 2339269771 : uint64)",
    "?categorical(10 : int64, 2339269771 : uint64)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 2339269771 : uint64)",
    "10 * categorical(10 : int64, 20 : int64, 2339269771 : uint64)",
    1 },

  { "categorical(10 : int64, 20 : int64, 2339269771 : uint64)",
    "categorical(10 : int64, 20 : int64, 2339269771 : uint64)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 2339269771 : uint64)",
    "?categorical(10 : int64, 20 : int64, 2339269771 : uint64)",
    1 },

  { "10 * categorical(1.2 : float32)",
    "10 * categorical(1.2 : float32)",
    1 },

  { "categorical(-1.2e+33 : float32)",
    "categorical(-1.2e+33 : float32)",
    1 },

  { "?categorical(-1.2e-33 : float32)",
    "?categorical(-1.2e-33 : float32)",
    1 },

  { "10 * categorical(10 : int64, 1.05e+10 : float32)",
    "10 * categorical(10 : int64, 1.05e+10 : float32)",
    1 },

  { "categorical(10 : int64, 1.05e+10 : float32)",
    "categorical(10 : int64, 1.05e+10 : float32)",
    1 },

  { "?categorical(10 : int64, 1.05e+10 : float32)",
    "?categorical(10 : int64, 1.05e+10 : float32)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 1.05e+10 : float32)",
    "10 * categorical(10 : int64, 20 : int64, 1.05e+10 : float32)",
    1 },

  { "categorical(10 : int64, 20 : int64, 1.05e+10 : float32)",
    "categorical(10 : int64, 20 : int64, 1.05e+10 : float32)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 1.05e+10 : float32)",
    "?categorical(10 : int64, 20 : int64, 1.05e+10 : float32)",
    1 },

  { "10 * categorical(1.05e+300 : float64)",
    "10 * categorical(1.05e+300 : float64)",
    1 },

  { "categorical(-1.05e+300 : float64)",
    "categorical(-1.05e+300 : float64)",
    1 },

  { "?categorical(-1.05e+300 : float64)",
    "?categorical(-1.05e+300 : float64)",
    1 },

  { "10 * categorical(10 : int64, 1.05e+300 : float64)",
    "10 * categorical(10 : int64, 1.05e+300 : float64)",
    1 },

  { "categorical(10 : int64, 1.05e+300 : float64)",
    "categorical(10 : int64, 1.05e+300 : float64)",
    1 },

  { "?categorical(10 : int64, 1.05e+300 : float64)",
    "?categorical(10 : int64, 1.05e+300 : float64)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 1.05e+300 : float64)",
    "10 * categorical(10 : int64, 20 : int64, 1.05e+300 : float64)",
    1 },

  { "categorical(10 : int64, 20 : int64, 1.05e+300 : float64)",
    "categorical(10 : int64, 20 : int64, 1.05e+300 : float64)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 1.05e+300 : float64)",
    "?categorical(10 : int64, 20 : int64, 1.05e+300 : float64)",
    1 },

  { "10 * categorical('jRAMoBPQ' : string)",
    "10 * categorical('jRAMoBPQ' : string)",
    1 },

  { "categorical('jRAMoBPQ' : string)",
    "categorical('jRAMoBPQ' : string)",
    1 },

  { "?categorical('jRAMoBPQ' : string)",
    "?categorical('jRAMoBPQ' : string)",
    1 },

  { "10 * categorical(10 : int64, 'jRAMoBPQ' : string)",
    "10 * categorical(10 : int64, 'jRAMoBPQ' : string)",
    1 },

  { "categorical(10 : int64, 'jRAMoBPQ' : string)",
    "categorical(10 : int64, 'jRAMoBPQ' : string)",
    1 },

  { "?categorical(10 : int64, 'jRAMoBPQ' : string)",
    "?categorical(10 : int64, 'jRAMoBPQ' : string)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 'jRAMoBPQ' : string)",
    "10 * categorical(10 : int64, 20 : int64, 'jRAMoBPQ' : string)",
    1 },

  { "categorical(10 : int64, 20 : int64, 'jRAMoBPQ' : string)",
    "categorical(10 : int64, 20 : int64, 'jRAMoBPQ' : string)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 'jRAMoBPQ' : string)",
    "?categorical(10 : int64, 20 : int64, 'jRAMoBPQ' : string)",
    1 },

  { "10 * categorical(127 : int8)",
    "10 * categorical(127 : int8)",
    1 },

  { "categorical(127 : int8)",
    "categorical(127 : int8)",
    1 },

  { "?categorical(127 : int8)",
    "?categorical(127 : int8)",
    1 },

  { "10 * categorical(10 : int64, 127 : int8)",
    "10 * categorical(10 : int64, 127 : int8)",
    1 },

  { "categorical(10 : int64, 127 : int8)",
    "categorical(10 : int64, 127 : int8)",
    1 },

  { "?categorical(10 : int64, 127 : int8)",
    "?categorical(10 : int64, 127 : int8)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 127 : int8)",
    "10 * categorical(10 : int64, 20 : int64, 127 : int8)",
    1 },

  { "categorical(10 : int64, 20 : int64, 127 : int8)",
    "categorical(10 : int64, 20 : int64, 127 : int8)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 127 : int8)",
    "?categorical(10 : int64, 20 : int64, 127 : int8)",
    1 },

  { "10 * categorical(-128 : int8)",
    "10 * categorical(-128 : int8)",
    1 },

  { "categorical(-128 : int8)",
    "categorical(-128 : int8)",
    1 },

  { "?categorical(-128 : int8)",
    "?categorical(-128 : int8)",
    1 },

  { "10 * categorical(10 : int64, -128 : int8)",
    "10 * categorical(10 : int64, -128 : int8)",
    1 },

  { "categorical(10 : int64, -128 : int8)",
    "categorical(10 : int64, -128 : int8)",
    1 },

  { "?categorical(10 : int64, -128 : int8)",
    "?categorical(10 : int64, -128 : int8)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, -128 : int8)",
    "10 * categorical(10 : int64, 20 : int64, -128 : int8)",
    1 },

  { "categorical(10 : int64, 20 : int64, -128 : int8)",
    "categorical(10 : int64, 20 : int64, -128 : int8)",
    1 },

  { "?categorical(10 : int64, 20 : int64, -128 : int8)",
    "?categorical(10 : int64, 20 : int64, -128 : int8)",
    1 },

  { "10 * categorical(32767 : int16)",
    "10 * categorical(32767 : int16)",
    1 },

  { "categorical(32767 : int16)",
    "categorical(32767 : int16)",
    1 },

  { "?categorical(32767 : int16)",
    "?categorical(32767 : int16)",
    1 },

  { "10 * categorical(10 : int64, 32767 : int16)",
    "10 * categorical(10 : int64, 32767 : int16)",
    1 },

  { "categorical(10 : int64, 32767 : int16)",
    "categorical(10 : int64, 32767 : int16)",
    1 },

  { "?categorical(10 : int64, 32767 : int16)",
    "?categorical(10 : int64, 32767 : int16)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 32767 : int16)",
    "10 * categorical(10 : int64, 20 : int64, 32767 : int16)",
    1 },

  { "categorical(10 : int64, 20 : int64, 32767 : int16)",
    "categorical(10 : int64, 20 : int64, 32767 : int16)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 32767 : int16)",
    "?categorical(10 : int64, 20 : int64, 32767 : int16)",
    1 },

  { "10 * categorical(-32768 : int16)",
    "10 * categorical(-32768 : int16)",
    1 },

  { "categorical(-32768 : int16)",
    "categorical(-32768 : int16)",
    1 },

  { "?categorical(-32768 : int16)",
    "?categorical(-32768 : int16)",
    1 },

  { "10 * categorical(10 : int64, -32768 : int16)",
    "10 * categorical(10 : int64, -32768 : int16)",
    1 },

  { "categorical(10 : int64, -32768 : int16)",
    "categorical(10 : int64, -32768 : int16)",
    1 },

  { "?categorical(10 : int64, -32768 : int16)",
    "?categorical(10 : int64, -32768 : int16)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, -32768 : int16)",
    "10 * categorical(10 : int64, 20 : int64, -32768 : int16)",
    1 },

  { "categorical(10 : int64, 20 : int64, -32768 : int16)",
    "categorical(10 : int64, 20 : int64, -32768 : int16)",
    1 },

  { "?categorical(10 : int64, 20 : int64, -32768 : int16)",
    "?categorical(10 : int64, 20 : int64, -32768 : int16)",
    1 },

  { "10 * categorical(2147483647 : int32)",
    "10 * categorical(2147483647 : int32)",
    1 },

  { "categorical(2147483647 : int32)",
    "categorical(2147483647 : int32)",
    1 },

  { "?categorical(2147483647 : int32)",
    "?categorical(2147483647 : int32)",
    1 },

  { "10 * categorical(10 : int64, 2147483647 : int32)",
    "10 * categorical(10 : int64, 2147483647 : int32)",
    1 },

  { "categorical(10 : int64, 2147483647 : int32)",
    "categorical(10 : int64, 2147483647 : int32)",
    1 },

  { "?categorical(10 : int64, 2147483647 : int32)",
    "?categorical(10 : int64, 2147483647 : int32)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 2147483647 : int32)",
    "10 * categorical(10 : int64, 20 : int64, 2147483647 : int32)",
    1 },

  { "categorical(10 : int64, 20 : int64, 2147483647 : int32)",
    "categorical(10 : int64, 20 : int64, 2147483647 : int32)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 2147483647 : int32)",
    "?categorical(10 : int64, 20 : int64, 2147483647 : int32)",
    1 },

  { "10 * categorical(-2147483648 : int32)",
    "10 * categorical(-2147483648 : int32)",
    1 },

  { "categorical(-2147483648 : int32)",
    "categorical(-2147483648 : int32)",
    1 },

  { "?categorical(-2147483648 : int32)",
    "?categorical(-2147483648 : int32)",
    1 },

  { "10 * categorical(10 : int64, -2147483648 : int32)",
    "10 * categorical(10 : int64, -2147483648 : int32)",
    1 },

  { "categorical(10 : int64, -2147483648 : int32)",
    "categorical(10 : int64, -2147483648 : int32)",
    1 },

  { "?categorical(10 : int64, -2147483648 : int32)",
    "?categorical(10 : int64, -2147483648 : int32)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, -2147483648 : int32)",
    "10 * categorical(10 : int64, 20 : int64, -2147483648 : int32)",
    1 },

  { "categorical(10 : int64, 20 : int64, -2147483648 : int32)",
    "categorical(10 : int64, 20 : int64, -2147483648 : int32)",
    1 },

  { "?categorical(10 : int64, 20 : int64, -2147483648 : int32)",
    "?categorical(10 : int64, 20 : int64, -2147483648 : int32)",
    1 },

  { "10 * categorical(9223372036854775807 : int64)",
    "10 * categorical(9223372036854775807 : int64)",
    1 },

  { "categorical(9223372036854775807 : int64)",
    "categorical(9223372036854775807 : int64)",
    1 },

  { "?categorical(9223372036854775807 : int64)",
    "?categorical(9223372036854775807 : int64)",
    1 },

  { "10 * categorical(10 : int64, 9223372036854775807 : int64)",
    "10 * categorical(10 : int64, 9223372036854775807 : int64)",
    1 },

  { "categorical(10 : int64, 9223372036854775807 : int64)",
    "categorical(10 : int64, 9223372036854775807 : int64)",
    1 },

  { "?categorical(10 : int64, 9223372036854775807 : int64)",
    "?categorical(10 : int64, 9223372036854775807 : int64)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 9223372036854775807 : int64)",
    "10 * categorical(10 : int64, 20 : int64, 9223372036854775807 : int64)",
    1 },

  { "categorical(10 : int64, 20 : int64, 9223372036854775807 : int64)",
    "categorical(10 : int64, 20 : int64, 9223372036854775807 : int64)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 9223372036854775807 : int64)",
    "?categorical(10 : int64, 20 : int64, 9223372036854775807 : int64)",
    1 },

  { "10 * categorical(-9223372036854775808 : int64)",
    "10 * categorical(-9223372036854775808 : int64)",
    1 },

  { "categorical(-9223372036854775808 : int64)",
    "categorical(-9223372036854775808 : int64)",
    1 },

  { "?categorical(-9223372036854775808 : int64)",
    "?categorical(-9223372036854775808 : int64)",
    1 },

  { "10 * categorical(10 : int64, -9223372036854775808 : int64)",
    "10 * categorical(10 : int64, -9223372036854775808 : int64)",
    1 },

  { "categorical(10 : int64, -9223372036854775808 : int64)",
    "categorical(10 : int64, -9223372036854775808 : int64)",
    1 },

  { "?categorical(10 : int64, -9223372036854775808 : int64)",
    "?categorical(10 : int64, -9223372036854775808 : int64)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, -9223372036854775808 : int64)",
    "10 * categorical(10 : int64, 20 : int64, -9223372036854775808 : int64)",
    1 },

  { "categorical(10 : int64, 20 : int64, -9223372036854775808 : int64)",
    "categorical(10 : int64, 20 : int64, -9223372036854775808 : int64)",
    1 },

  { "?categorical(10 : int64, 20 : int64, -9223372036854775808 : int64)",
    "?categorical(10 : int64, 20 : int64, -9223372036854775808 : int64)",
    1 },

  { "10 * categorical(255 : uint8)",
    "10 * categorical(255 : uint8)",
    1 },

  { "categorical(255 : uint8)",
    "categorical(255 : uint8)",
    1 },

  { "?categorical(255 : uint8)",
    "?categorical(255 : uint8)",
    1 },

  { "10 * categorical(10 : int64, 255 : uint8)",
    "10 * categorical(10 : int64, 255 : uint8)",
    1 },

  { "categorical(10 : int64, 255 : uint8)",
    "categorical(10 : int64, 255 : uint8)",
    1 },

  { "?categorical(10 : int64, 255 : uint8)",
    "?categorical(10 : int64, 255 : uint8)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 255 : uint8)",
    "10 * categorical(10 : int64, 20 : int64, 255 : uint8)",
    1 },

  { "categorical(10 : int64, 20 : int64, 255 : uint8)",
    "categorical(10 : int64, 20 : int64, 255 : uint8)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 255 : uint8)",
    "?categorical(10 : int64, 20 : int64, 255 : uint8)",
    1 },

  { "10 * categorical(65535 : uint16)",
    "10 * categorical(65535 : uint16)",
    1 },

  { "categorical(65535 : uint16)",
    "categorical(65535 : uint16)",
    1 },

  { "?categorical(65535 : uint16)",
    "?categorical(65535 : uint16)",
    1 },

  { "10 * categorical(10 : int64, 65535 : uint16)",
    "10 * categorical(10 : int64, 65535 : uint16)",
    1 },

  { "categorical(10 : int64, 65535 : uint16)",
    "categorical(10 : int64, 65535 : uint16)",
    1 },

  { "?categorical(10 : int64, 65535 : uint16)",
    "?categorical(10 : int64, 65535 : uint16)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 65535 : uint16)",
    "10 * categorical(10 : int64, 20 : int64, 65535 : uint16)",
    1 },

  { "categorical(10 : int64, 20 : int64, 65535 : uint16)",
    "categorical(10 : int64, 20 : int64, 65535 : uint16)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 65535 : uint16)",
    "?categorical(10 : int64, 20 : int64, 65535 : uint16)",
    1 },

  { "10 * categorical(4294967295 : uint32)",
    "10 * categorical(4294967295 : uint32)",
    1 },

  { "categorical(4294967295 : uint32)",
    "categorical(4294967295 : uint32)",
    1 },

  { "?categorical(4294967295 : uint32)",
    "?categorical(4294967295 : uint32)",
    1 },

  { "10 * categorical(10 : int64, 4294967295 : uint32)",
    "10 * categorical(10 : int64, 4294967295 : uint32)",
    1 },

  { "categorical(10 : int64, 4294967295 : uint32)",
    "categorical(10 : int64, 4294967295 : uint32)",
    1 },

  { "?categorical(10 : int64, 4294967295 : uint32)",
    "?categorical(10 : int64, 4294967295 : uint32)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 4294967295 : uint32)",
    "10 * categorical(10 : int64, 20 : int64, 4294967295 : uint32)",
    1 },

  { "categorical(10 : int64, 20 : int64, 4294967295 : uint32)",
    "categorical(10 : int64, 20 : int64, 4294967295 : uint32)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 4294967295 : uint32)",
    "?categorical(10 : int64, 20 : int64, 4294967295 : uint32)",
    1 },

  { "10 * categorical(18446744073709551615 : uint64)",
    "10 * categorical(18446744073709551615 : uint64)",
    1 },

  { "categorical(18446744073709551615 : uint64)",
    "categorical(18446744073709551615 : uint64)",
    1 },

  { "?categorical(18446744073709551615 : uint64)",
    "?categorical(18446744073709551615 : uint64)",
    1 },

  { "10 * categorical(10 : int64, 18446744073709551615 : uint64)",
    "10 * categorical(10 : int64, 18446744073709551615 : uint64)",
    1 },

  { "categorical(10 : int64, 18446744073709551615 : uint64)",
    "categorical(10 : int64, 18446744073709551615 : uint64)",
    1 },

  { "?categorical(10 : int64, 18446744073709551615 : uint64)",
    "?categorical(10 : int64, 18446744073709551615 : uint64)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 18446744073709551615 : uint64)",
    "10 * categorical(10 : int64, 20 : int64, 18446744073709551615 : uint64)",
    1 },

  { "categorical(10 : int64, 20 : int64, 18446744073709551615 : uint64)",
    "categorical(10 : int64, 20 : int64, 18446744073709551615 : uint64)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 18446744073709551615 : uint64)",
    "?categorical(10 : int64, 20 : int64, 18446744073709551615 : uint64)",
    1 },

  { "10 * categorical(1.1755e-38 : float32)",
    "10 * categorical(1.1755e-38 : float32)",
    1 },

  { "categorical(1.1755e-38 : float32)",
    "categorical(1.1755e-38 : float32)",
    1 },

  { "?categorical(1.1755e-38 : float32)",
    "?categorical(1.1755e-38 : float32)",
    1 },

  { "10 * categorical(10 : int64, 1.1755e-38 : float32)",
    "10 * categorical(10 : int64, 1.1755e-38 : float32)",
    1 },

  { "categorical(10 : int64, 1.1755e-38 : float32)",
    "categorical(10 : int64, 1.1755e-38 : float32)",
    1 },

  { "?categorical(10 : int64, 1.1755e-38 : float32)",
    "?categorical(10 : int64, 1.1755e-38 : float32)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 1.1755e-38 : float32)",
    "10 * categorical(10 : int64, 20 : int64, 1.1755e-38 : float32)",
    1 },

  { "categorical(10 : int64, 20 : int64, 1.1755e-38 : float32)",
    "categorical(10 : int64, 20 : int64, 1.1755e-38 : float32)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 1.1755e-38 : float32)",
    "?categorical(10 : int64, 20 : int64, 1.1755e-38 : float32)",
    1 },

  { "10 * categorical(2.22508e-308 : float64)",
    "10 * categorical(2.22508e-308 : float64)",
    1 },

  { "categorical(2.22508e-308 : float64)",
    "categorical(2.22508e-308 : float64)",
    1 },

  { "?categorical(2.22508e-308 : float64)",
    "?categorical(2.22508e-308 : float64)",
    1 },

  { "10 * categorical(10 : int64, 2.22508e-308 : float64)",
    "10 * categorical(10 : int64, 2.22508e-308 : float64)",
    1 },

  { "categorical(10 : int64, 2.22508e-308 : float64)",
    "categorical(10 : int64, 2.22508e-308 : float64)",
    1 },

  { "?categorical(10 : int64, 2.22508e-308 : float64)",
    "?categorical(10 : int64, 2.22508e-308 : float64)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 2.22508e-308 : float64)",
    "10 * categorical(10 : int64, 20 : int64, 2.22508e-308 : float64)",
    1 },

  { "categorical(10 : int64, 20 : int64, 2.22508e-308 : float64)",
    "categorical(10 : int64, 20 : int64, 2.22508e-308 : float64)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 2.22508e-308 : float64)",
    "?categorical(10 : int64, 20 : int64, 2.22508e-308 : float64)",
    1 },

  { "10 * categorical(3.40282e+38 : float32)",
    "10 * categorical(3.40282e+38 : float32)",
    1 },

  { "categorical(3.40282e+38 : float32)",
    "categorical(3.40282e+38 : float32)",
    1 },

  { "?categorical(3.40282e+38 : float32)",
    "?categorical(3.40282e+38 : float32)",
    1 },

  { "10 * categorical(10 : int64, 3.40282e+38 : float32)",
    "10 * categorical(10 : int64, 3.40282e+38 : float32)",
    1 },

  { "categorical(10 : int64, 3.40282e+38 : float32)",
    "categorical(10 : int64, 3.40282e+38 : float32)",
    1 },

  { "?categorical(10 : int64, 3.40282e+38 : float32)",
    "?categorical(10 : int64, 3.40282e+38 : float32)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 3.40282e+38 : float32)",
    "10 * categorical(10 : int64, 20 : int64, 3.40282e+38 : float32)",
    1 },

  { "categorical(10 : int64, 20 : int64, 3.40282e+38 : float32)",
    "categorical(10 : int64, 20 : int64, 3.40282e+38 : float32)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 3.40282e+38 : float32)",
    "?categorical(10 : int64, 20 : int64, 3.40282e+38 : float32)",
    1 },

  { "10 * categorical(1.79769e+308 : float64)",
    "10 * categorical(1.79769e+308 : float64)",
    1 },

  { "categorical(1.79769e+308 : float64)",
    "categorical(1.79769e+308 : float64)",
    1 },

  { "?categorical(1.79769e+308 : float64)",
    "?categorical(1.79769e+308 : float64)",
    1 },

  { "10 * categorical(10 : int64, 1.79769e+308 : float64)",
    "10 * categorical(10 : int64, 1.79769e+308 : float64)",
    1 },

  { "categorical(10 : int64, 1.79769e+308 : float64)",
    "categorical(10 : int64, 1.79769e+308 : float64)",
    1 },

  { "?categorical(10 : int64, 1.79769e+308 : float64)",
    "?categorical(10 : int64, 1.79769e+308 : float64)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 1.79769e+308 : float64)",
    "10 * categorical(10 : int64, 20 : int64, 1.79769e+308 : float64)",
    1 },

  { "categorical(10 : int64, 20 : int64, 1.79769e+308 : float64)",
    "categorical(10 : int64, 20 : int64, 1.79769e+308 : float64)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 1.79769e+308 : float64)",
    "?categorical(10 : int64, 20 : int64, 1.79769e+308 : float64)",
    1 },

  { "10 * categorical('' : string)",
    "10 * categorical('' : string)",
    1 },

  { "categorical('' : string)",
    "categorical('' : string)",
    1 },

  { "?categorical('' : string)",
    "?categorical('' : string)",
    1 },

  { "10 * categorical(10 : int64, '' : string)",
    "10 * categorical(10 : int64, '' : string)",
    1 },

  { "categorical(10 : int64, '' : string)",
    "categorical(10 : int64, '' : string)",
    1 },

  { "?categorical(10 : int64, '' : string)",
    "?categorical(10 : int64, '' : string)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, '' : string)",
    "10 * categorical(10 : int64, 20 : int64, '' : string)",
    1 },

  { "categorical(10 : int64, 20 : int64, '' : string)",
    "categorical(10 : int64, 20 : int64, '' : string)",
    1 },

  { "?categorical(10 : int64, 20 : int64, '' : string)",
    "?categorical(10 : int64, 20 : int64, '' : string)",
    1 },

  { "10 * categorical('' : string)",
    "10 * categorical('' : string)",
    1 },

  { "categorical('' : string)",
    "categorical('' : string)",
    1 },

  { "?categorical('' : string)",
    "?categorical('' : string)",
    1 },

  { "10 * categorical(10 : int64, '' : string)",
    "10 * categorical(10 : int64, '' : string)",
    1 },

  { "categorical(10 : int64, '' : string)",
    "categorical(10 : int64, '' : string)",
    1 },

  { "?categorical(10 : int64, '' : string)",
    "?categorical(10 : int64, '' : string)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, '' : string)",
    "10 * categorical(10 : int64, 20 : int64, '' : string)",
    1 },

  { "categorical(10 : int64, 20 : int64, '' : string)",
    "categorical(10 : int64, 20 : int64, '' : string)",
    1 },

  { "?categorical(10 : int64, 20 : int64, '' : string)",
    "?categorical(10 : int64, 20 : int64, '' : string)",
    1 },

  { "10 * categorical('xyz' : string)",
    "10 * categorical('xyz' : string)",
    1 },

  { "categorical('xyz' : string)",
    "categorical('xyz' : string)",
    1 },

  { "?categorical('xyz' : string)",
    "?categorical('xyz' : string)",
    1 },

  { "10 * categorical(10 : int64, 'xyz' : string)",
    "10 * categorical(10 : int64, 'xyz' : string)",
    1 },

  { "categorical(10 : int64, 'xyz' : string)",
    "categorical(10 : int64, 'xyz' : string)",
    1 },

  { "?categorical(10 : int64, 'xyz' : string)",
    "?categorical(10 : int64, 'xyz' : string)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 'xyz' : string)",
    "10 * categorical(10 : int64, 20 : int64, 'xyz' : string)",
    1 },

  { "categorical(10 : int64, 20 : int64, 'xyz' : string)",
    "categorical(10 : int64, 20 : int64, 'xyz' : string)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 'xyz' : string)",
    "?categorical(10 : int64, 20 : int64, 'xyz' : string)",
    1 },

  { "10 * categorical('xyz' : string)",
    "10 * categorical('xyz' : string)",
    1 },

  { "categorical('xyz' : string)",
    "categorical('xyz' : string)",
    1 },

  { "?categorical('xyz' : string)",
    "?categorical('xyz' : string)",
    1 },

  { "10 * categorical(10 : int64, 'xyz' : string)",
    "10 * categorical(10 : int64, 'xyz' : string)",
    1 },

  { "categorical(10 : int64, 'xyz' : string)",
    "categorical(10 : int64, 'xyz' : string)",
    1 },

  { "?categorical(10 : int64, 'xyz' : string)",
    "?categorical(10 : int64, 'xyz' : string)",
    1 },

  { "10 * categorical(10 : int64, 20 : int64, 'xyz' : string)",
    "10 * categorical(10 : int64, 20 : int64, 'xyz' : string)",
    1 },

  { "categorical(10 : int64, 20 : int64, 'xyz' : string)",
    "categorical(10 : int64, 20 : int64, 'xyz' : string)",
    1 },

  { "?categorical(10 : int64, 20 : int64, 'xyz' : string)",
    "?categorical(10 : int64, 20 : int64, 'xyz' : string)",
    1 },

  { "10 * pointer(Any)",
    "10 * pointer(Any)",
    1 },

  { "pointer(Any)",
    "pointer(Any)",
    1 },

  { "?pointer(Any)",
    "?pointer(Any)",
    1 },

  { "10 * (...)",
    "10 * (...)",
    1 },

  { "(...)",
    "(...)",
    1 },

  { "?(...)",
    "?(...)",
    1 },

  { "10 * (Any)",
    "10 * (Any)",
    1 },

  { "(Any)",
    "(Any)",
    1 },

  { "?(Any)",
    "?(Any)",
    1 },

  { "10 * (int64, Any)",
    "10 * (int64, Any)",
    1 },

  { "(int64, Any)",
    "(int64, Any)",
    1 },

  { "?(int64, Any)",
    "?(int64, Any)",
    1 },

  { "10 * (int64, int64, Any)",
    "10 * (int64, int64, Any)",
    1 },

  { "(int64, int64, Any)",
    "(int64, int64, Any)",
    1 },

  { "?(int64, int64, Any)",
    "?(int64, int64, Any)",
    1 },

  { "10 * (Any)",
    "10 * (Any)",
    1 },

  { "(Any)",
    "(Any)",
    1 },

  { "?(Any)",
    "?(Any)",
    1 },

  { "10 * (Any)",
    "10 * (Any)",
    1 },

  { "(Any)",
    "(Any)",
    1 },

  { "?(Any)",
    "?(Any)",
    1 },

  { "10 * (Any, ...)",
    "10 * (Any, ...)",
    1 },

  { "(Any, ...)",
    "(Any, ...)",
    1 },

  { "?(Any, ...)",
    "?(Any, ...)",
    1 },

  { "10 * {...}",
    "10 * {...}",
    1 },

  { "{...}",
    "{...}",
    1 },

  { "?{...}",
    "?{...}",
    1 },

  { "10 * {a : Any}",
    "10 * {a : Any}",
    1 },

  { "{a : Any}",
    "{a : Any}",
    1 },

  { "?{a : Any}",
    "?{a : Any}",
    1 },

  { "10 * {x : int64, a : Any}",
    "10 * {x : int64, a : Any}",
    1 },

  { "{x : int64, a : Any}",
    "{x : int64, a : Any}",
    1 },

  { "?{x : int64, a : Any}",
    "?{x : int64, a : Any}",
    1 },

  { "10 * {x : int64, x : int64, a : Any}",
    "10 * {x : int64, x : int64, a : Any}",
    1 },

  { "{x : int64, x : int64, a : Any}",
    "{x : int64, x : int64, a : Any}",
    1 },

  { "?{x : int64, x : int64, a : Any}",
    "?{x : int64, x : int64, a : Any}",
    1 },

  { "10 * {a : int64}",
    "10 * {a : int64}",
    1 },

  { "{a : int64}",
    "{a : int64}",
    1 },

  { "?{a : int64}",
    "?{a : int64}",
    1 },

  { "10 * {a : int64}",
    "10 * {a : int64}",
    1 },

  { "{a : int64}",
    "{a : int64}",
    1 },

  { "?{a : int64}",
    "?{a : int64}",
    1 },

  { "10 * {a : int64, ...}",
    "10 * {a : int64, ...}",
    1 },

  { "{a : int64, ...}",
    "{a : int64, ...}",
    1 },

  { "?{a : int64, ...}",
    "?{a : int64, ...}",
    1 },

  { "10 * (...) -> Any",
    "10 * (...) -> Any",
    1 },

  { "(...) -> Any",
    "(...) -> Any",
    1 },

  { "?(...) -> Any",
    "?(...) -> Any",
    1 },

  { "10 * () -> (...)",
    "10 * () -> (...)",
    1 },

  { "() -> (...)",
    "() -> (...)",
    1 },

  { "?() -> (...)",
    "?() -> (...)",
    1 },

  { "10 * (Any) -> Any",
    "10 * (Any) -> Any",
    1 },

  { "(Any) -> Any",
    "(Any) -> Any",
    1 },

  { "?(Any) -> Any",
    "?(Any) -> Any",
    1 },

  { "10 * () -> (Any)",
    "10 * () -> (Any)",
    1 },

  { "() -> (Any)",
    "() -> (Any)",
    1 },

  { "?() -> (Any)",
    "?() -> (Any)",
    1 },

  { "10 * (int64, Any) -> Any",
    "10 * (int64, Any) -> Any",
    1 },

  { "(int64, Any) -> Any",
    "(int64, Any) -> Any",
    1 },

  { "?(int64, Any) -> Any",
    "?(int64, Any) -> Any",
    1 },

  { "10 * () -> (int64, Any)",
    "10 * () -> (int64, Any)",
    1 },

  { "() -> (int64, Any)",
    "() -> (int64, Any)",
    1 },

  { "?() -> (int64, Any)",
    "?() -> (int64, Any)",
    1 },

  { "10 * (int64, int64, Any) -> Any",
    "10 * (int64, int64, Any) -> Any",
    1 },

  { "(int64, int64, Any) -> Any",
    "(int64, int64, Any) -> Any",
    1 },

  { "?(int64, int64, Any) -> Any",
    "?(int64, int64, Any) -> Any",
    1 },

  { "10 * () -> (int64, int64, Any)",
    "10 * () -> (int64, int64, Any)",
    1 },

  { "() -> (int64, int64, Any)",
    "() -> (int64, int64, Any)",
    1 },

  { "?() -> (int64, int64, Any)",
    "?() -> (int64, int64, Any)",
    1 },

  { "10 * (Any) -> Any",
    "10 * (Any) -> Any",
    1 },

  { "(Any) -> Any",
    "(Any) -> Any",
    1 },

  { "?(Any) -> Any",
    "?(Any) -> Any",
    1 },

  { "10 * () -> (Any)",
    "10 * () -> (Any)",
    1 },

  { "() -> (Any)",
    "() -> (Any)",
    1 },

  { "?() -> (Any)",
    "?() -> (Any)",
    1 },

  { "10 * (Any) -> Any",
    "10 * (Any) -> Any",
    1 },

  { "(Any) -> Any",
    "(Any) -> Any",
    1 },

  { "?(Any) -> Any",
    "?(Any) -> Any",
    1 },

  { "10 * () -> (Any)",
    "10 * () -> (Any)",
    1 },

  { "() -> (Any)",
    "() -> (Any)",
    1 },

  { "?() -> (Any)",
    "?() -> (Any)",
    1 },

  { "10 * (Any, ...) -> Any",
    "10 * (Any, ...) -> Any",
    1 },

  { "(Any, ...) -> Any",
    "(Any, ...) -> Any",
    1 },

  { "?(Any, ...) -> Any",
    "?(Any, ...) -> Any",
    1 },

  { "10 * () -> (Any, ...)",
    "10 * () -> (Any, ...)",
    1 },

  { "() -> (Any, ...)",
    "() -> (Any, ...)",
    1 },

  { "?() -> (Any, ...)",
    "?() -> (Any, ...)",
    1 },

  { "10 * (a : Any, ...) -> Any",
    "10 * (a : Any, ...) -> Any",
    1 },

  { "(a : Any) -> int64",
    "(a : Any) -> int64",
    1 },

  { "10 * (a : Any, ...) -> Any",
    "10 * (a : Any, ...) -> Any",
    1 },

  { "(a : Any, ...) -> Any",
    "(a : Any, ...) -> Any",
    1 },

  { "?(a : Any, ...) -> Any",
    "?(a : Any, ...) -> Any",
    1 },

  { "10 * (x : int64, a : Any, ...) -> Any",
    "10 * (x : int64, a : Any, ...) -> Any",
    1 },

  { "(x : int64, a : Any, ...) -> Any",
    "(x : int64, a : Any, ...) -> Any",
    1 },

  { "?(x : int64, a : Any, ...) -> Any",
    "?(x : int64, a : Any, ...) -> Any",
    1 },

  { "10 * (x : int64, x : int64, a : Any, ...) -> Any",
    "10 * (x : int64, x : int64, a : Any, ...) -> Any",
    1 },

  { "(x : int64, x : int64, a : Any, ...) -> Any",
    "(x : int64, x : int64, a : Any, ...) -> Any",
    1 },

  { "?(x : int64, x : int64, a : Any, ...) -> Any",
    "?(x : int64, x : int64, a : Any, ...) -> Any",
    1 },

  { "10 * (Any) -> Any",
    "10 * (Any) -> Any",
    1 },

  { "(Any) -> Any",
    "(Any) -> Any",
    1 },

  { "?(Any) -> Any",
    "?(Any) -> Any",
    1 },

  { "10 * (Any) -> Any",
    "10 * (Any) -> Any",
    1 },

  { "(Any) -> Any",
    "(Any) -> Any",
    1 },

  { "?(Any) -> Any",
    "?(Any) -> Any",

    1 },

  { "10 * (Any, ...) -> Any",
    "10 * (Any, ...) -> Any",
    1 },

  { "(Any, ...) -> Any",
    "(Any, ...) -> Any",
    1 },

  { "?(Any, ...) -> Any",
    "?(Any, ...) -> Any",
    1 },

  { "10 * (Any, a : Any) -> Any",
    "10 * (Any, a : Any) -> Any",
    1 },

  { "(Any, a : Any) -> Any",
    "(Any, a : Any) -> Any",
    1 },

  { "?(Any, a : Any) -> Any",
    "?(Any, a : Any) -> Any",
    1 },

  { "10 * (Any, ..., a : Any) -> Any",
    "10 * (Any, ..., a : Any) -> Any",
    1 },

  { "(Any, ..., a : Any) -> Any",
    "(Any, ..., a : Any) -> Any",
    1 },

  { "?(Any, ..., a : Any) -> Any",
    "?(Any, ..., a : Any) -> Any",
    1 },

  { "10 * (int64, Any, a : Any) -> Any",
    "10 * (int64, Any, a : Any) -> Any",
    1 },

  { "(int64, Any, a : Any) -> Any",
    "(int64, Any, a : Any) -> Any",
    1 },

  { "?(int64, Any, a : Any) -> Any",
    "?(int64, Any, a : Any) -> Any",
    1 },

  { "10 * (int64, Any, ..., a : Any) -> Any",
    "10 * (int64, Any, ..., a : Any) -> Any",
    1 },

  { "(int64, Any, ..., a : Any) -> Any",
    "(int64, Any, ..., a : Any) -> Any",
    1 },

  { "?(int64, Any, ..., a : Any) -> Any",
    "?(int64, Any, ..., a : Any) -> Any",
    1 },

  { "10 * (int64, int64, Any, a : Any) -> Any",
    "10 * (int64, int64, Any, a : Any) -> Any",
    1 },

  { "(int64, int64, Any, a : Any) -> Any",
    "(int64, int64, Any, a : Any) -> Any",
    1 },

  { "?(int64, int64, Any, a : Any) -> Any",
    "?(int64, int64, Any, a : Any) -> Any",
    1 },

  { "10 * (int64, int64, Any, ..., a : Any) -> Any",
    "10 * (int64, int64, Any, ..., a : Any) -> Any",
    1 },

  { "(int64, int64, Any, ..., a : Any) -> Any",
    "(int64, int64, Any, ..., a : Any) -> Any",
    1 },

  { "?(int64, int64, Any, ..., a : Any) -> Any",
    "?(int64, int64, Any, ..., a : Any) -> Any",
    1 },

  { "10 * (Any, a : Any) -> Any",
    "10 * (Any, a : Any) -> Any",
    1 },

  { "(Any, a : Any) -> Any",
    "(Any, a : Any) -> Any",
    1 },

  { "?(Any, a : Any) -> Any",
    "?(Any, a : Any) -> Any",
    1 },

  { "10 * (Any, x : int64, a : Any) -> Any",
    "10 * (Any, x : int64, a : Any) -> Any",
    1 },

  { "(Any, x : int64, a : Any) -> Any",
    "(Any, x : int64, a : Any) -> Any",
    1 },

  { "?(Any, x : int64, a : Any) -> Any",
    "?(Any, x : int64, a : Any) -> Any",
    1 },

  { "10 * (Any, x : int64, x : int64, a : Any) -> Any",
    "10 * (Any, x : int64, x : int64, a : Any) -> Any",
    1 },

  { "(Any, x : int64, x : int64, a : Any) -> Any",
    "(Any, x : int64, x : int64, a : Any) -> Any",
    1 },

  { "?(Any, x : int64, x : int64, a : Any) -> Any",
    "?(Any, x : int64, x : int64, a : Any) -> Any",
    1 },

  { "10 * (Any, a : Any) -> Any",
    "10 * (Any, a : Any) -> Any",
    1 },

  { "(Any, a : Any) -> Any",
    "(Any, a : Any) -> Any",
    1 },

  { "?(Any, a : Any) -> Any",
    "?(Any, a : Any) -> Any",
    1 },

  { "10 * (Any, ..., a : Any) -> Any",
    "10 * (Any, ..., a : Any) -> Any",
    1 },

  { "(Any, ..., a : Any) -> Any",
    "(Any, ..., a : Any) -> Any",
    1 },

  { "?(Any, ..., a : Any) -> Any",
    "?(Any, ..., a : Any) -> Any",
    1 },

  { "10 * (Any, a : Any) -> Any",
    "10 * (Any, a : Any) -> Any",
    1 },

  { "(Any, a : Any) -> Any",
    "(Any, a : Any) -> Any",
    1 },

  { "?(Any, a : Any) -> Any",
    "?(Any, a : Any) -> Any",
    1 },

  { "10 * (Any, ..., a : Any) -> Any",
    "10 * (Any, ..., a : Any) -> Any",
    1 },

  { "(Any, ..., a : Any) -> Any",
    "(Any, ..., a : Any) -> Any",
    1 },

  { "?(Any, ..., a : Any) -> Any",
    "?(Any, ..., a : Any) -> Any",
    1 },

  { "10 * (Any, a : Any, ...) -> Any",
    "10 * (Any, a : Any, ...) -> Any",
    1 },

  { "(Any, a : Any, ...) -> Any",
    "(Any, a : Any, ...) -> Any",
    1 },

  { "?(Any, a : Any, ...) -> Any",
    "?(Any, a : Any, ...) -> Any",
    1 },

  { "10 * (Any, ..., a : Any, ...) -> Any",
    "10 * (Any, ..., a : Any, ...) -> Any",
    1 },

  { "(Any, ..., a : Any, ...) -> Any",
    "(Any, ..., a : Any, ...) -> Any",
    1 },

  { "?(Any, ..., a : Any, ...) -> Any",
    "?(Any, ..., a : Any, ...) -> Any",
    1 },

  { "10 * Up",
    "10 * Up",
    1 },

  { "10 * X(Any)",
    "10 * X(Any)",
    1 },

  { "X(Any)",
    "X(Any)",
    1 },

  { "?X(Any)",
    "?X(Any)",
    1 },

  /* BEGIN RANDOM */
  { "fixed_bytes(size=1342281638, align=8)",
    "fixed_bytes(size=1342281638, align=8)",
    1 },

  { "?pointer(fixed_string(3865363101, 'ucs2'))",
    "?pointer(fixed_string(3865363101, 'ucs2'))",
    1 },

  { "ZmQxcy * var * 1098824011 * var * var * (...)",
    "ZmQxcy * var * 1098824011 * var * var * (...)",
    1 },

  { "categorical('a' : string, 1619552300 : uint64, 49062 : uint16, 18772 : int16, -84 : int8, 'l' : string)",
    "categorical('a' : string, 1619552300 : uint64, 49062 : uint16, 18772 : int16, -84 : int8, 'l' : string)",
    1 },

  { "?categorical(30987 : int16, -16536 : int16, 1.2e-32 : float32, 189 : uint8, -823800099 : int32)",
    "?categorical(30987 : int16, -16536 : int16, 1.2e-32 : float32, 189 : uint8, -823800099 : int32)",
    1 },

  { "categorical(1.2e-32 : float64, 2840608325 : uint32, 44038 : uint16, 1763886348 : uint32, 'jOt' : string, 24 : uint8)",
    "categorical(1.2e-32 : float64, 2840608325 : uint32, 44038 : uint16, 1763886348 : uint32, 'jOt' : string, 24 : uint8)",
    1 },

  { "categorical(-2049848438 : int32, 94 : uint8, 3599739756 : uint64, 3577056037 : uint32, 1.2e-32 : float32)",
    "categorical(-2049848438 : int32, 94 : uint8, 3599739756 : uint64, 3577056037 : uint32, 1.2e-32 : float32)",
    1 },

  { "categorical(2753441703 : uint32, 1.2e-32 : float32)",
    "categorical(2753441703 : uint32, 1.2e-32 : float32)",
    1 },

  { "1293035889 * SQc2jI * 508611408 * var * ... * var * FYqqwF * VKte * string",
    "1293035889 * SQc2jI * 508611408 * var * ... * var * FYqqwF * VKte * string",
    1 },

  { "1286044356 * LbR6JPFI * 2096958782 * uint8",
    "1286044356 * LbR6JPFI * 2096958782 * uint8",
    1 },

  { "categorical(1.2e-32 : float64, -25910 : int16, 'xM3Mys0XqH' : string, 4265882500 : uint64)",
    "categorical(1.2e-32 : float64, -25910 : int16, 'xM3Mys0XqH' : string, 4265882500 : uint64)",
    1 },

  { "var * 279953679 * NaZyx * ZQ * 221035040 * var * 1446706288 * FixedBytes",
    "var * 279953679 * NaZyx * ZQ * 221035040 * var * 1446706288 * FixedBytes",
    1 },

  { "SJBOs2xZm * var * ... * 4142176455 * BeL * 584505763 * Nf",
    "SJBOs2xZm * var * ... * 4142176455 * BeL * 584505763 * Nf",
    1 },

  { "S * 3750021327 * 66749723 * var * var * var * 3816827158 * IhlydZ515 * 1507982035 * fixed_bytes(size=2816010943, align=16)",
    "S * 3750021327 * 66749723 * var * var * var * 3816827158 * IhlydZ515 * 1507982035 * fixed_bytes(size=2816010943, align=16)",
    1 },

  { "3663546803 * 1650974226 * fixed_bytes(size=912328236, align=2)",
    "3663546803 * 1650974226 * fixed_bytes(size=912328236, align=2)",
    1 },

  { "BfM2hS6zey * var * 163901665 * var * 747688899 * FbU2mb * var * ZcTmBXnKPi",
    "BfM2hS6zey * var * 163901665 * var * 747688899 * FbU2mb * var * ZcTmBXnKPi",
    1 },

  { "?categorical(31275 : uint16, 69 : uint8, 1.2e-32 : float64)",
    "?categorical(31275 : uint16, 69 : uint8, 1.2e-32 : float64)",
    1 },

  { "3334650506 * var * var * ... * void",
    "3334650506 * var * var * ... * void",
    1 },

  { "categorical('omhwkoWVWw' : string, 43 : uint8, 946986991 : int64)",
    "categorical('omhwkoWVWw' : string, 43 : uint8, 946986991 : int64)",
    1 },

  { "2857261760 * var * 888172155 * float32",
    "2857261760 * var * 888172155 * float32",
    1 },

  { "RZxERR * var * var * 2828578146 * var * 2925191533 * uint16",
    "RZxERR * var * var * 2828578146 * var * 2925191533 * uint16",
    1 },

  { "2995650016 * var * N_IeNyWYjQ * ... * int16",
    "2995650016 * var * N_IeNyWYjQ * ... * int16",
    1 },

  { "var * var * var * 3340205417 * 2074830512 * Scalar",
    "var * var * var * 3340205417 * 2074830512 * Scalar",
    1 },

  { "?var * 199384207 * 3794803015 * LPLE0XH * EInCii3 * ... * 1462089522 * 531802952 * 1242541165 * int16",
    "?var * 199384207 * 3794803015 * LPLE0XH * EInCii3 * ... * 1462089522 * 531802952 * 1242541165 * int16",
    1 },

  { "fixed_bytes(size=280180385, align=8)",
    "fixed_bytes(size=280180385, align=8)",
    1 },

  { "fixed_string(1901614748, 'utf32')",
    "fixed_string(1901614748, 'utf32')",
    1 },

  { "A8w8pNJ * 3945513946 * 3057917060 * var * IFB * 1919373335 * M7",
    "A8w8pNJ * 3945513946 * 3057917060 * var * IFB * 1919373335 * M7",
    1 },

  { "?categorical(1.2e-32 : float64, 3715192786 : uint32, 1.2e-32 : float32, 'oJgBt_WUse' : string, -67 : int8)",
    "?categorical(1.2e-32 : float64, 3715192786 : uint32, 1.2e-32 : float32, 'oJgBt_WUse' : string, -67 : int8)",
    1 },

  { "3546970538 * var * 542837605 * J0fcbFoNy3 * 1766819960 * bytes(align=2)",
    "3546970538 * var * 542837605 * J0fcbFoNy3 * 1766819960 * bytes(align=2)",
    1 },

  { "3608776903 * MYlGTj * 1980216455 * Hce1_dqKx * var * Jfl * ... * E",
    "3608776903 * MYlGTj * 1980216455 * Hce1_dqKx * var * Jfl * ... * E",
    1 },

  { "2948091211 * ... * categorical(-1869840431 : int64, 2052908559 : uint32)",
    "2948091211 * ... * categorical(-1869840431 : int64, 2052908559 : uint32)",
    1 },

  { "fixed_bytes(size=1882259764, align=16)",
    "fixed_bytes(size=1882259764, align=16)",
    1 },

  { "categorical(1.2e-32 : float32, -58 : int8, -83 : int8)",
    "categorical(1.2e-32 : float32, -58 : int8, -83 : int8)",
    1 },

  { "3739637665 * 1476113530 * 1701021063 * IKd * 450514382 * WXn",
    "3739637665 * 1476113530 * 1701021063 * IKd * 450514382 * WXn",
    1 },

  { "pointer(AilcKv4su1(FixedBytes))",
    "pointer(AilcKv4su1(FixedBytes))",
    1 },

  { "R79_AhZau0 * 950069447 * 2112203142 * 3298306739 * var * ... * complex128",
    "R79_AhZau0 * 950069447 * 2112203142 * 3298306739 * var * ... * complex128",
    1 },

  { "?fixed_string(2371793992, 'ucs2')",
    "?fixed_string(2371793992, 'ucs2')",
    1 },

  { "var * 3432474393 * ... * 1514376178 * R8KFFEabJ",
    "var * 3432474393 * ... * 1514376178 * R8KFFEabJ",
    1 },

  { "?fixed_bytes(size=3129686755, align=8)",
    "?fixed_bytes(size=3129686755, align=8)",
    1 },

  { "var * 2253137925 * VUx39mzbW * QoFb",
    "var * 2253137925 * VUx39mzbW * QoFb",
    1 },

  { "57676169 * var * ... * fixed_string(1464831555, 'ucs2')",
    "57676169 * var * ... * fixed_string(1464831555, 'ucs2')",
    1 },

  { "var * 2859160145 * fixed_string(1233383142, 'utf32')",
    "var * 2859160145 * fixed_string(1233383142, 'utf32')",
    1 },

  { "fixed_bytes(size=2882797968, align=16)",
    "fixed_bytes(size=2882797968, align=16)",
    1 },

  { "fixed_bytes(size=1233209957, align=8)",
    "fixed_bytes(size=1233209957, align=8)",
    1 },

  { "WhRsMHHXYp(categorical(145 : uint8))",
    "WhRsMHHXYp(categorical(145 : uint8))",
    1 },

  { "?categorical(4079164787 : uint64, 23814 : int16)",
    "?categorical(4079164787 : uint64, 23814 : int16)",
    1 },

  { "?categorical(123 : uint8, 1.2e-32 : float64, 'piLDeH2' : string, 214836863 : uint32)",
    "?categorical(123 : uint8, 1.2e-32 : float64, 'piLDeH2' : string, 214836863 : uint32)",
    1 },

  { "var * var * Z * LWfWfV6Gp6 * O8 * GWLJMYrf * 756518781 * PDVa3IbLt * bytes(align=16)",
    "var * var * Z * LWfWfV6Gp6 * O8 * GWLJMYrf * 756518781 * PDVa3IbLt * bytes(align=16)",
    1 },

  { "categorical(-49 : int8, -26791 : int16, 1780 : uint16, -85 : int8, 'pX' : string, 8094 : int16, 1.2e-32 : float64)",
    "categorical(-49 : int8, -26791 : int16, 1780 : uint16, -85 : int8, 'pX' : string, 8094 : int16, 1.2e-32 : float64)",
    1 },

  { "D6nfBg_(categorical(147170982 : uint32, 16278 : int16, 1.2e-32 : float32, 'ylR7' : string, 26651 : int16))",
    "D6nfBg_(categorical(147170982 : uint32, 16278 : int16, 1.2e-32 : float32, 'ylR7' : string, 26651 : int16))",
    1 },

  { "categorical(-1.2e-32 : float64, 3229733591 : uint64, 482331467 : uint64, 1.2e-32 : float64)",
    "categorical(-1.2e-32 : float64, 3229733591 : uint64, 482331467 : uint64, 1.2e-32 : float64)",
    1 },

  /* END RANDOM */

  /* BEGIN MANUALLY GENERATED */

  { "()",
    "()",
    1 },

  { "(...)",
    "(...)",
    1 },

  { "{}",
    "{}",
    1 },

  { "{...}",
    "{...}",
    1 },

  { "() -> ()",
    "() -> ()",
    1 },

  { "(...) -> ()",
    "(...) -> ()",
    1 },

  { "(...) -> (...)",
    "(...) -> (...)",
    1 },

  { "(..., a : int64, ...) -> complex128",
    "(..., a : int64, ...) -> complex128",
    1 },

  { "() -> int32",
    "() -> int32",
    1 },

  { "(int32) -> int32",
    "(int32) -> int32",
    1 },

  { "(int32, float64) -> int32",
    "(int32, float64) -> int32",
    1 },

  { "(scale : float64) -> int32",
    "(scale : float64) -> int32",
    1 },

  { "(scale : float64, color : float64) -> int32",
    "(scale : float64, color : float64) -> int32",
    1 },

  { "(int32, scale : float64) -> int32",
    "(int32, scale : float64) -> int32",
    1 },

  { "(int32, scale : float64, color : float64) -> int32",
    "(int32, scale : float64, color : float64) -> int32",
    1 },

  { "(int32, float32, scale : float64, color : float64) -> int32",
    "(int32, float32, scale : float64, color : float64) -> int32",
    1 },

  { "(...) -> int32",
    "(...) -> int32",
    1 },

  { "(int32, ...) -> int32",
    "(int32, ...) -> int32",
    1 },

  { "(int32, float32, ...) -> int32",
    "(int32, float32, ...) -> int32",
    1 },

  { "(scale : float64, ...) -> int32",
    "(scale : float64, ...) -> int32",
    1 },

  { "(scale : float64, color : float64, ...) -> int32",
    "(scale : float64, color : float64, ...) -> int32",
    1 },

  { "(..., scale : float64) -> int32",
    "(..., scale : float64) -> int32",
    1 },

  { "(int32, ..., scale : float64) -> int32",
    "(int32, ..., scale : float64) -> int32",
    1 },

  { "(int32, float32, ..., scale : float64) -> int32",
    "(int32, float32, ..., scale : float64) -> int32",
    1 },

  { "(int32, scale : float64, ...) -> int32",
    "(int32, scale : float64, ...) -> int32",
    1 },

  { "(int32, float32, scale : float64, color : float64, ...) -> int32",
    "(int32, float32, scale : float64, color : float64, ...) -> int32",
    1 },

  { "(..., scale : float64, ...) -> int32",
    "(..., scale : float64, ...) -> int32",
    1 },

  { "(int32, ..., scale : float64, color : float64, ...) -> int32",
    "(int32, ..., scale : float64, color : float64, ...) -> int32",
    1 },

  { "(int32, float32, ..., scale : float64, color : float64, ...) -> int32",
    "(int32, float32, ..., scale : float64, color : float64, ...) -> int32",
    1 },


  { "10 * defined_t",
    "10 * defined_t",
    1 },

  { "defined_t",
    "defined_t",
    1 },

  { "?defined_t",
    "?defined_t",
    1 },

  { "defined_t",
    "defined_t",
    1 },

  { "(int32, float32, ..., scale : defined_t, color : float64, ...) -> defined_t",
    "(int32, float32, ..., scale : defined_t, color : float64, ...) -> defined_t",
    1 },

  { "(a : pointer({b : defined_t, c : (defined_t, int16) -> float64})) -> defined_t",
    "(a : pointer({b : defined_t, c : (defined_t, int16) -> float64})) -> defined_t",
    1 },


  { "10 * foo_t",
    "10 * foo_t",
    1 },

  { "foo_t",
    "foo_t",
    1 },

  { "?foo_t",
    "?foo_t",
    1 },

  { "foo_t",
    "foo_t",
    1 },

  { "(int32, float32, ..., scale : defined_t, color : float64, ...) -> foo_t",
    "(int32, float32, ..., scale : defined_t, color : float64, ...) -> foo_t",
    1 },

  { "(a : pointer({b : defined_t, c : (foo_t, int16) -> float64})) -> foo_t",
    "(a : pointer({b : defined_t, c : (foo_t, int16) -> float64})) -> foo_t",
    1 },

  { "10 * foo_t",
    "10 * foo_t", 1 },

  { "10 * foo_t",
    "11 * foo_t", 0 },

  { "N * foo_t",
    "10 * foo_t", 1 },

  { "N * foo_t",
    "10 * int64", 0 },

  { "... * foo_t",
    "10 * foo_t", 1 },

  { "... * foo_t",
    "... * foo_t", 1 },

  { "... * foo_t",
    "... * 10 * foo_t", 1 },

  { "... * 10 * foo_t",
    "... * foo_t", 0 },

  { "... * 10 * var * foo_t",
    "... * foo_t", 0 },

  { "... * foo_t",
    "... * 10 * var * foo_t", 1 },

  { "N * N * foo_t",
    "10 * 10 * foo_t", 1 },

  { "N * N * foo_t",
    "10 * 20 * var * foo_t", 0 },

  { "N * Z * foo_t",
    "10 * 20 * foo_t", 1 },

  { "N * Z * ... * foo_t",
    "10 * 20 * var * foo_t", 1 },

  { "N * Z * ... * foo_t",
    "10 * 20 * var * 10 * ... * foo_t", 1 },

  { "N * Z * ... * foo_t",
    "10 * 20 * var * 10 * ... * foo_t", 1 },

  { "N * Z * ... * N * foo_t",
    "10 * 20 * var * 10 * ... * 10 * foo_t", 1 },

  { "N * Z * ... * N * foo_t",
    "10 * 20 * var * 10 * ... * 10 * foo_t", 1 },

  { "N * Z * ... * N * foo_t",
    "10 * 20 * var * 10 * ... * 20 * foo_t", 0 },

  { "N * Z * ... * N * foo_t",
    "A * 20 * var * 10 * ... * A * foo_t", 1 },

  { "N * Z * ... * N * Z * foo_t",
    "10 * 20 * var * 10 * ... * 10 * 20 * foo_t", 1 },

  { "N * Z * ... * 10 * N * Z * foo_t",
    "10 * 20 * var * 10 * ... * 10 * 20 * foo_t", 0 },

  /* Half-float */
  { "3 * float16",
    "3 * float16", 1 },

  { "3 * float32",
    "3 * float16", 0 },

  { "3 * complex32",
    "3 * complex32", 1 },

  { "3 * complex64",
    "3 * complex32", 0 },

  /* Named dtypes using the constructor syntax */
  { "3 * Matrix(3 * 3 * float64)",
    "3 * Matrix(3 * 3 * float64)", 1 },

  { "3 * Matrix(3 * 3 * float64)",
    "3 * 3 * 3 * float64", 0 },

  { "3 * Matrix(3 * 3 * float64)",
    "3 * OtherMatrix(3 * 3 * float64)", 0 },

  /* Named ellipses */
  { "Dims... * 2 * 3 * int64",
    "2 * 3 * int64", 1 },

  { "... * 2 * 3 * int64",
    "2 * 3 * int64", 1 },

  { "(Dims... * 2 * 3 * int64, Dims... * 2 * 3 * int64)",
    "(2 * 3 * int64, 2 * 3 * int64)", 1 },

  { "A... * float64",
    "A... * float64", 1 },

  { "(A... * float64, A... * float64)",
    "(A... * float64, A... * float64)", 1 },

  { "A... * float64",
    "3 * 5 * float64", 1 },

  { "A... * float64",
    "B... * float64", 1 },

  { "(A... * float64, A... * float64) -> A... * float64",
    "(3 * 5 * float64, 3 * 5 * float64) -> 3 * 5 * float64", 1 },

  { "(A... * float64, A... * float32, B... * float32)",
    "(B... * float64, 2 * var * float32, 3 * var * float32)", 0 },

  { "(A... * float64, A... * float64)",
    "(3 * 5 * float64, 3 * 5 * float64)", 1 },

  { "(3 * A... * float64, 3 * A... * float64)",
    "(3 * 5 * 10 *  float64, 3 * 5 * 10 * float64)", 1 },

  { "(A... * float64, A... * float64)",
    "(3 * 5 * float64, 3 * 4 * float64)", 0 },

  { "(A... * float64, A... * float64)",
    "(3 * 5 * float64, 3 * 5 * 6 * float64)", 0 },

  { "(A... * float64, A... * float32, B... * float32)",
    "(B... * float64, 3 * float32, 3 * float32)", 0 },

  { "(A... * float64, A... * float32, B... * float32)",
    "(B... * float64, 3 * ... * float32, 3 * ... * float32)", 0 },

  { "(3 * A... * float64, 3 * A... * float64)",
    "(3 * 5 * 10 *  float64, 3 * 5 * 2 * 10 * float64)", 0 },

  { "(A... * float64, A... * float64)",
    "(B... * float64, A... * float64)", 0 },

  { "(A... * float64, A... * float64)",
    "(A... * float64, B... * float64)", 0 },

  { "(A... * float64,  B... * float64,  C... * float64,    A... * float64)",
    "(B... * float64,  C... * float64,  3 * 10 * float64,  3 * 11 * float64)", 0 },

  { "(A... * float64,  B... * float64,  C... * float64,    A... * float64)",
    "(B... * float64,  C... * float64,  3 * 10 * float64,  3 * 10 * float64)", 0 },

  { "(A * float64,  B * float64,  C * float64,  A * float64)",
    "(B * float64,  C * float64,  3 * float64,  3 * float64)", 0 },

  { "(M * N * T, N * P * T)",
    "(2 * 3 * int64, 3 * 10 * int64)", 1 },

  { "... * M * N * T",
    "2 * 3 * int64", 1 },

  { "(... * M * N * T, ... * N * P * T)",
    "(2 * 3 * int64, 3 * 10 * int64)", 1 },

  { "(Dims... * M * N * T, Dims... * N * P * T)",
    "(2 * 3 * int64, 3 * 10 * int64)", 1 },

  { "(Dims... * M * N * T, Dims... * N * P * T)",
    "(2 * 3 * int64, 2 * 10 * int64)", 0 },

#if 0
  /* ndarray */
  { "[10 * 2 * int64, style='ndarray']",
    "[10 * 2 * int64, style='ndarray']", 1 },

  { "[10 * 2 * int32, style='ndarray']",
    "[10 * 2 * int64, style='ndarray']", 0 },

  { "[10 * N * int64, style='ndarray']",
    "[10 * 2 * int64, style='ndarray']", 1 },

  { "[10 * 2 * int64, style='ndarray']",
    "[10 * N * int64, style='ndarray']", 0 },

  { "[N * M * int64, style='ndarray']",
    "[10 * 2 * int64, style='ndarray']", 1 },

  { "[10 * 2 * int64, order='F', style='ndarray']",
    "[10 * 2 * int64, order='F', style='ndarray']", 1 },

  { "[10 * 2 * int64, order='C', style='ndarray']",
    "[10 * 2 * int64, order='F', style='ndarray']", 0 },

  { "[10 * 2 * int64, order='F', style='ndarray']",
    "[10 * 2 * int64, order='C', style='ndarray']", 0 },
#endif

  /* END MANUALLY GENERATED */

  { NULL, NULL, 0 }
};
