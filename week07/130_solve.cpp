// ----------------- leetcode 130 ----------------

class Solution {
public:

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x<0 || x>=board[0].size() || y<0 || y>=board.size()) return;

        if (board[y][x] == 'O') {
            board[y][x] = 'i';
            dfs(board, x-1, y);
            dfs(board, x, y-1);
            dfs(board, x+1, y);
            dfs(board, x, y+1);
        }
    }


    void solve(vector<vector<char>>& board) {

        int col = board.size(); 
        if (col == 0) return;
        int row = board[0].size();

        for (int i=0; i< col; i++) {
            dfs(board, 0, i);
            dfs(board, row-1, i);
        }

        for (int i=0; i< row; i++) {
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }

        for (int i=0; i<col; i++) {

            for (int j=0; j<row; j++) {
                if (board[i][j] == 'i') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }

        }

    }
};