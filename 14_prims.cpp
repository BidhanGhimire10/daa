// //  Write a code to implement Prim’s Algorithm.
#include <iostream>
using namespace std;
int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0};
int mincost = 0;
int cost[10][10];

int main()
{
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the cost of adjacency matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    visited[1] = 1;
    cout << endl;
    cout << "The edges of Minimum Cost Spanning Tree are:\n";
    while (ne < n) {
        int min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        
        if (visited[u] == 0 || visited[v] == 0)
        {
            cout << "Edge " << ne << ": (" << a << ", " << b << ") cost: " << min;
            ne++;
            mincost += min;
            visited[b] = 1;
            cout << endl;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << endl;
    cout << "Minimum cost = " << mincost << endl;
    return 0;
}