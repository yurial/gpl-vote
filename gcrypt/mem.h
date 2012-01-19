#ifndef GCRYPT_MEMH
#define GCRYPT_MEMH

#include <memory>
#include <limits>
#include <stdexcept>
#include <gcrypt.h>

namespace gcrypt
{
typedef void* (*alloc_func_t)(size_t n);
typedef void  (*free_func_t)(void* p);

template <class T, alloc_func_t alloc_func, free_func_t free_func>
class allocator_template
{
public:
typedef T           value_type;
typedef T*          pointer;
typedef T&          reference;
typedef const T*    const_pointer;
typedef const T&    const_reference;
typedef size_t      size_type;
typedef ptrdiff_t   difference_type;

inline              allocator_template()
                    {}

inline              ~allocator_template()
                    {}

inline pointer address(reference x) const
{
return &x;
}

inline const_pointer address(const_reference x) const
{
return &x;
}

pointer allocate(size_type n, std::allocator<void>::const_pointer hint=0)
{
if ( n > max_size() )
    {
    throw std::bad_alloc();
    }
pointer ptr = (T*)alloc_func( sizeof(T) * n );
if ( NULL == ptr )
    {
    throw std::bad_alloc();
    }
return ptr;
}

inline void deallocate(pointer p, size_type n)
{
free_func( p );
}

inline size_type max_size() const throw()
{
return std::numeric_limits<size_type>::max() / sizeof(T);
}

inline void construct(pointer p, const_reference val)
{
new ((void*)p) T(val);
}

inline void destroy (pointer p)
{
((T*)p)->~T();
}

}; //allocator_template

template <class T>
class allocator:
    public allocator_template<T,gcry_malloc,gcry_free>
{
};

template <class T>
class sec_allocator:
    public allocator_template<T,gcry_malloc,gcry_free>
{
};

#if 0
inline static void* operator new (std::size_t size) throw (std::bad_alloc)
{
void* ptr = gcry_malloc( size );
if ( NULL == ptr )
    {
    throw std::bad_alloc();
    }
return ptr;
}

inline static void* operator new (std::size_t size, const std::nothrow_t& nothrow_constant) throw()
{
return gcry_malloc( size );
}

inline static void* operator new (std::size_t size, void* ptr) throw()
{
return ptr;
}

inline static void* operator new[] (std::size_t size) throw (std::bad_alloc)
{
void* ptr = gcry_malloc( size );
if ( NULL == ptr )
    {
    throw std::bad_alloc();
    }
return ptr;
}

inline static void* operator new[] (std::size_t size, const std::nothrow_t& nothrow_constant) throw()
{
return gcry_malloc( size );
}

inline static void* operator new[] (std::size_t size, void* ptr) throw()
{
return ptr;
}

inline static void operator delete (void* ptr) throw ()
{
gcry_free( ptr );
}

inline static void operator delete (void* ptr, const std::nothrow_t& nothrow_constant) throw()
{
gcry_free( ptr );
}

inline static void operator delete (void* ptr, void* voidptr2) throw()
{
}

inline static void operator delete[] (void* ptr) throw ()
{
gcry_free( ptr );
}

inline static void operator delete[] (void* ptr, const std::nothrow_t& nothrow_constant) throw()
{
gcry_free( ptr );
}

inline static void operator delete[] (void* ptr, void* voidptr2) throw()
{
}
#endif

} //namespace gcrypt

#endif

