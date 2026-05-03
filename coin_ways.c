#include <stdio.h>

int count_ways(int *coins, int n, int amount) {

    int dp[amount+1];

    for(int i = 0; i <= amount; i++)
        dp[i] = 0;

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}
