class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int prevprev = 0;
        int n=nums.size();
        if(n==1)return nums[0];
        for(int i =1; i<=n; i++){
            int skip = prev;
            int steal = nums[i-1]+prevprev;
            int temp = max(skip,steal);
            prevprev = prev;
            prev = temp;
        }
        return prev;
    }
};