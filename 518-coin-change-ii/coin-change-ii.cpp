class Solution {
public:
    /**
     * Helper function to find the *number of ways* to make 'amount'
     * using coins from index 0 up to 'n'.
     *
     * 'h' is the memoization table (dp table).
     * h[n][amount] will store the number of ways to make 'amount'
     * using coins up to index 'n'.
     */
    int help(vector<int>& coins, int amount, int n, vector<vector<int>>& h)
    {
        // --- BASE CASE 1 (Success) ---
        // If amount is 0, we found exactly one valid combination.
        // We return 1 (to add to the total count).
        if (amount == 0) {
            return 1;
        }

        // --- BASE CASE 2 (Failure) ---
        // If we run out of coins (n < 0) or the amount is negative,
        // this path is invalid. It contributes 0 ways.
        if (n < 0 || amount < 0) {
            return 0;
        }

        // --- MEMOIZATION CHECK ---
        // If we've already computed this state, return the stored result.
        if (h[n][amount] != -1) {
            return h[n][amount];
        }

        // --- RECURSIVE STEP (Choices) ---

        // Choice 1: "Don't use coin 'n'".
        // Find all combinations for the *same amount* using the rest of the coins (n-1).
        int one = help(coins, amount, n - 1, h);

        // Choice 2: "Use coin 'n'".
        // Find all combinations for the *remaining amount* (amount - coins[n]).
        // We stay at index 'n' because we can use this coin multiple times.
        // (Note: We do NOT add 1 here, we just want the count).
        int two = help(coins, amount - coins[n], n, h);

        // --- STORE & RETURN ---
        // The total ways is the sum of both choices.
        // We store this result in our memoization table.
        h[n][amount] = one + two;
        return h[n][amount];
    }

    /**
     * Main function for Coin Change 2.
     * Note the name and parameters are changed to match the problem's definition.
     */
    int change(int amount, vector<int>& coins) {
        // Create the memoization table.
        // Size: coins.size() rows (for indices 0 to n-1)
        //       amount + 1 cols (for amounts 0 to amount)
        // Initialize with -1 (meaning "not computed").
        vector<vector<int>> h(coins.size(), vector<int>(amount + 1, -1));

        // Start the recursion with the full amount and the last coin index.
        int ans = help(coins, amount, coins.size() - 1, h);
        
        // No check is needed. If no ways are found, 'ans' will be 0.
        return ans;
    }
};