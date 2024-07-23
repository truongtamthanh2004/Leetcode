class Solution {
public:
    static bool customCompare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;  // Sort by first element
        } else {
            return a.second > b.second;  // If first elements are equal, sort by second element
        }
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (auto i : nums) mp[i]++;

        vector<pair<int, int>> freq;
        for (auto i : mp)
        {
            freq.push_back({i.second, i.first});
        }

        sort(freq.begin(), freq.end(), customCompare);

        int j = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(freq[j].second);
            freq[j].first--;
            if (freq[j].first == 0) j++;
        }

        return ans;
    }
};