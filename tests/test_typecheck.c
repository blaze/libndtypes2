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


const typecheck_testcase_t typecheck_tests[] = {
  { "() -> float32",
    "()",
    "float32" },

  { "() -> T",
    "()",
    NULL },

  { "(T) -> T",
    "(T)",
    NULL },

  { "(T) -> T",
    "(int64)",
    "int64" },

  { "(M * N * T, N * P * T) -> M * P * T",
    "(2 * 3 * int64, 3 * 10 * int64)",
    "2 * 10 * int64" },

  { "(Dims... * M * N * T, Dims... * N * P * T) -> Dims... * M * P * T",
    "(2 * 3 * int64, 3 * 10 * int64)",
    "2 * 10 * int64" },

  { "(Dims... * M * N * T, Dims... * N * P * T) -> Dims... * M * P * T",
    "(2 * 3 * int64, 3 * 10 * int32)",
    NULL },

  { "(Dims... * M * N * T, Dims... * N * P * T) -> Dims... * M * P * T",
    "(3 * int64, 3 * 10 * int64)",
    NULL },

  { "(Dims... * M * N * T, Dims... * N * P * T) -> Dims... * M * T",
    "(2 * 3 * int64, 3 * 10 * int64)",
    "2 * int64" },

  { "(Dims... * M * T, Dims... * N * T) -> Dims... * M * T",
    "(2 * 3 * int64, 3 * 3 * int64)",
    NULL },

  { "(Dims... * M * T, Dims... * N * T) -> Dims... * M * T",
    "(2 * 3 * int64, 3 * 3 * int64)",
    NULL },

  { "(M * N * T, N * P * T) -> M * P * T",
    "(2 * 3 * int64, 2 * 10 * int64)",
    NULL },

  { "(M * N * T, N * P * T) -> M * P * T",
    "(2 * 3 * int64, 3 * 10 * int32)",
    NULL },

  { "(Dims... * M * N * T, Dims... * N * P * T) -> Dims... * M * P * T",
    "(3 * int64, 3 * 10 * int64)",
    NULL },

  { "(Dims... * M * N * T, Dims... * N * P * T) -> Dims... * M * P * T",
    "(2 * 3 * int64, 3 * 10 * int64)",
    "2 * 10 * int64" },

  { "(Dims... * M * N * T, Dims... * N * P * T) -> Dims... * M * P * T",
    "(400 * 2 * 3 * int64, 400 * 3 * 10 * int64)",
    "400 * 2 * 10 * int64" },

  { "(pointer(Dims... * M * N * T), pointer(Dims... * N * P * T)) -> Dims... * M * P * T",
    "(pointer(400 * 2 * 3 * int64), pointer(400 * 3 * 10 * int64))",
    "400 * 2 * 10 * int64" },

  { "(pointer(Dims... * M * N * T), pointer(Dims... * N * P * T)) -> pointer(Dims... * M * P * T)",
    "(pointer(400 * 2 * 3 * int64), pointer(400 * 3 * 10 * int64))",
    "pointer(400 * 2 * 10 * int64)" },

  { NULL, NULL, 0 }
};
