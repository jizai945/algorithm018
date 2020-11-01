// ---------------- leetcode 49 ----------------------------------

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int index = 0;
        map<string, int> map;
        vector<vector<string>> res;
        
        for (int i=0; i<strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(), copy.end());

            // 未找到
            if (map.find(copy) == map.end()) {
                map[copy] = index++;
                vector<string> temp;
                temp.emplace_back(strs[i]);
                res.emplace_back(temp);
            } else {
                res[map[copy]].emplace_back(strs[i]);
            }

       }

       return res;

    }
};