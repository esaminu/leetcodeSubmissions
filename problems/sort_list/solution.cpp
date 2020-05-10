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
    ListNode* sortList(ListNode* head) {
        return quickSort(head, NULL);
    }
    ListNode* quickSort(ListNode* start, ListNode* end) {
        if(!start || !start->next || start == end || start->next == end) return start;
        ListNode* newHead = partitionAroundPivot(start, end);
        start->next = quickSort(start->next, end);
        return quickSort(newHead, start);
    }
    ListNode* partitionAroundPivot(ListNode* start, ListNode* end) {
        ListNode* currHead = start, *ptr = start;
        
        while(ptr->next != end) {
            if(ptr->next->val < start->val) {
                ListNode* temp = ptr->next;
                ptr->next = temp->next;
                temp->next = currHead;
                currHead = temp;
            } else {
                ptr = ptr->next;
            }
        }
        return currHead;
    }
};