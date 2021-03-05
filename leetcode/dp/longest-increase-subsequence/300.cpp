// https://leetcode-cn.com/problems/longest-increasing-subsequence/
// Created by admin on 2021/3/4.
// 354题的简单版，dp+二分查找，难点在于二分查找
using namespace std;
#include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(1,-9999); // 第i位表示长度为i的最小末位
        for (int num:nums){
            int index = findLongestLessIndexQ(dp,num);
            if(index==dp.size()){
                dp.push_back(num);
            }else{
                dp[index] = min(dp[index],num);
            }
        }
        return dp.size()-1;
    }

    int findLongestLessIndex(vector<int>& dp,int n){
        int index = 0;
        for (index = 0; index < dp.size(); ++index) {
            if(dp[index]>=n){
                break;
            }
        }
        return index;
    }

    // 改进：二分查找，找最小的大于的下标，难点在这里！
    int findLongestLessIndexQ(vector<int>& dp,int n){
        int left = 0,right = dp.size()-1;
        while (left!=right){
            // 二分查找最大的小于的下标
            int mid = left+(right-left+1)/2;
            if(dp[mid]==n){
                return mid+1;
            }else if(dp[mid]<n){
                left = mid;
            }else if(dp[mid]>n){
                right = mid-1;
            }
        }
        return left+1;
    }
};

int main(){
    vector<int> v{0,1,0,3,2,3};
    Solution s;
    s.lengthOfLIS(v);
}