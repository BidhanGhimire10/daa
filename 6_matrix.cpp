//Write a suitable code to implement Strassen’s Matrix Multiplication.
#include <iostream>
#include <climits>
using namespace std;
#define MAX 100
void printOptimalParenthesis(int i, int j, int n, int s[MAX][MAX], char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printOptimalParenthesis(i, s[i][j], n, s, name);
    printOptimalParenthesis(s[i][j] + 1, j, n, s, name);
    cout << ")";
}

void matrixChain(int p[], int n) {
    int m[MAX][MAX];                                  // Table to store minimum number of multiplications
    int s[MAX][MAX];                                  // Table to store the split points
    for (int i = 1; i < n; i++) {                       // Initialize the table with zero for diagonal elements
        m[i][i] = 0;
    }

    for (int cl = 2; cl < n; cl++) {                                // l is chain length.
        for (int i = 1; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];           // q is the cost of multiplying A[i]...A[k] and A[k+1]...A[j]
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;                        // Store the split point
                }
            }
        }
    }
    cout << "\nMinimum number of multiplications is: " << m[1][n - 1] << endl;           // Output the result
    char name = 'A';
    cout << "Optimal multiplication order: ";
    printOptimalParenthesis(1, n - 1, n, s, name);
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int p[MAX];
    cout << "Enter the dimensions (p0, p1, ..., pn):" << endl;
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    matrixChain(p, n + 1);
    return 0;
}
