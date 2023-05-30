#include "Line.hpp"
#include<vector>
using namespace std;

void Line::set_char(uint index, char c){
    line.at(index) = c;
    empty_line = false;
}
char Line::get_char(uint index){
    return line.at(index);
}
