// ------------- leetcode 200 ---------------

class Solution {
public:

    void landsToWater(int x, int y, vector<vector<char>>& grid) {
        if (x>=grid[0].size() || y>=grid.size()) return;
        if (grid[y][x] != '1') return;

        grid[y][x] = '0';
        landsToWater(x-1, y, grid);
        landsToWater(x+1, y, grid);
        landsToWater(x, y-1, grid);
        landsToWater(x, y+1, grid);
}

    int numIslands(vector<vector<char>>& grid) {

        int res = 0;

        for (int x=0; x<grid[0].size(); x++) {
            for (int y=0; y<grid.size(); y++) {
                if (grid[y][x] != '0') {
                    landsToWater(x, y, grid);
                    res++;
                }
            }
        }

        return res;

    }
};