// https://leetcode-cn.com/problems/maximum-average-subarray-i/
// Created by admin on 2021/2/4.
//

using namespace std;
#include <vector>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0,right = k;
        int sum = 0;
        double maxAvg = 0;
        for (int i = 0; i < k; ++i) {
            sum+=nums[i];
        }
        maxAvg = (double)sum/k;
        while (k<nums.size()){
            sum-=nums[left++];
            sum+=nums[right++];
            maxAvg=max(maxAvg,(double)sum/k);
        }
        return maxAvg;
    }
};