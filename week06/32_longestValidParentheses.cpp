// ------------- leetcode 32 -----------------------

class Solution {
public:
    int longestValidParentheses(string s) {

        int size = s.size(), l=0, r=0, res = 0;

       vector <int>temp;
       auto dp = vector<int> (size);

        for (int i=0; i<size; i++) {

            if (s[i] == '(') {
                temp.push_back(i);
                l++;
                dp[i] = 0;

            } else {
                
                r++;
                if (r > l) {
                    l = 0;
                    r = 0;
                    temp.clear();
                    dp[i] = 0;
                } else {
                    dp[i] = i-temp.back()+1;
                    dp[i] += temp.back() > 1? dp[temp.back()-1] : 0;
                    res = max(res, dp[i]);
                    temp.pop_back();
                }
            }

        }

        return res;

    }
};