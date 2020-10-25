// ------------------------------ leetcode 66 ----------------------------------
// 思路1：把所有的数字读出来组合成一个整数，整数+1后，再把这个整数上各位的数字以此放入数组中，时间复杂度 O(2*N)
// 思路2：从尾部开始遍历，以此每个位置上的数据加一，直到不需要进位停止，如果到数组索引0还需要进位，那么在数组头部插入一个数字1 时间复杂度 小于等于O（N）

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // 思路二解法
        for (int i=digits.size()-1; i>=0; i--) {
            digits[i] ++;
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                return digits;
            }
        }

         digits.insert(digits.begin()+0, 1);

         return digits;

    }
};