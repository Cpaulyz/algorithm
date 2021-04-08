// https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
// Created by admin on 2021/4/8.
// 麻烦的二分查找

using namespace std;
#include <vector>

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0,right =nums.size()-1;
        while(left<=right){
            int mid = left + (right-left+1)/2;
            if(nums[mid]==target||nums[left]==target||nums[right]==target){
                return true;
            }else if(nums[left]==nums[mid]&&nums[mid]==nums[right]){
                left++;
                right--;
            }else if(nums[left]<=nums[mid]){
                if(target>=nums[left]&&target<=nums[mid]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else if(nums[left]>nums[mid]){
                if(target<=nums[left]&&target>=nums[mid]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> v{1,2,0,1,1,1};
    s.search(v,0);
}