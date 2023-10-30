#include "Character.hpp"

Character::Character( void ) : _name("default") {
    for (int i = 0; i < 4; i++)
        _inven[i] = NULL;
}

Character::Character( std::string const & name ) {
    _name = name;
    for (int i = 0; i < 4; i++)
        _inven[i] = NULL;
}

Character::Character( Character const & src ) {
    this->_name = src._name;
    for (int i = 0; i < 4; i++)
        this->_inven[i] = src._inven[i];
}

Character &Character::operator=( Character const & src ) {
    if (this != &src) {
        this->_name = src._name;
        for (int i = 0; i < 4; i++)
            this->_inven[i] = src._inven[i];
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inven[i] != NULL) {
            delete _inven[i];
            _inven[i] = NULL;
        }
    }
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip( AMateria* m ) {
    int i = 0;
    while (i < 4 && _inven[i] != NULL) i++;
    if (i < 4) _inven[i] = m;
}

void Character::unequip( int idx ) {
    if (idx >= 0 && idx < 4) _inven[idx] = NULL;
}

void Character::use( int idx, ICharacter& target ) {
    if (idx >= 0 && idx < 4 && _inven[idx] != NULL) _inven[idx]->use(target);
}