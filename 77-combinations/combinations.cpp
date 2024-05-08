class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& cur, int n, int k, int idx)
    {
        for(int i = idx; i <= n; i++)
        {
            cur.push_back(i);

            if (cur.size() == k) ans.push_back(cur);
            else dfs(cur, n, k, i + 1);
            
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        dfs(cur, n, k, 1);

        return ans;
    }
};