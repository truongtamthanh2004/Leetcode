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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 1;
        int amount = 0;
        for (ListNode* p = head; p; p = p->next) amount++;
        
        ListNode* p = head;
        while (count <= amount - n)
        {
            p = p->next;
            count++;
        }
        if (p == head)
        {
            head = p->next;
            delete p;
            return head;
        }
        ListNode* t = head;
        while (t->next != p) t = t->next;
        t->next = p->next;
        p->next = nullptr;
        delete p;
        return head;
    }
};