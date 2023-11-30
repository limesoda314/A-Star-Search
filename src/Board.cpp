#include "../headers/Board.hpp"

// accessors 
void Board::print_board() const {
    for (int i = 0; i < board.size(); i++) {
        
        for (int j = 0; j < board.at(i).size(); j++) {
            
            cout << board.at(i).at(j) << " "; 
        }
        cout << endl; 
    }
}

void Board::fill_board(vector<vector<int> > _board) {
    for (int i = 0; i < _board.size(); i++) {
        // add a row 
        this->board.push_back(vector<int>(_board.size())); 
        for (int j = 0; j < _board.at(i).size(); j++) {
            // fill in the row 
            this->board.at(i).at(j) = _board.at(i).at(j); 
        }
    }
}

void Board::get_board() {
    for (int i = 0; i < length; i++) {
        this->board.push_back(vector<int>(width));
        cout << "Enter row " << i+1 << ", use space or tabs between numbers" << endl;
        for (int j = 0; j < width; j++) {
            int temp; 
            
            cin >> temp;
            this->board.at(i).at(j) = temp; 
        }
    }
}

