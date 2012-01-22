#ifndef GCRYPT_SEXPH
#define GCRYPT_SEXPH

#include <gcrypt.h>

namespace gcrypt
{

class sexp_t
{
protected:
gcry_sexp_t m_sexp;

public:
inline          sexp_t();
inline          ~sexp_t();
//new
//create
//sscan

inline          operator gcry_sexp_t& ();
inline          operator const gcry_sexp_t& ();

inline          operator gcry_sexp_t* ();
inline          operator const gcry_sexp_t* ();
};

#include "sexp.inc"

} //namespace gcrypt

#endif

