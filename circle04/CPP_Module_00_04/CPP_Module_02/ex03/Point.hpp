#ifndef _POINT_HPP
#define _POINT_HPP

#include "Fixed.hpp"
#define Vec Point
class Point {
private:
    const Fixed m_x;
    const Fixed m_y;

public:
    Point();
    explicit Point( const float x, const float y );
    ~Point();
    Point( const Point &src );
    Point   &operator = ( const Point &src );
    Fixed   getX( void ) const;
    Fixed   getY( void ) const;
};

Fixed   operator * ( const Vec &v1, const Vec &v2 ); //cross
Vec     operator - ( const Point &p1, const Point &p2 );
std::ostream &operator << ( std::ostream &out, const Point &point);
bool bsp( Point const a, Point const b, Point const c, Point const p );

#endif