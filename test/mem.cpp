#include <cstdlib>

#include "gcrypt/mem.h"

int main(int argc, char* argv[])
{
gcrypt::allocator<int> a;
int* buff = a.allocate( 1024 );
a.deallocate( buff, 1024 );
return EXIT_SUCCESS;
}

