#ifndef __PROBLEM_HPP__
#define __PROBLEM_HPP__

#include "Tree.hpp"
#include "Board.hpp"
#include<queue>
#include<set> 

class Problem {

    public:
        // states
        Tree *tree = new Tree(init_state); 
        Board *init_state;
        Board *goal_state; 

        // operators 
        Problem(Board *_init_state, Board *_goal_state) : init_state(_init_state), goal_state(_goal_state) {}
        Problem() :
            init_state(new Board(vector<vector<int>> {{1,0,3},{7,2,6},{5,4,8}})),
            goal_state(new Board(vector<vector<int>> {{1,2,3},{4,5,6},{7,8,0}}))
        {}
        ~Problem() {
            delete init_state;
            delete goal_state;
            delete tree; 
        }

        bool valid_board(Board*); 

        // expand the state (move up, down, right, left)
        // void expand_state(set<pair<int, Board*>>,  pair<int, Board*>);  
        // expands in all 4 directions without caring about if there are any repeats :D, probably not good 

        // void expand_up(Tree*, Board*);
        // void expand_down(Tree*, Board*);
        // void expand_right(Tree*, Board*);
        // void expand_left(Tree*, Board*);

        // get the board after expanding up/down/right/left 
        vector<vector<int>> expand_up(Board*, int, int); 
        vector<vector<int>> expand_down(Board*, int, int);
        vector<vector<int>> expand_right( Board*, int, int);
        vector<vector<int>> expand_left(Board*, int, int);

        
        
};

#endif