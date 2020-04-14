#include "solver.h"

vector<vector<int>> Solver::solve() {
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
