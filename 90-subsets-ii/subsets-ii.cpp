class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1) 
                    tmp.push_back(nums[j]);
            }
            sort(tmp.begin(), tmp.end());
            if (count(ans.begin(), ans.end(), tmp) == 0) 
                ans.push_back(tmp);
        }
        return ans;
    }
};