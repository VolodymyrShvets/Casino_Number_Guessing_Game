#include <iostream>
#include <string>
#include "game_entity/player/Player.h"
#include "game_entity/casino/Casino.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    string name;
    double initialCash;
    cout << "\tHello and Welcome to \"Casino World\"!" << endl;
    cout << "Please, enter your name:  ";
    cin >> name;
    cout << "Please, enter the amount of your deposit:  ";
    cin >> initialCash;

    Player player(name, initialCash);

    cout << endl << "Congratulations, " << player.getName() << " and thanks for joining!" << endl;

    Casino casino(&player);

    casino.play();

    if (player.getEarnings() - initialCash > 0) {
        cout << endl << "Congratulations on your big win! Today luck was on your side! Hope we'll see you soon!" << endl;
    } else {
        cout << endl
             << "Well, seems like it's just not your day today...\nMaybe next time luck would be on your side, so, please, come again!"
             << endl;
    }

    getchar();
    getchar();

    return 0;
}
