class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int curCost = 0;
        int maxLength = 0;

        while (end++ < n)
        {
            curCost += abs(s[end - 1] - t[end - 1]);

            while (curCost > maxCost)
            {
                curCost -= abs(s[start] - t[start]);
                start += 1;
            }

            maxLength = max(maxLength, end - start);
        }

        return maxLength;
    }
};