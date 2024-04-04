class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int countOpenParen = 0;

        for (auto c : s)
        {
            if (c == '(')
                res = max(res, ++countOpenParen);
            else if (c == ')')
                countOpenParen--;
        }

        return res;
    }
};