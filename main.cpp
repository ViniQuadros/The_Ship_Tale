#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    std::string name;
    char start;
    bool play = false;

    do {
    cout << "*************** THE SHIP TALE ***************" << endl;
    cout << "   Press 1 to play the game or 2 to Quit    " << endl;
    cin >> start;
    
    if(start == '1')
    {
        play = true;
    }
    else if (start == '2'){
        exit(1);
    }
    else{
        cout << "*************** THE SHIP TALE ***************" << endl;
        cout << "   Press 1 to play the game or 2 to Quit    " << endl;
        cin >> start;
    }
    } while (play == false);

    

    if(play == true){
        cout << "What's the name of your adventurer?" << endl;
        cin >> name;
        cout << "Nice to meet you, " << name << ".\n";
        cout << "I will explain a situation and you will tell me what you will do according to the situation, ok?" << endl;
    }

    return 0;
}