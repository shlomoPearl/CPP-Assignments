#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Player;
    class Game{
        vector<Player*> players_list;
        vector<Player*>* get_list();
        bool start = false;
        uint current_turn = 0;
        public:
            Game();

            string turn();
            vector<string> players();
            string winner();
            void next_turn();
            void next_turn(int);
            void set_turn(const string&);
            void add_player(Player*);
            void add_player(Player*, int);
            void remove_player(const string&);
            void set_start();

    };
}