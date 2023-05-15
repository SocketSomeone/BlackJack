//
// Created by SocketSomeone on 04.05.2023.
//

#include "iostream"
#include "deck.h"
#include "player.h"

using namespace std;

Deck::Deck() {
    cards.reserve(52);
    Populate();
}

Deck::~Deck() {}

void Deck::Populate() {
    Clear();
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
        for (int r = Card::ACE; r <= Card::KING; ++r) {
            Add(new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
        }
    }
}

void Deck::Shuffle() {
    random_shuffle(cards.begin(), cards.end());
}

void Deck::Deal(Hand& hand) {
    if (!cards.empty()) {
        hand.Add(cards.back());
        cards.pop_back();
    } else {
        cout << "Out of cards. Unable to deal.";
    }
}

void Deck::AdditionalCards(Player& player) {
    cout << endl;
    while (!(player.IsBusted()) && player.IsHitting()) {
        Deal(player);
        cout << player << endl;
        if (player.IsBusted()) {
            player.Bust();
        }
    }
}