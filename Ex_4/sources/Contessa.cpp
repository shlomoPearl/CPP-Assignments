#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Contessa.hpp"
const int MIN_PLAYERS = 2;
const int TAX = 3;
using namespace std;

namespace coup{
    Contessa::Contessa(Game& game ,const string& name) : Player(game, name){}
    string Contessa::role(){
        return this-> card;
    }
    void Contessa::block(Assassin& a){
        if (a.last_operation != "coup_A"){
            throw logic_error("can block only coup of Assassin");
        }
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        Player* p = a.get_coup_player();
        string name = this->game.turn();
        this->game.add_player(p ,p->get_place());    
        this->game.set_turn(name);
    }    
}