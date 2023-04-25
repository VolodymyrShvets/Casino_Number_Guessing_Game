#include "Player.h"

Player::Player(std::string name, double cash) : m_Name(name), m_Cash(cash) {}

string Player::getName() {
    return m_Name;
}

double Player::getEarnings() const {
    return m_Cash;
}

void Player::addWin(double cash) {
    m_Cash += cash;
}

bool Player::makeBet(double bet) {
    if (m_Cash - bet < 0)
        return false;

    m_Cash -= bet;
    return true;
}

bool Player::hasMoney() const {
    return m_Cash > 0;
}
