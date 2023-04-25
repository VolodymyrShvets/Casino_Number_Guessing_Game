#include <random>
#include <iostream>
#include "Casino.h"

using std::cout;
using std::endl;
using std::cin;

Casino::Casino(Player *p) : player(p) {
    changeDifficulty();
}

void Casino::updateSlots() {
    slots.clear();
    while (slots.size() != (int) difficulty) {
        slots.emplace(generateRandomNumInRangeIncl(LOWER_BOUND, UPPER_BOUND));
    }
    setBigNumber();
}

void Casino::setBigNumber() {
    int index = generateRandomNumInRangeIncl(0, slots.size() - 1);
    BIG_NUMBER = *std::next(slots.begin(), index);
}

int Casino::generateRandomNumInRangeIncl(int lower, int higher) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(lower, higher);
    return distr(gen);
}

void Casino::play() {
    int choice;
    double bet;
    while (player->hasMoney()) {
        updateSlots();

        cout << endl;
        printLine();
        printPlayerBalance();

        cout << R"(Enter '1' to continue betting, '2' to show options, '0' to exit.)" << endl << " -> ";
        cin >> choice;
        if (choice == 2) {
            showOptions();
            printLine();
            continue;
        } else if (choice == 0)
            break;

        cout << "Enter your bet -> ";
        cin >> bet;

        if (player->makeBet(bet)) {
            cout << "Chose number (between " << LOWER_BOUND << " and " << UPPER_BOUND << ") -> ";
            cin >> choice;

            if (slots.find(choice) != slots.end()) {
                if (choice == BIG_NUMBER) {
                    cout << "\t\t!!! JACKPOT !!!" << endl << "Congratulations on Big Win !" << endl;
                    player->addWin(bet * Multiplier::getMultiplier(Difficulty::JACKPOT));
                } else {
                    double win = bet * Multiplier::getMultiplier(difficulty);
                    cout << "Congratulations on winning: " << win << endl;
                    player->addWin(win);
                }
            } else {
                cout << "Better luck next time." << endl;
            }
        }

        printPlayerBalance();
        printLine();
    }
}

void Casino::showOptions() {
    int choice;
    printLine();
    cout << endl << "Options:" << endl << " Enter \'1\' to change difficulty." << endl << " Enter \'2\' to return."
         << endl;
    cout << " -> ";
    cin >> choice;
    printLine();

    if (choice == 1) {
        changeDifficulty();
    }
}

void Casino::changeDifficulty() {
    cout << endl << "Select difficulty of the game: " << endl << "(You can change it later)" << endl;
    cout << "1. EASY" << endl << "2. MEDIUM" << endl << "3. HARD" << endl << "4. EXTREME" << endl;
    cout << "Your choice: ";
    int diff;
    cin >> diff;
    difficulty = getDifficulty(diff);
}

void Casino::printLine() {
    cout << "===================================================" << endl;
}

void Casino::printPlayerBalance() {
    cout << "  Balance: " << player->getEarnings() << endl;
}
