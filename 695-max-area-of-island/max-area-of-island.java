class Solution {
    int[] dx = new int[]{-1, 0, 1, 0};
    int[] dy = new int[]{0, 1, 0, -1};
    int count = 1;

    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int res = 0;
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || visited[i][j]) continue;

                dfs(i, j, m, n, grid, visited);
                res = Math.max(res, count);
                count = 1;
            }
        }

        return res;
    }

    private void dfs(int i, int j, int m, int n, int[][] grid, boolean[][] visited) {
        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (!isInside(x, y, m, n) || visited[x][y] || grid[x][y] == 0) continue;

            dfs(x, y, m, n, grid, visited);
            count++;
        }
    }

    private boolean isInside(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}