// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
// Created by admin on 2021/3/12.
//
using namespace std;
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size()+nums2.size();
        int index1 = 0;
        int index2 = 0;
        double res = 0;
        for (int i = 0; i < (len + 1) / 2; ++i) {
            int n1 = index1==nums1.size()?9999999:nums1[index1];
            int n2 = index2==nums2.size()?9999999:nums2[index2];
            res = min(n1,n2);
            if(n1<=n2){
                index1++;
            }else{
                index2++;
            }
        }
        if(len%2==0){
            int n1 = index1==nums1.size()?9999999:nums1[index1];
            int n2 = index2==nums2.size()?9999999:nums2[index2];
            double tmp = min(n1,n2);
            res = (tmp+res)/2;
        }
        return res;
    }
};