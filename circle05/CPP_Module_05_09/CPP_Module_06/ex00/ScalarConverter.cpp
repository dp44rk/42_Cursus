#include "ScalarConverter.hpp"

char     *ScalarConverter::_nptr = NULL;
double   ScalarConverter::_d = 0;
bool     ScalarConverter::_f = false;


ScalarConverter::ScalarConverter( void ){}
ScalarConverter::ScalarConverter( const ScalarConverter& src ){ (void)src; }
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& src){ (void)src; return *this; }
ScalarConverter::~ScalarConverter( void ){}

/*
    toChar: nan, flag -> impossible
    isprint -> char 변환
    else -> non displayable
*/
void ScalarConverter::_toChar( void ) {
    char c[4] = "\'\0\'";

    std::cout << "char: ";
    if (_f || _d != _d) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    else if (isprint(_d)) {
        c[1] = static_cast<char>(_d);
        std::cout << c << std::endl;
    }
    else
        std::cout << "Non displayable" << std::endl;

}

void ScalarConverter::_toInt( void ) {
    std::cout << "int: ";
    if (_f || _d != _d || _d > INT_MAX || _d < INT_MIN) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    std::cout << static_cast<int>(_d) << std::endl;
}

void ScalarConverter::_toFloat( void ) {
    std::cout << "float: ";
    if ((_f || _d > FLT_MAX || _d < -FLT_MAX) &&
                ! (_d != 0 && _d * 2 == _d)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_d) << "f" << std::endl;
}

void ScalarConverter::_toDouble( void ) {
    std::cout << "double: ";
    if ((_f || _d >  DBL_MAX || _d < -DBL_MAX) &&
                ! (_d != 0 && _d * 2 == _d)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    std::cout << std::fixed << std::setprecision(1) << _d << std::endl;
}

void ScalarConverter::convert( const char *target ) {
    _d = strtod( target, &_nptr );

    if (*_nptr && strcmp(_nptr, "f")) {
        if (strlen(target) == 1 && isprint(target[0]))
            _d = static_cast<double>(target[0]);
        else
            _f = 1;
    }
    else if (strcmp(target, "f") == 0)
        _d = static_cast<double>('f');
    
    _toChar();
    _toInt();
    _toFloat();
    _toDouble();
}