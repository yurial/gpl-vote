#include "rsa.h"

namespace gcrypt
{
namespace asymmetric
{
namespace rsa
{

pub_t::pub_t(const n_t& n, const e_t& e) throw(exception)
{
m_key = ext::move<sexp_t>( sexp_t::build( "(public-key(rsa(n%m)(e%d)))", n.native(), e ) );
}

void pub_t::fingerprint(int algo, void* dst, size_t size) const throw(exception)
{
sexp_t n = m_key.find( ext::const_c_str( "n" ) );
hash::make mh;
mh.enable( algo );
mh.write( n.data( 1 ) );
mh.read( algo, dst, size );
}

priv_t priv_t::generate(int nbits, const e_t& e, bool transistent) throw(exception)
{
static const char QUERY_NORMAL [] = "(genkey (rsa (nbits %d) (rsa-use-e %d)))";
static const char QUERY_LIGHT [] = "(genkey (rsa (nbits %d) (rsa-use-e %d) (transistent-key)))";
const char* query_str = ( transistent )? QUERY_LIGHT : QUERY_NORMAL;
sexp_t query = ext::move<sexp_t>( sexp_t::build( query_str, nbits, e ) );
sexp_t key;
error_t err = gcry_pk_genkey( &key.native(), query.native() );
throwif( err );
return priv_t( ext::move<native_t>( key ) );
}

} //namespace rsa
} //namespace asymmetric
} //namespace gcrypt

