#ifndef GCRYPT_MPIH
#define GCRYPT_MPIH

#include <gcrypt.h>
#include "exception.h"

namespace gcrypt
{

template <bool secure>
class mpi_template
{
public:
typedef gcry_mpi_t  native_t;

protected:
native_t            m_mpi;

public:
inline              mpi_template() throw();
inline              mpi_template(const native_t& native) throw();
                    mpi_template(unsigned int nbits) throw(); //no inline because bug with multiple definition
inline              mpi_template(const mpi_template& origin) throw();
inline              mpi_template(const unsigned char* buff, size_t size) throw(exception);
template <class T>
inline              mpi_template(const T& buff) throw(exception);

inline              ~mpi_template() throw();

inline  void        dump() const;

mpi_template&       operator = (const mpi_template& rvalue);
mpi_template&       operator = (const unsigned long rvalue);

mpi_template&       swap(mpi_template& rvalue);
mpi_template&       scan(enum gcry_mpi_format format, const unsigned char* buff, size_t size, size_t* nscanned) throw(exception);

native_t&           native();
const native_t&     native() const;
};

typedef mpi_template<false> mpi_t;
typedef mpi_template<true>  smpi_t;

#include "mpi.inc"

} //namespace gcrypt

#endif

