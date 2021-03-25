// https://leetcode-cn.com/problems/132-pattern/
// Created by admin on 2021/3/25.
// 单调栈 比较难
using namespace std;

#include <vector>
#include <stack>

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        stack<int> rightStack; // 单调递减栈，栈底最大
        int two = -999999999;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<two){
                return true;
            }
            while((!rightStack.empty())&&rightStack.top()<nums[i]){ // 7 3 4 6 2
                two = rightStack.top();
                rightStack.pop();
            }
            rightStack.push(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> v{3,5,0,3,4};
    Solution s;
    s.find132pattern(v);
}