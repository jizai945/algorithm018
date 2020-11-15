// ---------------- leetcode 74 ---------------------------------

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        vector <int> nums;
        for (int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++) {
                nums.push_back(matrix[i][j]);
            }
        }

        int l=0, r=matrix.size()*matrix[0].size()-1, m;
        
        while (l <= r) {
            m=(l+r)/2;

            if (target == nums[m]) return true;

            if (target <= nums[m]) {
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return false;

    }
};