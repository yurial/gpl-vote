exception::exception() throw():
    m_error( noerr )
{
}

exception::exception(const gcry_error_t& err) throw():
    m_error( err )
{
}

exception::exception(const exception& origin) throw():
    m_error( origin.m_error )
{
}

exception::~exception() throw()
{
}

exception& exception::operator = (const exception& rvalue) throw()
{
m_error = rvalue.m_error;
return *this;
}

const char* exception::what() const throw()
{
return error();
}

const char* exception::error() const throw()
{
return gcry_strerror( m_error );
}

const char* exception::source() const throw()
{
return gcry_strsource( m_error );
}

void throwif(error_t err) throw(exception)
{
if ( noerr != err )
    throw exception( err );
}

