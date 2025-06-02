class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());

    int maxLen = 1, currentLen = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) continue; // Skip duplicates

        if (nums[i] == nums[i-1] + 1) {
            currentLen++;
        } else {
            maxLen = max(maxLen, currentLen);
            currentLen = 1;
        }
    }

    return max(maxLen, currentLen);
    }
};