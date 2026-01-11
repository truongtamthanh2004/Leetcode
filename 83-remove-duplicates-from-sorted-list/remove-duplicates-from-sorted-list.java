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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode i = head;
        while (i != null) {
            ListNode j = i;
            while (j.next != null && j.next.val == i.val) {
                j = j.next;
            }

            if (i != j) {
                i.next = j.next;
                i = j.next;
                j.next = null;
            } else {
                i = j.next;
            }
        }

        return head;
    }
}