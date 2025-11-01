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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Start with the root node.
        TreeNode* current = root;

        // Loop as long as we haven't fallen off the tree (current is not null)
        // and we haven't found the value yet.
        // We can simplify the condition to just (current != nullptr)
        // and handle the found case inside the loop.
        
        while (current != nullptr) {
            // Case 1: Found the value. Return the node.
            if (val == current->val) {
                return current;
            }
            
            // Case 2: The value we're looking for is smaller.
            // It must be in the left subtree.
            if (val < current->val) {
                current = current->left;
            } 
            // Case 3: The value we're looking for is larger.
            // It must be in the right subtree.
            else {
                current = current->right;
            }
        }

        // If the loop finishes, 'current' became nullptr,
        // which means the value was not found in the tree.
        return nullptr;
    }
};