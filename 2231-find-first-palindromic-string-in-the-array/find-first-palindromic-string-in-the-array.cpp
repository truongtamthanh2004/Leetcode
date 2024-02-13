class Solution {
public:
    bool isPalindromic(string s)
    {
        int i = 0;
        int j = (int)s.length() - 1;
        while (i <= j)
        {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string s = "";
        for (auto i : words)
        {
            if (isPalindromic(i))
            {
                s = i;
                return s;
            }
        }
        return s;
    }
};