class Solution {
    int[] dx = new int[]{-1, 0, 1, 0};
    int[] dy = new int[]{0, 1, 0, -1};
    Queue<int[]> q = new LinkedList<>();

    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        int res = 0;
        boolean[][] visited = new boolean[n][n];

        boolean found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, n, n, grid, visited);
                    found = true;
                }
            }
        }

        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int[] cur = q.poll();
                for (int k = 0; k < 4; ++k) {
                    int u = cur[0] + dx[k];
                    int v = cur[1] + dy[k];
                    if (!isInside(u, v, n, n) || visited[u][v]) {
                        continue;
                    }
                    if (grid[u][v] == 1) {
                        return res;
                    }
                    visited[u][v] = true;
                    q.add(new int[]{u, v});
                }
            }
            res++;
        }

        return -1;
    }

    private void dfs(int i, int j, int m, int n, int[][] grid, boolean[][] visited) {
        visited[i][j] = true;
        q.add(new int[]{i, j});

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (!isInside(x, y, m, n) || visited[x][y] || grid[x][y] == 0) continue;

            dfs(x, y, m, n, grid, visited);
        }
    }

    private boolean isInside(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}