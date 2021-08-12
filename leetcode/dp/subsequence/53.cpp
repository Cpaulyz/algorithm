// https://leetcode-cn.com/problems/maximum-subarray/
// Created by admin on 2021/3/8.
// dp: 包含num[i-1]的最大子序列
using namespace std;
#include <vector>
#include <iostream>
#include <cstring>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int res = dp;
        for (int i = 1; i < nums.size(); ++i) {
            if(dp>=0){
                dp += nums[i];
            }else{
                dp = nums[i];
            }
            res = max(res,dp);
        }
        return res;
    }
};

int main(){
    char *c;
    string s;
    getline(cin,s);
    c = new char[s.size()];
    strcpy(c,s.c_str());
    char* tmp = strtok(c," ");
    while (tmp!=NULL){
        string stmp = string(tmp);
        cout << stmp << endl;
        tmp = strtok(NULL," ");
    }
    cout << s << endl;
}