// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
// Created by admin on 2021/2/20.
// 快排
using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // 方法一：库函数
//    int findKthLargest(vector<int>& nums, int k) {
//        sort(nums.begin(),nums.end(),greater<int>());
//        return nums[k-1];
//    }
    // 方法二：快排选择
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, k-1,0, nums.size()-1);
    }

    int helper(vector<int>& nums,int k,int left,int right){
        // 随机选择pivot
        int randomI = left+rand()%(right-left+1);
        int pivot = nums[randomI];
        swap(nums[randomI],nums[left]);
        // 快排
        int l=left,r=right;
        while (l<r){
            while (l<r&&nums[r]<=pivot){
                r--;
            }
            nums[l] = nums[r];
            while (l<r&&nums[l]>=pivot){
                l++;
            }
            nums[r]=nums[l];
        }
        nums[l] = pivot;
        // now l == r
        if(l==k){
            return nums[l];
        }else if(l<k){
            return helper(nums,k,l+1,right);
        }else{ // l > k
            return helper(nums,k,left,l-1);
        }
    }
};

int main(){
    Solution s;
    vector<int> a{1};
//    vector<int> a{3,2,3,1,2,4,5,5,6};
    cout << s.findKthLargest(a,1);
}