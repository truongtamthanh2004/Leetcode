class Solution {
public:
    int total = 0;
    void dfs(vector<int>& nums, int idx, int curXor)
    {
        if (idx == nums.size()) 
        {
            total += curXor;
            return;
        }

        dfs(nums, idx + 1, curXor ^ nums[idx]);
        
        dfs(nums, idx + 1, curXor);
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0, 0);
        return total;
    }
};