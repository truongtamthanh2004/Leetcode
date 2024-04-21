class Solution {
public:
    pair<int, int> p[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void flooding(vector<vector<char>>& board, int i, int j)
    {
        board[i][j] = 'V';
        for (int k = 0; k < 4; k++)
        {
            int x = i + p[k].first;
            int y = j + p[k].second;
            if (x < board.size() && x >= 0 && y < board[0].size() && y >= 0 && board[x][y] == 'O')
            {
                flooding(board, x, y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O') flooding(board, i, 0);
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][m - 1] == 'O') flooding(board, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O') flooding(board, 0, j);
        }
        for (int j = 0; j < m; j++)
        {
            if (board[n - 1][j] == 'O') flooding(board, n - 1, j);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'V') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
    }
};