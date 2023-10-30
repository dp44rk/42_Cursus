#pragma once

#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

struct Record {
    std::string date;
    float rate;
    bool operator<(const Record &rhs) const{ //for multiset
        return date < rhs.date;
    }
};

class BitcoinExchange {
private:
    std::multiset <Record> _c;
    BitcoinExchange();
public:
    virtual ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);

    BitcoinExchange(const std::string &f);

    void readCsv(const std::string &filename);
    void convertToRecord(const std::string &filename);

    bool checkExtension(const std::string &ext, const std::string &f);
    bool checkDate(const std::string &s);
    bool convertToFloat(const std::string &s, float *dest);

    float cal2(const std::string &date, float v);

    class InvalidExtentionException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FailToOpenFileException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class EmptyFileException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class InvalidHeaderFormatException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class InvalidLineFormatException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class NotPositiveNumberException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class TooLargeNumberException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};