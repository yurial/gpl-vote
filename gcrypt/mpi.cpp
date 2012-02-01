#include "mpi.h"

namespace gcrypt
{

template <>
mpi_template<false>::mpi_template(unsigned int nbits)
{
m_mpi = gcry_mpi_new( nbits );
}

template <>
mpi_template<true>::mpi_template(unsigned int nbits)
{
m_mpi = gcry_mpi_snew( nbits );
}

} //namespace gcrypt

