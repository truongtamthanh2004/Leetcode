class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        int sumM = accumulate(rolls.begin(), rolls.end(), 0);
        int sumN = sum - sumM;
        
        vector<int> ans;
        if (sumN < n || sumN > n * 6) return ans;
        else {
            int full = sumN / n;
            int extra = sumN % n;
            for (int i = 0; i < n; i++) {
                if (extra) ans.push_back(full + 1);
                else ans.push_back(full);
                extra = max(0, extra - 1);
            }
        }

        return ans;
    }
};