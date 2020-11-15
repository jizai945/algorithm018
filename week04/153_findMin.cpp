// ----------- leetcode 153 ------------------------

class Solution {
public:
    int findMin(vector<int>& nums) {

        int l=0, r=nums.size()-1, m;

        while (l < r) {
            if (nums[l] < nums[r]) return nums[l];

            if (l+1 == r) {
                if (nums[l] < nums[r]) return nums[l];
                else return nums[r];
            } 

            m = (l+r)/2;
            if (nums[l] < nums[m]) {
                l=m;
            } else {
                r=m;
            }
        }

        return nums[l];

    }
};