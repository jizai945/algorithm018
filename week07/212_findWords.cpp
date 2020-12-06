// ---------------------- leetcode 212 -------------------------

class Solution {
public:
    //                  二维字符网络                         字符串列表         字符在字符串中索引   第几个字符  方向：0头到尾 1尾到头
    bool isWord(vector<vector<char>>& board, int x, int y, vector<string> &temp, int index, int wordindex, int dirct) {

        if (x<0 || x>=board[0].size() || y<0 || y>=board.size()) return false;

        if (board[y][x] == temp[index][wordindex]) board[y][x] = 1;
        else return false;

        if (dirct == 0) {
            if (wordindex == temp[index].size()-1) {
                return true;
            }

            if (isWord(board, x-1, y, temp, index, wordindex+1, 0)==false&&
            isWord(board, x+1, y, temp, index, wordindex+1, 0)==false&&
            isWord(board, x, y-1, temp, index, wordindex+1, 0)==false&&
            isWord(board, x, y+1, temp, index, wordindex+1, 0)==false) {
                board[y][x] = temp[index][wordindex];
                return false;
            }

        } else {
            if (wordindex == 0) {
                return true;
            }

            if (isWord(board, x-1, y, temp, index, wordindex-1, 1)==false&&
            isWord(board, x+1, y, temp, index, wordindex-1, 1)==false&&
            isWord(board, x, y-1, temp, index, wordindex-1, 1)==false&&
            isWord(board, x, y+1, temp, index, wordindex-1, 1)==false) {
                board[y][x] = temp[index][wordindex];
                return false;
            }

        }

        return true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int len = board.size(), size = board[0].size();

        vector<string> temp = words;
        bool find;
        vector<string> res;
        vector<vector<char>> board_temp;

        for (int i=0; i<len; i++) {
            for (int j=0; j<size; j++) {
                for (int k=0; k<temp.size(); k++) {
                    find = false;
                    board_temp = board;
                    if (board[i][j] == temp[k][0]) {                       
                        find = isWord(board_temp, j, i, temp, k, 0, 0);
                    } else if(board[i][j] == temp[k][temp[k].size()-1]) {
                        find = isWord(board_temp, j, i, temp, k, temp[k].size()-1, 1);
                    }

                    if (find == true) {
                        res.push_back(temp[k]);
                        temp.erase(temp.begin()+k);
                        k=-1;
                    }
                }
            }
        }

        return res;

    }
};