#ifndef CPP04_MATERIASOURCE_HPP
#define CPP04_MATERIASOURCE_HPP
#include "IMateriaSource.hpp" 

class MateriaSource : public IMateriaSource {
private:
    AMateria* _inven[4];
public:
    MateriaSource( void );
    MateriaSource( MateriaSource const & src );
    MateriaSource & operator=( MateriaSource const & src );
    ~MateriaSource( void );

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif