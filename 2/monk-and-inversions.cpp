#include <bits/stdc++.h>
using namespace std;

int n;
void process(int *count, int **mat, int i, int j) {
    int val = mat[i][j];
    int row = i;
    int col = j;
    while(row >= 0) {
        while(col >= 0) {
            if (val < mat[row][col]) {
                count[(n*row)+col]++;
            }
            col--;
        }
        row--;
        col = j;
    }
}

int main() {
    int t;
    cin >> t;
    int **mat = new int*[50];
    for (int i=0; i<50; i++) {
        mat[i] = new int[50];
    }

    int *count = new int[3000];

    while(t--) {
        // Input
        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> mat[i][j];
                count[n*i + j] = 0;
            }
        }

        // Process
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                process(count, mat, i, j);
            }
        }

        // Result
        int sum = 0;
        for (int i=0; i<n*n; i++) {
            sum += count[i];
        }
        cout << sum << endl;
    }
}
