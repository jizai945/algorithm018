// -------------- leetcode 47 --------------------------

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void getNum(int index, vector<int> &nums, int len) {

        if (index == len) {
            res.push_back(temp);
            return;
        }

        unordered_map<int, int> map;

        for (int i=index; i<len; i++) {
            if (index!=i && map.find(nums[i])!=map.end()) continue;
            map[nums[i]] = i;

            swap(nums[i], nums[index]);
            temp.push_back(nums[index]);
            getNum(index+1, nums, len);
            temp.pop_back();
            swap(nums[i], nums[index]);
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        getNum(0, nums, nums.size());

        return res;

    }
};