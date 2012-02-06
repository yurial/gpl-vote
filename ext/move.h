#ifndef EXT_MOVEH
#define EXT_MOVEH

namespace ext
{

template <class T>
class move
{
protected:
T&          m_obj;

public:
inline  explicit    move(T& obj) throw();
inline  explicit    move(const T& obj) throw();
inline  T&          obj() const throw();
inline              operator T& () const throw();
};

template <class T>
move<T>::move(T& obj) throw():
    m_obj( obj )
{
}

template <class T>
move<T>::move(const T& obj) throw():
    m_obj( const_cast<T&>( obj ) )
{
}

template <class T>
T& move<T>::obj() const throw()
{
return m_obj;
}

template <class T>
move<T>::operator T& () const throw()
{
return m_obj;
}

} //namespace ext

#endif

