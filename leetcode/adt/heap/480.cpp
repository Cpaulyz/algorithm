// https://leetcode-cn.com/problems/sliding-window-median/
// Created by admin on 2021/2/3.
//

using namespace std;

#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <unordered_map>

class Windows {
private:
    // 大顶堆，存小一半的
    priority_queue<int, vector<int>, less<int>> big_heap;
    // 小顶堆，存大一半的
    priority_queue<int, vector<int>, greater<int>> small_heap;
    // 延迟删除
    unordered_map<int, int> delay_delete;
    // 总元素个数
    int n = 0;
    int small = 0;
    int big = 0;

    template<typename T>
    void clear_top(T &heap) {
        if(heap.empty()){
            return;
        }
        while (delay_delete[heap.top()] != 0) {
            delay_delete[heap.top()]--;
            heap.pop();
            if (heap.empty()) {
                break;
            }
        }
    }

    // 保证balance以后是平衡、且顶上元素是有效的
    void balance(){
        // 调整后需要满足 big==small 或者 big==small+1
        while (big>small+1){
            clear_top(big_heap);
            int tmp = big_heap.top();
            big_heap.pop();
            small_heap.push(tmp);
            big--;
            small++;
        }
        while (big<small){
            clear_top(small_heap);
            int tmp = small_heap.top();
            small_heap.pop();
            big_heap.push(tmp);
            big++;
            small--;
        }
        clear_top(small_heap);
        clear_top(big_heap);
    }

public:
    void insert(int num) {
        n++;
        if (big_heap.empty()||num <= big_heap.top()) { // 情况1：直接加在大顶堆
            big_heap.push(num);
            big++;
        } else { // 情况2：加在小顶堆
            small_heap.push(num);
            small++;
        }
        balance();
    }

    void remove(int num) {
        n--;
        delay_delete[num]++;
        if (num <= big_heap.top()) { // 情况1：大顶堆里删
            big--;
            if(big_heap.top()==num){
                delay_delete[num]--;
                big_heap.pop();
            }
        } else { // 情况2：小顶堆里删
            small--;
            if(small_heap.top()==num){
                delay_delete[num]--;
                small_heap.pop();
            }
        }
        balance();
    }

    double getMedian() {
        if(n%2==1){
            return big_heap.top();
        }else{
            return ((double)big_heap.top()+(double)small_heap.top())/2;
        }
    }

};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<double> res;
        Windows windows;
        int left=0,right=k;
        for (int i = 0; i < k; ++i) {
            windows.insert(nums[i]);
        }
        res.push_back(windows.getMedian());
        while (right<nums.size()){
            windows.remove(nums[left++]);
            windows.insert(nums[right++]);
            res.push_back(windows.getMedian());
        }
        return res;
    }
};

int main(){
    vector<int> v{7,8,8,3,8,1,5,3,5,4};
    Solution s;
    s.medianSlidingWindow(v,3);
}