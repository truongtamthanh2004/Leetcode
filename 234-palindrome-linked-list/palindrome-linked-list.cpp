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
private:
    int calcAmount(ListNode* head)
    {
        int count = 0;
        for (ListNode* tmp = head; tmp; tmp = tmp->next) count++;
        return count;
    }
public:
    bool isPalindrome(ListNode* head) {
        stack<int> t;
        int amount = calcAmount(head);
        int count = 0;
        for (ListNode* p = head; p; p = p->next)
        {
            count++;
            if (amount % 2 == 0)
            {
                if (count <= amount / 2)
                {
                    t.push(p->val);
                }
                else 
                {
                    if (p->val != t.top()) return false;
                    else t.pop();
                }
            }
            else
            {
                if (count <= amount / 2)
                {
                    t.push(p->val);
                }
                else if (count > amount / 2 + 1)
                {
                    if (p->val != t.top()) return false;
                    else t.pop();
                }
            }
        }
        return true;
    }
};