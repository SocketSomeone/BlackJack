//
// Created by SocketSomeone on 04.05.2023.
//
#include "card.h"
#include "hand.h"

Hand::Hand() {
    cards.reserve(7);
}

Hand::~Hand() {
    Clear();
}

void Hand::Add(Card* card) {
    cards.push_back(card);
}

void Hand::Clear() {
    vector<Card*>::iterator iter = cards.begin();
    for (iter = cards.begin(); iter != cards.end(); ++iter) {
        delete *iter;
        *iter = 0;
    }
    cards.clear();
}

int Hand::GetTotal() const {
    if (cards.empty()) {
        return 0;
    }
    if (cards[0]->GetValue() == 0) {
        return 0;
    }
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = cards.begin(); iter != cards.end(); ++iter) {
        total += (*iter)->GetValue();
    }
    bool containsAce = false;
    for (iter = cards.begin(); iter != cards.end(); ++iter) {
        if ((*iter)->GetValue() == Card::ACE) {
            containsAce = true;
        }
    }
    if (containsAce && total <= 11) {
        total += 10;
    }
    return total;
}