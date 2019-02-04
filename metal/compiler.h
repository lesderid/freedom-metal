/* Copyright 2018 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#ifndef METAL__COMPILER_H
#define METAL__COMPILER_H

#define __METAL_DECLARE_VTABLE(type)                        \
    asm(".weak " #type);                                  \
    const struct type type                                \

#define __METAL_GET_FIELD(reg, mask)                        \
    (((reg) & (mask)) / ((mask) & ~((mask) << 1)))

/* Set field with mask for a given value */
#define __MEE_SET_FIELD(reg, mask, val) \
        (((reg) & ~(mask)) | (((val) * ((mask) & ~((mask) << 1))) & (mask)))

#endif