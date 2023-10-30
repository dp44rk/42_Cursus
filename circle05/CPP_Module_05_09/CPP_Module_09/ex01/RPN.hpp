# pragma once

#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
    std::string _expr;
    RPN(void);

public:
    RPN(const std::string &expr);
    RPN(const RPN &src);
    RPN &operator=(const RPN &src);
    virtual ~RPN(void);

    void cal(void);
    float op(char op, float a, float b);
};
