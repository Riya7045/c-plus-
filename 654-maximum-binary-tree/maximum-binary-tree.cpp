/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* ans(vector<int>&nums,int start,int end){
        if(start>end)
        return NULL;
        int p = start;
        for(int i =p+1;i<=end;i++){
            if(nums[i]>nums[p]){
                p =i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[p]);
        root->left = ans(nums,start,p-1);
        root->right = ans(nums,p+1,end);
        return root;
    
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return ans(nums,0,nums.size()-1);
    }
};