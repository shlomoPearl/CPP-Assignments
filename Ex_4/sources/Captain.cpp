#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Captain.hpp"
const int MIN_PLAYERS = 2;
const int TAX = 3;
const int STOLEN_MONEY = 3;
const int MUST_TO_DO_COUP = 11;
using namespace std;

namespace coup{
    Captain::Captain(Game& game ,const string& name) : Player(game, name){}
    string Captain::role(){
        return this-> card;
    }
    void Captain::steal(Player& p){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (this-> coins() >= MUST_TO_DO_COUP) {
            throw logic_error (" you must tfo do coup");
        }
        this->check_turn();
        this->last_operation = "steal";
        if (p.coins() >= 2) {
            this->set_money(2);
            p.set_money(-2);
            this->stolen_money = 2;
        }else {
            int avaiable = p.coins();
            this->set_money(avaiable);
            p.set_money(-avaiable);
            this->stolen_money = 2;
        }
        this->stolen = &p;
        this->game.set_start();
        this->game.next_turn();
    } 
    void Captain::block(Player& p){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (p.last_operation != "steal") {
            throw logic_error("can block only 'steal' operation");
        }
        if (p.role() != "Captain"){
            throw logic_error ("can block only Captain role");
        }
        Captain& c = dynamic_cast<Captain&>(p);
        c.set_money(-STOLEN_MONEY);
        Player* stolen_men = c.get_stolen();
        stolen_men->set_money(c.stolen_money);
    }
    Player* Captain::get_stolen(){
        return this->stolen;
    }   
}