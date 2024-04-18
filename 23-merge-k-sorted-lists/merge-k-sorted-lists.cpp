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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            ListNode* cur = lists[i];
            while (cur)
            {
                res.push_back(cur->val);
                cur = cur->next;
            }
        }

        if (res.empty()) return nullptr;

        sort(res.begin(), res.end());

        ListNode* ans = new ListNode{res[0], nullptr};
        ListNode* cur = ans;
        for (int i = 1; i < res.size(); i++)
        {
            ListNode* tmp = new ListNode{res[i], nullptr};
            cur->next = tmp;
            cur = cur->next;
        }

        return ans;
    }
};