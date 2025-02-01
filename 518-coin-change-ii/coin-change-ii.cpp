class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);  // Use ULL to prevent overflow
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];  // Prevent overflow with ULL
            }
        }

        return dp[amount];  // Convert back to int if required
    }
};

    