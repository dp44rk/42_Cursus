#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    // ? dp는?
    if (this != &other)
        _c = other._c;
    return *this;
}

void PmergeMe::parse(int ac, char **av)
{
    _c.clear();
    for (int i = 1; i < ac; ++i) {
        std::string str(av[i]);
        _c.push_back(atoiPositive(str));
    }
    if (_c.size() == 0)
        throw "Error: No element.";
}


void PmergeMe::printVec2(const std::string &head, std::vector<int> &vec)
{
    std::cout << head;
    for (std::string::size_type i = 0; i < vec.size() && i < 5; ++i) {
        if (i == 4 && vec.size() > 5)
            std::cout << " [...]";
        else
            std::cout << " " << vec[i];
    }
    std::cout << std::endl;
}


void PmergeMe::sort(void) {
    if (_c.size() == 0) {
        throw "The container to sort by is not set.";
    }

    std::deque<int> copyed;
    std::copy(_c.begin(), _c.end(), std::back_inserter(copyed));
    clock_t start, end;

    printVec2(std::string("Before"), _c);
    start = clock();
    std::vector<int> vectorResult = fordJohnsonSort(_c);
    end = clock();
    
    printVec2(std::string("After"), vectorResult);
    printDuration(start, end, vectorResult.size(), "std::vector<int>");

    /**********************************************************/

    start = clock();
    std::deque<int> dequeResult = fordJohnsonSort(copyed);
    end = clock();
    printDuration(start, end, dequeResult.size(), "std::deque<int>");

    std::cout << std::endl;

    std::cout << "Compared to std::sort | ";
    
    std::sort(_c.begin(), _c.end());
    std::sort(copyed.begin(), copyed.end());

    if (_c == vectorResult && copyed == dequeResult)
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl;
    std::cout << std::endl;
}

void PmergeMe::printDuration(clock_t start, clock_t end, size_t n, const char *data)
{
    clock_t duration = end - start;
    clock_t CLOCKS_PER_MILLI_SEC = 1000;
    std::cout << "Time to process a range of "
              << n << " elements with " << data << " : "
              << (duration / CLOCKS_PER_MILLI_SEC) << "ms " << (duration % CLOCKS_PER_MILLI_SEC) << "us"
              << std::endl;
}

std::deque<int> PmergeMe::fordJohnsonSort(std::deque<int> arr)
{
    std::deque<Group> newArr;

    for (size_t i = 0; i < arr.size(); i++) {
        Group temp(arr[i]);
        newArr.push_back(temp);
    }

    std::deque<Group> sorted = recur(newArr);

    std::deque<int> result;
    for (size_t i = 0; i < sorted.size(); i++) {
        result.push_back(sorted[i].getNumber(0));
    }
    return result;
}

std::deque<Group> PmergeMe::recur(std::deque<Group> arr) {
    if (arr.size() == 1)
        return arr;

    bool odd = (arr.size() % 2 == 1);
    size_t half = arr.size() / 2;

    std::deque<Group> newArr;
    size_t smallerIndex, biggerIndex;
    for (size_t i = 0; i < half; i++) {
        if (arr[2 * i] > arr[2 * i + 1]) {
            smallerIndex = 2 * i + 1;
            biggerIndex = 2 * i;
        }
        else {
            smallerIndex = 2 * i;
            biggerIndex = 2 * i + 1;
        }
        Group g(arr[smallerIndex], arr[biggerIndex]);
        newArr.push_back(g);
    }

    std::deque<Group> sorted = recur(newArr);
    std::deque<Group> dest, bigger, smaller;

    for (size_t i = 0; i < sorted.size(); i++)
    {
        Group tempBigger, tempSmaller;
        sorted[i].divide(tempBigger, tempSmaller);
        dest.push_back(tempBigger);
        bigger.push_back(tempBigger);
        smaller.push_back(tempSmaller);
    }

    if (odd)
        smaller.push_back(arr.back());
    
    // Cannot secure capacity with reverse
    // dest.reserve(dest.size() + smaller.size());

    dest.insert(dest.begin(), smaller[1 - 1]);

    size_t n = 3;
    size_t curJacobN = jacobsthal(n);
    size_t prevJacobN = jacobsthal(n - 1);
    
    std::deque<Group>::iterator pos;

    while (prevJacobN < smaller.size())
    {
        size_t endBoundary = std::min(dest.size(), curJacobN - 1 + prevJacobN);
        for (size_t i = std::min(smaller.size(), curJacobN);
             i > prevJacobN; --i)
        {
            pos = std::lower_bound(dest.begin(), dest.begin() + endBoundary, smaller[i - 1]);
            dest.insert(pos, smaller[i - 1]);
        }

        n += 1;
        prevJacobN = curJacobN;
        curJacobN = jacobsthal(n);
    }

    return dest;
}

std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> arr) {
    std::vector<Group> newArr;

    for (size_t i = 0; i < arr.size(); i++) {
        Group temp(arr[i]);
        newArr.push_back(temp);
    }

    std::vector<Group> sorted = recur(newArr);

    std::vector<int> result;
    for (size_t i = 0; i < sorted.size(); i++) {
        result.push_back(sorted[i].getNumber(0));
    }
    return result;
}

std::vector<Group> PmergeMe::recur(std::vector<Group> arr) {
    if (arr.size() == 1)
        return arr;

    bool odd = (arr.size() % 2 == 1);
    size_t half = arr.size() / 2;

    std::vector<Group> newArr;
    size_t smallerIndex, biggerIndex;
    for (size_t i = 0; i < half; i++) {
        if (arr[2 * i] > arr[2 * i + 1]) {
            smallerIndex = 2 * i + 1;
            biggerIndex = 2 * i;
        }
        else {
            smallerIndex = 2 * i;
            biggerIndex = 2 * i + 1;
        }
        Group g(arr[smallerIndex], arr[biggerIndex]);
        newArr.push_back(g);
    }

    std::vector<Group> sorted = recur(newArr);
    std::vector<Group> dest, bigger, smaller;

    for (size_t i = 0; i < sorted.size(); i++)
    {
        Group tempBigger, tempSmaller;
        sorted[i].divide(tempBigger, tempSmaller);
        dest.push_back(tempBigger);
        bigger.push_back(tempBigger);
        smaller.push_back(tempSmaller);
    }

    // odd -> Add the last element to small. 
    if (odd)
        smaller.push_back(arr.back());
    
    dest.reserve(dest.size() + smaller.size());

    // sorting s1
    dest.insert(dest.begin(), smaller[1 - 1]);

    size_t n = 3;
    size_t curJacobN = jacobsthal(n);
    size_t prevJacobN = jacobsthal(n - 1);

    std::vector<Group>::iterator pos;

    while (prevJacobN < smaller.size())
    {
        std::vector<Group>::iterator endBoundary = dest.begin() + std::min(dest.size(), curJacobN - 1 + prevJacobN);
        for (size_t i = std::min(smaller.size(), curJacobN); i > prevJacobN; --i) {
            pos = std::lower_bound(dest.begin(), endBoundary, smaller[i - 1]);
            dest.insert(pos, smaller[i - 1]);
        }
        n += 1;
        prevJacobN = curJacobN;
        curJacobN = jacobsthal(n);
    }
    return dest;
}

int PmergeMe::atoiPositive(const std::string &str) {
    int number = 0;

    for (std::string::size_type i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            throw "Error: Not Positive Nubmer";
        if ((number >= 214748365 || number == 214748364) && str[i] > '7')
            throw "Error: Out of range.";
        number = (number * 10) + (str[i] - '0');
    }
    return number;
}

int PmergeMe::jacobsthal(int n) {
    while (_dp.size() <= 1)
        _dp.push_back(static_cast<int>(_dp.size()));

    int s = _dp.size();

    if (s <= n) {
        for (int i = s; i <= n; i++)
            _dp.push_back(_dp[i - 1] + 2 * _dp[i - 2]);
    }

    return _dp[n];
}
