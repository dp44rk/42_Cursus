#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  std::string f = "F";
  std::string s = "S";
  std::string c = "C";

  FragTrap  t1(f);
  ScavTrap  t2(s);
  ClapTrap  t3(c);

  std::cout << std::endl;
  t1.highFivesGuys();
  std::cout << std::endl;

  std::cout << std::endl;
  t2.guardGate();
  std::cout << std::endl;

  std::cout << std::endl;
  t3.attack(f);
  t1.takeDamage(50);
  t3.attack(s);
  t2.takeDamage(30);
  std::cout << std::endl;

  std::cout << std::endl;
  t1.attack(s);
  t2.takeDamage(t1.getAD());
  t1.attack(c);
  t3.takeDamage(t1.getAD() * 2);
  std::cout << std::endl;

  std::cout << std::endl;
  t3.beRepaired(t3.getHP());
  std::cout << std::endl;

  std::cout << t1 << std::endl;
  std::cout << t2 << std::endl;
  std::cout << t3 << std::endl;

  return 0;
}