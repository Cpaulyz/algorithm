// https://leetcode-cn.com/problems/smallest-k-lcci/
// Created by 陈彦泽 on 2021/9/3.
// 堆


using namespace std;

#include <string>
#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(k==0){
            return vector<int>();
        }
        priority_queue<int,vector<int>,less<int>> heap;
        for(int n:arr){
            if(heap.size()<k){
                heap.push(n);
            }else if(n<heap.top()){
                heap.push(n);
                heap.pop();
            }
        }
        vector<int> res;
        while(!heap.empty()){
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v{1,3,5,7,2,4,6,8};
    s.smallestK(v,0);
}