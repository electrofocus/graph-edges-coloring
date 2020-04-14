#ifndef CAMOLA_TESTER_H
#define CAMOLA_TESTER_H

#include "solver.h"
#include <ctime>


class Tester {
public:
    Tester() = default;

    static bool check_correctness(vector<vector<int>> graph);

    static vector<vector<int>> time_test(int matrix_size, int probability);

    static vector<vector<int>> generate_matrix(int matrix_size, int probability);
};


#endif //CAMOLA_TESTER_H
