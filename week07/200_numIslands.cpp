// ---------------- leetcode 200 -----------------------

class Solution {
public:
    int dfs(vector<vector<char>>& grid, int x, int y) {
        if (x<0 || y<0 || x>=grid[0].size() || y>=grid.size()) {
            return 0;
        }

        if (grid[y][x] == '1') {
            grid[y][x] = '0';
            dfs(grid, x-1, y);
            dfs(grid, x+1, y);
            dfs(grid, x, y+1);
            dfs(grid, x, y-1);
            return 1;
        } else {
            return 0;
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int res = 0;
        vector<vector<char>>& temp = grid;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
               res += dfs(temp, j, i);
            }
        }

        return res;
    }
};