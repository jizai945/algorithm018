// -------------- leetcode 221 -----------------

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int len = matrix[0].size(), size = matrix.size(), res=0;

        auto dp = vector<vector<int>>(size, vector<int>(len));

        for (int i=0; i<len; i++) {
            dp[0][i] = matrix[0][i] - '0';
            res = max(res, dp[0][i]);
        }

        for (int j=0; j<size; j++) {
            dp[j][0]  = matrix[j][0] - '0';
            res = max(res, dp[j][0]);
        }


        for (int i=1; i<size; i++) {
            for (int j=1; j<len; j++) {

                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                }

                res = max(res, dp[i][j]);
                
            }
        }

        return res*res;

    }
};