class Solution {
public:
    map<char, int> countCharacter(string s, int start, int end)
    {
        map<char, int> mp;
        for (int i = start; i <= end; i++) mp[s[i]]++;
        return mp;
    }
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        map<char, int> mp1 = countCharacter(s1, 0, s1.length() - 1);

        int start = 0;
        int end = len - 1;

        while (end < s2.length()) 
        {
            map<char, int> mp2 = countCharacter(s2, start, end);

            if (mp2 == mp1) return true;

            start++;
            end++;
        }

        return false;
    }
};