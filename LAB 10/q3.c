#include <stdio.h>
#include <stdlib.h>

#define N 5  // Number of items
#define W 10  // Knapsack capacity

int knapsack(int values[N], int weights[N]) {
    int dp[N+1][W+1], i, j;
    
    // Initialize DP table with base cases
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = -1;
            }
        }
    }
    
    // Fill in DP table using bottom-up approach
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= W; j++) {
            if (weights[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = (values[i-1] + dp[i-1][j-weights[i-1]] > dp[i-1][j]) ? 
                            values[i-1] + dp[i-1][j-weights[i-1]] : dp[i-1][j];
            }
        }
    }
    
    // Return optimal knapsack value
    return dp[N][W];
}

int main() {
    int values[N] = {6, 10, 12, 8, 9};
    int weights[N] = {2, 4, 6, 3, 5};
    
    // Compute optimal knapsack value using bottom-up DP
    int result = knapsack(values, weights);
    
    // Print result
    printf("Optimal knapsack value: %d\n", result);
    
    return 0;
}