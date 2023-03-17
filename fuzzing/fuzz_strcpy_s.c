/*  SPDX-License-Identifier: MIT */
/*
*  Copyright (c) 2014 by Intel Corp
/*------------------------------------------------------------------
 * fuzz_strcpy_s
 *
 *
 *------------------------------------------------------------------
 */

#include "test_private.h"
#include "safe_str_lib.h"

#define MAX   ( 128 )
#define LEN   ( 128 )

static char   str1[LEN];
static char   str2[LEN];

int test_strcpy_s (void)
{
    errno_t rc;
#ifdef SAFE_LIB_STR_NULL_SLACK
    uint32_t i;
#endif /*SAFE_LIB_STR_NULL_SLACK*/
    int32_t  ind;

    strcpy(str1, "qqweqeqeqeq");
    strcpy(str2, "keep it simple");

    rc = strcpy_s(str1, LEN, str2);
    if (rc != EOK) {
        debug_printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__,  rc );
    }

    /* be sure the results are the same as strcmp */
    ind = strcmp(str1, str2);
    if (ind != 0) {
        debug_printf("%s %u -%s-  Error rc=%u \n",
                     __FUNCTION__, __LINE__,  str1, rc );
    }

    return (0);
}


