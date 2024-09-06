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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int maxNum = 0;
        for (auto i : nums) maxNum = max(i, maxNum);

        vector<bool> isExisting(maxNum + 1, false);
        for (auto i : nums) isExisting[i] = true;

        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (head) {
            if (head->val >= maxNum + 1 || !isExisting[head->val]) {
                
                cur->next = head;
                cur = cur->next;
            }
            head = head->next;
        } 

        cur->next = nullptr;

        return dummy->next;
    }
};