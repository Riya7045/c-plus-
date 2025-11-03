class Solution {
private:
    /**
     * @brief Recursive helper function to count the number of subsets that sum to 'target'.
     * This is the exact logic from your 'countPartitionsUtil'.
     *
     * @param ind The current index we are considering (from 0 to ind).
     * @param target The remaining target sum we need to achieve.
     * @param arr The array of numbers.
     * @param dp The memoization table.
     * @return The number of ways to form the 'target' sum.
     */
    int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // --- Base Cases ---
        if (ind == 0) {
            // We are at the first element (arr[0])
            
            // If target is 0 AND the number is 0, we have 2 ways:
            // 1. Pick the 0
            // 2. Don't pick the 0
            if (target == 0 && arr[0] == 0)
                return 2; 
            
            // If target is 0 (and arr[0] is not 0), 1 way (don't pick)
            // OR If target is equal to arr[0], 1 way (pick)
            if (target == 0 || target == arr[0])
                return 1; 
                
            return 0; // Otherwise, no way to partition
        }
        
        // --- Memoization Check ---
        // If the result for this state is already calculated, return it
        if (dp[ind][target] != -1)
            return dp[ind][target];
            
        // --- Recursive Steps ---
        
        // Calculate the number of ways without taking the current element
        int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
        
        // Calculate the number of ways by taking the current element
        int taken = 0;
        if (arr[ind] <= target)
            taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);
            
        // Store the sum of ways in the DP array and return it
        return dp[ind][target] = (notTaken + taken);
    }

public:
    /**
     * @brief Finds the number of ways to assign '+' or '-' to each number
     * in 'nums' such that the resulting sum equals 'target'.
     *
     * @param nums The input array of integers.
     * @param target The target sum.
     * @return The number of different expressions that evaluate to 'target'.
     */
    int findTargetSumWays(vector<int>& nums, int target) {
        // This is the logic from your 'targetSum' function
        int n = nums.size();
        
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }
        
        // --- Edge Case Checks ---
        // This logic finds the target for the "negative" subset, s2.
        // s2 = (totSum - target) / 2
        // s2 cannot be negative and must be an integer.
        
        // 1. If (totSum - target) is negative, s2 would be negative. Impossible.
        if (totSum - target < 0)
            return 0; 
            
        // 2. If (totSum - target) is odd, s2 would be a fraction. Impossible.
        if ((totSum - target) % 2 == 1)
            return 0;
        
        // Calculate the required sum for the "negative" subset (s2)
        int s2 = (totSum - target) / 2; 
        
        // Initialize DP table
        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1)); 
        
        // Call the helper function to find the number of ways
        // to make the subset sum 's2'.
        return countPartitionsUtil(n - 1, s2, nums, dp);
    }
};