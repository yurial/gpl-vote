#include "../gcrypt/sexp.h"

int main(int argc, char* argv[])
{
using gcrypt::sexp_t;
sexp_t s;
size_t erroff = 0;
gcry_sexp_build( s, NULL, "(public-key(rsa(n%d)(e%d)))", 7, 3 );
s.dump();
return 0;
}

