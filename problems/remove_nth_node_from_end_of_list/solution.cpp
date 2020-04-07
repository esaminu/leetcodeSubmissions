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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL ) {
            return NULL;
        }
        int c = n;
        ListNode* i = head;
        ListNode* j = head;
        while(c) {
            j = j->next;
            c--;
        }
        
        while(j != NULL && j->next != NULL) {
            j=j->next;
            i = i->next;
        }
        
        if(j==NULL) {
            return head->next;
        }
        ListNode* q = i->next;
        i->next = q->next;
        return head;
    }
};