//
// Created by SocketSomeone on 04.05.2023.
//

#ifndef UNTITLED5_GAME_H
#define UNTITLED5_GAME_H
#include "deck.h"
#include "player.h"

class BlackJackGame {
public:
    BlackJackGame(const vector<string>& names);
    virtual ~BlackJackGame();
    void Play();

private:
    Deck deck;
    ComputerPlayer dealer;
    vector<HumanPlayer> players;
};

#endif //UNTITLED5_GAME_H
