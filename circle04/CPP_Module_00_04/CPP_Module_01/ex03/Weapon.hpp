#ifndef _Weapon
#define _Weapon

#include <string>
#include <iostream>

class Weapon{
private:
    std::string m_type;

public:
    Weapon( std::string type );
    Weapon();
    ~Weapon();
    const   std::string& getType();
    void    setType( std::string _type );
};

#endif