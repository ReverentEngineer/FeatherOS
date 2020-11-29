#include "kernel/mm/pmm.hh"
#include "kernel/io/terminal.hh"
#include "kernel/boot/multiboot.h"

#include <stddef.h>
#include <stdint.h>

using namespace kernel;

bool
PMM::initialize(const multiboot_info_t* mb_info) {
    bool initialized = false;
    if (MULTIBOOT_INFO_MEM_MAP & mb_info->flags) {
        this->mb_info = mb_info;
        initialized = true;
    }
    return initialized;
}
