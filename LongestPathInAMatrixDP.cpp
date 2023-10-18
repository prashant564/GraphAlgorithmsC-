#include <bits/stdc++.h>
#define N 3
using namespace std;

// Function to find the length of the longest path in the matrix
int findLongestPathFromCell(int row, int col, int matrix[N][N], int dp[N][N]) {
    // Check if the cell is out of bounds
    if (row < 0 || row >= N || col < 0 || col >= N)
        return 0;

    // If this subproblem is already solved, return its result
    if (dp[row][col] != -1)
        return dp[row][col];

    // Initialize variables to store path lengths in all four directions
    int right = INT_MIN, left = INT_MIN, up = INT_MIN, down = INT_MIN;

    // Check if the cell to the right has a value one greater
    if (col < N - 1 && matrix[row][col] + 1 == matrix[row][col + 1])
        right = 1 + findLongestPathFromCell(row, col + 1, matrix, dp);

    // Check if the cell to the left has a value one greater
    if (col > 0 && matrix[row][col] + 1 == matrix[row][col - 1])
        left = 1 + findLongestPathFromCell(row, col - 1, matrix, dp);

    // Check if the cell above has a value one greater
    if (row > 0 && matrix[row][col] + 1 == matrix[row - 1][col])
        up = 1 + findLongestPathFromCell(row - 1, col, matrix, dp);

    // Check if the cell below has a value one greater
    if (row < N - 1 && matrix[row][col] + 1 == matrix[row + 1][col])
        down = 1 + findLongestPathFromCell(row + 1, col, matrix, dp);

    // If none of the adjacent cells has a value one greater, set the path length to 1
    return dp[row][col] = max({right, left, up, down, 1});
}

// Function to find the length of the longest path beginning from any cell
int findLongestPathInMatrix(int matrix[N][N]) {
    int longestPathLength = 1; // Initialize the result

    // Create a lookup table and fill all entries as -1
    int dp[N][N];
    memset(dp, -1, sizeof dp);

    // Compute the longest path beginning from all cells
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == -1)
                findLongestPathFromCell(i, j, matrix, dp);

            // Update the result if needed
            longestPathLength = max(longestPathLength, dp[i][j]);
        }
    }

    return longestPathLength;
}

int main() {
    int matrix[N][N] = { { 1, 2, 9 }, { 5, 3, 8 }, { 4, 6, 7 } };

    // Find and print the length of the longest path in the matrix
    cout << "Length of the longest path is " << findLongestPathInMatrix(matrix);

    return 0;
}
