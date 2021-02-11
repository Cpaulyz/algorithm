// https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
// Created by admin on 2021/2/11.
// 双优先队列，参考480

using namespace std;

#include <string>
#include <algorithm>
#include <queue>
#include <vector>
class KthLargest {

private:
    // 大顶堆，存小一半的
    priority_queue<int, vector<int>, less<int>> big_heap;
    // 小顶堆，存大一半的
    priority_queue<int, vector<int>, greater<int>> small_heap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k =k;
        for (int num:nums){
            add(num);
        }
    }

    int add(int val) {
        if(small_heap.size()<k){
            small_heap.push(val);
        }else{
            if(val>small_heap.top()){
                int tmp = small_heap.top();
                small_heap.pop();
                small_heap.push(val);
                big_heap.push(tmp);
            }else{
                big_heap.push(val);
            }
        }
        return small_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */