// https://leetcode-cn.com/problems/largest-divisible-subset/
// Created by admin on 2021/4/23.
// dp,自己写出了最优解！！ 时间O(n2) 空间O(n)

using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> pre(nums.size(),-1);
        int record = 1;
        int pos = 0;
        dp[0]=1;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        pre[i]=j;
                        if(dp[i]>record){
                            record = dp[i];
                            pos = i;
                        }
                    }
                }
            }
        }
        vector<int> res(dp[pos]);
        for (int i = dp[pos]-1; i >=0 ; --i) {
            res[i] = nums[pos];
            pos = pre[pos];
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> v{2,3,4,9,8};
    s.largestDivisibleSubset(v);
}