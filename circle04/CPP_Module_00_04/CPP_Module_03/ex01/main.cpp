#include "ScavTrap.hpp"

int main(void) {
  std::string s1 = "s1";
  std::string s2 = "s2";
  std::string c1 = "c1";

  ScavTrap t1(s1);
  ScavTrap t2(s2);
  ClapTrap t3(c1);

  std::cout << std::endl;
  t1.attack(c1);
  t3.takeDamage(t1.getAD());
  t3.takeDamage(t1.getAD());
  std::cout << std::endl;

  std::cout << std::endl;
  t1.attack(s2);
  t2.takeDamage(t1.getAD());
  t2.beRepaired(t1.getAD() / 2);
  t2.beRepaired(t1.getAD() / 2);
  t2.beRepaired(t1.getAD() / 2);
  std::cout << std::endl;

  std::cout << std::endl;
  t1.attack(c1);
  t2.takeDamage(t1.getAD());
  t1.attack(c1);
  t2.takeDamage(t1.getAD());
  t1.attack(c1);
  t2.takeDamage(t1.getAD());
  std::cout << std::endl;

  std::cout << std::endl;
  t2.guardGate();
  std::cout << std::endl;

  std::cout << t1 << std::endl;
  std::cout << t2 << std::endl;
  std::cout << t3 << std::endl;

  return 0;
}