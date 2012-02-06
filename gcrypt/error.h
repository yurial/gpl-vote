#ifndef GCRYPT_ERRORH
#define GCRYPT_ERRORH

#include <gpg-error.h>
#include <gcrypt.h>

namespace gcrypt
{

typedef gcry_error_t error_t;
enum { noerr = GPG_ERR_NO_ERROR };

} //namespace gcrypt

#endif

