#include <iostream>
using namespace std;

int i, j, a, b, u, v, n, ne = 1;
int mincost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);

int main() {
    cout << "Enter the no. of vertices: ";
    cin >> n;
    cout << "Enter the cost adjacency matrix:\n";
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cin >> cost[i][j];
            if(cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }

    cout << "\nThe edges of Minimum cost spanning tree are:\n";
    while(ne < n) {
        int min = 999;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);
        if(uni(u, v)) {
            cout << ne++ << " edge (" << a << ", " << b << ") = " << min << endl;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    cout << "\nMinimum cost = " << mincost;
    return 0;
}

int find(int i) {
    while(parent[i]) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
