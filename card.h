//
// Created by SocketSomeone on 04.05.2023.
//

#ifndef UNTITLED5_CARD_H
#define UNTITLED5_CARD_H
#include "istream"

using namespace std;

class Card {
public:
    enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};
    Card(Rank r = ACE, Suit s = SPADES, bool ifu = true);
    int GetValue() const;
    void Flip();
    friend ostream& operator<<(ostream& os, const Card& card);

private:
    Rank m_Rank;
    Suit m_Suit;
    bool m_IsFaceUp;
};
#endif //UNTITLED5_CARD_H
