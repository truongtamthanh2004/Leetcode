class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;

        int size = nums.size() - 1 >= k ? k : nums.size() - 1;
        for (int i = 0; i <= size; i++)
        {
            if (mp[nums[i]]) return true;
            else mp[nums[i]] = true;
        }

        int i = 1, j = size + 1;
        while (j < nums.size()) {
            mp[nums[i - 1]] = false;

            if (mp[nums[j]]) return true;

            mp[nums[j]] = true;

            i++;
            j++;
        }

        return false;
    }
};