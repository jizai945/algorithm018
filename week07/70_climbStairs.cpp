// ------------------- leetcode 70 -----------------------

class Solution {
public:

    int climbStairs(int n) {

        int step1=0, step2 = 1;
        int res ;

        for (int i=0; i<n; i++) {

            res = step1+step2;
            step1 = step2;
            step2 = res;

        }

        return res;

    }
};