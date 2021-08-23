// https://leetcode-cn.com/problems/get-maximum-in-generated-array/
// Created by 陈彦泽 on 2021/8/23.
// 简单模拟题


using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0){
            return 0;
        }
        int res = 1;
        vector<int> nums(n+1,0);
        nums[1] = 1;
        for(int i=2;i<=n;++i){
            if(i%2==0){
                nums[i] = nums[i/2];
            }else{
                nums[i] = nums[i/2] + nums[i/2+1];
                res = max(res,nums[i]);
            }
            // cout << i << ":"<< nums[i] << endl;
        }
        return res;
    }
};