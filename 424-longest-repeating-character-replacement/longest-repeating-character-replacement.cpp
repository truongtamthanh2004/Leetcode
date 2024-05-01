class Solution {
public:

    bool canReplace(int start, int end, vector<int>& count, int k) {
        int len = end - start + 1;
        int maxCount = 0;

        for (int i = 0; i < 26; i++) {
            maxCount = max(maxCount, count[i]);
        }

        return len - maxCount <= k;
    }
    
    int characterReplacement(string s, int k) {
        int n = s.length();
        int start = 0;
        int maxLength = 0;
        vector<int> count(26, 0);

        for (int end = 0; end < n; end++) {
            count[s[end] - 'A']++;

            while (!canReplace(start, end, count, k)) {
                count[s[start++] - 'A']--;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};