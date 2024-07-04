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
    ListNode* mergeNodes(ListNode* head) {
        while (head->val == 0)
        {
            head = head->next;
        }
        ListNode* cur = head;
        while (cur)
        {
            if (cur->next)
            {
                if (cur->next->val != 0)
                {
                    cur->val += cur->next->val;
                    cur->next = cur->next->next;
                    continue;
                }
                else cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};