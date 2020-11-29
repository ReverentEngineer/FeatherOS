#ifndef __STRING_HH__
#define __STRING_HH__

#include <stdint.h>

class string {
  public:
    string() :
      m_data(NULL);

  private:
    char* m_data; 
    size_t m_size;
};

#endif /* __STRING_HH__ */
