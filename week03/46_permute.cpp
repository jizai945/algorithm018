// ------------- leetcode 46 ------------------------

class Solution {
public:
    vector<int> buf;
    vector<vector<int>> res;

    void getNum (int index, vector<int>& nums, int len) {
        if (index == len) {
            res.push_back(buf);
            return;
        }

        for (int i=index; i<len; i++) {
            swap (nums[i], nums[index]);
            buf.push_back(nums[index]);
            getNum (index+1, nums, len);
            buf.pop_back();
            swap (nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> temp = nums;
        getNum(0, temp, nums.size());

        return res;
    }
};