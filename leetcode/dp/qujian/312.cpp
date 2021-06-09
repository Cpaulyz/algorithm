// https://leetcode-cn.com/problems/burst-balloons/solution/312-chuo-qi-qiu-dong-tai-gui-hua-by-jue-rg2cq/
// Created by admin on 2021/2/28.
// 区间dp

using namespace std;
#include <vector>
#include <iostream>
// 区间dp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // dp[i][j]表示(i,j)内被掏空时得分的最大值
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+2,0));
        vector<int> ns(nums.size()+2,1);
        for(int i=0;i<nums.size();++i){
            ns[i+1] = nums[i];
        }
        for(int n:ns){
            cout << n << " ";
        }
        cout << endl;
        for(int i=2;i<=nums.size()+1;++i){
            for(int j=0;j<=nums.size()+1-i;++j){
                for(int k=j+1;k<i+j;++k){
                    dp[j][i+j] = max(dp[j][i+j],dp[j][k]+dp[k][i+j]+ns[j]*ns[i+j]*ns[k]);
                }
                cout << j << "-"<<i+j << " : " << dp[j][i+j]<< endl;
            }
            cout << endl;
        }
        return dp[0][nums.size()+1];
    }
};
// 暴力方法。超时
//class Solution {
//public:
//    int maxCoins(vector<int>& nums) {
//        vector<int> used(nums.size());
//        return  dp(nums,used,nums.size());
//    }
//    int dp(vector<int>& nums,vector<int>& used,int last){
//        int maxCoin = 0;
//        if(last==1){
//            for (int i = 0; i < nums.size(); ++i) {
//                if(used[i]==0){
//                    return nums[i];
//                }
//            }
//        }
//        int pre = 1,nxt = 1;
//        for (int i = 0; i < nums.size(); ++i) {
//            if(used[i]==0){
//                nxt = 1;
//                for (int j = i+1; j < nums.size(); ++j) {
//                    if(used[j]==0){
//                        nxt = nums[j];
//                        break;
//                    }
//                }
//                used[i] = 1;
//                maxCoin = max(maxCoin,pre*nxt*nums[i]+dp(nums,used,last-1));
//                used[i] = 0;
//                pre = nums[i];
//            }
//        }
//        return maxCoin;
//    }
//};

int main(){
    Solution s;
    vector<int> v{3,1,5,8};
    s.maxCoins(v);
}