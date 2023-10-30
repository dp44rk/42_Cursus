#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const std::string &expr) : _expr(expr) {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &src) {
    if (this != &src) {
        _expr = src._expr;
    }
    return *this;
}

RPN::~RPN() {}

float RPN::op(char op, float a, float b)
{
    if (op == '/' && b == 0)
        throw "Error: Not divisible by zero";
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    throw "Error: Invalid token";
}

void RPN::cal(void)
{
    std::stack<float> s;

    if (_expr.size() < 5) {
        throw "Error: The length must be at least 5 to qualify for the 3 token minimum.";
    }
    if (_expr.size() % 2 == 0 || (_expr.size() + 1) % 4 == 0) {
        throw "Error: Invalid token. Make sure the number of tokens and length are both odd.";
    }

    float a, b;
    for (size_t i = 0; i < _expr.size(); i += 2)
    {
        if (i + 1 < _expr.size() && _expr[i + 1] != ' ')
            throw "Error: The odd number must be a white space.";
        if (std::isdigit(_expr[i])) {
            s.push(_expr[i] - '0');
            continue;
        }
        if (s.size() < 2)
            throw "Error: The computation requires at least two numbers in the stack.";
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(op(_expr[i], a, b));
    }

    if (s.size() != 1)
        throw "Error: The number of tokens must be one. ";
    std::cout << s.top() << std::endl;
}