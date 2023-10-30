#ifndef _FIXED_HPP
#define _FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int m_val;
    const static int m_bit = 8;

public:
    Fixed();
    explicit Fixed(const int i); // constant int -> fixed(8) point
    explicit Fixed(const float f); // constant fixed point -> fixed(8) point
    ~Fixed();
    Fixed( const Fixed &src );
    Fixed &operator = ( const Fixed &src );
    int toInt( void ) const; // fixed point -> integer
    float toFloat( void ) const; // fixed point -> floating point
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);
#endif