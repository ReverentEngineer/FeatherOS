#include "cxx/guard.hh"
#include "kernel/mm/pmm.hh"
#include "kernel/io/terminal.hh"

#include <stddef.h>
#include <stdint.h>

extern "C" void* kernel_end;

using namespace kernel;

struct multiboot_info;

extern "C" void kernel_main(const struct multiboot_info* mb_info) {
  Terminal& terminal = Terminal::get();
  if (PMM::get().initialize(mb_info)) {
    terminal.write("Initalized\n");
  } else {
    terminal.write("Failed to initialize memory.\n");
  }
}
