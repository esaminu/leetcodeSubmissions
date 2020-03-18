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
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* newList = new ListNode(INT_MIN);
        ListNode* ptr=newList;
        
        while(p && q) {
            if(p->val < q->val){
                ptr->next = new ListNode(p->val);
                p=p->next;
            } else {
                ptr->next = new ListNode(q->val); 
                q=q->next;
            }
            ptr=ptr->next;
        }
        
        ptr->next=p ? p : q;
        
        return newList->next;
        
    }
};