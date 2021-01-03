# 学习笔记WEEK9



## 动态规划复习

### 递归 - 自己调用自己

```java
public void recur (int level, int param) {
    // 终止条件
    if (levle > MAX_LEVEL) {
        return;
    }
    
    // 处理当前层
    process(level, param);
    
    // 沉浸到下一层
    recur(level:level+1, newParam);
    
    // 恢复当前层
}
```



### 分治

```python
def divide_conquer(problem, param1, param2, ...):
    # recursion terminator 递归终止条件
    if problem is None:
        print_result
        return
   
    # prepare data 准备数据和拆分问题
    data = prepare_data(problem)
    subproblems = split_problem(problem, data)
    
    #conquer subproblems 每一个子问题都调用分治函数求解
    subresult1 = self.divide_conquer(subproblems[0], p1, ...)
    subresult2 = self.divide_conquer(subproblems[1], p1, ...)
    subresult3 = self.divide_conquer(subproblems[2], p1, ...)
    ...
    
    # process and generate the final result 合并子问题
    result = process_result(subresult1, subresult2, subresult3)
    
    #revert the current level states
```



### 感触

1.  人肉递归低效、很累
2.  找到最近(最大公约数的意思)最简方法，将其拆解成可重复解决的问题
3.  数学归纳法思维



### 斐波拉契问题

f(6) = f(5)+f(4)

f(5)=f(4)+f(3)

....

重复计算的很多

分治加记忆化缓存，相当于从分治过度到动态规划



### 动态规划

1.  将复杂问题分解称为各个简单的子问题
2.  分治+最优子结果
3.  顺推形式：动态递推(一般递推的代码最简)



**DP顺推模板**

```python
function DP():
    dp = [][] # 二维情况
    
    for i=0...M:
        for j=0...N:
            dp[i][j] = _Function(dp[i`][j`]...)

	return dp[M][N];
```

模板不复杂，复杂在 dp的定义和状态转移方程的定义



走格子问题

爬楼梯问题

股票买卖问题



### 高级动态规划

复杂度来源:

1.  状态拥有更多维度(二维、三维、或者更多、甚至需要压缩)
2.  状态方程更加复杂



爬楼梯进阶版问题，相邻两次的步伐不能相同

单词1转换到单词2问题



## 字符串

python 和 java 中string是不可变的

c/c++是可变的



## 匹配算法



### 1.暴力法

​	后面两个算法都是基于暴力法之上优化

### 2. Rabin-Karp 算法

​	在朴素算法中，我们需要挨个比较所有字符，才知道目标字符串中是否包含字串。那么，是否有别的方法可以用来判断目标字符串是否包含字串呢?

​	答案是肯定的，确实存在一种更快的方法。为了避免挨个字符对目标字符串和字串进行比较，我们可以尝试一次性判断两者是否相等。因此，我们需要一个好的哈希函数(hash function)。通过哈希函数，我们可以算出字串的哈希值，然后将它和目标字符串中的字串的哈希值进行比较。这个新方法在速度比暴力法有显著提升。

```
思想：
	1. 假设子串的长度为M（pat）,目标字符串的长度为N（txt）
	2. 计算字串的hash值 hash_pat
	3. 计算目标字符串txt中每个长度为M的字串的hash值 (共需要计算N-M+1次)
	4. 比较hash值:如果hash值不同，字符串必然不匹配；如果hash值相同，还需要使用朴素算法再次判断
	
	hash计算的一种方式 :
	public final static int D = 256;	// 256 进制 字符是0~256
	public final static int Q = 9997;	// 最好是素数
	for (i = 0; i < M; i++) {
		patHash = (D * patHash + pat.charAt(i)) % Q;	
	}
	
	判断hash不同之后，像滑动窗口一样，先去掉最高位权重的hash值，然后加上进来的字符的哈希值
	for (i=0; i<M-1; i++) {
		highestPow = (highestPow * D) % Q;
	}
	
	
	txtHash = (D * (txtHash - txt.charAt(i) * highestPow) + txt.charAt(i+M)) % Q;
	if (txtHash < Q)
		txtHash += Q;
	
```





### 3.KMP算法

​	对比S是否是是T的字串问题中

​	在匹配之前可以预先判断

​	1. 比如: hash(text.substring(i, M)) == hash(pat) 子串和长串的hash值是否一样

	2. KMP （用来找已经匹配的这个片段的最大的前缀和最大的后缀最长有多长这么一个概念）



```
思想：
	当子串与目标字符串不匹配时，其实你已经知道了前面已经匹配成功那一部分的字符串(包括字串与目标字符串)。 设法利用这个已知信息，不要把"搜索位置"移回已经比较过的位置，继续把它向后移，这样就提高了效率。
	
	比如比较
	-->	ABCDAB ABCDABCDABDE
		ABCDABD
		
	--> ABCDAB ABCDABCDABDE
			ABCDABD
	
```





