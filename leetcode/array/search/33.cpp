// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
// Created by admin on 2021/3/6.
// 改进二分查找？

using namespace std;
#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = nums[0];
        if(target==first){
            return 0;
        }
        int left = 0,right = nums.size()-1;
        while (left<right){
            int mid = left + (right-left)/2;
            if(target<nums[mid]){
                if(nums[mid]<first){  // target < num[mid] < first
                    right = mid;
                }
                else {
                    if(target>first){ // first < target < num[mid]
                        right = mid;
                    }else{ // target < first < num[mid]
                        left = mid +1;
                    }
                }
            }else if(target>nums[mid]){
                if(nums[mid]<first){
                    if(target>first){ // num[mid] < first < target
                        right = mid;
                    }else{ // num[mid] < target < first
                        left = mid +1;
                    }
                } else { // first < num[mid] < target
                    left = mid +1;
                }
            }else if(target==nums[mid]){
                return mid;
            }
        }
        if(nums[left] == target){
            return left;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> a{1,3};
    s.search(a,2);
}