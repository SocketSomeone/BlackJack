//
// Created by SocketSomeone on 04.05.2023.
//

#ifndef UNTITLED5_PLAYER_H
#define UNTITLED5_PLAYER_H

#include "iostream"
#include "hand.h"

using namespace std;

class Player : public Hand {
public:
    Player(const string& name = "");
    virtual ~Player();
    virtual bool IsHitting() const = 0;
    bool IsBusted() const;
    void Bust() const;
    friend ostream& operator<<(ostream& os, const Player& player);

protected:
    string name;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(const string& name = "");
    virtual ~HumanPlayer();
    virtual bool IsHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};


class ComputerPlayer : public Player {
public:
    ComputerPlayer(const string& name = "Dealer");
    virtual ~ComputerPlayer();
    virtual bool IsHitting() const;
    void FlipFirstCard();
};
#endif //UNTITLED5_PLAYER_H
