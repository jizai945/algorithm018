// -------------- leetcode 64 ---------------------

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int len = grid.size(), size = grid[0].size();

        auto dp = vector < vector <int> > (len, vector <int> (size));

        dp[0][0] = grid[0][0];

        for (int i=1; i<len; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for (int j=1; j<size; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for (int i=1; i<len; i++) {
            for (int j=1; j<size; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[len-1][size-1];

    }
};