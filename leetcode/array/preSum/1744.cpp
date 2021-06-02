// https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
// Created by admin on 2021/6/1.
// 前缀和

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<long> prevSum(candiesCount.size()+1,0);
        for(int i=1;i<=candiesCount.size();++i){
            prevSum[i] = (long)prevSum[i-1]+(long)candiesCount[i-1];
        }
        // 第i天，最少吃i+1个，最多吃dailyCap*(i+1)个
        //
        for(auto q:queries){
            long minEat = q[1]+1;
            long maxEat = (long)(q[1]+1) * (long)q[2];
            if((minEat>prevSum[q[0]+1])||(maxEat<=prevSum[q[0]])){
                res.push_back(false);
            }else{
                res.push_back(true);
            }
        }
        return res;

    }
};