#include <cframework.h>

template< cube_size N > constexpr inline
size_t reverse( uint8_t m_id )
{
  return ( ( m_id * 0x80200802ULL ) & 0x0884422110ULL ) * 0x0101010101ULL >> ( 40 - N );
}

int main(int argc, char **argv)
{
  clog( Spin( _X, 1 ) | Spin( _Z, 3 ) );
  CFrame<4> frame;
  frame.print();
    Rotate<4> a( 1, 1 );

  DEBUG("first test")
  clog( a );
  frame << a;
  frame.print();
  clog( a * Spin( _Z, 3 ), a * Spin( _Z, 1 ) );
  frame << ( a * Spin( _Z, 3 ) );
  frame.print();
  ERROR("test error output");
  return 0;
}
