#include "MateriaSource.hpp"

MateriaSource:: MateriaSource( void ) {
    for (int i = 0; i < 4; i++)
        _inven[i] = NULL;
}

MateriaSource:: MateriaSource( MateriaSource const & src ) {
    for (int i = 0; i < 4; i++)
        _inven[i] = src._inven[i];
}

MateriaSource & MateriaSource::operator=( MateriaSource const & src ) {
    if (this != &src) {
        for (int i = 0; i < 4; i++) {
            if (_inven[i] != NULL) {
                delete _inven[i];
                _inven[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource( void ) {
    for (int i = 0; i < 4; i++) {
        if (_inven[i] != NULL) {
            delete _inven[i];
            _inven[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    int i = 0;
    while (i < 4 && _inven[i] != NULL) i++;
    if (i < 4) _inven[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_inven[i] != NULL && _inven[i]->getType() == type)
            return _inven[i]->clone();
    }
    return NULL;
}