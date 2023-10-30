#include "Fixed.hpp"

Fixed::Fixed() : m_val(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &src ) {
    std::cout << "Copy constructor called" << std::endl;
    m_val = src.getRawBits();
}

Fixed &Fixed::operator = ( const Fixed &src ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &src)
        return (*this);
    m_val = src.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return m_val;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    m_val = raw;
}

std::ostream& operator << (std::ostream &out, const Fixed &fixed) {
    return out << fixed.getRawBits();
}