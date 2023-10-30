#include "Point.hpp"

Point::Point() : m_x(0), m_y(0) { }

Point::Point( const float x, const float y ) : m_x(x), m_y(y) { }

Point::~Point() { }

Point::Point( const Point &src ) : m_x(src.getX()), m_y(src.getY()) { }

Point   &Point::operator = ( const Point &src ) {
    if (this == &src)
        return *this;
    const_cast<Fixed&>(this->m_x) = src.getX();
    const_cast<Fixed&>(this->m_y) = src.getY();
    return *this;
}

Fixed   Point::getX( void ) const {
    return m_x;
}

Fixed   Point::getY( void ) const {
    return m_y;
}

std::ostream &operator << ( std::ostream &out, const Point &point) {
    return out << "(" << point.getX() << ", " << point.getY() << ")";
}

Vec operator - (const Point &p1, const Point &p2) {
    return Vec((p1.getX() - p2.getX()).toFloat(), (p1.getY() - p2.getY()).toFloat());
}


Fixed   operator * ( const Vec &v1, const Vec &v2 ) {
    return Fixed((v1.getX() * v2.getY()) - (v1.getY() * v2.getX()));
}
