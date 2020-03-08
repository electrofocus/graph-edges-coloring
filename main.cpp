#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <set>

using namespace std;


class Solver {
    vector< vector<int> > graph;
    int steps;
    int size;
    int max_degree;

public:
    explicit Solver(vector< vector<int> > g, int clrs_num): graph(move(g)), steps(0), size(g.size()) {
        max_degree = 0;

        for (int i = 0; i < size; i++) {
            int k = 0;
            for (int j = 0; j < size; j++) {
                if (graph[i][j] != 0) {
                    k++;
                }
            }
            if (k > max_degree) {
                max_degree = k;
            }
        }

        max_degree++;
    }

    vector< vector<int> > solve() {
        set<int> colors;
        for (int i = 2; i < max_degree + 2; i++) {
            colors.insert(i);
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                set<int> clrs = colors;
                if (graph[i][j] == 1) {
                    for (int k = 0; k < size; k++) {
                        clrs.erase(graph[i][k]);
                        clrs.erase(graph[j][k]);
                    }
                    graph[i][j] = *clrs.begin();
                    graph[j][i] = *clrs.begin();
                }
            }
        }

        return graph;
    }

};

int main() {
    ifstream input("in.txt");
    int n = 0;
    input >> n;
    vector<vector<int> > gr(vector<vector<int> >(n, vector<int>(n, 0)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> gr[i][j];
        }
    }

    return 0;
}