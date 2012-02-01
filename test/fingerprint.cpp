#include <stdio.h>

#include "gcrypt/init.h"
#include "gcrypt/hash.h"
#include "gcrypt/rsa.h"

template <class T>
void print(const T* begin, const T* end)
{
typedef const unsigned char cuc;
print( reinterpret_cast<cuc*>( begin ), reinterpret_cast<cuc*>( end ) );
}

template <>
void print<unsigned char>(const unsigned char* b, const unsigned char* e)
{
for (; b != e; ++b)
    {
    fprintf( stdout, "%02x", *b );
    }
fprintf( stdout, "\n" );
}

int main()
{
using namespace gcrypt;
using namespace asymmetric;
init( 16*1024 );
ext::array<unsigned char,128> buff;
buff.fill( 0xFF );

rsa::pub_t::n_t n( buff );
rsa::pub_t::e_t e( 65537 );
rsa::pub_t key( n, e );

hash::sha256_t hash;
key.fingerprint( hash );

print( hash.begin(), hash.end() );
return 0;
}

