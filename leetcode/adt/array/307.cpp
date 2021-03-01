// https://leetcode-cn.com/problems/range-sum-query-mutable/
// Created by admin on 2021/3/1.
// 303 进阶题
// 多了个update方法，只需要更新index往后的preSum即可
// 超时，线段树解法看不懂

using namespace std;
#include <vector>
#include <unordered_map>

class NumArray {
private:
    vector<int> preSum;
    unordered_map<int,int> modify;
public:
    //  a+b+c+d  a+b c+d  a b c d
    NumArray(vector<int>& nums) {
        preSum.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            preSum.push_back(preSum.back()+nums[i]);
        }

    }

    void update(int index, int val) {
        int old = preSum[index+1] - preSum[index];
        int diff = val-old;
        modify[index] = diff;
    }

    int sumRange(int i, int j) {
        int tmp = preSum[j+1]-preSum[i];
        for(unordered_map<int,int>::iterator it = modify.begin();it!=modify.end();++it){
            if(i<=it->first&&j>=it->first){
                tmp += it->second;
            }
        }
        return tmp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */