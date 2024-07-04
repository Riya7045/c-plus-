/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while (fast != NULL && fast->next != NULL){
            // Move slow one step.
            slow = slow->next; 
            // Move fast two steps.
            fast = fast->next->next;
            if (slow == fast) {
            return true;  // Loop detected
            }
        } 
        return false;  
    }
};