// ----------------------- leetcode 77 ----------------------------

class Solution {
public:

    vector<int> temp;
    vector<vector<int>> res;

    void dfs (int index, int n, int k) {

        if (temp.size()+(n-index+1) < k) {
            return;
        }

        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        temp.push_back(index);
        dfs(index+1, n, k);
        temp.pop_back();
        dfs(index+1, n, k);

    }

    vector<vector<int>> combine(int n, int k) {

        dfs (1, n, k);

        return res;
    }
};