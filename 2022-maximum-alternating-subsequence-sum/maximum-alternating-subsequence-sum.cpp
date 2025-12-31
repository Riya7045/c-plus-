class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<long>> t(n, vector<long>(2, 0));

        t[0][0] = max(-nums[0], 0);
        t[0][1] = max(nums[0], 0);
            
        for(int i = 1; i < n; i++) {
            
            t[i][0] = max(t[i-1][1] - nums[i], t[i-1][0]);
            
            t[i][1] = max(t[i-1][0] + nums[i], t[i-1][1]);
            
            
        }
        
        return max(t[n-1][0], t[n-1][1]);
    }
};