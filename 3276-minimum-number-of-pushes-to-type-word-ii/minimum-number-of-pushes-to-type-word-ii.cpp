class Solution {
public:
    static bool compare(int& a, int& b) { return a > b; }

    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        for (auto i : word) mp[i - 'a']++;

        sort(mp.begin(), mp.end(), compare);

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (mp[i] == 0) break;
            ans += mp[i] * (i / 8 + 1);
        }

        return ans;
    }
};