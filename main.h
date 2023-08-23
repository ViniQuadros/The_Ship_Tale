#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int writing;
int writingR; //Writing for RightWay
int writingL; //Writing for RightWay

bool play = false;
bool Room = true;
bool Hallway = false;
bool deadMan = false;
bool SeeKey = false;
bool encounter = false;

std::vector <std::string> inventory;
std::string mainQuestion = "\nWhat do you want to do?\n";

void Choose(){
    std::cout << "Choose: [1] Look,\n";
    std::cout << "        [2] Take,\n";
    std::cout << "        [3] Inventory,\n";

    if (std::find(inventory.begin(), inventory.end(), "Room Key") != inventory.end())
    {
        std::cout <<"        [4] Use Key,\n";
    }
}

void Look(){
        switch (Room){
        case 1:
            std::cout << "\nNow, you have the light to help you see.\n";
            std::cout << "Your room have only one bed, one small closet and a window showing the infinite sea.\n";
            std::cout << "Also, the lifeless brown of the walls make you feel sad\n";
            std::cout << "You can see the key of your room over the closet. It is old and rusty.\n";
            SeeKey = true;
            break;
        default:
            std::cout << "\nNothing to look at.\n";
            break;
        }
}

void LookR(){
    if (deadMan){
        std::cout << "You take a closer look at the dead body in front of you.\n";
        std::cout << "His dark clothes are all teared, with blood on it.\n";
        std::cout << "His left leg is broken, the bones ripping the flesh\n";
        std::cout << "But the most unsettling thing for you is that he has no jaw.\n";
        std::cout << "Maybe it was done by a human... maybe not.\n\n";
        std::cout << "You see a shiny object next to the hand of the dead man. You took GOLDEN COIN.";
        inventory.push_back("Golden Coin");
    }
    else{
        std::cout << "\nNothing to look at.\n";
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
    else if (encounter == true){
        inventory.push_back("Axe");
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

void Type2(){
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
    if(HaveKey == true){
        std::cout << "You used the key to open the door!\n";
        inventory.pop_back();
        Room = false;
        HaveKey = false;
        Hallway = true;
    }
    else if(inventory.empty()){
        std::cout << "\nYou have nothing to use.\n";
        std::cout << mainQuestion;
        Choose();
        std::cin >> writing;
        Type2(); 
    }
}