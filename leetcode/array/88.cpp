// https://leetcode-cn.com/problems/merge-sorted-array/submissions/
// Created by admin on 2021/4/5.
// 逆序遍历

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1= m-1;
        int index2= n-1;
        int tail = m+n-1;
        while(index1>=0&&index2>=0){
            if(nums1[index1]>nums2[index2]){
                nums1[tail--] = nums1[index1--];
            }else{
                nums1[tail--] = nums2[index2--];
            }
        }
        while(index1>=0){
            nums1[tail--] = nums1[index1--];
        }
        while(index2>=0){
            nums1[tail--] = nums2[index2--];
        }
    }
};