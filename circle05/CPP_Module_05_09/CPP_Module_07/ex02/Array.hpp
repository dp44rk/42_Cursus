#pragma once

#include <iostream>

template <typename T>
class Array {
private:
    unsigned int _size;
    T* _arr;

public:
    Array<T>( void ) : _size(0), _arr(NULL) {}

    Array<T>( unsigned int n ) : _size(n), _arr(new T[n]) {}

    virtual ~Array<T>( void ) {
        delete[] _arr;
    }

    Array<T>( Array<T> const &src ) : _size(src._size), _arr(new T[src._size]) {
        *this = src;
    }

    Array<T> &operator=( Array<T> const &src ) {
        if (this != &src) {
            delete[] _arr;
            _size = src._size;
            _arr = new T[src._size];
            for (unsigned int i = 0; i < src._size; i++) {
                _arr[i] = src._arr[i];
            }
        }
        return *this;
    }

    const T &operator[]( const unsigned int i ) const { //read-only access
        if ( i < 0 || i >= _size) {
            throw Array::outOfBoundsException();
        }
        return _arr[i];
    }

    T &operator[]( const unsigned int i ) {
        if ( i < 0 || i >= _size) {
            throw Array::outOfBoundsException();
        }
        return _arr[i];
    }

    unsigned int size( void ) const {
        return _size;
    }

    class outOfBoundsException : public std::exception {
    public:
        outOfBoundsException() throw() {}
        virtual ~outOfBoundsException() throw(){};
        virtual const char* what() const throw() {
            return "Array index Out of bounds";
        }
    };
};