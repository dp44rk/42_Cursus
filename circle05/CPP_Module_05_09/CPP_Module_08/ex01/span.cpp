#include "span.hpp"

Span::Span(void) : _c(0), _s() {}

Span::~Span(void) {}

Span::Span(unsigned int c) : _c(c), _s() { }

Span::Span(const Span &src) {
    *this = src;
}

Span& Span::operator=(const Span &src) {
    if (this != &src) {
        _c = src._c;
        _s = src._s;
    }
    return *this;
}


void Span::addNumber(unsigned int n){
    if (_s.size() >= _c)
        throw sizeLimitException();
    _s.insert(n);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    if (_c - _s.size() - static_cast<unsigned int>(std::distance(start, end)))
        throw Span::sizeLimitException();
    while (start != end)
        addNumber(*start++); 
}

unsigned int Span::shortestSpan() const {
    if (_s.size() <= 1)
        throw Span::tooShortException();
    std::multiset<int>::iterator it = _s.begin();
    long prv = static_cast<long>(*it);
    long now = static_cast<long>(*++it);
    long d = now - prv;
    long rt = now - prv;
    while (++it != _s.end()) {
        now = static_cast<unsigned int>(*it);
        d = now - prv;
        rt = (d < rt ? d : rt);
        prv = now;
    }
    return static_cast<unsigned int>(rt);
}

unsigned int Span::longestSpan() const {
    if (_s.size() <= 1)
        throw Span::tooShortException();
    return static_cast<int>(static_cast<int>(*_s.rbegin()) - static_cast<int>(*_s.begin()));

}

const char *Span::sizeLimitException::what() const throw() { return "sizeLimitException"; }
const char *Span::tooShortException::what() const throw() { return "tooShortException"; }