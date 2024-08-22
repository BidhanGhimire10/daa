// Write a code to implement Dijkstra’s Algorithm.
#include <iostream>
using namespace std;
#define INF 9999
#define V 6

void dijkstra(int graph[V][V], int n, int start) {
    int distance[V], parent[V];
    bool visited[V];
    
    int i, count, u, v;

    for (i = 0; i < n; i++) {
        distance[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }
    distance[start] = 0; 

    for (count = 0; count < n - 1; count++) {
        u = -1;
        for (i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || distance[i] < distance[u])) {
                u = i;
            }
        }
        visited[u] = true;

        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i != start) {
            cout << "Distance from the source to " << i << ": " << distance[i] << endl;
        }
    }
}

int main() {
    int graph[V][V] = {
             {0,4,2,0,0,0},
             {4,0,1,5,0,0},
             {2,1,0,8,10,0},
             {0,5,8,0,2,6},
             {0,0,10,2,0,5},
             {0,0,0,6,5,0}
    };
    int start = 0;
    dijkstra(graph, V, start);
    return 0;
}

