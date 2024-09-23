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
public:
    int length(ListNode* head){
        int cnt = 0 ;
        while(head!=NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        // kth node from start = n - k + 1  th node from end
        int n = length(head);

        int end = n-k+1, i = 1;
        ListNode* t1 = head, *t2 = head;

        while(i < k){
            t1 = t1->next;
            i++;
        }

        i = 1;

        while(i<end){
            t2 = t2->next;
            i++;
        }

        swap(t1->val,t2->val);

        return head;
    }
};