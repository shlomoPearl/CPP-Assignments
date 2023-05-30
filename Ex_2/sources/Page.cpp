#include<string>
#include<iostream>
#include"Page.hpp"


/*
return - line from this page
paramaters - row - the index of the line we want
*/
const char ERASE_CHAR = '~';
const int NOT_ERASE = 0;
const int LEN_LINE = 100;
const int IILEGAL_CHAR = 31;

Line* Page::get_line(int row){ 
    if(page.count(row) == 0){ // its a 'new' line
        Line line;
        page[row] = line;
    }
    return &page.at(row);
}


void Page::writeByDirection(Line* line,Direction d,int row,uint column, string change, int length){
    if(length != NOT_ERASE){
        if( d == Direction::Horizontal){
            for (uint i = 0; i < length; i++){
                line->set_char(i + column ,change[0]); 
            }  
        }else{
            int currentRow = row;
            for (int i = 0; i < length; i++){
                line->set_char(column ,change[0]);
                currentRow ++;
                line = get_line(currentRow);
            }
        }
    }
    else if( d == Direction::Horizontal){
        for (uint i = 0; i < change.size(); i++){
            if(line->get_char(i + column) == '_' && change.at(i) != '~' && change.at(i) > IILEGAL_CHAR){
                line->set_char(i + column ,change.at(i));
            }else{
                throw("this line has been writed or this char iilegal");
            }
        }  
    }else{
        int currentRow = row;
        for (uint i = 0; i < change.size(); i++){
            if(line->get_char(column) == '_' && change.at(i) != '~'){
                line->set_char(column,change.at(i));
                currentRow ++;
                line = get_line(currentRow);

            }else{
                throw("this line has been writed or this char iilegal");
            }
        }
    }
    empty_page = false;
}

void Page::write_line(int row, int column,Direction d, const string &change){
    if(d == Direction::Horizontal && (uint)column + change.size()> LEN_LINE ){
                throw out_of_range("the text too big");
    }
    Line* currentLine = get_line(row);
    writeByDirection(currentLine ,d ,row ,(uint)column ,change , NOT_ERASE);
}

void Page::erase_line(int row , int column ,Direction d, int length){
    if(d == Direction::Horizontal && column + length > LEN_LINE ){
                throw out_of_range(" too much erase");
    }
    Line* currentLine = get_line(row);
    writeByDirection(currentLine ,d ,row ,(uint)column ,&ERASE_CHAR , length);
}

string Page::read_line(int row ,uint column ,Direction d ,int length){
    if(d == Direction::Horizontal && column + (uint)length > LEN_LINE ){
                throw out_of_range("too much to read");
    }
    string ans;
    Line* l = get_line(row);
    if( d == Direction::Horizontal){
        for (uint i = 0; i < length ; i++){
            ans += l->get_char(column + i);
        }  
    }else{
        int currentRow = row;
        for (int i = 0; i < length; i++){
            ans += get_line(currentRow)->get_char(column);
            currentRow ++;
        }
    }
    return ans;
}