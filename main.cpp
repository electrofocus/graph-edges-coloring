#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;


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

    int max = 0;

    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (gr[i][j] != 0) {
                k++;
            }
        }
        if (k > max) {
            max = k;
        }
    }

    max++;

    set<int> colors;
    for (int i = 2; i < max + 2; i++) {
        colors.insert(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            set<int> clrs = colors;
            if (gr[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    clrs.erase(gr[i][k]);
                    clrs.erase(gr[j][k]);
                }
                gr[i][j] = *clrs.begin();
                gr[j][i] = *clrs.begin();
            }
        }
    }

    cout << "Max: " << max << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << gr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}