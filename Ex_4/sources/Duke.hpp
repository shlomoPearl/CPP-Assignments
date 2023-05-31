#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;
namespace coup{
    class Duke : public Player {
        string card = "Duke";
        public:
            Duke(Game& ,const string&);
            string role();
            void block(Player&);
            void tax();
    };
}