/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();

            // 1. Connection Logic (SAME as before)
            // Connect to the next node in the queue, or set to nullptr if it's the last node.
            if (i < levelSize - 1) {
                node->next = q.front();
            } else {
                node->next = nullptr; 
            }

            // 2. Child Enqueue Logic (THE ONLY DIFFERENCE)
            // We MUST check both left and right pointers individually 
            // because one might be missing (e.g., node 6 in the example).
            
            // Instead of checking 'if (node->left)' once, we check both:
            if (node->left) { // Check for the left child
                q.push(node->left);
            }
            if (node->right) { // Check for the right child
                q.push(node->right);
            }
        }}
        return root;
    }
    

    
};