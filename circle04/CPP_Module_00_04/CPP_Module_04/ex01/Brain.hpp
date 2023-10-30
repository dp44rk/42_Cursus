#ifndef CPP04_BRAIN_HPP_
#define CPP04_BRAIN_HPP_

#include <iostream>
#include <string>

class Brain {
protected:
    std::string _ideas[100];
public:
    Brain( void );
    Brain(const Brain& src);
    ~Brain( void );
    Brain& operator=(const Brain& src);
    std::string getIdea(int idx) const;
    void setIdea(int idx, std::string idea);
};

#endif