#include <bits/stdc++.h>
#define ROWS 3
#define COLS 3
using namespace std;

// Recursive function to count paths with a sum of 'targetSum' from
// (0, 0) to (row, col)
int countPathsRecursively(int matrix[][COLS], int row, int col, int targetSum) {
	// Base cases
	if (row < 0 || col < 0 || targetSum < 0)
		return 0;
	if (row == 0 && col == 0)
		return (targetSum == matrix[row][col]);

	// (row, col) can be reached either from (row - 1, col) or
	// from (row, col - 1)
	return countPathsRecursively(matrix, row - 1, col, targetSum - matrix[row][col]) +
		countPathsRecursively(matrix, row, col - 1, targetSum - matrix[row][col]);
}

// A wrapper function over countPathsRecursively()
int countPathsWithSum(int matrix[][COLS], int targetSum) {
	return countPathsRecursively(matrix, ROWS - 1, COLS - 1, targetSum);
}

// Driver program
int main() {
	int targetSum = 12;
	int matrix[ROWS][COLS] = {
		{1, 2, 3},
		{4, 6, 5},
		{3, 2, 1}
	};

	// Find and print the number of paths with the given sum
	cout << "Number of paths with sum " << targetSum << ": " << countPathsWithSum(matrix, targetSum);

	return 0;
}
