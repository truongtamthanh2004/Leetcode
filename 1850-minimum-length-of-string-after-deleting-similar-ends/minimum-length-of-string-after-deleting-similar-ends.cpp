class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                while (i < n - 1 && s[i] == s[i + 1]) i++;
                while (j >= 1 && s[j] == s[j - 1]) j--;
            }
            else break;
            i++;
            j--;
        }
        if (i > j) return 0;
        return j - i + 1;
    }
};