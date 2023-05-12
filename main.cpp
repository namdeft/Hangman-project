#include "Game/Game.h"
#include "Menu/Menu.h"
#include <iostream>
using namespace std;

enum ACTIONTYPE {
    PLAY_GAME,
    EXIT_GAME,
    HINT_SETTING,
    FAIL_SETTING,
    WORD_SETTING
};

int main() {
    Menu *mainMenu = new Menu("Main Menu", "The game main menu");
    Menu *settingMenu = new Menu("Game Settings Menu", "The game setting menu");
    Menu *wordBankMenu = new Menu("Word Bank Menu", "The Word Bank menu");
    Menu *playMenu = new Menu("Play Game", "Back to the main menu", PLAY_GAME);
    Menu *exitMenu = new Menu("Exit Game", "Bye", EXIT_GAME);
    mainMenu->addSubMenu(settingMenu);
    mainMenu->addSubMenu(wordBankMenu);
    mainMenu->addSubMenu(playMenu);
    mainMenu->addSubMenu(exitMenu);

    Menu *setHint = new Menu("Hint Settings",
                             "Set the maximum hint can be used", HINT_SETTING);
    Menu *setFail = new Menu("Fail Settings",
                             "Set the maximum failure in a game", FAIL_SETTING);
    Menu *setWord = new Menu("Word Settings",
                             "Set the number of words in a game", WORD_SETTING);
    settingMenu->addSubMenu(setHint);
    settingMenu->addSubMenu(setFail);
    settingMenu->addSubMenu(setWord);
    settingMenu->addSubMenu(mainMenu);

    playMenu->addSubMenu(mainMenu);

    Menu *currentMenu = mainMenu;
    Game *currentGame = new Game();

    while (true) {
        currentMenu->displayMenu();
        int option = currentMenu->promptOption();
        currentMenu = currentMenu->getSubMenu(option);
        switch (currentMenu->getAction()) {
        case -1:
            ////
            break;
        case PLAY_GAME:
            cout << "Playing the game" << endl;
            break;
        case EXIT_GAME:
            cout << "Exit the game" << endl;
            exit(0);
        case FAIL_SETTING:
            currentGame->setFailLimit();
            break;
        default:
            cout << "Default action" << endl;
        }
    }

    return 0;
}