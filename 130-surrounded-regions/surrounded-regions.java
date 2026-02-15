class Solution {
    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') continue;
                if (board[i][j] == 'O' && isEdge(i, j, m, n)) {
                    dfs(i, j, m, n, board);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

    private void dfs(int r, int c, int m, int n, char[][] board) {
        board[r][c] = '#';
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int[] dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (isNotInside(nr, nc, m, n)) continue;
            if (board[nr][nc] == 'X' || board[nr][nc] == '#') continue;
            
            dfs(nr, nc, m, n, board);
        }
    }

    private boolean isEdge(int r, int c, int m, int n) {
        return r == 0 || c == 0 || r == m - 1 || c == n - 1;
    }

    private boolean isNotInside(int r, int c, int m, int n) {
        return r < 0 || c < 0 || r >= m || c >= n;
    }
}