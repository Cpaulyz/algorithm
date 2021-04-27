// https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
// Created by admin on 2021/4/27.
// 直接用了遍历搜索，可以AC，可以二分查找优化

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0;
        int maxW = -999999;
        for(int w:weights){
            sum+=w;
            maxW = max(w,maxW);
        }
        int n = (sum%D==0)?(sum/D):(sum/D+1);
        n = max(n,maxW);
        while(!helper(weights,D,n)){
            n++;
        }
        return n;
    }

    bool helper(vector<int>& weights, int D,int n){
        int sum = 0;
        int group = 1;
        for(int w:weights){
            sum+=w;
            if(sum>n){
                group++;
                if(group>D){
                    return false;
                }
                sum = w;
            }
        }
        return true;
    }
};