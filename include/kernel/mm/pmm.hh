#ifndef __PMM_HH__
#define __PMM_HH__

#include <stddef.h>
#include <stdint.h>

struct multiboot_info;
struct physical_memory_entry;

namespace kernel {

/**
 * @brief Physical memory manager
 *
 */
class PMM {
  public:
    static PMM& get(void) {
      static PMM instance;
      return instance;
    }

    bool initialize(const struct multiboot_info* mb_info);

    void* allocate(int blocks);

    void free(void *block);


  private:
    PMM() = default;
    const struct multiboot_info* mb_info;

}; 

}

#endif
