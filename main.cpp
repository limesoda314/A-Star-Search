#include <iostream>
#include "headers/AStar.hpp"
#include "headers/Board.hpp"
#include "headers/Problem.hpp"
#include "headers/Tree.hpp"
using namespace std; 


void print_menu(); 

int main() {

    print_menu(); 

    return 0; 
}

void print_menu() {

    cout << "Welcome to 862208602 8 puzzle solver." << endl;
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl; 
    string puzzle_type; 
    cin >> puzzle_type; 
    cout << endl;

    AStar *astar_ver1 = new AStar(); 

    // init_state = 
    // 1 0 3
    // 7 2 6
    // 5 4 8
    // goal state =
    // 1 2 3
    // 4 5 6 
    // 7 8 0
    
    
    if (puzzle_type == "2") {
        Board *board1 = new Board();
    
        cout << "Enter your puzzle, use a zero to represent the blank" << endl;
        board1->get_board(); 
        
        cout << endl; 

        astar_ver1->problem->init_state = board1; 

    }

    cout << "initial state: " << endl; 
    astar_ver1->problem->init_state->print_board();
    cout << "goal state: " << endl; 
    astar_ver1->problem->goal_state->print_board();

    
    string heuristic; 
    cout << "Enter your choice of algorithm" << endl; 
    cout << "1 - Uniform Cost Search" << endl;
    cout << "2 - A* with the Misplaced Tile heuristic" << endl;
    cout << "3 - A* with the Euclidian distance heuristic" << endl;
    cout << endl; 

    cin >> heuristic;
    
    Board* solution = new Board(); 
    solution = astar_ver1->A_star_search(heuristic);
    if (solution == nullptr) {
        cout << "A Star Search has failed to find the solution" << endl; 
        cout << "The search algorithm expanded a total of " << astar_ver1->expanded_states <<" nodes." << endl;
        cout << "Tree depth: " << astar_ver1->problem->tree->get_height(astar_ver1->problem->tree->get_root()) << "." << endl;
        cout << "The maximum number of nodes in the queue at any one time: " << astar_ver1->max_queue << endl; 
        return;
    }

    cout << "To solve this problem the search algorithm expanded a total of " << astar_ver1->expanded_states <<" nodes." << endl;
    cout << "The depth of the goal node: " << astar_ver1->problem->tree->get_depth(solution) << "." << endl;
    cout << "The maximum number of nodes in the queue at any one time: " << astar_ver1->max_queue << endl; 
    
    cout << "Path of solution to root" << endl;
    astar_ver1->find_path(solution, solution->depth); 


}



/*
A star 
"1 - Uniform Cost Search" 
"2 - A* with the Misplaced Tile heuristic" 
"3 - A* with the Euclidian distance heuristic" 

*/