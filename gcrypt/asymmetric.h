#ifndef GCRYPT_ASYMMETRICH
#define GCRYPT_ASYMMETRICH

#include "sexp.h"
#include "hash.h"

namespace gcrypt
{

namespace asymmetric
{

typedef sexp_t sign_t;

class key_t
{
public:
typedef sexp_t  native_t;

protected:
native_t        m_key;

inline          key_t();
inline          key_t(const native_t& key);

public:
unsigned int    nbits() const;
hash::sha1_t    keygrip() const;
inline          sexp_t& native();
inline          const sexp_t& native() const;
};

template <class D>
class pub_sign_key_t
{
public:
bool    verify(const sexp_t& data, const sign_t& sign) const;
};

template <class D>
class priv_sign_key_t
{
public:
sign_t  sign(const sexp_t& data) const;
};

template <class D>
class pub_crypt_key_t
{
public:
sexp_t  decrypt(const sexp_t data);
};

template <class D>
class priv_crypt_key_t
{
public:
sexp_t  encrypt(const sexp_t data);
};

//inc
key_t::key_t()
{
}

key_t::key_t(const native_t& key):
    m_key( key )
{
}

sexp_t& key_t::native()
{
return m_key;
}

const sexp_t& key_t::native() const
{
return m_key;
}

} //namespace asymmetric
} //namespace gcrypt

#endif

