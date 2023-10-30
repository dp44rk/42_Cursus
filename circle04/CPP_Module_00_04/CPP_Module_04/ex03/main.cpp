#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void check_leaks( void ) {
    system("leaks ex03");
}

void default_test( void ) {
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void test2( void ) {
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
    AMateria* tmp[2] = {NULL, NULL};
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp[0] = src->createMateria("ice");
	me->equip(tmp[0]);
	tmp[1] = src->createMateria("cure");
	me->equip(tmp[1]);

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->unequip(1);

	delete tmp[0];
    tmp[0] = NULL;
	delete tmp[1];
    tmp[1] = NULL;

	delete bob;
	delete me;
	delete src;
}

int main( void )
{
    if (0) default_test();
    else if (1) test2();
    atexit(check_leaks);
    return 0;
}