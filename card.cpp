//
// Created by SocketSomeone on 04.05.2023.
//
#include "card.h"


Card::Card(Rank r, Suit s, bool ifu): m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

int Card::GetValue() const {
    int value = 0;
    if (m_IsFaceUp) {
        value = m_Rank;
        if (value > 10) {
            value = 10;
        }
    }
    return value;
}

void Card::Flip() {
    m_IsFaceUp = !(m_IsFaceUp);
}

ostream& operator<<(ostream& os, const Card& card) {
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"✞", "◆", "♥", "♠"};

    if (card.m_IsFaceUp) {
        os << RANKS[card.m_Rank] << SUITS[card.m_Suit];
    } else {
        os << "XX";
    }
    return os;
}