#pragma once

#include <iostream>
#include <string>
#include "Game.hpp"

using namespace std;
namespace coup{
    class Game;
    class Player{

        int money = 0;
        int place;
        protected:
            Game& game;
        public:
            string last_operation;
            const string& name;
            Player(Game&, const string&);
            virtual void income();
            virtual void foreign_aid();
            virtual void coup(Player&);
            virtual string role();
            int coins()const;
            int get_money()const;
            void set_money(int);
            void check_turn();
            int get_place()const;
    };
}