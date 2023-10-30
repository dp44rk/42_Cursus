#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main( void ) {
    
    // const Animal* a = new Animal(); //error: cannot declare variable ‘a’ to be of abstract type ‘Animal’
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;

    j->makeSound(); //will output the cat sound!
    i->makeSound();

    delete j;
    delete i;
}