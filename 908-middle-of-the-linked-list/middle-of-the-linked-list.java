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
    public ListNode middleNode(ListNode head) {
        if (head == null) return head; // not neccessary because the minimum length of linked list is 1

        ListNode i = head, j = head;
        while (j != null && j.next != null) {
            i = i.next;
            j = j.next.next;
        }

        return i;
    }
}