#ifndef __MEMORY_HH__
#define __MEMORY_HH__

namespace kernel {

template <class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
    while (first != last ) {
        *result = *first;
        result++; first++;
    }
    return result;
}

}

#endif /* __MEMORY_HH__ */
