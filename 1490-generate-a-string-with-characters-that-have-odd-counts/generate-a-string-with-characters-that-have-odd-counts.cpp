class Solution {
public:
    string generateTheString(int n) {
        string s(n, ' ');
        if (n % 2 == 0)
        {
            char start = 'a';
            s[0] = start;
            for (int i = 1; i < n; i++)
            {
                s[i] = start + 1;
            }
        }
        else {
            char start = 'a';
            s[0] = start;
            s[1] = start + 1;
            for (int i = 2; i < n; i++)
            {
                s[i] = start + 2;
            }
        }
        return s;
    }
};