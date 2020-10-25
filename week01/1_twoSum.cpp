// ---------------------- leetcode 1  两数之和 ------------------- 
// 使用哈希表的做法，c++中有一个map的功能

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map <int, int> re;

        for (int i=0; i<nums.size(); i++) {
            if (re.count(target - nums[i])) {
                return {i, re[target - nums[i]]};
            }

            re.insert(map <int, int>::value_type(nums[i], i));
        }

        return {-1, -1};
    }
};