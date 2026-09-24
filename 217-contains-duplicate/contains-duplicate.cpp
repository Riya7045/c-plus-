class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>numset;
        for(int num: nums){
            if(numset.find(num)!=numset.end()){
                return true;
            }
            numset.insert(num);
        }
        return false;
    }
};