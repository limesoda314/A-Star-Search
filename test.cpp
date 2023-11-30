#include <iostream>
#include <set>
#include <queue>

#include "headers/AStar.hpp"
#include "headers/Problem.hpp"
#include "headers/Tree.hpp"
#include "headers/Board.hpp"

int main() {
    Board *board1; 
    Board *board2; 
    board1 = new Board(vector<vector<int>> {{1,2,3},{4,5,6}, {7,0,8}});
    board2 = new Board(vector<vector<int>> {{1,2,3},{4,5,6}, {7,8,0}}); 

    Problem* problem1;
    problem1 = new Problem(board1, board2); 
    AStar* astar1;
    astar1 = new AStar(problem1); 

    cout << "initial board: " << endl; 
    astar1->problem->init_state->print_board(); 
    cout << "goal board: " << endl; 
    astar1->problem->goal_state->print_board(); 

    cout << "----------------------------------" << endl;

    pair<int, Board*> item1;
    item1 = make_pair(2, board1);
    pair<int, Board*> item2;
    item2 = make_pair(1, board2);
    pair<int, Board*> item3(0, board2);
    pair<int, Board*> item4(0, board1);

    astar1->problem;
    astar1->frontier_queue; 
    astar1->frontier_set;

    astar1->frontier_queue.push(item1); 
    cout << astar1->frontier_queue.top().first << endl; 
    astar1->frontier_queue.push(item2); 
    cout << astar1->frontier_queue.top().first << endl; 
    astar1->frontier_queue.push(item3);
        cout << astar1->frontier_queue.top().first << endl; 
        //astar1->frontier_queue.top().second->print_board();
    astar1->frontier_queue.push(item4);
        cout << astar1->frontier_queue.top().first << endl; 
        //astar1->frontier_queue.top().second->print_board();

    astar1->frontier_set.insert(item1.second->board); 
    astar1->frontier_set.insert(item2.second->board);
    astar1->frontier_set.insert(item3.second->board); 
    astar1->frontier_set.insert(item4.second->board);

    // astar1->frontier_queue.size() == 0
    while (!(astar1->frontier_queue.empty())) {
        cout << "popped an item" << endl; 
        astar1->frontier_set.erase(astar1->frontier_queue.top().second->board);
        astar1->frontier_queue.pop();
    }
    cout << "frontier set size: " << astar1->frontier_set.size() << endl; 

    astar1->expand_state(astar1->frontier_queue.top(), "1");  

    cout << "number of children: " <<  astar1->frontier_queue.top().second->children.size() << endl; 

    if (astar1->frontier_set.find(item3.second->board) == astar1->frontier_set.end()) {
        cout << "top is not in the frontier set" << endl;
    }

    else {
        cout << "found the top in the frontier set" << endl;
    }
    

    

    return 0; 

}