#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "functions.h"


bool Room = true;
bool Hallway = false;
bool SeeKey = false;

std::vector <std::string> inventory;
int writing;
std::string mainQuestion = "\nWhat do you want to do?\n";

void Choose()
{
    std::cout << "Choose: [1] Look,\n";
    std::cout << "        [2] Take,\n";
    std::cout << "        [3] Inventory,\n";

    if (std::find(inventory.begin(), inventory.end(), "Room Key") != inventory.end())
    {
        std::cout <<"        [4] Use Key,\n";
    }
}

void Look()
{
    if(Room == true){
        std::cout << "\nNow, you have the light to help you see.\n";
        std::cout << "Your room have only one bed, one small closet and a window showing the infinite sea.\n";
        std::cout << "Also, the lifeless brown of the walls make you feel sad\n";
        std::cout << "You can see the key of your room over the closet. It is old and rusty.\n";
        SeeKey = true;
    }
    else if(Hallway == true){

    }
    else{
<<<<<<< HEAD
        std::cout << "\nNothing to look at.\n";
=======
        std::cout << "Nothing to look at.";
>>>>>>> 1c8c846ec8e179b8ef77850156a76e9f6bb4301f
    }
}

bool HaveKey = false;
void Take(){
    if(Room == true && SeeKey == true){
        std::cout << "You took the key to your room\n";
        inventory.push_back("Room Key");
        std::cout << "You have " << inventory[0] << std::endl;

        SeeKey = false;
        HaveKey = true;
    }
    else{
        std::cout <<"\nYou see nothing to take.\n";
    }
}

void Inventory(){
    if(inventory.empty()){
        std::cout << "You have nothing with you!\n";
    }
    else{
        std::cout << "Your items: " << std::endl;
        for( unsigned int i = 0; i < inventory.size(); i++)
            std::cout << inventory[i] << std::endl;
    }
}

void Type2() {
    if(Hallway == false){
        switch (writing)
        {
        case 1:
            Look();
            break;
        case 2:
            Take();
            break;
        case 3:
            Inventory();
            break;
        default:
            std::cout << "Invalid Option\n";
            std::cout << mainQuestion;
            Choose();
            std::cin >> writing;
            Type2();  
        }
    }
}

void Use(){
    if(inventory.empty()){
        std::cout << "Invalid Option\n";
        std::cout << mainQuestion;
        Choose();
        std::cin >> writing;
        Type2(); 
    }
    else if(HaveKey == true){
        std::cout << "You used the key to open the door!\n";
<<<<<<< HEAD
        inventory.pop_back();
        Room = false;
        HaveKey = false;
        Hallway = true;
    }
    else{
        std::cout << "\nYou have nothing to use.\n";
=======
        inventory.pull_back("Room Key");
        Room = false;
        Hallway = true;
    }
    else{
        std::cout << "You have nothing to use.";
>>>>>>> 1c8c846ec8e179b8ef77850156a76e9f6bb4301f
    }
}