class Solution {
public:
    int minInRow(vector<vector<int>>& matrix, int row, int n) {
        int ans = 100000;

        for (int i = 0; i < n; i++) {
            ans = min(ans, matrix[row][i]);
        }

        return ans;
    }

    int maxInCol(vector<vector<int>>& matrix, int col, int m) {
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            ans = max(ans, matrix[i][col]);
        }

        return ans;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == minInRow(matrix, i, n) && matrix[i][j] == maxInCol(matrix, j, m))
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};