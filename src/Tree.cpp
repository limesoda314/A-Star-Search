#include "../headers/Tree.hpp"
#include "../headers/Board.hpp"

// accessors

void Tree::print_children(Board *parent) const{
    cout << endl << "printing parent board: " << endl; 
    parent->print_board();
    cout << endl; 
    if (parent->children.empty()) {
        cout << "no children" << endl; 
        return; 
    }

    cout << "printing children" << endl; 
    for (int i = 0; i < parent->children.size(); i++) {
        cout << i << ". " << endl; 
        parent->children.at(i)->print_board(); 
    }
} 

void Tree::print_children() const{

    if (root == nullptr) {
        cout << "Tree is empty" << endl; 
    }
    cout << endl << "printing parent board: " << endl; 
    root->print_board();
    cout << endl; 
    if (root->children.empty()) {
        cout << "no children" << endl; 
        return; 
    }

    cout << "printing children: " << endl; 
    for (int i = 0; i < root->children.size(); i++) {
        cout << i << ". " << endl; 
        root->children.at(i)->print_board(); 
    }
}

// mutators 
void Tree::insert(Board *parent, Board *child) {
    child->depth = parent->depth +1; 
    parent->children.push_back(child); 
    child->parent = parent; 
}

void Tree::insert(Board *child) {
    if (root == nullptr) {
        root = child; 
        child->depth = 0; 
        child->parent = nullptr; 
    }
    else {
        child->depth=1; 
        root->children.push_back(child); 
        child->parent = root; 
    }
}


// height of a leaf is 0
// height is the distance a node is from a leaf node
int Tree::get_height(Board *node) const {
    int result = 0; 

    for (int i = 0; i < node->children.size(); i++) {
        result = max(result, get_height(node->children.at(i), 1)); 
    }

    return result; 
}

int Tree::get_height(Board *Node, int height) const {
    int result = height; 

    for (int i = 0; i < Node->children.size(); i++) {
        result = max(result, get_height(Node->children.at(i), height +1)); 
    }

    return result; 
}

int Tree::get_depth(Board *Node) const {
    return Node->depth; 
}

