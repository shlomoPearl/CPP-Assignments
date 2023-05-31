#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Ambassador.hpp"
const int MUST_TO_DO_COUP = 11;
const int TAX = 3;
const int STOLEN_MONEY = 2;
const int MIN_PLAYERS = 2;
using namespace std;

namespace coup{
    Ambassador::Ambassador(Game& game ,const string& name) : Player(game, name){}
    string Ambassador::role(){
        return this-> card;
    }
    void Ambassador::transfer(Player& p1, Player& p2){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (this-> coins() >= MUST_TO_DO_COUP) {
            throw logic_error (" you must tfo do coup");
        }
        this->check_turn();
        if (p1.coins() > 0){
            p1.set_money(-1);
            p2.set_money(1);
            this->game.next_turn();
        }else{
            throw logic_error ("can transfer one coin not zero"); 
        }
    }  
    void Ambassador::block(Captain& c){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (c.last_operation != "steal"){
            throw logic_error ("can block only steal method");
        }
        c.set_money(-STOLEN_MONEY);
        Player* stolen_men = c.get_stolen();
        stolen_men->set_money(STOLEN_MONEY);
    }  
}