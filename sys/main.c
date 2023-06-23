/* SPDX-License-Identifier: BSD-2-Clause */
/* Copyright (c) 2023, KanOS Contributors */
#include <stddef.h>
#include <sys/boot.h>
#include <sys/initcall.h>
#include <sys/panic.h>
#include <sys/printf.h>
#include <sys/version.h>

uintptr_t hhdm_offset = 0;
uintptr_t kernel_base_phys = 0;
uintptr_t kernel_base_virt = 0;

volatile struct limine_hhdm_request hhdm_request = {
    .id = LIMINE_HHDM_REQUEST,
    .revision = 0,
    .response = NULL,
};

volatile struct limine_kernel_address_request kernel_address_request = {
    .id = LIMINE_KERNEL_ADDRESS_REQUEST,
    .revision = 0,
    .response = NULL,
};

volatile struct limine_memmap_request memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0,
    .response = NULL,
};

volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0,
    .response = NULL,
};

void __noreturn __used main(void)
{
    size_t i;

    kprintf("%s %s %s", sysname, release, version);

    panic_if(!hhdm_request.response, "main: hhdm_request has no response");
    panic_if(!memmap_request.response, "main: memmap_request has no response");
    panic_if(!kernel_address_request.response, "main: kernel_address_request has no response");

    hhdm_offset = hhdm_request.response->offset;
    kernel_base_phys = kernel_address_request.response->physical_base;
    kernel_base_virt = kernel_address_request.response->virtual_base;

    /* UNDONE: should SMP and sched use initcalls? */
    for(i = 0; initcalls[i]; initcalls[i++]());

    panic("main: nothing else to do!");
    unreachable();
}
