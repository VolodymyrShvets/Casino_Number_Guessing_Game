#pragma once

#include <string>

using std::string;

class Player {
private:
    string m_Name;
    double m_Cash;

public:
    Player(string name, double cash);

    string getName();

    double getEarnings() const;

    void addWin(double cash);

    bool makeBet(double bet);

    bool hasMoney() const;
};
