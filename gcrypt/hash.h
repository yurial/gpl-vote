#ifndef GCRYPT_HASHH
#define GCRYPT_HASHH

#include <stdint.h>
#include <stdexcept>
#include <gcrypt.h>

#include "ext/array.h"
#include "ext/rawdata.h"

namespace gcrypt
{
namespace hash
{

template <int md_algo, class T, int md_size>
struct hash_t:
    public ext::array<T,md_size>
{
enum { algo = md_algo };
enum { static_size = md_size*sizeof(T) };
};

struct make
{
protected:
gcry_md_hd_t    m_md;

public:
inline  make() throw(std::runtime_error)
    {
    gcry_error_t err = gcry_md_open( &m_md, GCRY_MD_NONE, GCRY_MD_FLAG_SECURE );
    if ( 0 != err )
        {
        throw std::runtime_error( "gcry_md_open()" );
        }
    }
inline  make(const char* key, size_t size) throw(std::runtime_error)
    {
    gcry_error_t err = gcry_md_open( &m_md, GCRY_MD_NONE, GCRY_MD_FLAG_SECURE | GCRY_MD_FLAG_HMAC );
    if ( 0 != err )
        {
        throw std::runtime_error( "gcry_md_open()" );
        }
    err = gcry_md_setkey( m_md, key, size );
    if ( 0 != err )
        {
        gcry_md_close( m_md );
        throw std::runtime_error( "gcry_md_setkey()" );
        }
    }
inline ~make() throw()
    {
    gcry_md_close( m_md );
    }
inline void reset() throw()
    {
    gcry_md_reset( m_md );
    }
template <int algo,class T, int size>
inline void enable(const hash_t<algo,T,size>& hash) throw(std::invalid_argument)
    {
    enable( algo );
    }
inline void enable(int algo) throw(std::invalid_argument)
    {
    gcry_error_t err = gcry_md_enable( m_md, algo );
    if ( 0 != err )
        {
        throw std::invalid_argument( "gcry_md_enable() unknown md algo" );
        }
    }
inline void write(const ext::rawdata& data) throw()
    {
    gcry_md_write( m_md, data.begin(), data.size() );
    }
inline void write(const void* data, size_t size) throw()
    {
    gcry_md_write( m_md, data, size );
    }

template <int algo, class T, int size>
inline void read(hash_t<algo,T,size>& hash) const throw(std::logic_error)
    {
    read( algo, &hash, size*sizeof(T) );
    }
inline void read(int algo, void* dst, size_t size) const throw(std::logic_error)
    {
    const void* data = gcry_md_read( m_md, algo );
    if ( NULL == data )
        {
        throw std::logic_error( "gcry_md_read() algo not enabled" );
        }
    memcpy( dst, data, size );
    }
};

typedef hash_t<GCRY_MD_RMD160,uint32_t,5>                   rmd160;
typedef hash_t<GCRY_MD_TIGER,size_t,24/sizeof(size_t)>      tiger_t;
typedef hash_t<GCRY_MD_TIGER1,size_t,24/sizeof(size_t)>     tiger1_t;
typedef hash_t<GCRY_MD_TIGER2,size_t,24/sizeof(size_t)>     tiger2_t;
typedef hash_t<GCRY_MD_HAVAL,uint32_t,5>                    haval_t;

typedef hash_t<GCRY_MD_MD2,size_t,16/sizeof(size_t)>        md2_t;
typedef hash_t<GCRY_MD_MD4,size_t,16/sizeof(size_t)>        md4_t;
typedef hash_t<GCRY_MD_MD5,size_t,16/sizeof(size_t)>        md5_t;

typedef hash_t<GCRY_MD_SHA1,uint32_t,5>                     sha1_t;
typedef hash_t<GCRY_MD_SHA224,uint32_t,7>                   sha224_t;
typedef hash_t<GCRY_MD_SHA256,size_t,32/sizeof(size_t)>     sha256_t;
typedef hash_t<GCRY_MD_SHA384,size_t,48/sizeof(size_t)>     sha384_t;
typedef hash_t<GCRY_MD_SHA512,size_t,64/sizeof(size_t)>     sha512_t;

typedef hash_t<GCRY_MD_CRC32,uint32_t,1>                    crc32_t;
typedef hash_t<GCRY_MD_CRC32_RFC1510,uint32_t,1>            crc32_rfc1510_t;
typedef hash_t<GCRY_MD_CRC24_RFC2440,uint32_t,1>            crc24_rfc2440_t;

typedef hash_t<GCRY_MD_WHIRLPOOL,size_t,64/sizeof(size_t)>  whirlpool_t;

} //namespace hash
} //namespace gcrypt

#endif

