// ------------------------- leetcode 283 移动零 -----------------------

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int zeroSize = 0;   // 记录0个数
        int index = 0; // 记录非0索引
        for (int i=0; i<nums.size(); i++) {

            if (nums[i] != 0) {
                if(index < i) {
                    nums[index] = nums[i];
                }
                index ++;
            } else {
                zeroSize ++;
            }

        }

        while (zeroSize) {
            nums[nums.size() - zeroSize] = 0;
            zeroSize--;
        }


    }
};