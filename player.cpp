//
// Created by SocketSomeone on 04.05.2023.
//

#include "player.h"

Player::Player(const string& name): name(name) {}

Player::~Player() {}

bool Player::IsBusted() const {
    return (GetTotal() > 21);
}

void Player::Bust() const {
    cout << name << " busts." << endl;
}

ostream& operator<<(ostream& os, const Player& player) {
    os << player.name << ":\t";
    vector<Card*>::const_iterator iter;
    if (!player.cards.empty()) {
        for (iter = player.cards.begin(); iter != player.cards.end(); ++iter) {
            os << *(*iter) << "\t";
        }
        if (player.GetTotal() != 0) {
            cout << "(" << player.GetTotal() << ")";
        }
    } else {
        os << "<empty>";
    }
    return os;
}


// Human Player

HumanPlayer::HumanPlayer(const string& name): Player(name) {}

HumanPlayer::~HumanPlayer() {}

bool HumanPlayer::IsHitting() const {
    cout << name << ", do you want to hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void HumanPlayer::Win() const {
    cout << name << " wins." << endl;
}
void HumanPlayer::Lose() const {
    cout << name << " loses." << endl;
}

void HumanPlayer::Push() const {
    cout << name << " pushes." << endl;
}

// Computer Player

ComputerPlayer::ComputerPlayer(const string& name): Player(name) {}

ComputerPlayer::~ComputerPlayer() {}

bool ComputerPlayer::IsHitting() const {
    return (GetTotal() <= 16);
}

void ComputerPlayer::FlipFirstCard() {
    if (!(cards.empty())) {
        cards.front()->Flip();
    } else {
        cout << "No card to flip!" << endl;
    }
}