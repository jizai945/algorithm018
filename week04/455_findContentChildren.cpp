// ------------ leetcode 455 ----------------------
// 贪心算法

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int res = 0, index = s.size()-1;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i=g.size()-1; i>=0; i--) {
            if (index>=0 && s[index] >= g[i]) {
                res++;
                index--;
            }
        }

        return res;
    }
};