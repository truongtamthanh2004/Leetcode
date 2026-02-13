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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode cur1 = l1, cur2 = l2;
        ListNode head = null;
        ListNode tail = null;
        int more = 0;

        while (cur1 != null && cur2 != null) {
            int sum = cur1.val + cur2.val + more;
            more = sum / 10;
            int val = sum % 10;
            
            if (head == null && tail == null) {
                head = tail = new ListNode(val);
            } else {
                ListNode newNode = new ListNode(val);
                tail.next = newNode;
                tail = newNode;
            }

            cur1 = cur1.next;
            cur2 = cur2.next;
        }

        while (cur1 != null) {
            int sum = cur1.val + more;
            more = sum / 10;
            int val = sum % 10;

            ListNode newNode = new ListNode(val);
            tail.next = newNode;
            tail = newNode;

            cur1 = cur1.next;
        }

        while (cur2 != null) {
            int sum = cur2.val + more;
            more = sum / 10;
            int val = sum % 10;

            ListNode newNode = new ListNode(val);
            tail.next = newNode;
            tail = newNode;

            cur2 = cur2.next;
        }

        if (more > 0) {
            ListNode newNode = new ListNode(more);
            tail.next = newNode;
            tail = newNode;
        }

        return head;
    }
}