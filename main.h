#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "LeftWay.cpp"

int writing;
int writingR; // Writing for RightWay
int writingL; // Writing for RightWay

bool play = false;
bool Room = true;
bool Hallway = false;
bool deadMan = false;
bool SeeKey = false;
bool encounter = false;
bool HaveKey = false;
bool runaway = false;

std::vector<std::string> inventory;
std::string mainQuestion = "\nWhat do you want to do?\n";

class Character
{
public:
    int HP = 100;

};

class Enemy
{
public:
    int enemyLife;
    int enemyDamage;
};

void Choose()
{
    std::cout << "Choose: [1] Look,\n";
    std::cout << "        [2] Take,\n";
    std::cout << "        [3] Inventory,\n";

    if (std::find(inventory.begin(), inventory.end(), "Room Key") != inventory.end())
    {
        std::cout << "        [4] Use Key,\n";
    }
}

void Look()
{
    switch (Room)
    {
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

void LookR()
{
    if (deadMan)
    {
        std::cout << "You take a closer look at the dead body in front of you.\n";
        std::cout << "His dark clothes are all teared, with blood on it.\n";
        std::cout << "His left leg is broken, the bones ripping the flesh\n";
        std::cout << "But the most unsettling thing for you is that he has no jaw.\n";
        std::cout << "Maybe it was done by a human... maybe not.\n";
        std::cout << "You see a shiny object next to the hand of the dead man. You took GOLDEN COIN.\n\n";
        inventory.push_back("Golden Coin");
    }
    else
    {
        std::cout << "\nNothing to look at.\n";
    }
}

void Take()
{
    if (Room == true && SeeKey == true)
    {
        std::cout << "You took the key to your room\n";
        inventory.push_back("Room Key");
        std::cout << "You have " << inventory[0] << std::endl;

        SeeKey = false;
        HaveKey = true;
    }
    else if (encounter == true)
    {
        switch (writingR)
        {
        case 1:
            inventory.push_back("Axe");
            break;
        case 2:
            inventory.push_back("Sword");
        default:
            break;
        }
    }
    else
    {
        std::cout << "You have nothing to take\n";
    }
}

void Inventory()
{
    if (inventory.empty())
    {
        std::cout << "You have nothing with you!\n";
    }
    else
    {
        std::cout << "Your items: " << std::endl;
        for (unsigned int i = 0; i < inventory.size(); i++)
            std::cout << inventory[i] << std::endl;
    }
}

void Type2()
{
    if (Hallway == false)
    {
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

void Use()
{
    if (HaveKey == true)
    {
        std::cout << "You used the key to open the door!\n";
        inventory.pop_back();
        Room = false;
        HaveKey = false;
        Hallway = true;
    }
    else if (inventory.empty())
    {
        std::cout << "\nYou have nothing to use.\n";
        std::cout << mainQuestion;
        Choose();
        std::cin >> writing;
        Type2();
    }
}

void Choice()
{
    switch (writingR)
    {
    case 1:
        if (deadMan == true)
        {
            LookR();
            break;
        }
    case 2:
        if (deadMan == true)
        {
            std::cout << "You decide not to care about the dead man in front of you.\n";
            break;
        default:
            std::cout << "Invalid Option.\n";
            break;
        }
    }
}

void Fight()
{
    bool fight = true;

    Character Player;
    Player.HP;

    Enemy Monster1;
    Monster1.enemyDamage = 8;
    Monster1.enemyLife = 20;

    while (fight == true || Player.HP > 0 || Monster1.enemyDamage > 0)
    {
        int danoPersonagem1 = rand() % ataquePersonagem1;
        Player.HP -= Monster1.enemyDamage;
        std::cout << "You received " << danoPersonagem1 << " damage." << std::endl;

        // Verificar se o Personagem 2 morreu após o ataque
        if (Player.HP <= 0)
        {
            std::cout << "GameOver" << std::endl;
            return 0;
            break;
        }

        // Personagem 2 ataca o Personagem 1
        int danoPersonagem2 = rand() % ataquePersonagem2;
        vidaPersonagem1 -= danoPersonagem2;
        std::cout << "Your attack gave " << danoPersonagem2 << " damage." << std::endl;

        // Verificar se o Personagem 1 morreu após o ataque
        if (Monster1.enemyLife <= 0)
        {
            std::cout << "You defeated the enemy!" << std::endl;
            break;
        }
    }
}

void Right()
{
    deadMan = true;
    std::cout << "\nYou walk for a second and get closer to a dead body.\n";
    std::cout << "There is blood all around the man\n";
    std::cout << "Next to him is an AXE and a SWORD\n";
    std::cout << "You don't know what happended here.\n";
    std::cout << "Choose: [1] Look Closely\n";
    std::cout << "        [2] Keep Going\n";

    while (writingR != 1 || writingR != 2)
    {
        Choice();
        std::cin >> writingR;
    }

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
    std::cin >> writingR;
    if (writingR == 1 || writingR == 2)
    {
        Take();
    }
    else
    {
        std::cout << "You ran away\n";
        runaway = true;
    }

    /*std::cout << "Your items: " << std::endl;
    for (unsigned int i = 0; i < inventory.size(); i++)
        std::cout << inventory[i] << std::endl;*/
}