# pragma once

#include <iostream>
#include <exception>
#include <set>
#include <vector>

class Span {
private:
    unsigned int _c; // capacity
public:
    std::multiset<int> _s; // set
    Span(void);
    ~Span(void);
    Span(unsigned int c);
    Span(const Span &src);
    Span& operator=(const Span &src);
    void addNumber(unsigned int n);
    void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class sizeLimitException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class tooShortException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};