// https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Created by admin on 2021/2/21.
// 目测又是滑动窗口秒杀
using namespace std;
#include <deque>
#include <vector>
#include <functional>
#include <unordered_map>
class MQ{
    // 大队列
    deque<int> big_queue;
    // 小队列
    deque<int> small_queue;
public:
    void add(int n){
        while ((!big_queue.empty())&&big_queue.back()<n){
            big_queue.pop_back();
        }
        big_queue.push_back(n);
        while ((!small_queue.empty())&&small_queue.back()>n){
            small_queue.pop_back();
        }
        small_queue.push_back(n);

    }
    int limit(){
        return big_queue.front()-small_queue.front();
    }
    void remove(int n){
        if(big_queue.front()==n){
            big_queue.pop_front();
        }
        if(small_queue.front()==n){
            small_queue.pop_front();
        }
    }

};
class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        MQ mq;
        int maxLen = 0;
        int left=0,right=0;
        while (right<nums.size()){
            mq.add(nums[right++]);
            while (mq.limit()>limit){
                mq.remove(nums[left++]);
            }
            maxLen = max(maxLen,right-left);
        }
        return maxLen;
    }
};