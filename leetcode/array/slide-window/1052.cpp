// https://leetcode-cn.com/problems/grumpy-bookstore-owner/
// Created by admin on 2021/2/23.
// 固定长度的滑动窗口，复用原数组

using namespace std;
#include <vector>

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0; // 本来的满意人数
        int loss = 0;
        int maxLoss; // 最多可以挽救的人数
        for(int i = 0;i<customers.size();++i){
            if(grumpy[i]==1){
                grumpy[i] = customers[i];
            }else{
                sum+=customers[i];
            }
        }
        int left = 0,right =X;
        for (int i = 0; i < customers.size(); ++i) {
            loss+=grumpy[i];
        }
        maxLoss = loss;
        while (right<grumpy.size()){
            loss+=grumpy[right++];
            loss-=grumpy[left++];
            maxLoss = max(maxLoss,loss);
        }
        return sum+maxLoss;
    }
};