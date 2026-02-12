class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] || grid[i][j] != 1) continue;
                int area = dfs(i, j, grid, visited);
                ans = Math.max(area, ans);
            }
        }

        return ans;
    }

    private int dfs(int r, int c, int[][] grid, boolean[][] visited) {
        visited[r][c] = true;
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int area = 1;

        for (int[] dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (isNotInside(nr, nc, grid) || visited[nr][nc] || grid[nr][nc] != 1) continue;
            area += dfs(nr, nc, grid, visited);
        }

        return area;
    }

    private boolean isNotInside(int r, int c, int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        return r < 0 || c < 0 || r >= m || c >= n;
    }
}