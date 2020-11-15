// -------------------- leetcode 529 -------------------

class Solution {
public:

    // 判断该坐标是否合法
    bool isLegal(int x, int y, vector<vector<char>>& board) {
        if (x>=0 && x<board[0].size() && y>=0 && y<board.size()) 
            return true;

        return false;
    }

    // 计算周围的炸弹数量
    int clacBomb(int x, int y, vector<vector<char>>& board) {
        int count=0;

        for (int t_x=x-1; t_x<=x+1; t_x++) {
            for(int t_y=y-1; t_y<=y+1; t_y++) {
                if (isLegal(t_x, t_y, board)==true && board[t_y][t_x]=='M') count++;
            }
        }

        return count;
    }

    void dfs(int x, int y, vector<vector<char>>& board) {
        if (x<0 || x>=board[0].size() || y<0 || y>=board.size()) return;

        int count=0;

        if (board[y][x] == 'E') {
            count = clacBomb(x, y, board);

            if (count == 0) {
                board[y][x] = 'B';

                for (int t_x=x-1; t_x<=x+1; t_x++) {
                    for(int t_y=y-1; t_y<=y+1; t_y++) {
                        dfs(t_x, t_y, board);
                    }
                }
            } else{
                board[y][x] = '1'+count-1;
            }
        } else {}
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        int y=click[0], x=click[1];

        if (board[y][x] == 'M') {
            board[y][x] = 'X';
            return board;
        } else if (board[y][x] == 'E') {                
            dfs(x, y, board);
        } 

        return board;

    }
};