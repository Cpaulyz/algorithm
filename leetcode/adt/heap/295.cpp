// https://leetcode-cn.com/problems/find-median-from-data-stream/
// Created by 陈彦泽 on 2021/8/27.
// 双堆

using namespace std;

#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

class MedianFinder {
private:
    // 大顶堆，存小一半的
    priority_queue<int, vector<int>, less<int>> big_heap;
    // 小顶堆，存大一半的
    priority_queue<int, vector<int>, greater<int>> small_heap;
    // 保证大顶堆堆数量 <= 小顶堆的数量
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if(small_heap.empty()){
            small_heap.push(num);
        }else if(big_heap.empty()){
            if(num<small_heap.top()){
                big_heap.push(num);
            }else{
                small_heap.push(num);
                big_heap.push(small_heap.top());
                small_heap.pop();
            }
        }else{
            if(num>big_heap.top()){
                small_heap.push(num);
            }else{
                big_heap.push(num);
            }
            if(small_heap.size()>1+big_heap.size()){
                big_heap.push(small_heap.top());
                small_heap.pop();
            }else if(big_heap.size()>small_heap.size()){
                small_heap.push(big_heap.top());
                big_heap.pop();
            }
        }
    }

    double findMedian() {
        if(small_heap.size()==big_heap.size()){
            return (small_heap.top()+big_heap.top())/2.0;
        }else{
            return small_heap.top();
        }
    }
};

int main(){
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */