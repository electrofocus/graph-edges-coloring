#include <iostream>
#include "solver.h"
#include "tester.h"

using namespace std;


int main() {
    Tester::time_test(300, 90);
    Tester::time_test(400, 90);
    Tester::time_test(500, 90);
    Tester::time_test(600, 90);
    Tester::time_test(700, 90);

//    Solver solver = Solver(Tester::generate_matrix(500, 100), 1000);
//    vector<vector<int>> result = solver.solve();
//    cout << endl << "Is correct: " << Tester::check_correctness(result) << endl << endl;

    return 0;
}
