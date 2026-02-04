class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] dist = new int[m][n];
        Queue<int[]> q = new LinkedList<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.offer(new int[]{i, j});
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = -1;
            }
        }

        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int r = cur[0];
            int c = cur[1];

            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (!isNotInside(nr, nc, m, n) && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.offer(new int[]{nr, nc});
                }
            }
        }

        return dist;
    }

    private boolean isNotInside(int r, int c, int m, int n) {
        return r < 0 || c < 0 || r >= m || c >= n;
    }
}