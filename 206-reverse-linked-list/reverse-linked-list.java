/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) return head;

        ListNode newHead = null;
        ListNode next = head.next;

        while (head != null) {
            head.next = newHead;
            newHead = head;
            head = next;

            if (head != null) next = head.next;
        }

        return newHead;
    }
}