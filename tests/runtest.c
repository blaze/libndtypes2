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
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ndtypes.h"
#include "test.h"
#include "alloc_fail.h"


static int
init_tests(void)
{
    ndt_context_t *ctx;
    ndt_t *t = NULL;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    if (ndt_init(ctx) < 0) {
        ndt_err_fprint(stderr, ctx);
        ndt_context_del(ctx);
        return -1;
    }

    t = ndt_from_string("{a: size_t, b: pointer(string)}", ctx);
    if (t == NULL) {
        ndt_err_fprint(stderr, ctx);
        ndt_context_del(ctx);
        return -1;
    }
    if (ndt_typedef("defined_t", t, ctx) < 0) {
        ndt_err_fprint(stderr, ctx);
        ndt_context_del(ctx);
        return -1;
    }

    t = ndt_from_string("(10 * 2 * defined_t)", ctx);
    if (t == NULL) {
        ndt_err_fprint(stderr, ctx);
        ndt_context_del(ctx);
        return -1;
    }
    if (ndt_typedef("foo_t", t, ctx) < 0) {
        ndt_err_fprint(stderr, ctx);
        ndt_context_del(ctx);
        return -1;
    }

    ndt_context_del(ctx);
    return 0;
}

static int
test_parse(void)
{
    const char **c;
    ndt_context_t *ctx;
    ndt_t *t;
    char *s;
    int count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (c = parse_tests; *c != NULL; c++) {
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            ndt_set_alloc_fail();
            t = ndt_from_string(*c, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (t != NULL) {
                ndt_del(t);
                ndt_context_del(ctx);
                fprintf(stderr, "test_parse: parse: FAIL: t != NULL after MemoryError\n");
                fprintf(stderr, "test_parse: parse: FAIL: %s\n", *c);
                return -1;
            }
        }
        if (t == NULL) {
            fprintf(stderr, "test_parse: parse: FAIL: expected success: \"%s\"\n", *c);
            fprintf(stderr, "test_parse: parse: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_context_del(ctx);
            return -1;
        }

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            ndt_set_alloc_fail();
            s = ndt_as_string(t, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (s != NULL) {
                ndt_free(s);
                ndt_del(t);
                ndt_context_del(ctx);
                fprintf(stderr, "test_parse: convert: FAIL: s != NULL after MemoryError\n");
                fprintf(stderr, "test_parse: parse: FAIL: %s\n", *c);
                return -1;
            }
        }
        if (s == NULL) {
            fprintf(stderr, "test_parse: convert: FAIL: expected success: \"%s\"\n", *c);
            fprintf(stderr, "test_parse: convert: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_del(t);
            ndt_context_del(ctx);
            return -1;
        }

        ndt_free(s);
        ndt_del(t);
        count++;
    }
    fprintf(stderr, "test_parse (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int
test_parse_roundtrip(void)
{
    const char **c;
    ndt_context_t *ctx;
    ndt_t *t;
    char *s;
    int count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (c = parse_roundtrip_tests; *c != NULL; c++) {
        t = ndt_from_string(*c, ctx);
        if (t == NULL) {
            fprintf(stderr, "test_parse_roundtrip: parse: FAIL: expected success: \"%s\"\n", *c);
            fprintf(stderr, "test_parse_roundtrip: parse: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_context_del(ctx);
            return -1;
        }

        s = ndt_as_string(t, ctx);
        if (s == NULL) {
            fprintf(stderr, "test_parse_roundtrip: convert: FAIL: expected success: \"%s\"\n", *c);
            fprintf(stderr, "test_parse_roundtrip: convert: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_del(t);
            ndt_context_del(ctx);
            return -1;
        }

        if (strcmp(s, *c) != 0) {
            fprintf(stderr, "test_parse_roundtrip: convert: FAIL: input:     \"%s\"\n", *c);
            fprintf(stderr, "test_parse_roundtrip: convert: FAIL: roundtrip: \"%s\"\n", s);
            ndt_free(s);
            ndt_del(t);
            ndt_context_del(ctx);
            return -1;
        }

        ndt_free(s);
        ndt_del(t);
        count++;
    }
    fprintf(stderr, "test_parse_roundtrip (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int
test_parse_error(void)
{
    const char **c;
    ndt_context_t *ctx;
    ndt_t *t;
    int count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (c = parse_error_tests; *c != NULL; c++) {
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            ndt_set_alloc_fail();
            t = ndt_from_string(*c, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (t != NULL) {
                ndt_del(t);
                ndt_context_del(ctx);
                fprintf(stderr, "test_parse_error: FAIL: t != NULL after MemoryError\n");
                fprintf(stderr, "test_parse_error: FAIL: input: %s\n", *c);
                return -1;
            }
        }
        if (t != NULL) {
            fprintf(stderr, "test_parse_error: FAIL: unexpected success: \"%s\"\n", *c);
            fprintf(stderr, "test_parse_error: FAIL: t != NULL after %s: %s\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_del(t);
            ndt_context_del(ctx);
            return -1;
        }
        count++;
    }
    fprintf(stderr, "test_parse_error (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int
test_indent(void)
{
    const indent_testcase_t *tc;
    const char **c;
    ndt_context_t *ctx;
    ndt_t *t;
    char *s;
    int count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (c = parse_tests; *c != NULL; c++) {
        t = ndt_from_string(*c, ctx);
        if (t == NULL) {
            fprintf(stderr, "test_indent: parse: FAIL: expected success: \"%s\"\n", *c);
            fprintf(stderr, "test_indent: parse: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_context_del(ctx);
            return -1;
        }

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            ndt_set_alloc_fail();
            s = ndt_indent(t, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (s != NULL) {
                ndt_free(s);
                ndt_del(t);
                ndt_context_del(ctx);
                fprintf(stderr, "test_indent: convert: FAIL: s != NULL after MemoryError\n");
                fprintf(stderr, "test_indent: convert: FAIL: %s\n", *c);
                return -1;
            }
        }
        if (s == NULL) {
            fprintf(stderr, "test_indent: convert: FAIL: expected success: \"%s\"\n", *c);
            fprintf(stderr, "test_indent: convert: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_del(t);
            ndt_context_del(ctx);
            return -1;
        }

        ndt_free(s);
        ndt_del(t);
        count++;
    }

    for (tc = indent_tests; tc->input != NULL; tc++) {
        t = ndt_from_string(tc->input, ctx);
        if (t == NULL) {
            fprintf(stderr, "test_indent: parse: FAIL: expected success: \"%s\"\n", tc->input);
            fprintf(stderr, "test_indent: parse: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_context_del(ctx);
            return -1;
        }

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            ndt_set_alloc_fail();
            s = ndt_indent(t, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (s != NULL) {
                ndt_free(s);
                ndt_del(t);
                ndt_context_del(ctx);
                fprintf(stderr, "test_indent: convert: FAIL: s != NULL after MemoryError\n");
                fprintf(stderr, "test_indent: convert: FAIL: %s\n", tc->input);
                return -1;
            }
        }
        if (s == NULL) {
            fprintf(stderr, "test_indent: convert: FAIL: expected success: \"%s\"\n", tc->input);
            fprintf(stderr, "test_indent: convert: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_del(t);
            ndt_context_del(ctx);
            return -1;
        }

        if (strcmp(s, tc->indented) != 0) {
            fprintf(stderr, "test_indent: convert: FAIL: expected success: \"%s\"\n", tc->input);
            fprintf(stderr, "test_indent: convert: FAIL: got: %s: %s\n\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_del(t);
            ndt_context_del(ctx);
            return -1;
        }

        ndt_free(s);
        ndt_del(t);
        count++;
    }

    fprintf(stderr, "test_indent (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int
test_typedef(void)
{
    const char **c;
    ndt_context_t *ctx;
    ndt_t *t;
    int count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (c = typedef_tests; *c != NULL; c++) {
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            t = ndt_from_string("10 * 20 * {a : int64, b : pointer(float64)}", ctx);

            ndt_set_alloc_fail();
            (void)ndt_typedef(*c, t, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (ndt_typedef_find(*c, ctx) != NULL) {
                fprintf(stderr, "test_typedef: FAIL: key in map after MemoryError\n");
                fprintf(stderr, "test_typedef: FAIL: input: %s\n", *c);
                ndt_context_del(ctx);
                return -1;
            }
        }

        if (ndt_typedef_find(*c, ctx) == NULL) {
            fprintf(stderr, "test_typedef: FAIL: key not found: \"%s\"\n", *c);
            fprintf(stderr, "test_typedef: FAIL: lookup failed after %s: %s\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_context_del(ctx);
            return -1;
        }

        count++;
    }

    fprintf(stderr, "test_typedef (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int
test_typedef_duplicates(void)
{
    const char **c;
    ndt_context_t *ctx;
    ndt_t *t;
    int count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (c = typedef_tests; *c != NULL; c++) {
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            t = ndt_from_string("10 * 20 * {a : int64, b : pointer[float64]}", ctx);

            ndt_set_alloc_fail();
            (void)ndt_typedef(*c, t, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (ndt_typedef_find(*c, ctx) == NULL) {
                fprintf(stderr, "test_typedef: FAIL: key should be in map\n");
                fprintf(stderr, "test_typedef: FAIL: input: %s\n", *c);
                ndt_context_del(ctx);
                return -1;
            }
        }

        if (ctx->err != NDT_ValueError) {
            fprintf(stderr, "test_typedef: FAIL: no value error after duplicate key\n");
            fprintf(stderr, "test_typedef: FAIL: input: %s\n", *c);
            ndt_context_del(ctx);
            return -1;
        }

        count++;
    }

    fprintf(stderr, "test_typedef_duplicates (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int
test_typedef_error(void)
{
    const char **c;
    ndt_context_t *ctx;
    ndt_t *t;
    int count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (c = typedef_error_tests; *c != NULL; c++) {
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            t = ndt_from_string("10 * 20 * {a : int64, b : pointer[float64]}", ctx);

            ndt_set_alloc_fail();
            (void)ndt_typedef(*c, t, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (ndt_typedef_find(*c, ctx) != NULL) {
                fprintf(stderr, "test_typedef_error: FAIL: key in map after MemoryError\n");
                fprintf(stderr, "test_typedef: FAIL: input: %s\n", *c);
                ndt_context_del(ctx);
                return -1;
            }
        }

        if (ndt_typedef_find(*c, ctx) != NULL) {
            fprintf(stderr, "test_typedef_error: FAIL: unexpected success: \"%s\"\n", *c);
            fprintf(stderr, "test_typedef_error: FAIL: key in map after %s: %s\n",
                    ndt_err_as_string(ctx->err),
                    ndt_context_msg(ctx));
            ndt_context_del(ctx);
            return -1;
        }

        count++;
    }

    fprintf(stderr, "test_typedef_error (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int
test_equal(void)
{
    const char **c;
    ndt_context_t *ctx;
    ndt_t *t, *u;
    int count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (c = parse_roundtrip_tests; *c && *(c+1); c++) {
        ndt_err_clear(ctx);

        t = ndt_from_string(*c, ctx);
        if (t == NULL) {
            ndt_context_del(ctx);
            fprintf(stderr, "test_equal: FAIL: could not parse \"%s\"\n", *c);
            return -1;
        }

        u = ndt_from_string(*(c+1), ctx);
        if (u == NULL) {
            ndt_del(t);
            ndt_context_del(ctx);
            fprintf(stderr, "test_equal: FAIL: could not parse \"%s\"\n", *(c+1));
            return -1;
        }

        if (!ndt_equal(t, t)) {
            ndt_del(t);
            ndt_del(u);
            ndt_context_del(ctx);
            fprintf(stderr, "test_equal: FAIL: \"%s\" != \"%s\"\n", *c, *c);
            return -1;
        }

        if (ndt_equal(t, u)) {
            ndt_del(t);
            ndt_del(u);
            fprintf(stderr, "test_equal: FAIL: \"%s\" == \"%s\"\n", *c, *(c+1));
            return -1;
        }

        ndt_del(t);
        ndt_del(u);
        count++;
    }

    fprintf(stderr, "test_equal (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int
test_match(void)
{
    const match_testcase_t *t;
    ndt_context_t *ctx;
    ndt_t *p;
    ndt_t *c;
    int ret, count = 0;

    ctx = ndt_context_new();
    if (ctx == NULL) {
        fprintf(stderr, "error: out of memory");
        return -1;
    }

    for (t = match_tests; t->pattern != NULL; t++) {
        p = ndt_from_string(t->pattern, ctx);
        if (p == NULL) {
            fprintf(stderr, "test_match: FAIL: could not parse \"%s\"\n", t->pattern);
            ndt_context_del(ctx);
            return -1;
        }

        c = ndt_from_string(t->candidate, ctx);
        if (c == NULL) {
            ndt_del(p);
            ndt_context_del(ctx);
            fprintf(stderr, "test_match: FAIL: could not parse \"%s\"\n", t->candidate);
            return -1;
        }

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ndt_err_clear(ctx);

            ndt_set_alloc_fail();
            ret = ndt_match(p, c, ctx);
            ndt_set_alloc();

            if (ctx->err != NDT_MemoryError) {
                break;
            }

            if (ret != -1) {
                ndt_del(p);
                ndt_del(c);
                ndt_context_del(ctx);
                fprintf(stderr, "test_match: FAIL: expect ret == -1 after MemoryError\n");
                fprintf(stderr, "test_match: FAIL: \"%s\"\n", t->pattern);
                return -1;
            }
        }

        if (ret != t->expected) {
            ndt_del(p);
            ndt_del(c);
            ndt_context_del(ctx);
            fprintf(stderr, "test_match: FAIL: expected %s\n", t->expected ? "true" : "false");
            fprintf(stderr, "test_match: FAIL: pattern: \"%s\"\n", t->pattern);
            fprintf(stderr, "test_match: FAIL: candidate: \"%s\"\n", t->candidate);
            return -1;
        }

        ndt_del(p);
        ndt_del(c);
        count++;
    }
    fprintf(stderr, "test_match (%d test cases)\n", count);

    ndt_context_del(ctx);
    return 0;
}

static int (*tests[])(void) = {
  test_parse,
  test_parse_error,
  test_parse_roundtrip,
  test_indent,
  test_typedef,
  test_typedef_duplicates,
  test_typedef_error,
  test_equal,
  test_match,
#ifdef __GNUC__
  test_struct_align_pack,
#endif
  NULL
};

int
main(void)
{
    int (**f)(void);
    int success = 0;
    int fail = 0;

    if (init_tests() < 0) {
        return 1;
    }

    for (f = tests; *f != NULL; f++) {
        if ((*f)() < 0)
            fail++;
        else
            success++;
    }

    if (fail) {
        fprintf(stderr, "\nFAIL (failures=%d)\n", fail);
    }
    else {
        fprintf(stderr, "\n%d tests OK.\n", success);
    }

    ndt_finalize();
    return fail ? 1 : 0;
}
