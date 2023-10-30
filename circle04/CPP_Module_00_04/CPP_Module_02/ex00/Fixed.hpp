#ifndef _FIXED_HPP
#define _FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int m_val; // fixed point value
    const static int m_bit = 8; // number of fractional bits()

public:
    Fixed();
    ~Fixed();
    Fixed( const Fixed &src );
    Fixed &operator = ( const Fixed &src );
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

std::ostream& operator << (std::ostream &out, const Fixed &fixed);

#endif