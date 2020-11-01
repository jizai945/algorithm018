// ---------------------- leetcode1------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> arry;

        for (int i=0; i<nums.size(); i++) {
            if (map[target - nums[i]] != 0) {
                arry.push_back(i);
                arry.push_back(map[target - nums[i]]-1);
                return arry;
            }

            map[nums[i]] = (i+1);
        }

        return arry;

    }
};