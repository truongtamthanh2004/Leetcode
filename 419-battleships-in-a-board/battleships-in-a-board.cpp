class Solution {
public:
    pair<int, int> p[2] = {{0, 1}, {1, 0}};
    void flooding(vector<vector<char>>& board, int i, int j)
    {
        board[i][j] = '.';
        for (int k = 0; k < 2; k++)
        {
            int x = i + p[k].first;
            int y = j + p[k].second;

            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'X')
                flooding(board, x, y);
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'X')
                {
                    ans += 1;
                    flooding(board, i, j);
                }
            }
        }

        return ans;
    }
};