// ------------- leetcode 189 旋转数组 --------------
/*
	1.新建一个新的数组
	2.记录移动后当前读指针的索引变化
	3.再把数据从新数组的读索引开始拷贝到原数组中
*/	
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector <int> newNums = nums;
        int size = newNums.size();
        int index = 0; //索引

        index = index-k;
        while (index<0) {
            index+=size;
        }
        index %= size;

        for (int i=0; i<size; i++) {
            nums[i] = newNums[(index+i)%size];
        }



    }
};