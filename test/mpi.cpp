#include "../gcrypt/mpi.h"

int main(int argc, char* argv[])
{
using gcrypt::mpi_t;

mpi_t n( 1024 );
n = 127;
n.dump();

return 0;
}

