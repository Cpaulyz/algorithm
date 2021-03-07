// https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/
// Created by admin on 2021/3/7.
// 回溯就完事了
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

bool cmp(int a,int b){
    return a<b;
}

class Solution {
    vector<int> group; // 每个组的和
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int target = 0;
        for(int num:nums){
            sum += num;
        }
        if(sum%k!=0){
            return false;
        }else{
            sort(nums.begin(),nums.end(),cmp);
            group = vector<int>(k);
            target = sum/k;
            return recall(nums,0,target);
        }
    }

    bool recall(vector<int>& nums,int index,int target){
        if(index==nums.size()){
            return true;
        }
        for (int i = 0; i < group.size(); ++i) {
            if(group[i]+nums[index]<=target){
                group[i] += nums[index];
                int tmp = recall(nums,index+1,target);
                group[i] -= nums[index];
                if(tmp){
                    return true;
                }
            }
        }
        return false;
    }
};