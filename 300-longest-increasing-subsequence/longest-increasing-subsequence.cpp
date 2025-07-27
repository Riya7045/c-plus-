class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>piles;
        for (int x : nums) {
            auto it = lower_bound(piles.begin(), piles.end(), x);
            if (it == piles.end()) piles.push_back(x);
            else *it = x;
        }
        return piles.size();
    }
};