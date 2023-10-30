#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src)
        _c = src._c;
    return *this;
}

bool BitcoinExchange::checkExtension(const std::string &ext, const std::string &f) {
    return (ext.size() <= f.size()) && (f.substr(f.size() - ext.size()) == ext);
}

bool BitcoinExchange::checkDate(const std::string &s) {
    std::istringstream ss(s);
    std::string res;

    // 2009-01-03
    // year
    if (!std::getline(ss, res, '-') || res.size() != 4 ||
        !std::isdigit(res.at(0)) || !std::isdigit(res.at(1)) ||
        !std::isdigit(res.at(2)) || !std::isdigit(res.at(3)))
        return false;
    // month
    if (!std::getline(ss, res, '-') || res.size() != 2 ||
        !std::isdigit(res.at(0)) || !std::isdigit(res.at(1)))
        return false;
    // date
    if (!std::getline(ss, res) || res.size() != 2 ||
        !std::isdigit(res.at(0)) || !std::isdigit(res.at(1)))
        return false;
    return true;
}

bool BitcoinExchange::convertToFloat(const std::string &s, float *dest)
{
    char *endPtr;
    // *dest = std::strtof(s.c_str(), &endPtr);
    *dest = static_cast<float>(std::strtod(s.c_str(), const_cast<char**>(&endPtr)));

    return std::strcmp(endPtr, "") == 0 || std::strcmp(endPtr, "f") == 0;
}

BitcoinExchange::BitcoinExchange(const std::string &f) {
    readCsv(f);
}

void BitcoinExchange::readCsv(const std::string &f) {
    const std::string csvExt(".csv");
    _c.clear();
    if (!checkExtension(csvExt, f))
        throw InvalidExtentionException();
    
    std::ifstream inptFile(f.c_str());

    if (!inptFile.is_open())
        throw FailToOpenFileException();

    std::string line;
    if (!std::getline(inptFile, line))
        throw EmptyFileException();
    if (line != "date,exchange_rate")
        throw InvalidHeaderFormatException();
    
    line = "";
    while (std::getline(inptFile, line)) {
        std::istringstream ss(line);
        std::string date, rate;

        Record rawData;
        if (!std::getline(ss, date, ',') ||
            !std::getline(ss, rate) ||
            !checkDate(date) ||
            !convertToFloat(rate, &rawData.rate))
            throw InvalidLineFormatException();
        // 유가도 - 인적 있었음 -> 음수 처리 x
        rawData.date = date;
        _c.insert(rawData);
    }
    inptFile.close();
}

void BitcoinExchange::convertToRecord(const std::string &f) {
    std::ifstream inptFile(f.c_str());
    std::string line;

    if (!inptFile.is_open())
        throw FailToOpenFileException();
    
    if (!std::getline(inptFile, line))
        throw EmptyFileException();
    if (line != "date | value")
        throw InvalidHeaderFormatException();
    
    while (std::getline(inptFile, line)) {
        std::istringstream ss(line);
        std::string dateStr, valStr, tmp1, tmp2;

        float valF;
        // 2014-03-04,673.28
        if (!std::getline(ss, dateStr, ' ') ||
            !std::getline(ss, tmp1, '|') ||
            tmp1 != "" ||
            !std::getline(ss, tmp2, ' ') ||
            tmp2 != "" ||
            !std::getline(ss, valStr) ||
            !checkDate(dateStr) ||
            !convertToFloat(valStr, &valF))
            std::cout << "Error: bad input => " << line << std::endl;
        else if (valF < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else if (valF > 1000)
            std::cout << "Error: too large a number." << std::endl;
        else {
            std::cout << dateStr << " => "
                      << valF << " = " << cal2(dateStr, valF) << std::endl;
        }
    }
    inptFile.close();
}

float BitcoinExchange::cal2(const std::string &date, float value)
{
    Record key;
    key.date = date;

    std::multiset<Record>::iterator it = _c.upper_bound(key);
    if (it == _c.begin())
        return 0;
    return (--it)->rate * value;
}

const char *BitcoinExchange::InvalidExtentionException::what() const throw() {
    return "Error: invalid extension.";
}

const char *BitcoinExchange::InvalidHeaderFormatException::what() const throw() {
    return "Error: invalid header format.";
}

const char *BitcoinExchange::FailToOpenFileException::what() const throw() {
    return "Error: could not open file.";
}

const char *BitcoinExchange::EmptyFileException::what() const throw() {
    return "Error: empty file.";
}

const char *BitcoinExchange::InvalidLineFormatException::what() const throw() {
    return "Error: InvalidLine.";
}

const char *BitcoinExchange::NotPositiveNumberException::what() const throw() {
    return "Error: not a positive number.";
}

const char *BitcoinExchange::TooLargeNumberException::what() const throw() {
    return "Error: too large a number.";
}