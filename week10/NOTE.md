# 学习笔记_WEEK10



##  复习



### 数据结构

```
一维：
	基础：数组arry(string)、链表linked list
		访问:O(1)				O(N)
		修改：O（n）			O（1）
	高级:栈stack、队列quene、双端队列deque、集合set、映射map(hash or map)、etc
	
二维：
	基础：树tree、图graph
	高级：二叉搜索树 binary search tree(red-black tree、AVL)，堆heap，并查集disjoint set,字典树 Trie，etc

特殊：
	位运算 Bitwise 布隆过滤器 BloomFilter
	LRU Cache
```



	### 算法

```
if-else、switch->branch
for,while loop->lteration
递归Recursion(Divide & Conquer,Backtrace)
搜素Search:深度优先搜索Depth first search 广度优先搜索Breadth first search,A*,etc
动态规划 Dynamic Programming
二分查找 Binary Search
贪心 Greedy
数学 Math 几何Geometry

```



==注意:在头脑中回忆上面每种算法的思想和代码模板==



### 位运算技巧

```
判断奇偶：
	X%2==1 --> (X&1) == 1
	X%2==0 --> (X&1) == 0
	
	X>>1 --> X/2
		即: X = X/2; --> X=X>>1;
		mid = (left+right)/2; --> mid = (left+right) >> 1;
		
	X=X&(X-1) 清零最低位的1
	
	X&-X=>得到最低为的1
	
	X&~X=>0
```



### 化繁为简的思想

``` 
1. 人肉递归低效、很累
2. 找到最近最简方法，将其拆解成可重复解决的问题
3. 数学归纳法思维
```

==本质：寻找重复性->计算机指令集==



### 学习要点

```
基本功时区别业余和职业选手的根本。身后功底来自于---过遍数
最大误区：只做一遍
五毒神掌
刻意练习--练习缺陷弱点地方、不舒服、枯燥
反馈--看题解、看国际版的高票回答
```



### 经典习题

```
爬楼梯、硬币兑换
括号匹配、括号生成、直方图最大面积、滑动窗口
二叉树遍历、分层输出树、判断二叉排序树
股票买卖、头房子、字符串编辑距离、最长上升子序列、最长公共子序列
异位词(判断和归类)、回文串（最大回文串）、regex和通配符匹配
高级数据结构（Trie、BlommFilter、LRU cache、 etc）
```







