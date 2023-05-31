#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Duke.hpp"
const int MIN_PLAYERS = 2;
const int TAX = 3;
const int FOREIGN_AID = 2;
const int MUST_TO_DO_COUP = 11;
using namespace std;

namespace coup{
    Duke::Duke(Game& game, const string& name) : Player(game, name){} 
    
    string Duke::role(){
        return this-> card;
    }
    void Duke::block(Player& p){
        this->last_operation = "block";
        if (p.last_operation != "foreign_aid") {
            throw logic_error ("can block only FOREIGN_AID");
        }
        p.set_money(-FOREIGN_AID);
    }
    void Duke::tax(){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (this-> coins() >= MUST_TO_DO_COUP) {
            throw logic_error (" you must tfo do coup");
        }
        check_turn();
        this->last_operation = "tax";
        this->set_money(TAX);
        this->game.set_start();
        this->game.next_turn();
    }    
}