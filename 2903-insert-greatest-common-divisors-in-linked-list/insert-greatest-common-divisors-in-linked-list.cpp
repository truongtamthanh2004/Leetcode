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
    int greatestCommonDivisor(int a, int b) {
        while (a != b) {
            if (a > b) a -= b;
            else b -= a;
        }

        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next) {
            int a = cur->val;
            int b = cur->next->val;

            int gcd = greatestCommonDivisor(a, b);

            ListNode* tmp = new ListNode{gcd, nullptr};
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }

        return head;
    }
};