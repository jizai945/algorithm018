// -------------------- leetcode 621 ----------------

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int size = tasks.size();

        vector<int> temp(26);
        for (char c:tasks) temp[c-'A']++;
        sort(temp.rbegin(),temp.rend());

        int cnt=1;
        while(cnt<temp.size()&&temp[cnt]==temp[0]) cnt++;
        return max(size,cnt+(n+1)*(temp[0]-1) );

    }
};