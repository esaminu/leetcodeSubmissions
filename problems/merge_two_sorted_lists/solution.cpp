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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* S = new ListNode();
        ListNode* nHead = S;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                S->next = l1;
                l1 = l1->next;
                S = S->next;
            } else {
                S->next = l2;
                l2=l2->next;
                S=S->next;
            }
        }
        while(l1) {
            S->next = l1;
            l1 = l1->next;
            S = S->next;
        }
        while(l2) {
           S->next = l2;
            l2=l2->next;
            S=S->next;
        }
        return nHead->next;
    } 
};