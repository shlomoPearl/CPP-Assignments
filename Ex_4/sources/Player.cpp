#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
#include "Player.hpp"
const int MIN_PLAYERS = 2;
const int FOREIGN_AID = 2;
const int COST_OF_COUP = 7;
const int MUST_TO_DO_COUP = 11;
using namespace std;

namespace coup{
    Player::Player(Game& game ,const string& name) : game(game), name(name){
        game.add_player(this);
        this->place = (int)this->game.players().size() - 1;
    }
    void Player::income(){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (this-> coins() >= MUST_TO_DO_COUP) {
            throw logic_error (" you must tfo do coup");
        }
        check_turn();
        this->money++;
        this->last_operation = "income";
        this->game.set_start();
        this->game.next_turn();
    }
    void Player::foreign_aid(){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        if (this-> coins() >= MUST_TO_DO_COUP) {
            throw logic_error (" you must tfo do coup");
        }
        check_turn();
        this->money += FOREIGN_AID;
        this->last_operation = "foreign_aid";
        this->game.set_start();
        this->game.next_turn(); 
    }
    void Player::coup(Player& p){
        if (this->game.players().size() < MIN_PLAYERS) {
            throw logic_error ("the game need at least 2 players to begin");
        }
        check_turn();
        if (this->coins() < COST_OF_COUP){
            throw logic_error("can coup with at least 7 coins");
        }
        this->game.remove_player(p.name);
        this->set_money(-COST_OF_COUP);
        this->last_operation = "coup";
        this->game.set_start();
        // this->game.next_turn();
        this->game.next_turn(this->get_place());
    }
    int Player::coins()const{
        return this->money;
    }
    int Player::get_money()const{
        return this->money;
    }
    void Player::set_money(int m){
        this->money += m;
    }
    string Player::role(){
        return "role";
    }
    void Player::check_turn(){
        // cout << name<< " <- name , turn-> " << game.turn()<< endl;
        if (this->name != this->game.turn()){
            throw logic_error("it's not your turn");
        }
    }
    int Player::get_place()const{
        return this->place;
    }
}