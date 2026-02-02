class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        boolean[][] visited = new boolean[n][n];

        int[][] dirs = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0, 1});
        visited[0][0] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int row = cur[0];
            int col = cur[1];
            int dis = cur[2];

            if (row == n - 1 && col == n - 1) return dis;

            for (int[] dir : dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (isNotInside(newRow, newCol, n)) continue;

                if (visited[newRow][newCol] || grid[newRow][newCol] == 1) continue;

                q.offer(new int[]{newRow, newCol, dis + 1});
                visited[newRow][newCol] = true;
            }
        }

        return -1;
    }

    private boolean isNotInside(int r, int c, int n) {
        return r < 0 || c < 0 || r >= n || c >= n;
    }
}