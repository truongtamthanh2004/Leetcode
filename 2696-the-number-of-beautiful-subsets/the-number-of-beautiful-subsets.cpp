class Solution {
public:
    unordered_map<int, int> mp;
    int count = 0;

    void dfs(vector<int>& nums, int k, int idx)
    {
        if (idx == nums.size()) 
        {
            count++;
            return;
        }

        dfs(nums, k, idx + 1);

        if (mp[nums[idx] - k] == 0)
        {
            mp[nums[idx]]++;
            dfs(nums, k, idx + 1);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        dfs(nums, k, 0);
        return count - 1;
    }
};