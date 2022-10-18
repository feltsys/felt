/* SPDX-License-Identifier: BSD-2-Clause */
/* Copyright (c), 2022, Kaneru Contributors */
#ifndef __INCLUDE_X86_64_GDT_H__
#define __INCLUDE_X86_64_GDT_H__
#include <kaneru/initcall.h>

#define GDT_INDEX_NULL_NEITHER 0
#define GDT_INDEX_KERN_CODE_16 1
#define GDT_INDEX_KERN_DATA_16 2
#define GDT_INDEX_KERN_CODE_32 3
#define GDT_INDEX_KERN_DATA_32 4
#define GDT_INDEX_KERN_CODE_64 5
#define GDT_INDEX_KERN_DATA_64 6
#define GDT_INDEX_USER_CODE_64 7
#define GDT_INDEX_USER_DATA_64 8
#define GDT_SELECTOR(index, ldt, ring) (((ring) & 4) | (((ldt) & 1) << 2) | (index) << 3)

initcall_extern(gdt);

#endif /* __INCLUDE_X86_64_GDT_H__ */
