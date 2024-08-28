class Solution {
public:
    vector<int> x = {0, 0, 1, -1};
    vector<int> y = {1, -1, 0, 0};
    bool island = false;
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int m, int n) {
        if (grid1[i][j] != grid2[i][j]) {
            island = false;
            return;
        }

        grid2[i][j] = grid1[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            int newX = i + x[k];
            int newY = j + y[k];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1) 
                dfs(newX, newY, grid1, grid2, m, n);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int m = grid1.size();
        int n = grid1[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    island = true;
                    dfs(i, j, grid1, grid2, m, n);
                    if (island) count++;
                }
            }
        }

        return count;
    }
};