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

} //namespace gcrypt

