template <bool secure>
mpi_template<secure>::mpi_template() throw():
    m_mpi( NULL )
{
}

template <bool secure>
mpi_template<secure>::mpi_template(const mpi_template<secure>::native_t& native) throw():
    m_mpi( native )
{
}

template <bool secure>
mpi_template<secure>::mpi_template(const mpi_template<secure>& origin) throw()
{
m_mpi = gcry_mpi_copy( origin.m_mpi );
}

template <bool secure>
mpi_template<secure>::mpi_template(const unsigned char* buff, size_t size) throw(exception)
{
scan( GCRYMPI_FMT_USG, buff, size, NULL );
}

template <bool secure>
template <class T>
mpi_template<secure>::mpi_template(const T& buff) throw(exception)
{
scan( GCRYMPI_FMT_USG, buff.begin(), buff.size(), NULL );
}

template <bool secure>
mpi_template<secure>::~mpi_template() throw()
{
gcry_mpi_release( m_mpi );
}

template <bool secure>
void mpi_template<secure>::dump() const
{
gcry_mpi_dump( m_mpi );
}

template <bool secure>
mpi_template<secure>& mpi_template<secure>::operator = (const mpi_template<secure>& rvalue)
{
m_mpi = gcry_mpi_set( m_mpi, rvalue.m_mpi );
return *this;
}

template <bool secure>
mpi_template<secure>& mpi_template<secure>::operator = (const unsigned long rvalue)
{
m_mpi = gcry_mpi_set_ui( m_mpi, rvalue );
}

template <bool secure>
mpi_template<secure>& mpi_template<secure>::swap(mpi_template<secure>& rvalue)
{
gcry_mpi_sqap( m_mpi, rvalue.m_mpi );
}

template <bool secure>
mpi_template<secure>& mpi_template<secure>::scan(enum gcry_mpi_format format, const unsigned char* buff, size_t size, size_t* nscanned) throw(exception)
{
gcry_error_t err = gcry_mpi_scan( &m_mpi, format, buff, size, nscanned );
if ( GPG_ERR_NO_ERROR != err )
    {
    throw exception( err );
    }
}

template <bool secure>
typename mpi_template<secure>::native_t& mpi_template<secure>::native()
{
return m_mpi;
}

template <bool secure>
const typename mpi_template<secure>::native_t& mpi_template<secure>::native() const
{
return m_mpi;
}

