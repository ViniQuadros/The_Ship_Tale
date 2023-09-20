#include <iostream>

/*Fazer um sistema de RPG, com dados e valores aleatório,
  N�o � poss�vel se defender, apenas se esconder.*/

class characterLeft{
private:
  
public:
  int HP = 100;
};


void Left(){
  std::cout << "\nYou start to to walk in the long corridor.\n";
  std::cout << "You see dozens of doors that belong to other travelers\n";
  std::cout << "It is possible to hear the snors of all the drunkers inside their Rooms.\n";
  std::cout << "But after a short walk, you get to the kitchen of the ship.\n\n";

  std::cout << "You entered the kitchen.\n";
  std::cout << "You entered a nightmare.";
}