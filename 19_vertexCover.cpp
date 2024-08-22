// // WAP to implement vertex cover problem.
#include <iostream>
using namespace std;
const int MAX = 100;
void vertexCoverApprox(int adjMatrix[][MAX], int num);
int main()
{
    int num;
    cout << "Enter the number of vertices in the graph: ";
    cin >> num;
    int adjMatrix[MAX][MAX];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < num; ++i)
    {
        for (int j = 0; j < num; ++j)
        {
            cin >> adjMatrix[i][j];
        }
    }
    vertexCoverApprox(adjMatrix, num);
    return 0;
}

void vertexCoverApprox(int adjMatrix[MAX][MAX], int num)
{
    bool inVertexCover[MAX] = {false};
    for (int i = 0; i < num; ++i)
    {
        for (int j = i + 1; j < num; ++j)          // Ensure no double counting of edges
        {
            if (adjMatrix[i][j] == 1 && !inVertexCover[i] && !inVertexCover[j]) {
                inVertexCover[i] = true;             // If edge (i, j) exists and neither i nor j is in the cover
                inVertexCover[j] = true;
            }
        }
    }

    cout << "Approximate Vertex Cover: ";
    for (int i = 0; i < num; ++i)
    {
        if (inVertexCover[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
