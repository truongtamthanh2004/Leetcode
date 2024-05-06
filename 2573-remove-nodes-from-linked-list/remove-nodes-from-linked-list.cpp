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
    ListNode* removeNodes(ListNode* head) {
        deque<ListNode*> dq;

        for (ListNode* tmp = head; tmp; tmp = tmp->next)
        {
            while (!dq.empty() && dq.back()->val < tmp->val) dq.pop_back();

            dq.push_back(tmp);
        }

        head = nullptr;
        ListNode* tmp = nullptr;

        while (!dq.empty())
        {
            if (!head)
            {
                head = dq.front();
                tmp = head;
            }
            else 
            {
                tmp->next = dq.front();
                tmp = tmp->next;
            }

            dq.pop_front();
        }

        return head;
    }
};