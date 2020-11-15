// ----------- leetcode 55 -----------------------

class Solution {
public:

    bool canJump(vector<int>& nums) {

        int size = nums.size();
        int top=0;

        for (int i=0; i<size; i++) {
            if (top>=i) {
                top = max(top, nums[i]+i);
                if(top >= size) return true;
            } else {
                return false;
            }            

        }

        return true;

    }
};