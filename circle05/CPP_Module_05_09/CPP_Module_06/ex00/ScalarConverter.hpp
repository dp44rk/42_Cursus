#ifndef CPP06_EX00_SCALARCONVERTER_CPP
#define CPP06_EX00_SCALARCONVERTER_CPP

#include <iostream>
#include <iomanip>
#include <math.h>
#include <float.h>

class ScalarConverter {
private:
    static void _toChar();
    static void _toInt();
    static void _toFloat( void );
    static void _toDouble( void );

private:
    static char     *_nptr;
    static double   _d;
    static bool     _f;

private:
    ScalarConverter( void );
    ScalarConverter( const ScalarConverter& src );
    ScalarConverter& operator=( const ScalarConverter& src);
    ~ScalarConverter( void );

public:
    static void convert( const char *target );
};


#endif