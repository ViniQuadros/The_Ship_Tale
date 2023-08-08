#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

bool Room = true;
bool Kitchen = true;

std::vector <std::string> inventory;

void Choose()
{
    std::cout << "Choose: [1] Look,\n";
    std::cout << "        [2] Take,\n";
    std::cout << "        [3] Inventory,\n";
}

void Look()
{
    if(Room == true){
        std::cout << "\nNow, you have the light to help you see.\n";
        std::cout << "Your room have only one bed, one small closet and a window showing the infinite sea.\n";
        std::cout << "Also, the lifeless brown of the walls make you feel sad\n";
        std::cout << "You can see the key of your room over the closet. It is old and rusty.\n";
    }
}

void Take(){
    if(Room == true){
        std::cout << "You took the key to your room\n";
        inventory.push_back("Room Key");
        std::cout << "You have " << inventory[0];
    }
}

void Inventory(){
    if(inventory.empty()){
        std::cout << "You have nothing with you!";
    }
    else{
        for( unsigned int i = 0; i < inventory.size(); i++)
            std::cout << i << std::endl;
    }
}