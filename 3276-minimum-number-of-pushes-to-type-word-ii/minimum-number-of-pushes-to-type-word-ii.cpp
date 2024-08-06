class Solution {
public:
    static bool compare(pair<int, char>& a, pair<int, char>& b) { return a.first > b.first; }

    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for (auto i : word) mp[i]++;

        vector<pair<int, char>> arr;
        for (auto i : mp) {
            arr.push_back({i.second, i.first});
        }

        sort(arr.begin(), arr.end(), compare);

        int count = 0;
        int push = 1;
        int ans = 0;
        for (auto i : arr) {
            ans += (i.first * push);
            count++;
            if (count % 8 == 0) push++;
        }

        return ans;
    }
};