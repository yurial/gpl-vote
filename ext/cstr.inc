#include <string.h>

namespace ext
{

c_str::c_str()
{
}

c_str::c_str(const char* str, size_t size):
    rawdata( str, size )
{
}

c_str::c_str(const char* str):
    rawdata( str, strlen( str ) )
{
}

c_str::operator const char*() const
{
return m_begin;
}

const_c_str::const_c_str()
{
}

const_c_str::const_c_str(const char* str):
    c_str( str )
{
}

} //namespace ext

