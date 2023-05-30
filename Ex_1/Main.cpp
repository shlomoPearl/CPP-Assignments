#include<iostream>
#include"mat.hpp"
#include<string>
#include<vector>

int main(){
    using namespace ariel;
    using namespace std;
    int row = 7;
    int column = 9;
    char c1 = '#';
    char c2 = '-';
    string a;
    a = mat(column,row,c1,c2);
    for(int i = 0 ; i< a.size(); i++){
        cout << a.at(i);
    }
    cout << endl<< "Enter mat size and design:"<< endl;
    cin >> column;
    cin >> row;
    cin >> c1;
    cin >> c2;
    a = mat(column,row,c1,c2);
    for(int i = 0 ; i< a.size(); i++){
        cout << a.at(i);
    }

    return 0;
}