// ---------------- leetcode 91 ---------------------

class Solution {
public:
    int numDecodings(string s) {

        int size = s.size();
        if (size == 0) return 0;

        auto dp = vector<vector<int >> (size, vector<int >(2));
        if (s[0] == '0') return 0;
        // 代表不连的方式
        dp[0][0] = 1;
        // 代表连的方式
        dp[0][1] = 0;

        for (int i=1; i<size; i++) {
            if (s[i] == '0') dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0] + dp[i-1][1];

            string temp;
            temp += s[i-1];
            temp += s[i];
            
            if (atoi(temp.c_str())<1 || atoi(temp.c_str())>26) {
                dp[i][1] = 0;
            } else {
                dp[i][1] = dp[i-1][0];
            }
        }

        return dp[size-1][0] + dp[size-1][1];
        
    }
};