class Solution {
public:
    int startposition(vector<int>&nums,int target){
        int ans= nums.size();
        int s= 0;
        int e= nums.size()-1;
    
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    int endposition(vector<int>&nums,int target){
        int ans = nums.size();
        int s= 0;
        int e= nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = startposition(nums,target);
        if(start == nums.size()||nums[start]!=target)return {-1 ,-1};
        int end = endposition(nums,target);
        return{start,end};
    }
};