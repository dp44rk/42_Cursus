#include "Fixed.hpp"

Fixed::Fixed()
    : m_val(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
    : m_val(i << m_bit) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
    : m_val(roundf(f * ( 1 << m_bit))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &src ) {
    std::cout << "Copy constructor called" << std::endl;
    m_val = src.getRawBits();
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed) {
    return out << fixed.toFloat();
}

Fixed &Fixed::operator = ( const Fixed &src ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &src)
        return (*this);
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