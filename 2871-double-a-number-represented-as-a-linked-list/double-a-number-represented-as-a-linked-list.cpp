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
    string doubleNumber(string& s)
    {
        string res = "";
        int carry = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            int digit = s[i] - '0';
            int doubleDigit = digit * 2 + carry;
            res += to_string(doubleDigit % 10);
            carry = doubleDigit / 10;
        }

        if (carry) res += "1";

        reverse(res.begin(), res.end());

        return res;
    }
    ListNode* doubleIt(ListNode* head) {
        string s = "";
        for (ListNode* tmp = head; tmp; tmp = tmp->next)
        {
            s += to_string(tmp->val);
        }

        s = doubleNumber(s);

        ListNode* curr = nullptr;
        ListNode* pHead = nullptr;

        for(auto i : s)
        {
            ListNode* tmp = new ListNode {i - '0', nullptr};
            if (!pHead)
            {
                pHead = tmp;
                curr = tmp;
            }
            else
            {
                curr->next = tmp;
                curr = tmp;
            }
        }

        return pHead;
    }
};