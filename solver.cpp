#include "solver.h"

vector<vector<int>> Solver::solve() {
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (graph[i][j] == 1) {

                for (int r = 0; r < colors_num; r++) {
                    colors[r] = true;
                }

                for (int k = 0; k < graph.size(); k++) {
                    if (graph[i][k] > 1) {
                        colors[graph[i][k] - 2] = false;
                    }
                    if (graph[j][k] > 1) {
                        colors[graph[j][k] - 2] = false;
                    }
                    steps++;
                }

                int r;
                for (r = 0; r < colors_num; r++) {
                    if (colors[r] == true) {
                        graph[i][j] = r + 2;
                        graph[j][i] = r + 2;
                        break;
                    }
                }

                if (r == colors_num) {
                    graph.clear();
                    return graph; // возвращает пустой граф, если не может раскрасить
                }
            }
        }
    }

    return graph;
}
