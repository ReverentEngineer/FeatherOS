#include "kernel/io/terminal.hh"

using namespace kernel;

/* Hardware text mode color constants. */
enum vga_color {
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE = 1,
  VGA_COLOR_GREEN = 2,
  VGA_COLOR_CYAN = 3,
  VGA_COLOR_RED = 4,
  VGA_COLOR_MAGENTA = 5,
  VGA_COLOR_BROWN = 6,
  VGA_COLOR_LIGHT_GREY = 7,
  VGA_COLOR_DARK_GREY = 8,
  VGA_COLOR_LIGHT_BLUE = 9,
  VGA_COLOR_LIGHT_GREEN = 10,
  VGA_COLOR_LIGHT_CYAN = 11,
  VGA_COLOR_LIGHT_RED = 12,
  VGA_COLOR_LIGHT_MAGENTA = 13,
  VGA_COLOR_LIGHT_BROWN = 14,
  VGA_COLOR_WHITE = 15,
};
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
  return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
    return (uint16_t) uc | (uint16_t) color << 8;
}

static size_t strlen(const char* str) 
{
  size_t len = 0;
  while (str[len])
    len++;
  return len;
}

Terminal::Terminal() :
   row(0),
   column(0),
   color(vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK)),
   buffer((uint16_t*) 0xB8000) {
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            buffer[index] = vga_entry(' ', color);
        }
    }
}

void
Terminal::write(const char* data) 
{
    for (size_t i = 0; i < strlen(data); i++) {
        if (data[i] != '\n') {
            const size_t index = row * VGA_WIDTH + column;
            buffer[index] = vga_entry(data[i], color);
            if (++column == VGA_WIDTH) {
                column = 0;
                if (++row == VGA_HEIGHT) {
                    row = 0;
                }
            } 
        } else {
            column = 0;
            row++;
        }
    }
}
