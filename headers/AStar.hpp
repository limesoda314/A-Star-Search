#ifndef __ASTAR_HPP__
#define __ASTAR_HPP__

#include <queue>
#include <vector>
#include <set> 
#include <cmath> 
#include "Tree.hpp"
#include "Board.hpp"
#include "Problem.hpp"

struct BoardCompare {
    bool operator()(const pair<int, Board*> lhs, pair<int, Board*> rhs) const
    {
        if (lhs.first != rhs.first) {
            return lhs.first > rhs.first;
        }
        return false;
    }

};

class AStar {

    public:
        int expanded_states = 0; 
        int max_queue = 0; 
        Problem *problem = new Problem();

        AStar(Problem *_problem) : problem(_problem) {}
        AStar() : problem(new Problem()) {}
        

        // pair<priority, Board*>
        priority_queue<pair<int, Board*>, vector<pair<int,Board*>>, BoardCompare> frontier_queue;
        set<vector<vector<int>>> exploredSet; 
        set<vector<vector<int>>> frontier_set; 

        void expand_state(pair<int, Board*>, const string &);  

        int f(Board* n, const string &) const; 


        // g(n) is the cost to get to node n from the initial state
        int g(Board* n) const; 

        // h(n) is the estimated distance from node n to the goal
        int h(Board* n, const string &) const; 
        int misplaced(Board* n) const;  
        int euclidean(Board* n) const; 

        Board* A_star_search(const string &); 

        void find_path(Board *, int i) const;


};

#endif