// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
// Created by admin on 2021/4/6.
// 快慢双指针

using namespace std;
#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=0,quick=0;
        while (quick<nums.size()){
            if(slow<2||nums[slow-2]!=nums[quick]){
                nums[slow++] = nums[quick++];
            }else{
                quick++;
            }
        }
        return slow;
    }
};