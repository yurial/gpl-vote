#include "sexp.h"

namespace gcrypt
{

const sexp_t::string_t sexp_t::string(int index) const throw()
{
string_t result;
char* str = gcry_sexp_nth_string( m_sexp, index );
if ( NULL != str )
    {
    result.assign( str );
    }
gcry_free( str );
return result;
}

sexp_t sexp_t::build(const char* fmt, ...) throw(std::pair<exception,size_t>)
{
native_t result;
size_t erroff;
va_list args;
va_start( args, fmt );
error_t err = gcry_sexp_build_array( &result, &erroff, fmt, (void**)&args );
va_end( args );
if ( noerr != err )
    {
    throw std::pair<exception,size_t>( exception( err ), erroff );
    }
return sexp_t( ext::move<native_t>( result ) );
}

} //namespace gcrypt

