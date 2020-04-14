#include <iostream>
#include "tester.h"
#include "solver.h"

using namespace std;


int main() {
//    Tester::time_test(300, 90);
//    Tester::time_test(400, 90);
//    Tester::time_test(500, 90);
//    Tester::time_test(600, 90);
//    Tester::time_test(700, 90);

//    Solver solver = Solver(Tester::generate_matrix(10, 50), 10);

//    solver.print_matrix();
//    solver.solve();
//    cout << endl;
//    solver.print_matrix();

    auto gr = Tester::time_test(20, 50);

    for (int i = 0; i < gr.size(); i++) {
        for (int j = 0; j < gr.size(); j++) {
            cout << gr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
