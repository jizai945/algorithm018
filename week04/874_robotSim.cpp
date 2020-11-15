// ----------------------- leetcode 874 ------------------

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int res = 0;

        int y_d[] = {1, 0, -1, 0};
        int x_d[] = {0, -1, 0, 1};
        int index=0, temp_x, temp_y, x=0, y=0;
        set<pair<int, int>> obstacleSet;

        for(int i=0;i<obstacles.size();i++)
            obstacleSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));


        for (int i=0; i<commands.size(); i++) {

            if (commands[i] == -2) {
                index++;
                index %= 4;
            } else if (commands[i] == -1) {
                index += 3;
                index %= 4;
            } else {
                for (int j=0; j<commands[i]; j++){
                    temp_x = x+x_d[index];
                    temp_y = y+y_d[index];

                    if (obstacleSet.find(make_pair(temp_x, temp_y)) == obstacleSet.end()) {
                        x = temp_x;
                        y = temp_y;
                        res = max(res, x*x+y*y);
                    } else{}
                }

            }


        }

        return res;

    }
};