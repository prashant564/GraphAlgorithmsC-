#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int findLCSLength(string str1, string str2, int len1, int len2) {
    // Base case: if either string is empty, the LCS is 0
    if (len1 == 0 || len2 == 0)
        return 0;

    // If the last characters of both strings match
    if (str1[len1 - 1] == str2[len2 - 1])
        return 1 + findLCSLength(str1, str2, len1 - 1, len2 - 1);
    else
        // If the last characters don't match, take the maximum LCS
        // by either excluding the last character from str1 or str2
        return max(findLCSLength(str1, str2, len1, len2 - 1),
                   findLCSLength(str1, str2, len1 - 1, len2));
}

int main() {
    string string1 = "AGGTAB";
    string string2 = "GXTXAYB";
    int length1 = string1.size();
    int length2 = string2.size;

    // Find and print the length of the LCS
    cout << "Length of Longest Common Subsequence is " << findLCSLength(string1, string2, length1, length2);

    return 0;
}
