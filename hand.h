//
// Created by SocketSomeone on 04.05.2023.
//

#ifndef UNTITLED5_HAND_H
#define UNTITLED5_HAND_H

#include "card.h"

class Hand {
public:
    Hand();
    virtual ~Hand();
    void Add(Card* card);
    void Clear();
    int GetTotal() const;

protected:
    vector<Card*> cards;
};
#endif //UNTITLED5_HAND_H
