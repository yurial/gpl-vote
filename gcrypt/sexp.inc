sexp_t::sexp_t() throw():
    m_sexp( NULL )
{
}

sexp_t::sexp_t(const ext::move<native_t>& origin) throw():
    m_sexp( origin.obj() )
{
origin.obj() = NULL;
}

sexp_t::sexp_t(const sexp_t& origin) throw(std::pair<exception,size_t>):
    m_sexp( NULL )
{
operator = ( origin );
}

sexp_t::~sexp_t() throw()
{
clear();
}

void sexp_t::clear() throw()
{
gcry_sexp_release( m_sexp );
m_sexp = NULL;
}

sexp_t& sexp_t::operator = (const sexp_t& origin) throw()
{
clear();
operator = ( ext::move<sexp_t>( build( "%S", origin.native() ) ) );
}

sexp_t& sexp_t::operator = (const ext::move<sexp_t>& origin) throw()
{
clear();
m_sexp = ext::move<native_t>( origin.obj().native() );
origin.obj().native() = NULL;
}

void sexp_t::dump() const throw()
{
gcry_sexp_dump( m_sexp );
}

sexp_t sexp_t::find(const token_t& token) const throw()
{
return sexp_t( ext::move<native_t>( gcry_sexp_find_token( m_sexp, token.begin(), token.size() ) ) );
}

sexp_t sexp_t::token(int index) const throw()
{
return sexp_t( ext::move<native_t>( gcry_sexp_nth( m_sexp, index ) ) );
}

sexp_t sexp_t::head() const throw()
{
return sexp_t( ext::move<native_t>( gcry_sexp_car( m_sexp ) ) );
}

sexp_t sexp_t::tail() const throw()
{
return sexp_t( ext::move<native_t>( gcry_sexp_cdr( m_sexp ) ) );
}

int sexp_t::size() const throw()
{
return gcry_sexp_length( m_sexp );
}

const sexp_t::data_t sexp_t::data(int index) const throw()
{
size_t size = 0;
const char* p = gcry_sexp_nth_data( m_sexp, index, &size );
return data_t( p, size );
}

const sexp_t::mpi_t sexp_t::mpi(int index, int mpifmt) const throw()
{
return mpi_t( gcry_sexp_nth_mpi( m_sexp, index, mpifmt ) );
}

sexp_t::native_t& sexp_t::native() throw()
{
return m_sexp;
}

const sexp_t::native_t& sexp_t::native() const throw()
{
return m_sexp;
}

