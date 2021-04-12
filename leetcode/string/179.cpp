// https://leetcode-cn.com/problems/largest-number/
// Created by admin on 2021/4/12.
// 排序，技巧在于排序
// 要求两个整数 x,y 如何拼接得到结果更大时，就想到先转字符串，然后比较 x+y 和 y+x
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

bool cmp(int a,int b);

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        if(nums[0]==0){
            return "0";
        }
        string res = "";
        for(int n:nums){
            res += to_string(n);
        }
        return res;
    }
};

bool cmp(int a,int b){
    string as = to_string(a);
    string bs = to_string(b);
    return as+bs > bs+as;
}