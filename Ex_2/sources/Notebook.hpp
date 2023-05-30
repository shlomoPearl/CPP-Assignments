#pragma once

#include <string.h>
#include <vector>
#include <unordered_map>
#include "Page.hpp"
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Notebook
    {
    unordered_map<int,Page> notebook;
    Page* get_page(int p);
    public:
        void write(int page, int row ,int column , Direction d,const string&);
        string read(int page, int row ,int column , Direction d, int len);
        void erase(int page, int row ,int column , Direction d, int len);  
        void show(int page);
    };
}