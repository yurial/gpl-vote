#include "../ext/array.h"
#include "../gcrypt/mpi.h"

int main(int argc, char* argv[])
{
using gcrypt::mpi_t;
ext::array<unsigned char,1> buff = { 127 };
mpi_t n( buff.begin(), buff.size() );
n.dump();
mpi_t e( 8U );
e = 47;
e.dump();
gcry_mpi_t& native = e.native();

return 0;
}

