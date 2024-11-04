#ifndef ___CUBELET_POSITION__H
#define ___CUBELET_POSITION__H

#include <cposition_lookup.h>
#include <crotation_objects.h>

template< cube_size N >
class CPosition
{
  static constexpr CPositionLookUp<N> LookUp = 0;

private:
  Coords<N>  m_coords;
  Spin       m_state;


public:
  constexpr CPosition();
  constexpr CPosition( const uint8_t x, const uint8_t y, const uint8_t z );

  constexpr Coords<N> coords() const { return m_coords; }
  constexpr Spin       state() const { return m_state;  }

  constexpr void operator *= ( const Rotate<N> & rotation );
  std::string str() const;
};

template< cube_size N > constexpr
CPosition<N>::CPosition()
  : m_coords( 0 )
  , m_state( 0 )
{

}

template< cube_size N > constexpr
CPosition<N>::CPosition( const uint8_t x, const uint8_t y, const uint8_t z )
  : m_coords( Coords<N>( x, y, z ) )
  , m_state( 0 )
{

}

template< cube_size N > constexpr
void CPosition<N>::operator *= ( const Rotate<N> & rotation )
{
  if ( m_coords.layers() & rotation.layers() )
  {
    m_coords = LookUp( m_coords.id(), rotation.spin() );
    m_state *= rotation.spin();
  }
}

#endif  //  ! ___CUBELET_POSITION__H
