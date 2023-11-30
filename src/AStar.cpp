#include "../headers/AStar.hpp"


int AStar::f(Board* n, const string &heuristic) const {
    // uniform cost search 
    if (heuristic == "1") {
        return g(n); 
    }
    // Misplaced tiles 
    if (heuristic == "2") {
        return g(n) + misplaced(n); 
    }

    // euclidean
    if (heuristic == "3") {
        return g(n) + euclidean(n); 
    }
    return g(n); 

}

int AStar::h(Board* n, const string &heuristic) const {
    // uniform cost search 
    if (heuristic == "1") {
        return 0; 
    }
    // Misplaced tiles 
    if (heuristic == "2") {
        return misplaced(n); 
    }

    // euclidean
    if (heuristic == "3") {
        return euclidean(n); 
    }
    return 0; 

}

// g(n) is the cost to get to node n from the initial state     
int AStar::g(Board* n) const {
    return n->depth; 
}

// difference between current state n and goal state :D 
int AStar::misplaced(Board* n) const {
    int difference = 0;
    for (int i = 0; i < problem->goal_state->board.size(); i++) {
        for (int j = 0; j < problem->goal_state->board.at(i).size(); j++) {
            if (problem->goal_state->board.at(i).at(j) == 0 && problem->goal_state->board.at(i).at(j) != n->board.at(i).at(j)) {
                return difference; 
            }
            else if (problem->goal_state->board.at(i).at(j) != n->board.at(i).at(j)) {
                difference++; 
            }
        }
    }

    return difference;
}

// using manhattan 
int AStar::euclidean(Board *n) const {
    
    int dist = 0; 
    int dist_x = 0;
    int dist_y = 0; 

    vector<vector<int>> goal_board = problem->goal_state->board; 
    for (int i = 0; i <goal_board.size(); i++) {
        for (int j = 0; j < goal_board.at(i).size(); j++) {
            // value at goal doesn't match up with value in n 
            if (goal_board.at(i).at(j) != n->board.at(i).at(j)) {
                // find goal_board.at(i).at(j) in n
                int x_coord, y_coord; 
                for (int k = 0; k < goal_board.size(); k++) {
                    for (int l = 0; l < goal_board.at(k).size(); l++) {
                        if (n->board.at(k).at(l) == goal_board.at(i).at(j)) {
                            x_coord = k;
                            y_coord = l;
                            break; 
                        }
                    }
                }
                // to convert to euclidean, make dist_x and dist_y to the power of 2
                // afterwards take the sqrt of the sum 
                dist_x = abs(x_coord - i);
                dist_y = abs(y_coord - j);
                dist += dist_x + dist_y; 
            }
        }
    }

    return dist; 
}

Board* AStar::A_star_search(const string &heuristic) {
    
    Board *n = new Board();
    n = problem->init_state; 
    // initialize frontier queue
    pair<int, Board*> item(f(n, heuristic), n);  
    frontier_queue.push(item); 
    frontier_set.insert(n->board); 

    while (!(frontier_queue.empty())) {
        
        if (frontier_queue.empty()) {
            // return nullptr if failure
            cout << "Failure!!" << endl; 
            return nullptr;
        }
        if (frontier_queue.size() > max_queue) {
            max_queue = frontier_queue.size(); 
        }

        // cout << "frontier queue: " << frontier_queue.size() << endl;
        // cout << "frontier set: " << frontier_set.size() << endl; 
 
        // pop top node from frontier queue 
        pair<int, Board*> node_pair = frontier_queue.top();
        frontier_queue.pop(); 
        // delete node from the frontier set also 
        frontier_set.erase(node_pair.second->board); // maybe frontier_set.erase(frontier_set.find(node_pair))
        

        // check if the node from the frontier pair was the goal state
        if (problem->goal_state->board == node_pair.second->board) {
            // put the node into the explored set, we finished 
            exploredSet.insert(node_pair.second->board); 
            cout << "Goal!!" << endl;
            node_pair.second->print_board(); 
            return node_pair.second;  
        }

        else {
            // item is not goal state4 


            // check if item is not in the explored set
            // if it is, we don't wanna expand the node cuz ya know... already been expanded xD 
            if (exploredSet.find(node_pair.second->board) == exploredSet.end()) {
                
                // expand the state since node was not in explored set 
                // expand function will check that the expanded nodes are not in frontier already 
                
                cout << "Expanding state with g(n) = " << g(node_pair.second) << ", h(n) = " << h(node_pair.second, heuristic) << ", and f(n) = " << f(n, heuristic) << endl; 
                node_pair.second->print_board();
                cout << endl; 
                expand_state(node_pair, heuristic); 

                exploredSet.insert(node_pair.second->board); 
                // put the expanded states into the frontier queue 
                for (int i = 0; i < node_pair.second->children.size(); i++) {
                    pair<int, Board*> item_child(f(node_pair.second->children.at(i), heuristic), node_pair.second->children.at(i));
                    frontier_queue.push(item_child); 
                    frontier_set.insert(item_child.second->board); 
                }
                
                expanded_states++;
                // cout << "expanding node: " << expanded_states << endl; 
                // cout << "frontier size: " << frontier_queue.size() << endl; 
                // cout << "max frontier size: " << max_queue << endl; 
                // cout << "current depth: " << node_pair.second->depth << endl; 
        

            }
        }
        
    }
    // failure 
    cout << "Failure!!" << endl;
    return nullptr; 

}


void AStar::expand_state(pair<int, Board*> item, const string &heuristic) {
    Board* state=item.second; 
    for (int i = 0; i < state->board.size(); i++) {
        for (int j = 0; j < state->board.at(i).size(); j++) {
            if (state->board.at(i).at(j) == 0) {
                // check where we can move :D 
                // 4 possible cases
                // 1. up
                // 2. down
                // 3. right
                // 4. left 
                Board *child;
                
                // option up 
                if (i > 0) {
                    //cout << "expand up" << endl; 
                    child = new Board(problem->expand_up(state, i, j));

                    // if it equals the frontier.end() then it is not in the set 
                    // otherwise it's in the set
            
                    if (frontier_set.find(child->board) == frontier_set.end())
                    {
                        problem->tree->insert(state, child); 
        
                    }
                    
                }
                // option down
                if (i < 2) {
                    //cout << "expand down" << endl; 
                    child = new Board(problem->expand_down(state, i, j));

                    if (frontier_set.find(child->board) == frontier_set.end())
                    {
                        problem->tree->insert(state, child); 
                       
                    }
                }  
                // option right
                if (j < 2) {
                    // cout << "expand right" << endl; 
                    child = new Board(problem->expand_right(state, i, j));
                   
                    if (frontier_set.find(child->board) == frontier_set.end())
                    {
                        problem->tree->insert(state, child); 
                        
                    } 
                }
                // option left
                if (j > 0) {
                    //cout << "expand left" << endl; 
                    child = new Board(problem->expand_left(state, i, j));

                    if (frontier_set.find(child->board) == frontier_set.end()) 
                    {
                        problem->tree->insert(state, child); 
                         
                    }
                }

            } 
        }
    }


}


void AStar::find_path(Board * n, int i) const  {

    
    if (n->parent == nullptr) {
        n->print_board();
        return; 
    }
    find_path(n->parent, i-1); 
    cout << i << ")" <<endl; 
    n->print_board();
    cout << endl; 
    

}

