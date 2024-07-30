class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int countB = 0;

        for (auto i : s) {
            if (i == 'b') countB++;
            else {
                if (countB != 0) {
                    ans = min(countB, ans + 1);
                }
            }
        }

        return ans;
    }
};