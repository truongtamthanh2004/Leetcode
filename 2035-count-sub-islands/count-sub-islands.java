class Solution {
    int[] dx = new int[]{-1, 0, 1, 0};
    int[] dy = new int[]{0, 1, 0, -1};

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int m = grid1.length, n = grid1[0].length;
        int res = 0;
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 0 || visited[i][j]) continue;

                res += dfs(i, j, m, n, grid1, grid2, visited) == true ? 1 : 0;
            }
        }

        return res;
    }

    private boolean dfs(int i, int j, int m, int n, int[][] grid1, int[][] grid2, boolean[][] visited) {
        visited[i][j] = true;
        boolean ok = grid1[i][j] == 1;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (!isInside(x, y, m, n) || visited[x][y] || grid2[x][y] == 0) continue;

            ok &= dfs(x, y, m, n, grid1, grid2, visited);
        }

        return ok;
    }

    private boolean isInside(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}