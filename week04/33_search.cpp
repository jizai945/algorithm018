// ------------- leetcode 33 -----------------

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0, right = nums.size()-1;

        while (left <= right) {

            int mid = (left+right)/2;

            if (target == nums[mid]) return mid;
            if (target == nums[left]) return left;
            if (target == nums[right]) return right;

            if (nums[left] < nums[mid]) {
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }   
            } else {
                if (target >= nums[mid] && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                } 
            }

        }

        return -1;

    }
};