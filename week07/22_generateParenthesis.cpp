// ------------------- leetcode 22 ----------------------------

class Solution {
private:
    vector<string> res;
public:
    void dfs(string &temp, int left, int right, int level) {
        if (level <= 0){
            res.push_back(temp);
            return;
        }

        if (left > 0) {
            temp.push_back('(');
            dfs(temp, left-1, right, level-1);
            temp.pop_back();
        }

        if (left < right) {
            temp.push_back(')');
            dfs(temp, left, right-1, level-1);
            temp.pop_back();
        }
        
    }


    vector<string> generateParenthesis(int n) {

        res.clear();

        if (n==0) res;

        string temp;
        dfs(temp, n, n, 2*n);

        return res;

    }
};