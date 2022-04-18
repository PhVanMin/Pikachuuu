#include "NormalMode.h"
#include "DifficultMode.h"

int main() {
    initWindow(1000, 500);

    int status;
    player p;

    while ((status = mainMenu()) != 3) {
        switch (status)
        {
        case 0:
            getPlayerInfo(p);
            normalMode(p);
            break;
        case 1:
            getPlayerInfo(p);
            difficultMode(p);
            break;
        case 2:
            readLeaderBoard();
            break;
        default:
            break;
        }
    }
}