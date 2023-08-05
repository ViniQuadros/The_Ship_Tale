#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

void Room()
{
    bool room = true;

    std::vector <std::string> inventory;
    std::vector <std::string> type;

    std::string options;
    std::cin >> options;

    if(room == true && options == "Look"){
        std::cout << "\nNow, you have the light to help you see.\n";
        std::cout << "Your room have only one bed, one small closet and a window showing the infinite sea.\n";
        std::cout << "Also, the lifeless brown of the walls make you feel sad\n";
        std::cout << "You can see the key of your room over the closet. It is old and rusty.\n";
    }
    else if(room == true && options == "Take"){
        std::cout << "You took the key to your room\n";
        inventory.push_back("Room Key");
    }

    std::cout << "You have " << inventory[0];
}
