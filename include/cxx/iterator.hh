#ifndef __ITERATOR_HH__
#define __ITERATOR_HH__

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag {};
struct bidirectional_iterator_tag {};
struct random_access_iterator_tag {};

template <typename Iterator>
struct iterator_traits {
    typedef typename Iterator::value_type  value_type;
    typedef typename Iterator::difference_type  difference_type;
    typedef typename Iterator::pointer    pointer;
    typedef typename Iterator::reference  reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template <typename T>
struct iterator_traits<T*> {
    typedef T    value_type;
    typedef ptrdiff_t  difference_type;
    typedef const T*  const_pointer;
    typedef T*    pointer;
    typedef const T&  const_reference;
    typedef T&    reference;
    typedef random_access_iterator_tag  iterator_category;
};

template <typename T>
struct iterator_traits<const T*> {
    typedef T    value_type;
    typedef ptrdiff_t  difference_type;
    typedef const T*  const_pointer;
    typedef const T*  pointer;
    typedef const T&  const_reference;
    typedef const T&  reference;
    typedef random_access_iterator_tag  iterator_category;
};

template <>
struct iterator_traits<void*> {
    typedef uint8_t    value_type;
    typedef ptrdiff_t    difference_type;
    typedef const void*    const_pointer;
    typedef void*    pointer;
    typedef const value_type&  const_reference;
    typedef value_type&    reference;
    typedef random_access_iterator_tag  iterator_category;
};

template <>
struct iterator_traits<const void*> {
    typedef uint8_t    value_type;
    typedef ptrdiff_t    difference_type;
    typedef const void*    const_pointer;
    typedef const void*    pointer;
    typedef const value_type&  const_reference;
    typedef const value_type&  reference;
    typedef random_access_iterator_tag  iterator_category;
};

#endif /* __ITERATOR_HH__ */
