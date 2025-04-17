#include <stdio.h>
#include <string.h>

#define MAX 100

/*
Sample Input:
Enter first string: ABCDGH
Enter second string: AEDFHR

Output:
Length of Longest Common Subsequence: 3
*/

// Function to find the length of the longest common subsequence
int lcsLength(char str1[], char str2[], int m, int n) {
    int dp[m+1][n+1];

    // Build the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;  // Characters match
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];  // Take the maximum
            }
        }
    }
    return dp[m][n];  // The length of the LCS is in the bottom-right cell
}

int main() {
    char str1[MAX], str2[MAX];

    // Input two strings
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    // Find the length of LCS
    int result = lcsLength(str1, str2, m, n);

    // Output the result
    printf("Length of Longest Common Subsequence: %d\n", result);

    return 0;
}
