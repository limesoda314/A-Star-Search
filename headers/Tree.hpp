#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <vector> 
#include <iostream> 
#include "Board.hpp"
// each node is 3x3 aray 
// 3 rows, 3 columns
// the tree represents each of the possibilities of the puzzle 
class Tree {
    private: 
        Board *root;
        
    public: 
        // constructors
        Tree() : root(nullptr) {} 
        Tree(Board *_root) : root(_root) {} 

        ~Tree() {
            // fix later
            delete root; 
        }

        // accessors
        // void print_Tree(Board *treeRoot) const; 
        // void print_Tree() const;
        void print_children(Board *) const; 
        void print_children() const; 

        int get_height(Board*) const;  
        int get_height(Board *, int) const; // recursive helper function
        int get_depth(Board *) const; 

        
        Board* get_root() { return root;}
        Board* get_parent(Board *child) { return child->parent;} // kinda unnecessary tbh 

        // mutators 
        void insert(Board *parent, Board *child); 
        void insert(Board *child);  

};


#endif

