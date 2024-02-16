class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (auto i : arr)
        {
            mp[i]++;
        }
        int n = mp.size();
        vector<pair<int, int>> tmp(n);
        int j = 0;
        for (auto i : mp)
        {
            tmp[j].first = i.second;
            tmp[j].second = i.first;
            j++;
        }

        sort(tmp.begin(), tmp.end());

        j = 0;
        while (k > 0) 
        {
            while (tmp[j].first > 0 && k > 0)
            {
                tmp[j].first--;
                k--;
            }
            if (tmp[j].first == 0)
            {
                j++;
                n--;
            }
        }
        return n;
    }
};