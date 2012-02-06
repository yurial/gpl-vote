#ifndef GCRYPT_EXCEPTIONH
#define GCRYPT_EXCEPTIONH

#include <exception>
#include "error.h"

namespace gcrypt
{

class exception:
    public std::exception
{
protected:
gcry_error_t        m_error;

public:
inline              exception() throw();
inline              exception(const error_t& err) throw();
inline              exception(const exception& origin) throw();
inline              ~exception() throw();
inline  exception&  operator = (const exception& rvalue) throw();
inline  const char* what() const throw();
inline  const char* error() const throw();
inline  const char* source() const throw();
};

inline  void        throwif(error_t err) throw(exception);

#include "exception.inc"

} //namespace gcrypt

#endif

