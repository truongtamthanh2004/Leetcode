class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int m = maze.length;
        int n = maze[0].length;
        boolean[][] visited = new boolean[m][n];
        // {x, y, dist from entry}
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]] = true;

        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int r     = cur[0];
            int c     = cur[1];
            int dist  = cur[2];
            
            for (int[] dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                int nd = dist + 1;

                if (isNotInside(nr, nc, m, n) || maze[nr][nc] == '+' || visited[nr][nc]) continue;
                if (isExitPosition(nr, nc, m, n) && maze[nr][nc] == '.') return nd;

                q.offer(new int[]{nr, nc, nd});
                visited[nr][nc] = true;
            }
        }

        return -1;
    }

    private boolean isExitPosition(int r, int c, int m, int n) {
        return r == 0 || c == 0 || r == m - 1 || c == n - 1;
    }

    private boolean isNotInside(int r, int c, int m, int n) {
        return r < 0 || c < 0 || r >= m || c >= n;
    }
}