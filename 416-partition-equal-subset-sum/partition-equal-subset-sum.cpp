class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));

        // Initialize the DP table
        for (int i = 0; i <= n; i++) {
            t[i][0] = true; // A sum of 0 can always be achieved by choosing no elements
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // If the sum is odd, it's not possible to partition the array
        if (sum % 2 != 0) {
            return false;
        }

        // Check if there's a subset with a sum equal to sum/2
        int target = sum / 2;
        return isSubsetSum(nums, target);
    }
};
