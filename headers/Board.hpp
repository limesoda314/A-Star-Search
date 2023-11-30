#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector> 
#include <iostream> 
using namespace std; 

// this is essentially the node class for the tree 
class Board {
    public:
        // 2-D array for a 3x3 board 
        vector<vector<int>> board; 
        int length = 3; 
        int width = 3;
        int depth = 0; 
        // vector of Boards 
        // cuz we don't want just a binary tree
        vector<Board*> children; 
        Board* parent = nullptr; 

        //constructors
        Board()  {} 
        Board(int l, int w) : length(l), width(w) {}
        Board(vector<vector<int>> array) : board(array){}

        // destructor
        ~Board() {
            // fix later
            if (children.empty()) {
                return; 
            }
            else {
                for (int i = 0; i < children.size(); i++) {
                    delete children.at(i);
                }
                children.clear(); 
            }
        }
        
        // accessors 
        void print_board() const; 

        // mutator 
        void fill_board(vector<vector<int>> _board); 
        void get_board(); 

        

};

#endif