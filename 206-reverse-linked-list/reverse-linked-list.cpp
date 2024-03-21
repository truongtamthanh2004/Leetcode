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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        // ListNode* p = reverseList(head->next);
        
        
        // head->next->next = head;
        // head->next = nullptr;
        // return p;
        ListNode* a = nullptr;
        ListNode* b = head;
        ListNode* c = head->next;
        while (b)
        {
            b->next = a;
            a = b;
            b = c;
            if (c)
                c = c->next;
        }
        return a;
    }
};