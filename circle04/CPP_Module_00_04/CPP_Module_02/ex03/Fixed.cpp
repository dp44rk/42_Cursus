#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
    : m_val(0) {
}

Fixed::Fixed(const int i)
    : m_val(i << m_bit) {
}

Fixed::Fixed(const float f)
    : m_val(roundf(f * ( 1 << m_bit))) {
}

Fixed::~Fixed() {
}

Fixed::Fixed( const Fixed &src ) {
    m_val = src.getRawBits();
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed) {
    return out << fixed.toFloat();
}

Fixed   &Fixed::operator = ( const Fixed &src ) {
    if (this == &src)
        return *this;
    m_val = src.getRawBits();
    return (*this);
}

int Fixed::toInt( void ) const {
    return m_val >> m_bit;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(m_val) / (1 << m_bit);
}

int Fixed::getRawBits( void ) const {
    return m_val;
}

void Fixed::setRawBits( int const raw ) {
    m_val = raw;
}


bool    Fixed::operator > ( const Fixed &src ) {
    return this->toFloat() > src.toFloat();
}

bool    Fixed::operator < ( const Fixed &src ) {
    return this->toFloat() < src.toFloat();
}

bool    Fixed::operator >= ( const Fixed &src ) {
    return this->toFloat() >= src.toFloat();
}

bool    Fixed::operator <= ( const Fixed &src ) {
    return this->toFloat() <= src.toFloat();
}

bool    Fixed::operator == ( const Fixed &src ) {
    return this->toFloat() == src.toFloat();
}

bool    Fixed::operator != ( const Fixed &src ) {
    return this->toFloat() != src.toFloat();
}

Fixed   Fixed::operator + ( const Fixed &src ) {
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed   Fixed::operator - ( const Fixed &src ) {
    return Fixed(this->toFloat() - src.toFloat());
}

Fixed   Fixed::operator * ( const Fixed &src ) {
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed   Fixed::operator / ( const Fixed &src ) {
    return Fixed(this->toFloat() / src.toFloat());
}

Fixed   &Fixed::operator ++ () {
    m_val++;
    return *this;
}

Fixed   &Fixed::operator -- () {
    m_val--;
    return *this;
}

Fixed   Fixed::operator ++ (int) {
    Fixed tmp(this->toFloat());
    ++(*this);
    return tmp;
}

Fixed   Fixed::operator -- (int) {
    Fixed tmp(this->toFloat());
    --(*this);
    return tmp;
}

Fixed   &Fixed::max( Fixed &src1, Fixed &src2) {
    return src1 > src2 ? src1 : src2;
}

Fixed   &Fixed::min( Fixed &src1, Fixed &src2) {
    return src1 > src2 ? src2 : src1;
}

const Fixed &Fixed::max( const Fixed &src1, const Fixed &src2 ) {
    return src1.toFloat() > src2.toFloat() ? src1 : src2;
}

const Fixed &Fixed::min( const Fixed &src1, const Fixed &src2 ) {
    return src1.toFloat() > src2.toFloat() ? src2 : src1;
}
