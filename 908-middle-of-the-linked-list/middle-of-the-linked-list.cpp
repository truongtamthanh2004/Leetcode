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
    int countNode(ListNode* head)
    {
        int count = 0;
        for (ListNode* tmp = head; tmp; tmp = tmp->next) count++;
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int amount = countNode(head);
        int position = amount / 2 + 1;
        int count = 0;
        for (ListNode* tmp = head; tmp; tmp = tmp->next) 
        {
            count++;
            if (count == position) return tmp;
        }
        return head;
    }
};