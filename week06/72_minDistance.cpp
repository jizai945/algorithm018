// --------------- leetcode 72 -----------------

class Solution {
public:
    int minDistance(string word1, string word2) {

        int size1 = word1.size(), size2 = word2.size();

        auto dp = vector<vector<int>> (size1+1, vector<int>(size2+1));

        dp[0][0] = 0;

        for (int i=1; i<size1+1; i++) {
            dp[i][0] = i;
        }

        for (int j=1; j<size2+1; j++) {
            dp[0][j] = j;
        }

        for (int i=1; i<size1+1; i++) {
            for (int j=1; j<size2+1; j++) {
            
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]-1)) + 1;
                }else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
            
            }
        }

        return dp[size1][size2];

    }
};