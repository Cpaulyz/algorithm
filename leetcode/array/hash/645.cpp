// https://leetcode-cn.com/problems/set-mismatch/
// Created by admin on 2021/7/4.
// 普普通通的哈希


using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        unordered_set<int> numset;
        for (int i = 0; i < nums.size(); ++i) {
            numset.insert(i+1);
        }
        for (int n:nums) {
            if(numset.count(n)==0){
                res[0] = n;
            }else{
                numset.erase(n);
            }
        }
        for(int n:numset){
            res[1] = n;
        }
        return res;
    }
};