#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <Windows.h>

#include "functions.h"
#include "functions.cpp"
/*#include "RightWay.cpp"
#include "LefWay.cpp"*/

using namespace std;

void Type() {
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
        case 4:
            Use();
        default:
            cout << "Invalid Option\n";
            cout << mainQuestion;
            Choose();
            cin >> writing;
            Type();  
        }
    }
    /*else{
        switch (writing)
        {
        case 1:
            Left();
            Hallway = false;
            break;
        case 2:
            Right();
            Hallway = false;
            break;
        default:
            cout << "Invalid Option\n";
            cout << mainQuestion;
            Choose();
            cin >> writing;
            Type();  
        }  
    }*/
}

int main()
{
    /*int width = GetSystemMetrics(SM_CYSCREEN);
    std::string name;
    char start;
    bool play = false;

    do {
    cout << setw(width / 3);
    cout << "*************** THE SHIP TALE ***************" << endl;
    cout << setw(width / 3);
    cout << "Instructions: " << endl;
    cout << "Press 1 to "Look""; << endl;
    cout << "Press 2 to "Take""; << endl;
    cout << "Press 3 to "Check Inventory""; << endl;
    cout << "Press 4 to "Use items""; << endl;
    cout << "   Press p to play the game or q to Quit    " << endl;
    cin >> start;
    
    if(start == 'p')
    {
        play = true;
    }
    else if (start == 'q'){
        exit(1);
    }
    else{
        cout << setw(width / 3);
        cout << "*************** THE SHIP TALE ***************" << endl;
        cout << setw(width / 3);
        cout << "   Press p to play the game or q to Quit    " << endl;
        cin >> start;
    }
    } while (play == false);

    cout << "\nHello! I would like to tell a short story to you. A interactive story."<< endl;
    cout << "But, first of all, what's the name of your adventurer?" << endl;
    cin >> name;
    cout << "Nice to meet you, " << name << ".\n";
    cout << "I will explain a situation and you will tell me what you will do according to the situation, ok?" << endl;
    cout << "Are you ready? Type YES to continue." << endl;
    
    std::string Yes;
    cin >> Yes;

    do {
    if (Yes == "yes" || Yes == "Yes" || Yes == "YES")
    {
        
    }
    else if(Yes == "no" || Yes == "No" || Yes == "NO")
    {
        cout << "Get out of here!!!" << endl;
        exit(1);
    }
    else
    {
        cout << "ARE YOU READY OR NOT??" << endl;
        cin >> Yes;
    }
    } while (Yes != "yes" && Yes != "Yes" && Yes != "YES");*/

    cout << "\nOk, then." << endl;

    while (Room == true)
    {
        cout << "\nYou wake up in your room, it is dark and you are all alone.";
        cout << "\nYou can listen to the waves hitting the boat and the cracks of the wood";
        cout << "\nYou feel a little dizzy and decide to take a walk around the ship.";
        cout << "\nSo, you stand up from your unconfortable bed, turn the fire of the candle on and realize you went to sleep with your shoes.";

        cout << mainQuestion;
        Choose();
        cin >> writing;
        Type();
    }

        while (Hallway == true)
    {
        cout << "\nYou open the door and face an empty big corridor going to the left and right.";
        cout << "\nThere are some lights in the dirty walls, but you can't see a long distance.";
        cout << "\nYou try to remember where the thing in the ship are located, because the captain told you yesterday.";
        cout << "\nBut you fail and you are not sure where to go.";

        cout << mainQuestion;
        cout << "Choose: [1] Go Left\n";
        cout << "        [2] Go Right\n";
        cin >> writing;
        break;
    }
    return 0;
}