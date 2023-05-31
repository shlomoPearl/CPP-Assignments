#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"
#include "Game.hpp"
using namespace std;
namespace coup{
    class Game;
    class Assassin : public Player {

        string card = "Assassin";
        bool coup_assassin = false;
        Player* coup_p = NULL;
        // uint turn_of_coup;
        public:
            Assassin(Game& ,const string&);
            string role();
            void coup(Player&);
            void income();
            void foreign_aid();
            Player* get_coup_player();
    };
}