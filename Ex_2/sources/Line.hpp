#pragma once

#include<vector>
#include<string>

using namespace std;
class Line{
    vector<char> line;
    public:
    bool empty_line = true;
    Line() : line(100,'_'){};
    void set_char(uint, char c);
    char get_char(uint index);

};