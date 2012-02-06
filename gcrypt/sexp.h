#ifndef GCRYPT_SEXPH
#define GCRYPT_SEXPH

#include <string>
#include <gcrypt.h>
#include "ext/rawdata.h"
#include "ext/cstr.h"
#include "exception.h"
#include "mpi.h"

namespace gcrypt
{

class sexp_t
{
public:
typedef gcry_sexp_t     native_t;
typedef std::string     string_t;
typedef gcrypt::mpi_t   mpi_t;
typedef ext::rawdata    data_t; 
typedef ext::c_str      token_t;

protected:
native_t        m_sexp;

inline          sexp_t(const native_t& native) throw();

public:
inline          sexp_t() throw();
inline          ~sexp_t() throw();

//new
//create
//sscan

inline  void    dump() const throw();

inline  sexp_t  find(const token_t& token) const throw();
inline  sexp_t  token(int index) const throw();
inline  sexp_t  head() const throw(); //car
inline  sexp_t  tail() const throw(); //cdr
inline  int     size() const throw(); //length

inline  const data_t    data(int index) const throw();
        const string_t  string(int index) const throw();
inline  const mpi_t     mpi(int index, int mpifmt = GCRYMPI_FMT_USG) const throw();

inline  native_t&       native() throw();
inline  const native_t& native() const throw();

static  sexp_t          build(const char* fmt, ...) throw (std::pair<exception,size_t>);

};

#include "sexp.inc"

} //namespace gcrypt

#endif

