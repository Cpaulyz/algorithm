// https://leetcode-cn.com/problems/total-hamming-distance/
// Created by admin on 2021/5/29.
// 普通的位运算

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> one(32,0);
        vector<int> zero(32,0);
        int res = 0;
        for(int n:nums){
            // add
            for(int i=0;i<32;++i){
                int ptr = (n&(1<<i))==0?0:1;
                if(ptr==0){
                    zero[i]++;
                    res += one[i];
                }else{
                    one[i]++;
                    res += zero[i];
                }
            }
        }
        return res;
    }
};