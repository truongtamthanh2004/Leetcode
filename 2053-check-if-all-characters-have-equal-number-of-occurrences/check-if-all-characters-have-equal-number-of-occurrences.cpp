class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> count(26, 0);
        for (auto i : s) count[i - 'a']++;
        int index = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                index = i;
                break;
            }
        }
        for (int i = index + 1; i < 26; i++)
        {
            if (count[i] > 0 && count[i] != count[index]) return false;
        }
        return true;
    }
};