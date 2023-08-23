#include <iostream>
#include <random>

#include "main.h"
/* Adicionar sistema de combate*/

class characterRight{
public:
    int HP = 100;

};

class Weapons{
public:
    int Damage;
    std::string name;
};

class enemies{
    int enemyHP;
    int enemyAttack;
    std::string enemyName;
};

void Choice(){
    switch (writingR){
    case 1:
        if (deadMan == true){
            LookR();
            break;
        }
    case 2:
        if (deadMan == true){
            std::cout << "You decide not to care about the dead man in front of you.\n";
            break;
    default:
        break;
    }
}
}

void Right(){

    /*while (bool play = true){
        if (int HP = 0){
            std::cout << "Game Over!";
            play = false;
            break;
        }
    }*/

    Weapons Sword;
    Sword.Damage = 10;
    Sword.name = "Sword";

    Weapons Axe;
    Axe.Damage = 12;
    Axe.name = "Axe";

    deadMan = true;
    std::cout << "\nYou walk for a second and get closer to a dead body.\n";
    std::cout << "There is blood all around the man\n";
    std::cout << "Next to him is an AXE and a SWORD\n";
    std::cout << "You don't know what happended here.\n";
    std::cout << "Choose: [1] Look Closely\n";
    std::cout << "        [2] Keep Going\n";
    std::cin >> writingR;
    Choice();

    std::cout << "As soon as you decide to get away from the body, you listen to a noise.\n";
    std::cout << "Footsteps.\n";
    std::cout << "From the darkness ahead of you, a creature emerge.";
    std::cout << "A creature with elongated limbs, pallid skin stretched taut over bony features, and sunken, hollow eyes that seem to absorb all light.";

    std::cout << mainQuestion;
    deadMan = false;
    encounter = true;
    std::cout << "Choose: [1] Take Axe and fight\n";
    std::cout << "        [2] Take Sword and fight\n";
    std::cout << "        [3] Escape\n\n\n";
    std::cin  >> writingR;
    if (writingR == 1 || writingR == 2)
    {
        Take();
    }
    else{
        std::cout << "You ran away";
    }

    std::cout << "Your items: " << std::endl;
        for( unsigned int i = 0; i < inventory.size(); i++)
            std::cout << inventory[i] << std::endl;
}