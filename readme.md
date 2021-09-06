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

    * [54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)（2021/3/6）遍历，没啥好说的

    * [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)（2021/3/6）边界条件十分恶心的二分查找

    * [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)（2021/3/12）遍历

    * [11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)（2021/3/12）双指针，两边往中间走

    	* 移动矮的指针

    		因为如果移动高指针，那么面积一定变小

    * [59. 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)（2021/3/16）模拟循环

    * [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)（2021/3/16）双指针解法，左右往中间缩，总是移动较矮的指针

    * [73. 矩阵置零](https://leetcode-cn.com/problems/set-matrix-zeroes/)（2021/3/21）复用原数组

    * [41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)（2021/3/21）原数组置换，练习降低空间、时间复杂度的好题！

    * [48. 旋转图像](https://leetcode-cn.com/problems/rotate-image/)（2021/3/22）变着花样遍历

    * [74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)（2021/3/30）两次二分查找

    * [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)（2021/4/5）逆序遍历

    * [80. 删除有序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)（2021/4/6）快慢双指针

    * [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)（2021/4/8）二分查找变种

    * [81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)（2021/4/8）麻烦的二分查找

    * [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)（2021/4/9）二分查找变式

    * [220. 存在重复元素 III](https://leetcode-cn.com/problems/contains-duplicate-iii/)（2021/4/17）滑动窗口，精髓在于桶排序，极妙！

    * [26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)（2021/4/18）快慢双指针

    * [27. 移除元素](https://leetcode-cn.com/problems/remove-element/)（2021/4/20）快慢双指针

    * [363. 矩形区域不超过 K 的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)（2021/4/22）固定左右区间，以区间内的rowSum，计算最大小于k的连续和

    * [1011. 在 D 天内送达包裹的能力](https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/)（2021/4/27）直接用了遍历搜索，可以AC，可以二分查找优化

    * [633. 平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/)（2021/4/29）

    	* 暴力sqrt
    	* [双指针](https://leetcode-cn.com/problems/sum-of-square-numbers/solution/shuang-zhi-zhen-de-ben-zhi-er-wei-ju-zhe-ebn3/)
    	
    * [690. 员工的重要性](https://leetcode-cn.com/problems/employee-importance/)（2021/5/4）BFS

    * [554. 砖墙](https://leetcode-cn.com/problems/brick-wall/)（2021/5/4）哈希表，时空O(mn)

    * [1074. 元素和为目标值的子矩阵数量](https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target/)（2021/5/29）前缀和+哈希表，用边限制，可参考363，好题！！

    * [1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？](https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/)(2021/6/1)前缀和

    * [523. 连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/)（2021/6/2）前缀和+哈希表

    * [278. 第一个错误的版本](https://leetcode-cn.com/problems/first-bad-version/)（2021/6/13）二分查找

    * [149. 直线上最多的点数](https://leetcode-cn.com/problems/max-points-on-a-line/)（2021/6/24）gcd+哈希表

    * [1833. 雪糕的最大数量](https://leetcode-cn.com/problems/maximum-ice-cream-bars/)（2021/7/2）排序就完事了

    * [451. 根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency/)（2021/7/3）排序

    * [645. 错误的集合](https://leetcode-cn.com/problems/set-mismatch/)（2021/7/4）普普通通的哈希

    * [1418. 点菜展示表](https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/)（2021/7/6）一顿哈希+排序模拟

    * [1711. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)（2021/7/7）很暴力，哈希搜索

    * [930. 和相同的二元子数组](https://leetcode-cn.com/problems/binary-subarrays-with-sum/)(2021/7/8)前缀和+哈希表

    * [274. H 指数](https://leetcode-cn.com/problems/h-index/)（2021/7/11）排序，可以用计数排序优化

    * [1846. 减小和重新排列数组后的最大元素](https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging/)（2021/7/15）排序+贪心

    * [剑指 Offer 53 - I. 在排序数组中查找数字 I](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)（2021/7/16）二分

    * [剑指 Offer 42. 连续子数组的最大和](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/)（2021/7/17）遍历+前缀和

    * [275. H 指数 II](https://leetcode-cn.com/problems/h-index-ii/)（2021/7/17）查找。。二分优化

    * [1838. 最高频元素的频数](https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/)(2021/7/19)滑动窗口

    * [1893. 检查是否区域内所有整数都被覆盖](https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered/)（2021/7/23）暴力哈希

    * [1743. 从相邻元素对还原数组](https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/)（2021/7/25）哈希链表

    * [581. 最短无序连续子数组](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)（2021/8/3）双向遍历

    * [611. 有效三角形的个数](https://leetcode-cn.com/problems/valid-triangle-number/)（2021/8/5）排序+双指针

    * [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/)（2021/8/10）一次遍历的计数dp

    * [1646. 获取生成数组中的最大值](https://leetcode-cn.com/problems/get-maximum-in-generated-array/)（2021/8/23）遍历模拟

    * [528. 按权重随机选择](https://leetcode-cn.com/problems/random-pick-with-weight/)（2021/8/30）其实用的是表驱动的思想，在实现上是前缀和+二分查找，涉及到随机数生成和二分查找轮子

    * [704. 二分查找](https://leetcode-cn.com/problems/binary-search/)（2021/9/6）二分模板题

* 链表

    * [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)（2021/3/1）使用**快慢双指针**，O(1)空间判断链表是否有环
    * [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)（2021/3/1）用两次快慢指针，O(1)空间，O(n)时间，重点在于用数学关系推出环长度
    * [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)（2021/3/1）快慢指针，把题目改成了142，但官方解答更好
    * [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)（2021/3/6）n个指针+优先队列，重点在于**优先队列自定义比较函数**
    * [82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)（2021/3/25）判断nullptr比较多
    * [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)（2021/3/26）上面一题的简化版
    * [61. 旋转链表](https://leetcode-cn.com/problems/rotate-list/)（2021/3/28）1.5次遍历
    * [203. 移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/)（2021/6/5）遍历即可
    * [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)（2021/7/22）加个哈希表就完事了
    * [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)（2021/9/2）快慢双指针

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
    * [395. 至少有 K 个重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)（2021/2/27）
    	* 解法一：滑动窗口，很复杂，[参考](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/xiang-jie-mei-ju-shuang-zhi-zhen-jie-fa-50ri1/)
    	* 解法二：分治 todo 
    * [165. 比较版本号](https://leetcode-cn.com/problems/compare-version-numbers/)（2021/3/8）直接遍历就完事了
    * [1047. 删除字符串中的所有相邻重复项](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/)（2021/3/9）栈操作
    * [224. 基本计算器](https://leetcode-cn.com/problems/basic-calculator/)（2021/3/10）双栈
    * [227. 基本计算器 II](https://leetcode-cn.com/problems/basic-calculator-ii/)（2021/3/11）哨兵+双栈
    * [6. Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/)（2021/3/12）找规律遍历
    * [150. 逆波兰表达式求值](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)（2021/3/21）栈
    * [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)（2021/3/21）回溯
    * [12. 整数转罗马数字](https://leetcode-cn.com/problems/integer-to-roman/)（2021/5/14）难度不大
    * [13. 罗马数字转整数](https://leetcode-cn.com/problems/roman-to-integer/)（2021/5/15）循环判断即可
    * [1190. 反转每对括号间的子串](https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/)（2021/5/26）括号处理+模拟
    * [剑指 Offer 38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)（2021/6/22）全排列、回溯
    * [726. 原子的数量](https://leetcode-cn.com/problems/number-of-atoms/)（2021/7/5）栈+哈希表
    * [面试题 10.02. 变位词组](https://leetcode-cn.com/problems/group-anagrams-lcci/)（2021/7/18）计数排序
    * [551. 学生出勤记录 I](https://leetcode-cn.com/problems/student-attendance-record-i/)（2021/8/17）简单遍历即可
    * [345. 反转字符串中的元音字母](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)（2021/8/19）原地修改，双指针双向遍历
    * [443. 压缩字符串](https://leetcode-cn.com/problems/string-compression/)（2021/8/21）快慢双指针
    * [165. 比较版本号](https://leetcode-cn.com/problems/compare-version-numbers/)（2021/9/1）遍历比较
    
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
    * [232. 用栈实现队列](https://leetcode-cn.com/problems/implement-queue-using-stacks/)（2021/3/5）分批导栈
    * [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)（2021/3/13）和正常的反转链表差不多
    * [341. 扁平化嵌套列表迭代器](https://leetcode-cn.com/problems/flatten-nested-list-iterator/)（2021/3/23）DFS
    * [173. 二叉搜索树迭代器](https://leetcode-cn.com/problems/binary-search-tree-iterator/)（2021/3/28）
    	* 方法一：直接中序遍历，保存数组，扁平化处理
    	* 方法二：二叉树中序遍历迭代版
    * [692. 前K个高频单词](https://leetcode-cn.com/problems/top-k-frequent-words/)（2021/5/20）哈希+优先队列，**自定义比较函数**
    * [981. 基于时间的键值存储](https://leetcode-cn.com/problems/time-based-key-value-store/)（2021/7/10）哈希套数组+二分查找
    * [295. 数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/)（2021/8/27）双优先队列
    * [面试题 17.14. 最小K个数](https://leetcode-cn.com/problems/smallest-k-lcci/)（2021/9/3）堆
    
* 贪心

    * [42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)（2021/2/23）单调栈
        * [单调栈解法](https://leetcode-cn.com/problems/trapping-rain-water/)
        * [DP解法](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)
        * [双指针解法（极好！）](https://leetcode-cn.com/problems/volume-of-histogram-lcci/solution/shuang-zhi-zhen-an-xing-qiu-jie-xiang-xi-d162/)
    * [55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)（2021/2/28）贪心
	* [45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)（2021/2/28）如果使用dp，超时，使用贪心，每次都往下一次可达的最远的跳，解析见https://mp.weixin.qq.com/s/hMrwcLn01BpFzBlsvGE2oQ
    * [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)（2021/2/25）单调栈+哨兵
    * [85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)（2021/2/25）单调栈+哨兵，很有意思，复用84题的代码
    * [503. 下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/)（2021/3/6）单调栈+两轮循环
    * [456. 132 模式](https://leetcode-cn.com/problems/132-pattern/)（2021/3/25）单调栈，有点难，注意理解！！！
        * [881. 救生艇](https://leetcode-cn.com/problems/boats-to-save-people/)（2021/8/26）排序+双指针+贪心
    
* 动态规划

    * [931. 下降路径最小和](https://leetcode-cn.com/problems/minimum-falling-path-sum/)（2021/2/26）复用原数组dp
    * [338. 比特位计数](https://leetcode-cn.com/problems/counting-bits/)（2021/3/3）位运算+dp
    * [354. 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)（2021/3/4）dp，自己实现了O(n2)的算法
    	* 标答：[O(nlogn)解法](https://leetcode-cn.com/problems/russian-doll-envelopes/solution/zui-chang-di-zeng-zi-xu-lie-kuo-zhan-dao-er-wei-er/)十分巧妙，写的时候想到了另外一道题，但没想到可以这样改
    * [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)（2021/3/5）354题的简单版，dp+二分查找，难点在于二分查找
    * [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)（2021/3/6）dp
    * [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)（2021/3/7）dp，但其实有更好的中心扩展解法
    * [[字节2019编程题-5]毕业旅行问题](https://www.nowcoder.com/questionTerminal/3d1adf0f16474c90b27a9954b71d125d)（2021/3/8）尝试使用回溯，超时。应该使用dp，极难！！！！[参考](https://blog.csdn.net/weixin_42490152/article/details/100105019)
    * [879. 盈利计划](https://leetcode-cn.com/problems/profitable-schemes/)（2021/3/11）阿里笔试题，DP 01背包升级版，不会写
    * [115. 不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)（2021/3/17）dp
    * [781. 森林中的兔子](https://leetcode-cn.com/problems/rabbits-in-forest/)（2021/4/4）贪心。据说是华为3.31笔试题。
    * [264. 丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/)（2021/4/11）三指针dp
    * [87. 扰乱字符串](https://leetcode-cn.com/problems/scramble-string/)（2021/4/16）三维dp
    * [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)（2021/4/21）普普通通的dp
    * [368. 最大整除子集](https://leetcode-cn.com/problems/largest-divisible-subset/)（2021/4/23）排序dp，自己写出了最优解！！ 时间O(n2) 空间O(n)
    * [403. 青蛙过河](https://leetcode-cn.com/problems/frog-jump/)（2021/4/29）hard；dp，时空O(n2)，`dp[i][j]`表示可以从`stones[j]`跳到`stones[i]`
    * [740. 删除并获得点数](https://leetcode-cn.com/problems/delete-and-earn/)（2021/5/6）动态规划 `dp[i][j] `表示选择0..i里面,j=1代表选i,j=0代表不选j
    * [1269. 停在原地的方案数](https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/)（2021/5/14）轻松拿下hard！
    * [1035. 不相交的线](https://leetcode-cn.com/problems/uncrossed-lines/)（2021/5/21）`dp[i][j] `表示 num1[0:i],num2[0:j]中的最大连线数。迁移函数需要画图理解，算是好题！
    * [664. 奇怪的打印机](https://leetcode-cn.com/problems/strange-printer/)（2021/5/24）区间dp，转移函数不好想
    * [1787. 使所有区间的异或结果为零](https://leetcode-cn.com/problems/make-the-xor-of-all-segments-equal-to-zero/)(2021/5/25) dp异或，难
    * [968. 监控二叉树](https://leetcode-cn.com/problems/binary-tree-cameras/)（2021/6/3）树形dp，用记忆化搜索，否则会超时
    * [474. 一和零](https://leetcode-cn.com/problems/ones-and-zeroes/)（2021/6/6）三维dp的背包问题
    * [494. 目标和](https://leetcode-cn.com/problems/target-sum/)（2021/6/7）dp，类似背包问题
    * [1049. 最后一块石头的重量 II](https://leetcode-cn.com/problems/last-stone-weight-ii/)（2021/6/8）背包问题dp，难在问题转换
    * [879. 盈利计划](https://leetcode-cn.com/problems/profitable-schemes/)（2021/6/9）三维的背包问题，现在会写了
    * [312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)（2021/6/9）区间dp
    * [877. 石子游戏](https://leetcode-cn.com/problems/stone-game/)（2021/6/16）区间dp..没想到答案可以直接return true
    * [1713. 得到子序列的最少操作次数](https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/)（2021/7/26）先转为最长公共子序列问题，再转为最长上升子序列问题，十分有意思！
    * [313. 超级丑数](https://leetcode-cn.com/problems/super-ugly-number/)（2021/8/9）多路合并dp
    * [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/)（2021/8/11）`dp[i][j]` 表示以第i个结尾，差为j的等差个数
    * [516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)（2021/8/12）子序列问题dp
    * [576. 出界的路径数](https://leetcode-cn.com/problems/out-of-boundary-paths/)（2021/8/15）Dp+空间优化
    * [552. 学生出勤记录 II](https://leetcode-cn.com/problems/student-attendance-record-ii/)（2021/8/18）Dp+空间优化
    
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
    * [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)（2021/3/5）DFS
    * [331. 验证二叉树的前序序列化](https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/)（2021/3/12）反向遍历+栈+状态压缩
    * BST待整理
    * [783. 二叉搜索树节点最小距离](https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/)（2021/4/14）中序遍历
    * [938. 二叉搜索树的范围和](https://leetcode-cn.com/problems/range-sum-of-bst/)（2021/4/27）中序+剪枝
    * [872. 叶子相似的树](https://leetcode-cn.com/problems/leaf-similar-trees/)(2021/5/10)顺序找叶子节点，dfs
    * [993. 二叉树的堂兄弟节点](https://leetcode-cn.com/problems/cousins-in-binary-tree/)（2021/5/17）BFS
    * [1600. 皇位继承顺序](https://leetcode-cn.com/problems/throne-inheritance/)（2021/6/23）n叉树+前序遍历
    * [671. 二叉树中第二小的节点](https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/)（2021/7/27）DFS
    * [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/)（2021/7/29）DFS建图，BFS搜索
    * [1104. 二叉树寻路](https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/)（2021/7/29）数学
    * [987. 二叉树的垂序遍历](https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/)（2021/7/31）DFS建表，排序
    
* 图

    * [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)（2021/3/1）并查集，也可以BFS/DFS
    * [463. 岛屿的周长](https://leetcode-cn.com/problems/island-perimeter/)(2021/3/1) 遍历，也可以DFS、BFS
    * [695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)（2021/3/1）DFS
    * [827. 最大人工岛](https://leetcode-cn.com/problems/making-a-large-island/)（2021/3/3）做了两种解法
    	* 笨方法，并查集+遍历
    	* DFS+记录
    * [815. 公交路线](https://leetcode-cn.com/problems/bus-routes/)（2021/3/7）BFS
    * [752. 打开转盘锁](https://leetcode-cn.com/problems/open-the-lock/)（2021/6/25）双向BFS
    * [773. 滑动谜题](https://leetcode-cn.com/problems/sliding-puzzle/)（2021/6/26）BFS，还没752难
    * [909. 蛇梯棋](https://leetcode-cn.com/problems/snakes-and-ladders/)（2021/6/27）BFS，在gone上面踩坑踩了好久。。
    * [815. 公交路线](https://leetcode-cn.com/problems/bus-routes/)（2021/6/28）二刷，双向BFS+两个map优化
    * [LCP 07. 传递信息](https://leetcode-cn.com/problems/chuan-di-xin-xi/)（2021/7/1）水水的bfs
    * [743. 网络延迟时间](https://leetcode-cn.com/problems/network-delay-time/)（2021/8/3）dijkstra
    * [802. 找到最终的安全状态](https://leetcode-cn.com/problems/find-eventual-safe-states/)（2021/8/5）拓扑排序，此外还有[三色标记法](https://leetcode-cn.com/problems/find-eventual-safe-states/solution/zhao-dao-zui-zhong-de-an-quan-zhuang-tai-yzfz/)，好题！！
    * [847. 访问所有节点的最短路径](https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes/)（2021/8/6）难！状态压缩+BFS，状态压缩很难想
    * [789. 逃脱阻碍者](https://leetcode-cn.com/problems/escape-the-ghosts/)（2021/8/22）曼哈顿距离
    * [797. 所有可能的路径](https://leetcode-cn.com/problems/all-paths-from-source-to-target/)（2021/8/25）DFS暴力搜索

    > 在 LeetCode 中，「岛屿问题」是一个系列系列问题，BFS、DFS是统一的解决方法，但是也可以用不同的方法解决

* 回溯
	* [46. 全排列](https://leetcode-cn.com/problems/permutations/)（2021/3/6）基本回溯
	* [51. N 皇后](https://leetcode-cn.com/problems/n-queens/)（2021/3/7）十分经典是回溯算法模板
	* [698. 划分为k个相等的子集](https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/)（2021/3/7）暴力回溯，技巧是在回溯前进行排序
	* [131. 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)（2021/3/7）经典回溯，判断回文部分可以用dp优化
	* [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)（2021/3/22）排序+回溯，因为原数组有重复，需要排序后判断是否可进入回溯
	* [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)（2021/3/31）回溯，重点在于去重
	* [526. 优美的排列](https://leetcode-cn.com/problems/beautiful-arrangement/)（2021/8/16）观察到题目给的范围比较小（15），直接暴力回溯即可
	
* 位运算

    * [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)（2021/3/22）
    
* 数学

    * [263. 丑数](https://leetcode-cn.com/problems/ugly-number/)（2021/4/11）数学题，分解质因数
    * [264. 丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/)（2021/4/11）[参考](https://leetcode-cn.com/problems/ugly-number-ii/solution/chou-shu-ii-by-leetcode-solution-uoqd/)
        * 解法一：三指针dp（非常妙！！！）
        * 解法二：堆
    * [179. 最大数](https://leetcode-cn.com/problems/largest-number/)（2021/4/12）难点在于排序，要求两个整数 x,y 如何拼接得到结果更大时，就想到先转字符串，然后比较 x+y 和 y+x
    * [1720. 解码异或后的数组](https://leetcode-cn.com/problems/decode-xored-array/)（2021/5/6）遍历异或，简单
    * [1486. 数组异或操作](https://leetcode-cn.com/problems/xor-operation-in-an-array/)（2021/5/7）无脑遍历，简单
    * [1734. 解码异或后的排列](https://leetcode-cn.com/problems/decode-xored-permutation/)（2021/5/11）根据奇数条件，异或得到一个数，然后就很简单了
    * [1310. 子数组异或查询](https://leetcode-cn.com/problems/xor-queries-of-a-subarray/)（2021/5/12）记忆化搜索
    * [1442. 形成两个异或相等数组的三元组数目](https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)（2021/5/18）根据奇数条件，异或得到一个数，然后就很简单了
    * [1738. 找出第 K 大的异或坐标值](https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/)（2021/5/19）前缀异或+优先队列
    * [810. 黑板异或游戏](https://leetcode-cn.com/problems/chalkboard-xor-game/)（2021/5/22）硬模拟，但更好的解法是[数学归纳](https://leetcode-cn.com/problems/chalkboard-xor-game/solution/hei-ban-yi-huo-you-xi-by-leetcode-soluti-eb0c/)
    * [1707. 与数组中元素的最大异或值](https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/)(2021/5/23)hard，字典树+懒加载思想
    * [461. 汉明距离](https://leetcode-cn.com/problems/hamming-distance/)（2021/5/27）异或遍历，水题
    * [477. 汉明距离总和](https://leetcode-cn.com/problems/total-hamming-distance/)（2021/5/29）位运算，标答用了乘法原理更好
    * [65. 有效数字](https://leetcode-cn.com/problems/valid-number/)（2021/6/17）编译原理的状态机
    * [剑指 Offer 15. 二进制中1的个数](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)（2021/6/23）位运算，O(1的个数)
    * [401. 二进制手表](https://leetcode-cn.com/problems/binary-watch/)（2021/6/23）本质上就是算1
    * [168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)（2021/6/29）1开始的26进制
    * [470. 用 Rand7() 实现 Rand10()](https://leetcode-cn.com/problems/implement-rand10-using-rand7/)（2021/9/6）7进制

### 岛屿系列问题

，比如：

[200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)：并查集解决

[463. 岛屿的周长](https://leetcode-cn.com/problems/island-perimeter/)：遍历解决

[695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)

[827. 最大人工岛](https://leetcode-cn.com/problems/making-a-large-island/)

### 二分查找

[35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)

[300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

难度简单837

分析题意，挖掘题目中隐含的 单调性；

* `while (left < right) `退出循环的时候有` left == right` 成立，因此无需考虑返回 left 还是 right；
* 始终思考下一轮搜索区间是什么，如果是` [mid, right] `就对应 `left = mid `，如果是` [left, mid - 1] `就对应` right = mid - 1`，是保留 mid 还是 +1+1、-1−1 就在这样的思考中完成；
* 从一个元素什么时候不是解开始考虑下一轮搜索区间是什么 ，把区间分为 22 个部分（一个部分肯定不存在目标元素，另一个部分有可能存在目标元素），问题会变得简单很多，这是一条 非常有用 的经验；
* 每一轮区间被划分成 2 部分，理解 区间划分 决定中间数取法（ 无需记忆，需要练习 + 理解 ），在调试的过程中理解 区间和中间数划分的配对关系：
	* 划分` [left, mid]` 与` [mid + 1, right] `，mid 被分到左边，对应 `int mid = left + (right - left) / 2;`；
	* 划分` [left, mid - 1] `与` [mid, right]` ，mid 被分到右边，对应` int mid = left + (right - left + 1) / 2;`。

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

### 二分

https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/yi-wen-dai-ni-gao-ding-er-fen-cha-zhao-j-00kj/

## TODO

https://leetcode-cn.com/problems/implement-strstr/ KMP

[1473. 粉刷房子 III](https://leetcode-cn.com/problems/paint-house-iii/)