class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxNum = 0;

        for (auto i : nums)
        {
            if (i < 0) 
                mp[i]++;
        }

        for (auto i : nums)
        {
            if (i > 0 && mp[-i] > 0) 
                maxNum = max(maxNum, i);
        }

        return maxNum > 0 ? maxNum : -1;
    }
};