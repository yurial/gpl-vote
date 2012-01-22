sexp_t::sexp_t():
    m_sexp( NULL )
{
}

sexp_t::~sexp_t()
{
gcry_sexp_release( m_sexp );
}

void sexp_t::dump() const
{
gcry_sexp_dump( m_sexp );
}

sexp_t::operator gcry_sexp_t& ()
{
return m_sexp;
}

sexp_t::operator const gcry_sexp_t& () const
{
return m_sexp;
}

sexp_t::operator gcry_sexp_t* ()
{
return &m_sexp;
}

sexp_t::operator const gcry_sexp_t* () const
{
return &m_sexp;
}

