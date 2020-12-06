// ------------------- leetcode 127---------------------------

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> wordMap;
        for (int i=0; i<wordList.size(); i++) {
            wordMap[wordList[i]] = i;
        }

        if (wordMap.find(endWord) == wordMap.end()) return 0;

        // 记录当前是否使用过
        bool *isUse = new bool[wordList.size()](); 

        // 初始化队列
        queue<string> que;
        // 记录当前层级 / 记录当前层级有多少个分支
        int level=1, size=1, size_next=0;


        que.push(beginWord);

        while(!que.empty()) {

            string nowWord = que.front();
            que.pop();

            for (int i=0; i<nowWord.size(); i++) {

                for(int j=0; j<26; j++) {

                    string newWord = nowWord;
                    newWord[i] = 'a'+j;
                    if (wordMap.find(newWord) != wordMap.end() && isUse[wordMap[newWord]]==false) {
                        if (newWord == endWord) return level+1; 
                        isUse[wordMap[newWord]] = true;
                        que.push(newWord);
                        size_next++;
                    }

                }
            }

            if (--size == 0) {
                level++;
                size = size_next;
                size_next=0;
            }

        }

        return 0;

    }
};