/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    void reverse(ListNode* &head, ListNode* &prev, ListNode* &curr){
        if(curr==NULL){
            head = prev;
            return;
        }
        ListNode* forward = curr->next;
        reverse(head,curr,forward);
        curr->next = prev;
    }
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head,prev,curr);
        return head;
    }
};