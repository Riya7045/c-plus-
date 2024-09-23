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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *rabbit=head;
        ListNode *kachua=head;
        int cnt=0;
        for(int i=0;i<n;i++){
            rabbit=rabbit->next;
        }
        if(rabbit==NULL){
            return head->next;
        }
        while (rabbit->next!=NULL){
            rabbit=rabbit->next;
            kachua=kachua->next;
        }
        ListNode *delNode=kachua->next;
        kachua->next=kachua->next->next;
        delete delNode;
        return head;
    }
};