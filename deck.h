//
// Created by SocketSomeone on 04.05.2023.
//

#ifndef UNTITLED5_DECK_H
#define UNTITLED5_DECK_H
#include "hand.h"
#include "player.h"


class Deck : public Hand {
public:
    Deck();
    virtual ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& hand);
    void AdditionalCards(Player& player);
};


#endif //UNTITLED5_DECK_H
