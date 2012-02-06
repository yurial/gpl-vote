#include <stdio.h>
#include "gcrypt/init.h"
#include "gcrypt/rsa.h"

void mylog(void* data, int, const char* fmt, va_list args)
{
vfprintf( stderr, fmt, args );
}

int main()
{
using namespace gcrypt;
using namespace asymmetric;

gcry_set_log_handler( mylog, NULL );
gcry_control( GCRYCTL_SET_VERBOSITY, 1 );
gcry_control( GCRYCTL_SET_DEBUG_FLAGS, 1 );
init( 1024 * 1024 );
gcry_set_log_handler( mylog, NULL );
rsa::priv_t key = rsa::priv_t::generate( 32768 );
key.native().dump();
return 0;
}

