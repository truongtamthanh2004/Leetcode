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
    ListNode* remove(ListNode* list1, int a, int b)
    {
        int n = b - a + 1;
        ListNode* tmp = list1;
        int t = a;

        while (t - 1 > 0) 
        {
            tmp = tmp->next;
            t--;
        }

        while (n > 0)
        {
            tmp->next = tmp->next->next;
            n -= 1;
        }
        return tmp;
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tmp = remove(list1, a, b);
        ListNode* head2 = list2;
        ListNode* tail2 = list2;
        while (tail2->next) tail2 = tail2->next;
        tail2->next = tmp->next;
        tmp->next = head2;
        return list1;
    }
};