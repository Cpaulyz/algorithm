# 算法题

## 做题记录

* `/nowcoder`：https://www.nowcoder.com/ta/coding-interviews?page=1

* 数组
    * [643. 子数组最大平均数I](https://leetcode-cn.com/problems/maximum-average-subarray-i/)（2021/2/4 ）：滑动窗口
    
    * [888. 公平的糖果棒交换](https://leetcode-cn.com/problems/fair-candy-swap/)（2021/2/1）：哈希搜索
    
    * [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)（2021/2/1）：二分搜索
    
    * [1128. 等价多米诺骨牌对的数量](https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/)（2021/1/26）：哈希搜索
    
    * [1208. 尽可能使字符串相等](https://leetcode-cn.com/problems/get-equal-substrings-within-budget/)（2021/2/5）：滑动窗口
    
    * [1423. 可获得的最大点数](https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/)（2021/2/6）：滑动窗口
    
    * [665. 非递减数列](https://leetcode-cn.com/problems/non-decreasing-array/)（2021/2/7）：遍历+判断修改
    
    * [978. 最长湍流子数组](https://leetcode-cn.com/problems/longest-turbulent-subarray/)（2021/2/8）：滑动窗口 or DP
    
    * [992. K 个不同整数的子数组](https://leetcode-cn.com/problems/subarrays-with-k-different-integers/)（2021/2/9）：滑动窗口
    
    	* 自己的解法：992.cpp 思想：确定右边界，左边界尝试收缩后还原
    
    		时间按理来说是O(n<sup>2</sup>)，但运行速度极快，超过了100%
    
    	* [参考答案的解法](https://leetcode-cn.com/problems/subarrays-with-k-different-integers/solution/cong-zui-jian-dan-de-wen-ti-yi-bu-bu-tuo-7f4v/)：992_2.cpp 思想：恰好k个=最多k个-最多(k-1)个，这个思想很值得学习
    
    		时间O(n)，不如自己的解法
    	
    * [119. 杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)（2021/2/12）直接迭代计算
    
    * [448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)（2021/2/13）原地修改数组，取模
    
    * [561. 数组拆分 I](https://leetcode-cn.com/problems/array-partition-i/)（2021/2/16）排序，超简单
    
    * [566. 重塑矩阵](https://leetcode-cn.com/problems/reshape-the-matrix/)（2021/2/17）一维数组的多维表示法
    
    * [995. K 连续位的最小翻转次数](https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/)（2021/2/18）贪心+滑动窗口，**极好题**！
    
    	* 最初思想：贪心，操作原数组，结果超时（类似该[解题](https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/solution/hua-dong-chuang-kou-shi-ben-ti-zui-rong-z403l/)的方法一）
    	* 优化时间复杂度：滑动窗口，记录翻转次数，不真正做翻转，每位翻转会影响到后K位（类似该[解题](https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/solution/hua-dong-chuang-kou-shi-ben-ti-zui-rong-z403l/)的方法二）
    	* 优化空间复杂度：用原数组来记录翻转次数，不另外开数组（类似该[解题](https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/solution/k-lian-xu-wei-de-zui-xiao-fan-zhuan-ci-s-bikk/)的方法二）
    	
    * [1004. 最大连续1的个数 III](https://leetcode-cn.com/problems/max-consecutive-ones-iii/)（2021/2/19）滑动窗口+复用原数组优化空间复杂度
    
    * [697. 数组的度](https://leetcode-cn.com/problems/degree-of-an-array/)（2021/2/20）滑动窗口+哈希
    
    * [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)（2021/2/20）快排选择+随机选择pivot
    
    * [766. 托普利茨矩阵](https://leetcode-cn.com/problems/toeplitz-matrix/)（2021/2/22）遍历，大水题
    
    * [1052. 爱生气的书店老板](https://leetcode-cn.com/problems/grumpy-bookstore-owner/)（2021/2/23）固定长度的滑动窗口
    
    * [832. 翻转图像](https://leetcode-cn.com/problems/flipping-an-image/)（2021/2/24）直接遍历，大水题
    
    * [1178. 猜字谜](https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/)（2021/2/26）位操作+求子集，好题！已发博客[笔记](https://www.cnblogs.com/cpaulyz/p/14453452.html)
    
    * [395. 至少有 K 个重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)（2021/2/27）
    
    	* 解法一：滑动窗口，很复杂，[参考](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/xiang-jie-mei-ju-shuang-zhi-zhen-jie-fa-50ri1/)
    	* 解法二：分治 todo 
    	
    
* 链表

    * [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)（2021/3/1）使用**快慢双指针**，O(1)空间判断链表是否有环
    * [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)（2021/3/1）用两次快慢指针，O(1)空间，O(n)时间，重点在于用数学关系推出环长度
    * [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)（2021/3/1）快慢指针，把题目改成了142，但官方解答更好

* 并查集

    * [1631. 最小体力消耗路径](https://leetcode-cn.com/problems/path-with-minimum-effort/)（2021/1/29）我们可以将所有边按照长度进行排序并依次添加进并查集，直到左上角和右下角连通为止
    * [778. 水位上升的泳池中游泳](https://leetcode-cn.com/problems/swim-in-rising-water/)（2021/1/30）类似1631
    * [839. 相似字符串组](https://leetcode-cn.com/problems/similar-string-groups/)（2021/1/31）字符串+并查集
    * [765. 情侣牵手](https://leetcode-cn.com/problems/couples-holding-hands/)（2021/2/14）贪心算法，比较难理解，[参考答案](https://leetcode-cn.com/problems/couples-holding-hands/solution/liang-chong-100-de-jie-fa-bing-cha-ji-ta-26a6/)
    
* 字符串

    * [415. 字符串相加](https://leetcode-cn.com/problems/add-strings/)（2021/2/1）字符串高精度计算
    * [211. 添加与搜索单词 - 数据结构设计](https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/)（2021/2/1）字典树模板题
    * [424. 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)（2021/2/2）：滑动窗口模板题，两种解法，一种是窗口动态变化，一种是窗口单调增
    * [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)（2021/2/10）：滑动窗口
    * [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)（2021/2/20）滑动窗口
    * [208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)（2021/3/1）Trie字典树
    
* 数据结构

    * [480. 滑动窗口中位数](https://leetcode-cn.com/problems/sliding-window-median/)（2021/2/3）：双优先队列/双顶堆
    * [703. 数据流中的第 K 大元素](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/)（2021/2/11）双优先队列
    * [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)（2021/2/20）递归or迭代
    * [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)（2021/2/20）206的扩展题
    * [1438. 绝对差不超过限制的最长连续子数组](https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)（2021/2/21）滑动窗口+单调队列
    * [146. LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)（2021/2/23）哈希+双向链表
    * [303. 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)（2021/3/1）前缀和
    * [307. 区域和检索 - 数组可修改](https://leetcode-cn.com/problems/range-sum-query-mutable/)（2021/3/1）线段树，TODO
    * [304. 二维区域和检索 - 矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/)（2021/3/2）二维前缀和，303拓展题
    
* 贪心

    * [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)（2021/2/23）单调栈
        * [单调栈解法](https://leetcode-cn.com/problems/trapping-rain-water/)
        * [DP解法](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)
    * [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)（2021/2/28）贪心
    * [45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)（2021/2/28）如果使用dp，超时，使用贪心，每次都往下一次可达的最远的跳，解析见https://mp.weixin.qq.com/s/hMrwcLn01BpFzBlsvGE2oQ
	* [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)（2021/2/25）单调栈+哨兵
    
    * [85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)（2021/2/25）单调栈+哨兵，很有意思，复用84题的代码
    
* 动态规划

    * [931. 下降路径最小和](https://leetcode-cn.com/problems/minimum-falling-path-sum/)（2021/2/26）复用原数组dp
    * [338. 比特位计数](https://leetcode-cn.com/problems/counting-bits/)（2021/3/3）位运算+dp
    
* 树

    * [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)（2021/3/1）层次遍历
    * [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)（2020/12/20）递归构造
    * [106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)（2020/12/20）递归构造
    * [114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)（2020/12/20）递归，[参考](https://labuladong.gitee.io/algo/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%B3%BB%E5%88%971.html)
    * [116. 填充每个节点的下一个右侧节点指针](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)（2020/12/20）递归，[参考](https://labuladong.gitee.io/algo/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%B3%BB%E5%88%971.html)
    * [652. 寻找重复的子树](https://leetcode-cn.com/problems/find-duplicate-subtrees/)（2020/12/26）二叉树序列化
    * [654. 最大二叉树](https://leetcode-cn.com/problems/maximum-binary-tree/)（2020/12/26）递归构造树
    * [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)（2021/3/1）DFS
    * [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/)（2021/3/1）层次遍历，取右边第一个即可
    * BST待整理
    
* 图

    * [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)（2021/3/1）并查集，也可以BFS/DFS
    * [463. 岛屿的周长](https://leetcode-cn.com/problems/island-perimeter/)(2021/3/1) 遍历，也可以DFS、BFS
    * [695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)（2021/3/1）DFS
    * [827. 最大人工岛](https://leetcode-cn.com/problems/making-a-large-island/)（2021/3/3）做了两种解法
	* 笨方法，并查集+遍历
    	* DFS+记录
    
    > 在 LeetCode 中，「岛屿问题」是一个系列系列问题，BFS、DFS是统一的解决方法，但是也可以用不同的方法解决

### 岛屿系列问题

，比如：

[200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)：并查集解决

[463. 岛屿的周长](https://leetcode-cn.com/problems/island-perimeter/)：遍历解决

[695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)

[827. 最大人工岛](https://leetcode-cn.com/problems/making-a-large-island/)



## 模板

### 滑动窗口

```python
def findSubstring(s):
    N = len(s) # 数组/字符串长度
    left, right = 0, 0 # 双指针，表示当前遍历的区间[left, right]，闭区间
    counter = collections.Counter() # 用于统计 子数组/子区间 是否有效
    res = 0 # 保存最大的满足题目要求的 子数组/子串 长度
    while right < N: # 当右边的指针没有搜索到 数组/字符串 的结尾
        counter[s[right]] += 1 # 增加当前右边指针的数字/字符的计数
        while 区间[left, right]不符合题意：# 此时需要一直移动左指针，直至找到一个符合题意的区间
            counter[s[left]] -= 1 # 移动左指针前需要从counter中减少left位置字符的计数
            left += 1 # 真正的移动左指针，注意不能跟上面一行代码写反
        # 到 while 结束时，我们找到了一个符合题意要求的 子数组/子串
        res = max(res, right - left + 1) # 需要更新结果
        right += 1 # 移动右指针，去探索新的区间
    return res
```

