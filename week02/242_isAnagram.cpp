// ---------------------- leetcode 242 --------------------------------
// 方法1：排序后判断两个字符串是否相等
// 方法2：哈希表
// 方法3：数组记录出现字符的次数是否相等

class Solution {
public:
    bool isAnagram(string s, string t) {

#if 0
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t) {
            return true;
        }

        return false;
#elif 0

        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> mymap;

        for (int i=0; i<s.length(); i++) {
            mymap[s[i]]++;
        }

        for (char ch : t) {
            if (--mymap[ch] < 0) {
                return false;
            }
        }

        return true;
#else
        if (s.length() != t.length()) {
            return false;
        }

        int arry[26] = {0};

        for (char ch:t) {
            arry[ch-'a']++;
        }

        for (char ch:s) {
            if(--arry[ch-'a'] < 0) {
                return false;
            }
        }

        return true;
#endif

    }
};