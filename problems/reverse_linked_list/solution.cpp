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
    ListNode* reverseList(ListNode* head) {
        if(head && head->next){
            ListNode* List = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return List;
        }
        return head;
    }
};