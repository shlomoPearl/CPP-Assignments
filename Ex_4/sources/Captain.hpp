#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
namespace coup{
class Captain : public Player {

    string card = "Captain";
    Player* stolen = NULL;
    int stolen_money = 0;
    public:

        Captain(Game& ,const string&);
        string role();
        void steal(Player&);
        void block(Player&);
        Player* get_stolen();
};
}