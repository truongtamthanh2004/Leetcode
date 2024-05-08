class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& cur, vector<int>& nums, int idx)
    {
        for (int i = idx; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            ans.push_back(cur);
            
            if (cur.size() <  nums.size())
            {
                dfs(cur, nums, i + 1);
            }

            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        ans.push_back(cur);
        
        dfs(cur, nums, 0);

        return ans;
    }
};