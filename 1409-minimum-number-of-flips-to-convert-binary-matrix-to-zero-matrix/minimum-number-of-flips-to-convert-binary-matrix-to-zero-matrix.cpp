class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int res = INT_MAX;
        for (int mask = 0; mask < 1 << (m * n); mask++)
        {
            if (__builtin_popcount(mask) >= res) continue;
            if (check(n, m, mat, mask)) res = __builtin_popcount(mask);
        }

        return res == INT_MAX ? -1 : res;
    }

    bool check(int n, int m, vector<vector<int>> a, int mask)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (testBit(mask, i * n + j)) flip(n, m, a, i, j);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != 0) return false;
            }
        }
        return true;
    }

    void flip(int n, int m, vector<vector<int>>& a, int i, int j)
    {
        a[i][j] ^= 1;
        for (int d = 0; d < 4; d++)
        {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x >= 0 && x < m && y >= 0 && y < n) a[x][y] ^= 1;
        }
    }

    bool testBit(int mask, int i)
    {
        return (mask >> i) & 1 == 1;
    }
};