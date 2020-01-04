/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        if(head.next.next == null) {
            ListNode node = new ListNode(head.next.val);
            head.next = null;
            node.next = head;
            return node;
        }
       
        ListNode reversed = reverseList(head.next);
        ListNode current = reversed;
        while(current.next != null) {
            current = current.next;
        }
        current.next = new ListNode(head.val);
        return reversed;
    }
}