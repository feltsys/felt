## SPDX-License-Identifier: GPL-2.0-only
## Copyright (c) 2024, VX/sys Contributors

CC := clang --target=$(LLVM_TARGET)
LD := ld.lld
CPPFLAGS += -nostdlibinc
