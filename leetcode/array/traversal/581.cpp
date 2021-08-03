// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
// Created by admin on 2021/8/3.
// 双向遍历

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 维护一个最小和最大
        int minVal = nums[nums.size()-1];
        int maxVal = nums[0];
        int start=-1,end=-1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]<maxVal){
                end = i;
            }else{
                maxVal = nums[i];
            }
        }
        for(int i=nums.size()-2;i>=0;--i){
            if(nums[i]>minVal){
                start = i;
            }else{
                minVal = nums[i];
            }
        }
        // cout << start << " "<<end << endl;
        return start==-1?0:end-start+1;
    }
};