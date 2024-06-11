class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp, mp2;
        vector<int> ans;
        for (auto i : arr1) mp[i]++;
        for (auto i : arr2) mp2[i]++;
        for (auto i : arr2)
        {
            for (int j = 0; j < mp[i]; j++) ans.push_back(i);
        }
        int tmp = ans.size();
        for (auto i : arr1)
        {
            if (!mp2[i]) ans.push_back(i);
        }
        if (ans.size() > tmp) sort(ans.begin() + tmp, ans.end());

        return ans;
    }
};