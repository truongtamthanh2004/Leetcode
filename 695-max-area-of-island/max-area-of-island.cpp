class Solution {
public:
    pair<int, int> p[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void flooding(vector<vector<int>>& grid, int i, int j, int& count)
    {
        grid[i][j] = -1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + p[k].first;
            int y = j + p[k].second;
            if (x < grid.size() && x >= 0 && y < grid[0].size() && y >= 0 && grid[x][y] == 1)
            {
                count++;
                flooding(grid, x, y, count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 1;
        int maxCount = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1) 
                {
                    flooding(grid, i, j, count);
                    maxCount = max(maxCount, count);
                    count = 1;
                }
            }
        }
        
        return maxCount;
    }
};