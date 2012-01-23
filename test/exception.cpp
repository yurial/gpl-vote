#include <iostream>
#include "../gcrypt/exception.h"

void test() throw(gcrypt::exception)
{
gcry_cipher_hd_t handle;
gcry_error_t err = gcry_cipher_open( &handle, -1/*GCRY_CIPHER_AES*/, GCRY_CIPHER_MODE_CBC, 0 );
if ( err )
    {
    throw gcrypt::exception( err );
    }
}

int main(int argc, char* argv[])
{
try
    {
    test();
    }
catch (gcrypt::exception& e)
    {
    std::cerr << "Failure: " << e.source() << '/' << e.error() << std::endl;
    }
return 0;
}

