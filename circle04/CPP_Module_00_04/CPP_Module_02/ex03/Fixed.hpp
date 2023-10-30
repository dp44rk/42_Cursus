#ifndef _FIXED_HPP
#define _FIXED_HPP

#include <iostream>

class Fixed {
private:
    int m_val;
    const static int m_bit = 8;

public:
    Fixed();
    explicit Fixed( const int i );
    explicit Fixed( const float f );
    ~Fixed();
    Fixed( const Fixed &src );
    int     toInt( void ) const;
    float   toFloat( void ) const;
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

    Fixed   &operator = ( const Fixed &src );
    Fixed   operator + ( const Fixed &src );
    Fixed   operator - ( const Fixed &src );
    Fixed   operator * ( const Fixed &src );
    Fixed   operator / ( const Fixed &src );
    bool    operator > ( const Fixed &src );
    bool    operator < ( const Fixed &src );
    bool    operator >= ( const Fixed &src );
    bool    operator <= ( const Fixed &src );
    bool    operator == ( const Fixed &src );
    bool    operator != ( const Fixed &src );
    Fixed   &operator ++ ();
    Fixed   &operator -- ();
    Fixed   operator ++ (int);
    Fixed   operator -- (int);

    static Fixed   &max( Fixed &src1, Fixed &src2); // param: fixed point
    static Fixed   &min( Fixed &src1, Fixed &src2);
    static const Fixed &max( const Fixed &src1, const Fixed &src2 );
    static const Fixed &min( const Fixed &src1, const Fixed &src2 );
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);
#endif