#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to add an edge to the graph
void add_edge(vector<pair<int, int> >& edges, int u, int v) {
    edges.push_back(make_pair(u, v));
}

// Function to find the vertex cover using a greedy algorithm
unordered_set<int> vertex_cover(const vector<pair<int, int> >& edges, int num_vertices) {
    // To keep track of the covered vertices
    unordered_set<int> covered_vertices;
    // To keep track of the edges that are still uncovered
    vector<bool> edge_covered(edges.size(), false);
    int covered_edges = 0;

    while (covered_edges < edges.size()) {
        for (int i = 0; i < edges.size(); ++i) {
            if (!edge_covered[i]) {
                // Select the edge
                int u = edges[i].first;
                int v = edges[i].second;

                // Add both endpoints to the vertex cover
                covered_vertices.insert(u);
                covered_vertices.insert(v);

                // Debug prints
                cout << "Selected edge: (" << u << ", " << v << ")\n";
                cout << "Adding vertices: " << u << " and " << v << " to the vertex cover\n";

                // Mark all edges incident to u and v as covered
                for (int j = 0; j < edges.size(); ++j) {
                    if (!edge_covered[j]) {
                        if (edges[j].first == u || edges[j].second == u || edges[j].first == v || edges[j].second == v) {
                            edge_covered[j] = true;
                            covered_edges++;
                        }
                    }
                }
            }
        }
    }

    return covered_vertices;
}

int main() {
    int num_vertices, num_edges;
    cout << "Enter the number of vertices: ";
    cin >> num_vertices;
    cout << "Enter the number of edges: ";
    cin >> num_edges;

    vector<pair<int, int> > edges;
    cout << "Enter the edges (u v) for each edge:\n";
    for (int i = 0; i < num_edges; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(edges, u, v);
    }

    unordered_set<int> cover = vertex_cover(edges, num_vertices);

    cout << "The vertices in the vertex cover are: ";
    for (unordered_set<int>::iterator it = cover.begin(); it != cover.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
