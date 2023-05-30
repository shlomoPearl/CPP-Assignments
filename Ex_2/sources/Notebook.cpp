#include "Notebook.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
const int LEN_LINE = 100;
const int PRINT_EMPTY_LINE = 10;
const int EMPTY_PAGE = 2;
const int NUM_OF_EMPTY_LINE_TO_PRINT = 5;


namespace ariel{
    Page* Notebook::get_page(int p){
        if(notebook.count(p) == 0){
            Page page;
            notebook[p] = page;
        }
        return &notebook.at(p);
    }
    void Notebook::write(int page, int row ,int column , Direction d, const string &st){ // string st
        if(st.empty()){
            return;
        }
        if(page < 0 || row < 0 || column <0){
            throw("negative input");
        }
        Page* p = get_page(page);
        p->write_line(row,column,d,st);
        }
    string Notebook::read(int page, int row ,int column , Direction d, int len){
        if(len == 0){
            return " ";
        }
        if(page < 0 || row < 0 || column < 0 || len < 0){
            throw("negative input");
        }   
        Page* p = get_page(page);
        return p->read_line(row,(uint)column,d,len);
    }
    void Notebook::erase(int page, int row ,int column , Direction d, int len){
        if(len == 0 ){
            return;
        }
        if(page < 0 || row < 0 || column < 0 || len < 0){
            throw("negative input");
        }
        Page* p = get_page(page);
        p->erase_line(row,column,d,len);
    }
    void print_line(Line* l ,int index, bool empty){
        if (index < 0 ){
            throw("negative input");
        }
        
        if(empty){
            cout<<index<<": ";
            for (int i = 0; i < PRINT_EMPTY_LINE; i++){
                cout<<l->get_char((uint)i);
            }
            cout<<endl;
        }else{
            cout<<index<<": ";
            for (int i = 0; i < LEN_LINE; i++)
            {
                cout<<l->get_char((uint)i);
            }
            cout<<endl;
        }
    }

    void Notebook::show(int page){
        if(page < 0 ){
            throw ("negative input");
        }
        Page* p = get_page(page);
        if(p->empty_page){
            for(int i = 0 ;i < EMPTY_PAGE ;i++){
                print_line(p->get_line(i), i, true);
            }
        }else{
            int count_empty_line = 0;
            int i = 0;
            while(count_empty_line < NUM_OF_EMPTY_LINE_TO_PRINT){
                if(p->get_line(i)->empty_line){
                    count_empty_line ++;
                }
                print_line(p->get_line(i) ,i ,false);
                i++;
            }

        }

    }
}
