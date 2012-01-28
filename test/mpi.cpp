#include "../gcrypt/mpi.h"

int main(int argc, char* argv[])
{
using gcrypt::mpi_t;
unsigned char buff[] = { 127 };
mpi_t n( 1024 );
n.scan( GCRYMPI_FMT_USG, buff, sizeof(buff), NULL );
n.dump();
mpi_t e( 8 );
e = 47;
e.dump();
gcry_mpi_t& native = e.native();

return 0;
}

