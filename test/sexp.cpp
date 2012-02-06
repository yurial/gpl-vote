#include <iostream>
#include "../gcrypt/exception.h"
#include "../gcrypt/sexp.h"

int main(int argc, char* argv[])
{
using gcrypt::sexp_t;
try
    {
    sexp_t s = sexp_t::build( "%d", 3 );
    s.dump();
    }
catch (std::pair<gcrypt::exception,size_t>& e)
    {
    std::cerr << "exception: " << e.second << std::endl;
    }
return 0;
}

