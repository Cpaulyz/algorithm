// https://leetcode-cn.com/problems/first-bad-version/submissions/
// Created by admin on 2021/6/13.
// 二分查找

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n;
        while(left<right){
            int mid = left + (right-left)/2;
            if(isBadVersion(mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};