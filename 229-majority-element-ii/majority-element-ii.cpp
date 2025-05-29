class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        unordered_map<int, int> freq;

        // Count frequencies
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Check and collect majority elements (> n/3), avoiding duplicates
        for (int i = 0; i < n; i++) {
            if (freq[nums[i]] > n / 3) {
                bool alreadyAdded = false;
                for (int j = 0; j < ls.size(); j++) {
                    if (ls[j] == nums[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    ls.push_back(nums[i]);
                }
            }
        }

        return ls;
    }
};
