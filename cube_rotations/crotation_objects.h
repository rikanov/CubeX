#ifndef ___CUBE_ROTATION_OBJECTS__H
#define ___CUBE_ROTATION_OBJECTS__H

#include <spin.h>
#include <clayers.h>
#include <bitset>

template < cube_size N >
class Rotate
{
  Layers<N>  m_layers;
  Spin       m_spin;

public:

  constexpr Rotate() = default;
  constexpr Rotate( const Layers<N> layers, const Spin spin );
  constexpr Rotate( const Layers<N> layers, const Turn turn );

  size_t layers () const;
  Axis   twister() const;
  Spin      spin() const;

  constexpr Rotate operator * ( const Spin spin ) const;
};


template< cube_size N >
constexpr Rotate<N>::Rotate( const Layers<N> layers, const Spin spin )
  : m_layers( layers )
  , m_spin( spin )
{

}

template< cube_size N >
constexpr Rotate<N>::Rotate( const Layers<N> layers, const Turn turn )
  : m_layers( layers )
  , m_spin( Spin( _X, turn ) )
{

}

template< cube_size N >
size_t Rotate<N>::layers () const
{
  return m_layers.id() << N * ( twister() - 1 );
}

template< cube_size N >
Axis Rotate<N>::twister() const
{
  return m_spin.twister();
}

template< cube_size N >
Spin Rotate<N>::spin() const
{
  return m_spin;
}

template< cube_size N >
constexpr Rotate<N> Rotate<N>::operator * ( const Spin spin ) const
{
  return Rotate<N>( spin.where( twister() ) < 0 ? m_layers.reverse() : m_layers, m_spin | spin );
}

template< cube_size N >
std::ostream & operator << ( std::ostream & os, const Rotate<N> & slice )
{
  return os << slice.twister() << " [" << std::bitset< 3*N > ( slice.layers() ) << "] " << slice.spin() << Color::off;
}

#endif  //  ! ___CUBE_ROTATION_OBJECTS__H
