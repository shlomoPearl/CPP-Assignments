#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
const int LEVEL = 1;
const int REVERSE = 2;
const int PRE_ORDER = 3;


namespace ariel{
	struct Node {
		string name;
		int size = 0;
		vector<Node*>* children = new vector<Node*>();
		Node* next = nullptr;
		Node(){}
		~Node();
		Node& operator=(const Node&) = default;
		Node & operator= (Node && ) = default;
		Node (Node&&) = default;
		Node(const string& name):name(name) {
			size = name.size();
		}
		Node(Node& other):name(other.name), size(other.size),children(other.children){}
	};
    class OrgChart{

		private:

		Node* root = NULL;
		int size = 0;
		bool exist = false;

		public:

		OrgChart();
        ~OrgChart(){}
		OrgChart(const OrgChart&);
		OrgChart& operator=(const OrgChart&) = default;
		OrgChart & operator= (OrgChart && ) = default;
		OrgChart (OrgChart&&) = default;
		friend void print(Node* , string* );
		friend ostream& operator<< (ostream& output, const OrgChart& orgChart);

        OrgChart& add_root(const string&);

        OrgChart& add_sub(const string& ,const string&);

		void add_sub(Node*, const string&, const string&);  

	class Iterator {

	private:

	  	int type = -1;
		Node* current_node;
		queue<Node*>* q = new queue<Node*>();
		stack<Node*>* s = new stack<Node*>();
		
	public:

		Iterator(int, Node*);
		Iterator(Node* ptr) : current_node(ptr){}
		void level();
		void reverse();
		void pre_order();
		void pre_order(Node*); //recursive
        
		string& operator*() const; 
		string* operator->() const;
		Iterator& operator++(); // prefix
		Iterator operator++(int); // postfix
		bool operator==(const Iterator& iter)const;
		bool operator!=(const Iterator& iter) const;
	};  // end iterator class

	
	Iterator begin()const;
	Iterator end()const;

	Iterator begin_level_order()const;
    Iterator end_level_order()const;

    Iterator begin_reverse_order()const;
    Iterator reverse_order()const;

    Iterator begin_preorder()const;
    Iterator end_preorder()const;
	
    }; // end of OrgChart class
};