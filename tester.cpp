#include "tester.h"

bool Tester::check_correctness(vector<vector<int>> graph) {
    for (int i = 0; i < graph.size(); i++) {
        set<int> colors_in_row;
        set<int> colors_in_col;
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] != 0) {
                if (colors_in_row.find(graph[i][j]) == colors_in_row.end() && graph[i][j] != 1) {
                    colors_in_row.insert(graph[i][j]);
                }
                else {
                    return false;
                }
            }
            if (graph[j][i] != 0) {
                if (colors_in_col.find(graph[j][i]) == colors_in_col.end() && graph[j][i] != 1) {
                    colors_in_col.insert(graph[j][i]);
                }
                else {
                    return false;
                }
            }
        }
    }

    return true;
}

vector<vector<int>> Tester::time_test(int matrix_size, int probability) {
    auto graph = Tester::generate_matrix(matrix_size, probability);
    Solver solver = Solver(graph, graph.size() * 2);

    clock_t time_begin = clock();
    auto colored_graph = solver.solve();
    clock_t time_end = clock();
    double final_time = (double) (time_end - time_begin) / CLOCKS_PER_SEC;

    cout << "Matrix size: " << matrix_size << ", Density: " << probability << ", Steps: " << solver.get_steps()
         << ", Predicted steps:" << ((float)(matrix_size * matrix_size * matrix_size) / 2) * (float)probability * 0.01
         << ", Time: " << final_time << ", Time/Steps: " << final_time / solver.get_steps() << endl;

    return colored_graph;
}

vector<vector<int>> Tester::generate_matrix(int matrix_size, int probability) {
    srand(time(nullptr));
    vector<vector<int>> graph(vector<vector<int>>(matrix_size, vector<int>(matrix_size, 0)));

    for (int i = 1; i < matrix_size; i++) {
        for (int j = 0; j < i; j++) {
            if (rand() % 101 <= probability) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    return graph;
}
