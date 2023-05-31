#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"
const int MAX_PLAYERS = 6;
using namespace std;
namespace coup{
    Game::Game(){}
    string Game::turn(){
        return this->players_list.at(this->current_turn % (uint)this->players_list.size())->name;
    }
    vector<string> Game::players(){
        vector<string> v;
        for (uint i = 0; i < this->players_list.size(); i++) {
            v.push_back(this->players_list.at(i)->name);
        }
        return v;
    }
    string Game::winner(){
        if (!this->start){
            throw logic_error ("the game not start");
        }
        if (this->players_list.size() == 1) {
            return this->players_list.at(0)->name;
        }
        throw logic_error("the game isn't over");
    }
    void Game::next_turn(){
        this->current_turn++;   
    }
    void Game::next_turn(int place){
        for (uint i = 0; i < this->players_list.size(); i++) {
            if (this->players_list.at(i)->get_place() == place) {
                current_turn = i + 1;
            }
        }
        // this->current_turn = 
    }
    // int Game::get_turn(){
    //     return (int)this->current_turn % (int)this->players_list.size();
    // }
    void Game::set_turn(const string& name){
        for (uint i = 0; i < this->players_list.size(); i++) {
            if (this->players_list.at(i)->name == name) {
                this->current_turn = i;
            }
        }  
    }
    vector<Player*>* Game::get_list() {
        return &this->players_list;
    }
    void Game::add_player(Player* p){
        if (this -> start) {
            throw logic_error("the game already start sorry.");
        }
        if (this->players_list.size() >= MAX_PLAYERS) {
            throw out_of_range("could be at most 6 players");
        }
        vector<Player*>* v = get_list();
        v->push_back(p);
    }
    void Game::add_player(Player* p ,int place){
        if (this->players_list.size() > MAX_PLAYERS) {
            throw out_of_range("could be at most 6 players");
        }
        vector<Player*>* v = get_list();
        bool not_last = false;
        for (uint i = 0; i < v->size(); i++) {
            if (i == place){
                v->insert(v->begin() + i , p);
                not_last = true;
                break;
            }
        }
        if (!not_last) {
            v->insert(v->end(), p);
        }
    }
    void Game::remove_player(const string& name) {
        vector<Player*>* v = get_list();
        bool exist = false;
        for (uint i = 0; i < v->size(); i++) {
            if (v->at(i)->name == name) {
                v->erase(v->begin() + i);
                exist = true;
                break;
            }
        }
        if (!exist) {
            throw logic_error ("the player is not exist");
        }
    }
    void Game::set_start(){
        this->start = true;
    }
}