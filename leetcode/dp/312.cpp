//
// Created by admin on 2021/2/28.
//

using namespace std;
#include <vector>
class Solution {
public:
    int maxCoins(vector<int> &nums) {
        
    }
}
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