// https://leetcode-cn.com/problems/continuous-subarray-sum/
// Created by admin on 2021/6/2.
// 前缀和+哈希表

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> preSum(nums.size()+1,0);
        unordered_map<int,int> map;
        for(int i=1;i<=nums.size();++i){
            preSum[i] = (preSum[i-1] + nums[i-1])%k;
            if(preSum[i]==0 && i>=2){
                return true;
            }else if(map[preSum[i]]==0){
                map[preSum[i]] = i;
            }else if(i-map[preSum[i]]>=2){
                return true;
            }
            // cout << i << ":" << preSum[i] << endl;
        }
        return false;
    }
};