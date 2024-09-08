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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        for (ListNode* start = head; start; start = start->next) {
            cnt++;
        }

        int minSize = cnt / k;
        int extra = cnt % k;

        ListNode* start = head;
        vector<ListNode*> res;
        while (start) {
            ListNode*tmp = nullptr;
            ListNode* tail = nullptr;
            if (extra-- > 0) {
                for (int i = 0; i < minSize + 1; i++) {
                    if (!tmp) {
                        tmp = new ListNode{start->val, nullptr};
                        tail = tmp;
                    }
                    else {
                        tail->next = new ListNode{start->val, nullptr};
                        tail = tail->next;
                    }
                    start = start->next;
                }
                
            }
            else {
                for (int i = 0; i < minSize; i++) {
                    if (!tmp) {
                        tmp = new ListNode{start->val, nullptr};
                        tail = tmp;
                    }
                    else {
                        tail->next = new ListNode{start->val, nullptr};
                        tail = tail->next;
                    }
                    start = start->next;
                }

            }
            k--;
            res.push_back(tmp);
        }

        while (k-- > 0) res.push_back({});

        return res;
    }
};