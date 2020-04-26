#ifndef CAMOLA_SOLVER_H
#define CAMOLA_SOLVER_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solver {
private:
    vector<vector<int>> graph;
    int steps;
    int colors_num;
    bool *colors;

public:
    explicit Solver(vector<vector<int>> g, int colors_num) {
        graph = g;
        steps = 0;

        this->colors_num = colors_num;
        colors = new bool[colors_num];
    }

    vector<vector<int>> solve();

    int get_steps() {
        return steps;
    }

    void print_matrix() {
        for (auto e: graph) {
            for (auto v: e) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};


#endif //CAMOLA_SOLVER_H
