#include "ScalarConverter.hpp"
#include <iostream>

int main( int argc, char **argv ) {
    if (argc != 2) {
        std::cout <<  "Please provide a single argument; no argument provided or too many arguments provided." << std::endl;
        return EXIT_FAILURE;
    }

    const std::string target = *(++argv);
    ScalarConverter::convert(target.c_str());

    /*
    echo "./ex00 0"
    ./ex00 0
    echo "./ex00 nan"
    ./ex00 nan
    echo "./ex00 42.0f"
    ./ex00 42.0f
    */
}