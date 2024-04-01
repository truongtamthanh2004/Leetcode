class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ') count++;
            else if (s[i]== ' ' && s[i + 1] != ' ' && i + 1 < s.size()) return count;
        }
        return count;
    }
};