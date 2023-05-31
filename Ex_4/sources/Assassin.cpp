#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Assassin.hpp"
const int FOREIGN_AID = 2;
const int MIN_PLAYERS = 2;
const int COST_OF_COUP = 7;
const int COST_OF_COUP_ASSASSIN = 3;
const int MUST_TO_DO_COUP = 11;
using namespace std;

namespace coup{
    Assassin::Assassin(Game& game ,const string& name) : Player(game, name){}
    string Assassin::role(){
        return this-> card;
    }
    void Assassin::income(){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (this-> coins() >= MUST_TO_DO_COUP) {
            throw logic_error (" you must tfo do coup");
        }
        check_turn();
        this->last_operation = "income";
        this->coup_p = NULL;
        this->set_money(1);
        this->game.set_start();
        this->game.next_turn();
    }
    void Assassin::foreign_aid(){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (this-> coins() >= MUST_TO_DO_COUP) {
            throw logic_error (" you must tfo do coup");
        }
        check_turn();
        this->coup_p = NULL;
        this->last_operation = "foreign_aid";
        this->set_money(FOREIGN_AID);
        this->game.set_start();
        this->game.next_turn(); 
    }
    void Assassin::coup(Player& p) {
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        check_turn();
        if (this->coins() < COST_OF_COUP_ASSASSIN){
            throw logic_error("need at least 3 coins");
        } 
        if (this->coins() >= COST_OF_COUP_ASSASSIN && this->coins() < COST_OF_COUP) {
            this->game.remove_player(p.name);
            this->set_money(-COST_OF_COUP_ASSASSIN);  // coup in 3 coins
            this->coup_p = &p;
            this->last_operation = "coup_A";
        }else {
            this->set_money(-COST_OF_COUP);  // coup in 7 like the other
            this->game.remove_player(p.name);
            this->last_operation = "coup";
            this->coup_p = NULL;
            // this->game.next_turn(); 
        }
        this->game.set_start();
        this->game.next_turn(this->get_place());
    }
    Player* Assassin::get_coup_player(){
        return this->coup_p;
    }
}