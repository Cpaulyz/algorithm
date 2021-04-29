// https://leetcode-cn.com/problems/sum-of-square-numbers/
// Created by admin on 2021/4/29.
//

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left=0,right=sqrt(c);
        while(left<=right){
            if(left*left+right*right==c){
                return true;
            }else if(left*left+right*right<c){
                left++;
            }else if(left*left+right*right>c){
                right--;
            }
        }
        return false;
    }
};