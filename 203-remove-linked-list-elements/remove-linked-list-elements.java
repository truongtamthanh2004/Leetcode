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
    public ListNode removeElements(ListNode head, int val) {
        ListNode i = new ListNode(0);
        i.next = head;
        ListNode j = i;
        while (j.next != null) {
            if (j.next.val == val) {
                j.next = j.next.next;
            } else {
                j = j.next;
            }
        }

        return i.next;
    }
}