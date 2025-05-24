class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == i && i < 10)
                return i;
            int sum = 0;
            while(nums[i]) {
                sum += nums[i]%10;
                nums[i] /= 10;
                if(sum > i)
                    break;
            }
            if(sum == i)
                return i;
        }
        return -1;
    }
};