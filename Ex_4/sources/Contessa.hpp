#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
using namespace std;
namespace coup{
    class Assassin;
    class Contessa : public Player {

        string card = "Contessa";
        Player* coup_assassin = NULL;
        public:
            
            Contessa(Game& ,const string&);
            string role();
            void block(Assassin&);
    };
}