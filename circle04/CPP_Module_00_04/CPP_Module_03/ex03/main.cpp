#include "DiamondTrap.hpp"

int main(void) {
  std::string s = "d";
  std::string e = "enemy";
  DiamondTrap d(s);

  std::cout << std::endl;
  d.whoAmI();
  std::cout << std::endl;

  std::cout << d << std::endl;

  std::cout << std::endl;
  d.attack(e);
  std::cout << std::endl;
  std::cout << d << std::endl;
  std::cout << std::endl;

  return 0;
}