// https://leetcode-cn.com/problems/jump-game-ii/
// Created by admin on 2021/2/28.
// 55题的进阶版，假设你总是可以到达数组的最后一个位置。

using namespace std;
#include <vector>
class Solution {
public:
    // 贪心解法，每次都往下一次可达的最远的跳
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int pos = 0;
        int cnt = 0;
        while (true){
            int farJump = 0;
            int farNext = 0;
            for (int i = 1; i <= nums[pos]; ++i) {
                if(pos+i>=nums.size()-1){ // 直接到了
                    return cnt+1;
                }
                if(i+nums[pos+i]>farJump){ // 寻找下一条
                    farJump = i+nums[pos+i];
                    farNext = i;
                }
            }
            pos += farNext;
            cnt++;
        }
    }
};


// 以下是超时的dp解法
//class Solution {
//public:
//    vector<int> memory;
//
//    int jump(vector<int>& nums) {
//        memory = vector<int>(nums.size(),-1);
//        return dp(nums,0);
//    }
//    int dp(vector<int>& nums,int start) {
//        if(start>=nums.size()-1){
//            return 0;
//        }
//        if(memory[start]!=-1){
//            return memory[start];
//        }
//        int minDp = 999;
//        for (int i = 1; i <= nums[start]; ++i) {
//            if(i==1){
//                minDp = dp(nums,start+i);
//            }else{
//                minDp = min(minDp,dp(nums,start+i));
//            }
//        }
//        memory[start] = minDp+1;
//        return minDp+1;
//    }
//};

int main(){
    Solution s;
    vector<int> v{1,1,1,1};
    s.jump(v);
}