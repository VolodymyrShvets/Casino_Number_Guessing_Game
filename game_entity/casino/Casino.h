#pragma once

#include <set>
#include "../utility/Difficulty.h"
#include "../player/Player.h"

using std::set;

class Casino {
private:
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 100;
    set<int> slots;
    int BIG_NUMBER;
    Difficulty difficulty;
    Player *player;

private:
    int generateRandomNumInRangeIncl(int lower, int higher);

    void updateSlots();

    void setBigNumber();

    void printLine();

    void showOptions();

    void changeDifficulty();

    void printPlayerBalance();

public:
    Casino(Player *p);

    void play();
};
