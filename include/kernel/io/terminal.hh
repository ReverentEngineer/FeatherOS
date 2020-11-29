#ifndef __TERMINAL_HH__
#define __TERMINAL_HH__

#include <stddef.h>
#include <stdint.h>

namespace kernel {

class Terminal {
    public:
        static Terminal& get(void) {
            static Terminal instance;
            return instance;
        }
        
        void write(const char* data);

    private:
        Terminal();

        size_t row;
        size_t column;
        uint8_t color;
        uint16_t* buffer;
};

}

#endif
