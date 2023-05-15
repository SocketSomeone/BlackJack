//
// Created by SocketSomeone on 04.05.2023.
//
#include "game.h"

BlackJackGame::BlackJackGame(const vector<string>& names) {
    vector<string>::const_iterator iter;
    for (iter = names.begin(); iter != names.end(); ++iter) {
        players.push_back(HumanPlayer(*iter));
    }
    deck.Populate();
    deck.Shuffle();
}

BlackJackGame::~BlackJackGame() {}

void BlackJackGame::Play() {
    vector<HumanPlayer>::iterator iter;
    for (int i = 0; i < 2; ++i) {
        for (iter = players.begin(); iter != players.end(); ++iter) {
            deck.Deal(*iter);
        }
        deck.Deal(dealer);
    }

    dealer.FlipFirstCard();

    for (iter = players.begin(); iter != players.end(); ++iter) {
        cout << *iter << endl;
    }
    cout << dealer << endl;

    for (iter = players.begin(); iter != players.end(); ++iter) {
        deck.AdditionalCards(*iter);
    }

    dealer.FlipFirstCard();
    cout << endl << dealer << endl;

    deck.AdditionalCards(dealer);

    if (dealer.IsBusted()) {
        for (iter = players.begin(); iter != players.end(); ++iter) {
            if (!(iter->IsBusted())) {
                iter->Win();
            }
        }
    } else {
        for (iter = players.begin(); iter != players.end(); ++iter) {
            if (!(iter->IsBusted())) {
                if (iter->GetTotal() > dealer.GetTotal()) {
                    iter->Win();
                } else if (iter->GetTotal() < dealer.GetTotal()) {
                    iter->Lose();
                } else {
                    iter->Push();
                }
            }
        }
    }

    for (iter = players.begin(); iter != players.end(); ++iter) {
        iter->Clear();
    }
    dealer.Clear();
}