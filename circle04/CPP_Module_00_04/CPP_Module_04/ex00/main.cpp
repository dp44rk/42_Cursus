#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void ) {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongCat();

    std::cout << std::endl;

    std::cout << "meta->getType(): " << meta->getType() << std::endl;
    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;

    std::cout << std::endl;

    meta->makeSound();
    j->makeSound(); //will output the cat sound!
    i->makeSound();
    wrong->makeSound();


    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    delete wrong;

    std::cout << std::endl;
    system("leaks ex00");
    return 0;
}