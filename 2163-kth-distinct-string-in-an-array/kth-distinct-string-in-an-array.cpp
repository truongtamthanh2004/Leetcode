class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto i : arr) mp[i]++;

        int count = 0;
        for (auto i : mp) {
            if (i.second == 1) count++;
        }
        
        if (count < k) return "";

        int nth = 1;
        for (auto i : arr)
        {
            if (mp[i] == 1) {
                if (nth == k) return i;

                nth++;
            }
        }

        return "";
    }
};