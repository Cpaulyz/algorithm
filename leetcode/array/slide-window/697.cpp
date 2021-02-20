// https://leetcode-cn.com/problems/degree-of-an-array/
// Created by admin on 2021/2/20.
//
using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0;
        int localDegree = 0;
        int minLen = 99999;
        unordered_map<int,int> numMap;
        unordered_map<int,int> localMap;
        for(int num:nums){
            numMap[num]++;
            degree = max(degree,numMap[num]);
        }
        int left = 0,right = 0;
        while (right<nums.size()){
            localMap[nums[right]]++;
            localDegree = max(localDegree,localMap[nums[right]]);
            while (localDegree==degree){
                minLen = min(minLen,right+1-left);
                localMap[nums[left]]--;
                localDegree = min(localDegree,localMap[nums[right]]);
                left++;
            }
            right++;
        }
        return minLen;
    }
};

int main(){
    Solution s;
    vector<int> a{1,2,2,3,1};
    s.findShortestSubArray(a);
}