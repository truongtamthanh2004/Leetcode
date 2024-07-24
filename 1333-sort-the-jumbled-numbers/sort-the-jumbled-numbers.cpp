class Solution {
public:
    static bool sortCustom(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
    {
        if(a.first != b.first)
            return a.first < b.first;
        
        return a.second.first < b.second.first;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < 10; i++)
        {
            mp[i] = mapping[i];
        }

        vector<pair<int, pair<int, int>>> tmp;
        int idx = 0;
        for (auto i : nums) {
            string t = to_string(i);
            int mapValue = 0;
            for (int j = 0; j < t.length(); j++)
            {
                mapValue = mapValue * 10 + mp[t[j] - '0'];
            }
            cout << "Original: " << i << " -> Mapped: " << mapValue << endl;
            tmp.push_back({mapValue, {idx, i}});
            idx++;
        }
        sort(tmp.begin(), tmp.end(), sortCustom);

        vector<int> ans;
        for (auto i : tmp) {
            ans.push_back(i.second.second);
        }

        return ans;
    }
};