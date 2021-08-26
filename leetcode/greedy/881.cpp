// https://leetcode-cn.com/problems/boats-to-save-people/
// Created by 陈彦泽 on 2021/8/26.
// 排序+双指针+贪心

using namespace std;
#include <vector>

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(),people.end());
        int left = 0,right=people.size()-1;
        while (left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            right--;
            res++;
        }
        return res;
    }
};