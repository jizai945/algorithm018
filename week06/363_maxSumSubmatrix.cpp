// ---------------- leetcode 363 -------------------------

class Solution {
public:

    int dpMax(vector<int> &sum, int k) {

        int max = INT_MIN;
        for (int l = 0; l < sum.size() ; l++) {
            int temp = 0;
            for (int r = l; r < sum.size() ; r++) {
                temp += sum[r];
                if (temp > max && temp <= k) max = temp;
            }
        }
        return max;


    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
     
        int len = matrix[0].size(), size = matrix.size();
        int temp = INT_MIN;

        for (int l=0; l<len; l++) {
            vector<int> sum(size,0);

            for (int r=l; r<len; r++) {               
                for (int i=0; i<size; i++) {
                    sum[i] += matrix[i][r];
                }

                temp = max(temp, dpMax(sum, k));
            }

        }

        return temp;

    }
};