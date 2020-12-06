// --------------- leetcode 36 ----------------

class Solution {
public:


    bool isValidSudoku(vector<vector<char>>& board) {

        int cols = board.size();
        if (cols == 0) return true;
        int rows = board[0].size();
        vector<vector<int>> rowNums(9, vector<int>(9, 0));
        vector<vector<int>> colNums(9, vector<int>(9, 0));
        vector<vector<int>> boxNums(9, vector<int>(9, 0));

        for (int i=0; i<cols; i++) {
            for (int j=0; j<rows; j++) {
                if (board[i][j] == '.') continue;

                int val = board[i][j] - '1';
                int boxIndex = (i/3)*3+j/3;
                if (rowNums[j][val]==0 && colNums[i][val]==0 && boxNums[boxIndex][val]==0) {
                    rowNums[j][val] = 1;
                    colNums[i][val] = 1;
                    boxNums[boxIndex][val] = 1;

                } else {
                    return false;
                }

            }
        
        }

        return true;

    }
};