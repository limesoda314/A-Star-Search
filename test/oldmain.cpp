#include <iostream>
// #include "headers/AStar.hpp"
// #include "headers/Board.hpp"
// #include "headers/Problem.hpp"
// #include "headers/Tree.hpp"
#include "../headers/AStar.hpp"
#include "../headers/Board.hpp"
#include "../headers/Problem.hpp"
#include "../headers/Tree.hpp"
using namespace std; 


void print_menu(); 

int main() {

    //print_menu(); 

    // checking if board works... think it does :D 
    // Board board1;
    // cout << "get board" << endl; 
    // board1.get_board();  
    // cout << endl << "print board" << endl; 
    // board1.print_board(); 
    // Board board2;
    // board2.fill_board(myBoard.board); 
    // cout << endl << "print board2" << endl; 
    // board2.print_board(); 

    Tree *Tree1 = new Tree(); 
    // Board *board1 = new Board();
    // cout << "get board1: " << endl; 
    // board1->get_board(); 

    // Board *board2 = new Board();
    // cout << "get board2: " << endl; 
    // board2->get_board(); 

    // Board *board3 = new Board();
    // cout << "get board3: " << endl; 
    // board3->get_board(); 


    // vector<vector<int>> vect = {{1,2,3},{4,8,0},{7,6,5}}; 
    vector<vector<int>> vect = {{1,2,3},{4,0,6},{7,5,8}}; 
    Board *board4 = new Board(vect); 

    cout << "-------insert children to tree1-------------" << endl;

    // Tree1->insert(board1); 
    // Tree1->insert(board2);
    // Tree1->insert(board2, board3); 
    // Tree1->insert(board3, board4); 
    Tree1->insert(board4); 

    Board *init_state = board4;
    Board *goal_state = new Board(vector<vector<int>> {{1,2,3},{4,5,6},{7,8,0}}); 

    Problem *problem1;
    problem1 = new Problem(init_state, goal_state);
    
    if (problem1->valid_board(Tree1->get_root())) {
        cout << "valid board" << endl; 
    }
    else {
        cout << "not valid" << endl; 
    }
    // void expand_state(Tree* tree, Board*);
    
    Tree1->get_root()->print_board(); 

    cout << "init state: " << endl; 
    problem1->init_state->print_board();
    cout << "goal state: " << endl; 
    problem1->goal_state->print_board();

    AStar *astar_ver1 = new AStar(problem1); 
    cout << "Astar init state" << endl; 
    astar_ver1->problem->init_state->print_board();

    cout << endl << endl; 

    cout <<"uniform cost search----------------" << endl; 

    Board* solution = new Board();
    // 1 - uniform cost search
    // 2 - misplaced
    // 3 - euclid 
    solution = astar_ver1->A_star_search(astar_ver1->problem->init_state, "3"); 
    if (solution == nullptr) {
        cout << "no solution" << endl;
    }
    else {
        cout << "solution found" << endl;
        solution->print_board();
    }
    cout << "number of nodes expanded: " << astar_ver1->expanded_states << endl; 
    cout << "depth of tree: " << astar_ver1->problem->tree->get_depth(solution) << endl;
    cout << "height of tree: " << astar_ver1->problem->tree->get_height(solution) << endl;

    


     
    // problem1->expand_state(Tree1, Tree1->get_root()); 

    // cout << endl << "--------print children------------" << endl; 
    // Tree1->print_children(); 

    // works so far, when expanded, the nodes become children of the node
    

    // cout << "--------print depth of tree1-----------------" << endl;
    // cout << "root depth:        " << Tree1.get_depth(Tree1.get_root()) << endl;  
    // cout << "child depth:       " << Tree1.get_depth(Tree1.get_root()->children.at(0)) << endl; 
    // cout << "grandchild depth:  " << Tree1.get_depth(Tree1.get_root()->children.at(0)->children.at(0)) << endl; 
    // cout << "great-grandchild depth:  " << Tree1.get_depth(Tree1.get_root()->children.at(0)->children.at(0)->children.at(0)) << endl;

    // cout << "--------print depth of tree2-----------------" << endl;
    // vector<vector<int>> vect2 = {{1,2,3},{4,5,6},{7,8,0}}; 
    // Tree Tree2(new Board(vect2)); 
    // cout << "root depth:        " << Tree2.get_depth(Tree2.get_root()) << endl;

    // cout << "--------print height of tree1-----------------" << endl;

    // cout << "root height:        " << Tree1.get_height(Tree1.get_root()) << endl;  
    // cout << "child height:       " << Tree1.get_height(Tree1.get_root()->children.at(0)) << endl; 
    // cout << "grandchild height:  " << Tree1.get_height(Tree1.get_root()->children.at(0)->children.at(0)) << endl; 
    // cout << "great-grandchild height:  " << Tree1.get_height(Tree1.get_root()->children.at(0)->children.at(0)->children.at(0)) << endl;

    // print tree doesn't work yet -------------------------------------
    // cout << "--------print Tree children------------" << endl;
    // Tree1.print_Tree(board1); 

    // root = board1
    // child = board2, board 3
    // grandchild = board3


    return 0; 
}

void print_menu() {

    cout << "Welcome to 862208602 8 puzzle solver." << endl;
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl; 
    cout << endl;

    cout << "Enter your puzzle, use a zero to represent the blank" << endl;
    cout << "Enter the first row, use space or tabs between numbers" << endl;
    cout << "Enter the second row, use space or tabs between numbers" << endl; 
    cout << "Enter the third row, use space or tabs between numbers" << endl; 
    cout << endl; 

    cout << "Enter your choice of algorithm" << endl; 
    cout << "1 - Uniform Cost Search" << endl;
    cout << "2 - A* with the Misplaced Tile heuristic" << endl;
    cout << "3 - A* with the Euclidian distance heuristic" << endl;
    cout << endl; 

    cout << "Expanding state" << endl; 
    // 1 2 3
    // 4 8 b
    // 7 6 5

    cout << "The best state to expand with g(n) = 1 and h(n) = 4 is..." << endl;
    // 1 2 3
    // 4 8 5
    // 7 6 b    Expanding this node... 

    cout << "The best state to expand with g(n) = 2 and h(n) = 3 is..." << endl;
    // 1 2 3
    // 4 8 5
    // 7 b 6    Expanding this node...


    cout << "The best state to expand with g(n) = 4 and h(n) = 1 is..." << endl;
    // 1 2 3
    // 4 5 6
    // 7 b 8    Expanding this node...

    cout << "Goal!!" << endl << endl;

    cout << "To solve this problem the search algorithm expanded a total of XXX nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time: YYY." << endl;
    cout << "The depth of the goal node: ZZZ." << endl;   



}



/*
A star 
"1 - Uniform Cost Search" 
"2 - A* with the Misplaced Tile heuristic" 
"3 - A* with the Euclidian distance heuristic" 









*/