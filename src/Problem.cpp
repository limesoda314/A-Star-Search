#include "../headers/Problem.hpp"
#include <set> 

// operators 


bool Problem::valid_board(Board* state) {
    // range: 0-8 
    set<int> vals = {0,1,2,3,4,5,6,7,8}; 
    set<int> board_vals; 
    for (int i = 0; i < state->board.size(); i++) {
        for (int j = 0; j < state->board.at(i).size(); j++) {
            board_vals.insert(state->board.at(i).at(j)); 
        }
    }
    if (board_vals == vals) {
        return true; 
    }
    
    return false; 
} 

vector<vector<int>> Problem::expand_up(Board* state, int row, int col) {
    vector<vector<int>> temp_array; 
    for (int i = 0; i < state->board.size(); i++) {
        temp_array.push_back(vector<int>{}); 
        for (int j = 0; j < state->board.at(i).size(); j++) {
            // state->board.at(i).at(j) == 0 
            // swap board.at(i).at(j) with board.at(i-1).at(j) == 0
            if (row-1 == i && j == col) {
                temp_array.at(i).push_back(state->board.at(row).at(col));
            }
            else if (row == i && j == col) {
                temp_array.at(i).push_back(state->board.at(i-1).at(j));
            }
            else {
                temp_array.at(i).push_back(state->board.at(i).at(j)); 
            }
        }
    }

    return temp_array; 
}
vector<vector<int>> Problem::expand_down(Board* state, int row, int col){
    vector<vector<int>> temp_array; 
    for (int i = 0; i < state->board.size(); i++) {
        temp_array.push_back(vector<int>{}); 
        for (int j = 0; j < state->board.at(i).size(); j++) {
            // state->board.at(i).at(j) == 0 
            // swap board.at(row).at(col) with board.at(row+1).at(col) == 0
            if (row+1 == i && j == col) {
                temp_array.at(i).push_back(state->board.at(row).at(col));
            }
            else if (row == i && j == col) {
                temp_array.at(i).push_back(state->board.at(i+1).at(j));
            }
            else {
                temp_array.at(i).push_back(state->board.at(i).at(j)); 
            }
        }
    }

    return temp_array; 
}
vector<vector<int>> Problem::expand_right(Board* state, int row, int col){
    vector<vector<int>> temp_array; 
    for (int i = 0; i < state->board.size(); i++) {
        temp_array.push_back(vector<int>{}); 
        for (int j = 0; j < state->board.at(i).size(); j++) {
            // state->board.at(i).at(j) == 0 
            // swap board.at(row).at(col) with board.at(row+1).at(col) == 0
            if (row == i && j == col+1) {
                temp_array.at(i).push_back(state->board.at(row).at(col));
            }
            else if (row == i && j == col) {
                temp_array.at(i).push_back(state->board.at(i).at(j+1));
            }
            else {
                temp_array.at(i).push_back(state->board.at(i).at(j)); 
            }
        }
    }

    return temp_array; 
}


vector<vector<int>> Problem::expand_left(Board* state, int row, int col) {
    vector<vector<int>> temp_array; 
    for (int i = 0; i < state->board.size(); i++) {
        temp_array.push_back(vector<int>{}); 
        for (int j = 0; j < state->board.at(i).size(); j++) {
            // state->board.at(i).at(j) == 0 
            // swap board.at(row).at(col) with board.at(row).at(col-1) == 0
            if (row == i && j == col-1) {
                temp_array.at(i).push_back(state->board.at(row).at(col));
            }
            else if (row == i && j == col) {
                temp_array.at(i).push_back(state->board.at(i).at(j-1));
            }
            else {
                temp_array.at(i).push_back(state->board.at(i).at(j)); 
            }
        }
    }

    return temp_array; 
}