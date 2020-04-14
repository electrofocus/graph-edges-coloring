#ifndef CAMOLA_TESTER_H
#define CAMOLA_TESTER_H

#include "solver.h"
#include <ctime>


class Tester {
public:
    Tester() = default;

    static bool check_correctness(vector<vector<int>> graph);

    static void time_test(int matrix_size, int probability);

    static vector<vector<int>> generate_graph(int matrix_size, int probability);
};


#endif //CAMOLA_TESTER_H
