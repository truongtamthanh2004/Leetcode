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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a1, a2;
        for (ListNode* i = l1; i; i = i->next) a1.push_back(i->val);
        for (ListNode* i = l2; i; i = i->next) a2.push_back(i->val);

        int i = 0;
        int j = 0;

        int res = 0, remain = 0;
        vector<int> ans;

        while (i < a1.size() && j < a2.size()) {
            int tmp = a1[i++] + a2[j++] + remain;
            res = tmp % 10;
            remain = tmp / 10;
            ans.push_back(res);
        }

        while (i < a1.size()) {
            int tmp = a1[i++] + remain;
            res = tmp % 10;
            remain = tmp / 10;
            ans.push_back(res);
        }
        while (j < a2.size()) {
            int tmp = a2[j++] + remain;
            res = tmp % 10;
            remain = tmp / 10;
            ans.push_back(res);
        }
        if (remain) ans.push_back(1);

        ListNode* head = nullptr;
        for (int i = ans.size() - 1; i >= 0; i--) {
            ListNode* tmp = new ListNode{ans[i], nullptr};
            if (!head) head = tmp;
            else {
                tmp->next = head;
                head = tmp;
            }
        }

        return head;
    }
};