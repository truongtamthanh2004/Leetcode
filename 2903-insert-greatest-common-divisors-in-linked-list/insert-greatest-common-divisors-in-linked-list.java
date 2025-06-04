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
    private int findGCD(int a, int b) {
        while (a != b) {
            if (a > b) a -= b;
            else if (b > a) b -= a;
        }

        return a;
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        for (ListNode cur = head; cur != null && cur.next != null; cur = cur.next.next) {
            int gcd = findGCD(cur.val, cur.next.val);
            ListNode newNode = new ListNode(gcd, cur.next);
            cur.next = newNode;
        }

        return head;
    }
}