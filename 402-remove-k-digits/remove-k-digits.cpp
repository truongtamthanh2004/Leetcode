class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <int> s;
        for (char c : num)
        {
            int value = c - '0';
            while (!s.empty() && s.top() > value && k > 0)
            {
                s.pop();
                k--;
            }

            s.push(value);
        }

        while (k-- > 0)
        {
            s.pop();
        }

        string ans = "";
        while (!s.empty())
        {
            ans += s.top() + '0';
            s.pop();
        }

        while (ans.size() > 0 && ans.back() == '0') ans.pop_back();

        reverse(ans.begin(), ans.end());

        return ans.size() > 0 ? ans : "0";
    }
};