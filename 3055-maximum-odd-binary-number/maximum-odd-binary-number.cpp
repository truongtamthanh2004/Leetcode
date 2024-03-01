class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<int> count(2, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) count[s[i] - '0']++;
        s[n - 1] = '1';
        count[1]--;
        for (int i = 0; i < n - 1; i++)
        {
            s[i] = '0';
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (count[1] == 0) return s;
            s[i] = '1';
            count[1]--;
        }
        return s;
    }
};