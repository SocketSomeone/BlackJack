#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "game.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "\t\tWelcome to BlackJack!\n\n";int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7) {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    BlackJackGame game(names);
    char again = 'y';
    while (again != 'n' && again != 'N') {
        game.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}