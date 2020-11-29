// ------------------ leetcode 403 ---------------
// 这个例题中二分查找比用map快

#define BINARY_SEARCH   1
#define MAP             0

class Solution {
public:
    map<int, int> myMap;

    bool dfs (vector<int>& stones, int level, int step) {
        if (level == stones.back()) return true;
    #if BINARY_SEARCH
        if (!binary_search(stones.begin(), stones.end(), level)) return false;
    #else
        if (!myMap.count(level)) return false;
    
    #endif

        return (dfs(stones, level+step+1, step+1) || 
                dfs(stones, level+step, step) ||
                (step > 1 &&  dfs(stones, level+step-1, step-1)));
    }

    bool canCross(vector<int>& stones) {

    #if BINARY_SEARCH
    #else
        for (int i=0; i<stones.size(); i++)
            myMap[stones[i]] = i;
    #endif

        for (int i=1; i<stones.size(); i++)
            if (stones[i] - stones[i-1] > i) return false;
    
         return dfs(stones, 1, 1);

    }
};