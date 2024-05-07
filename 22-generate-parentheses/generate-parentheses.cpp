class Solution {
public:
    vector<string> res;

    void dfs(string cur, int d, int n)
    {
        if (cur.length() == 2 * n)
        {
            if (d == 0) res.push_back(cur);
            return;
        }

        dfs(cur + "(", d + 1, n);
        if (d - 1 >= 0) dfs(cur + ")", d - 1, n);
    }

    vector<string> generateParenthesis(int n) {
        dfs("", 0, n);
        return res;
    }
};