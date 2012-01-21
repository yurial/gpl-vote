template <bool secure>
mpi_template<secure>::mpi_template():
    m_mpi( NULL )
{
}

template <>
mpi_template<false>::mpi_template(unsigned int nbits)
{
m_mpi = gcry_mpi_new( nbits );
}

template <>
mpi_template<true>::mpi_template(unsigned int nbits)
{
m_mpi = gcry_mpi_snew( nbits );
}

template <bool secure>
mpi_template<secure>::mpi_template(const mpi_template<secure>& origin)
{
m_mpi = gcry_mpi_copy( origin.m_mpi );
}

template <bool secure>
mpi_template<secure>::~mpi_template()
{
gcry_mpi_release( m_mpi );
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
mpi_template<secure>::operator gcry_mpi_t& ()
{
return m_mpi;
}

template <bool secure>
mpi_template<secure>::operator const gcry_mpi_t& () const
{
return m_mpi;
}

