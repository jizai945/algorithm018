 //--------------------- leetcode 547 -----------------

class Solution {
private:
    vector <int> parent;

public:
    int findParent(int num) {
        if (parent[num] == num) return num;

        return findParent(parent[num]);
    }

    int findCircleNum(vector<vector<int>>& M) {
      
        int size = M[0].size()*M[0].size();
        int res = M[0].size();
        
        int par1, par2;
        for (int i=0; i<size; i++) {
            parent.push_back(i);
        }

        for (int i=0; i<M.size(); i++) {

            for (int j=0; j<M[0].size(); j++) {
                if (M[i][j] != 0) {
                    par1 = findParent(i);
                    par2 = findParent(j);

                    if (par1 != par2) {
                        parent[par1] = par2;
                        res --;
                    }

                }
            }
            
        }

        return res;

    }
};