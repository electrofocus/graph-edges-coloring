#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <ctime>

using namespace std;


class Solver {
private:
    vector<vector<int>> graph;
    int steps;
    set<int> default_colors;

public:
    explicit Solver(vector<vector<int>> g, int colors_num) {
        graph = g;
        steps = 0;

        for (int i = 2; i < colors_num + 2; i++) {
            default_colors.insert(i);
        }
    }

    vector<vector<int>> solve() {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                if (graph[i][j] == 1) {
                    set<int> available_colors = default_colors;
                    for (int k = 0; k < graph.size(); k++) {
                        available_colors.erase(graph[i][k]);
                        available_colors.erase(graph[j][k]);
                        steps++;
                    }
                    if (available_colors.empty()) {
                        graph.clear();
                        return graph; // возвращает пустой граф, если не может раскрасить
                    }
                    graph[i][j] = *available_colors.begin();
                    graph[j][i] = *available_colors.begin();
                }
            }
        }

        return graph;
    }

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

class Tester {
public:
    Tester() = default;

    static bool check_correctness(vector<vector<int>> graph) {
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

    static void time_test(int matrix_size, int probability) {
        auto graph = Tester::generate_graph(matrix_size, probability);
        Solver solver = Solver(graph, graph.size());

        clock_t time_begin = clock();
        solver.solve();
        clock_t time_end = clock();
        double final_time = (double) (time_end - time_begin) / CLOCKS_PER_SEC;

        cout << "Matrix size: " << matrix_size << ", Density: " << probability << ", Steps: " << solver.get_steps() << ", Time: " << final_time
             << ", Time/Steps: " << final_time / solver.get_steps() << endl;
    }

    static vector<vector<int>> generate_graph(int matrix_size, int probability) {
        srand(time(nullptr));
        vector<vector<int> > graph(vector<vector<int> >(matrix_size, vector<int>(matrix_size, 0)));

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
};

int main() {

    Tester::time_test(100, 90);
    Tester::time_test(200, 90);
    Tester::time_test(300, 90);
    Tester::time_test(400, 90);
    Tester::time_test(500, 90);

    return 0;
}