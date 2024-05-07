class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& cur, vector<bool>& used, vector<int>& nums)
    {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i]) {
                cur.push_back(nums[i]);
                used[i] = true;
                dfs(cur, used, nums);
                used[i] = false;
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        dfs(cur, used, nums);

        return res;
    }
};