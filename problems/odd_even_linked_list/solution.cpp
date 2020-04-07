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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next==NULL || head->next->next == NULL ) {
            return head;
        }
        ListNode* i = head;
        ListNode* tj = head->next;
        ListNode* j = head->next->next;
        
        while(j!= NULL) {
            tj->next = j->next;
            j->next = i->next;
            i->next = j;
            
            i=i->next;
            tj=tj->next;
            if(tj != NULL) {
                j=tj->next;
            } else {
                break;
            }
        }
        
        return head;
    }
};