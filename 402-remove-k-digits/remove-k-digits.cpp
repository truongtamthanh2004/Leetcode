class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) return "0";

        string res;
        stack <char> s;
        for (int i = 0; i < num.length(); i++)
        {
            while (k > 0 && !s.empty() && s.top() > num[i])
            {
                s.pop();
                --k;
            }
            s.push(num[i]);
        }
        cout << s.top();
        while (k > 0) 
        {
            s.pop();
            k--;
        }

        while (!s.empty())
        {
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.length(); i++)
        {
            if (res[i] != '0') break;
            else
            {
                res.erase(i, 1);
                i--;
            }
        }

        return res.empty() ? "0" : res;
    }
};