#ifndef GCRYPT_MPIH
#define GCRYPT_MPIH

#include <gcrypt.h>

namespace gcrypt
{

template <bool secure>
class mpi_template
{
protected:
gcry_mpi_t  m_mpi;

public:
inline          mpi_template();
inline          mpi_template(unsigned int nbits);
inline          mpi_template(const mpi_template& origin);
inline          ~mpi_template();

inline  void    dump() const;

mpi_template&   operator = (const mpi_template& rvalue);
mpi_template&   operator = (const unsigned long rvalue);

mpi_template&   swap(mpi_template& rvalue);
mpi_template&   scan(enum gcry_mpi_format format, const unsigned char* buff, size_t size, size_t* nscanned);

                operator gcry_mpi_t& ();
                operator const gcry_mpi_t& () const;
};

typedef mpi_template<false> mpi_t;
typedef mpi_template<true>  smpi_t;

#include "mpi.inc"

} //namespace gcrypt

#endif

