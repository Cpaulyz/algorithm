// https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/submissions/
// Created by admin on 2021/5/18.
// 问题转化，降低复杂度

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> xor_sum;
        int prev = 0;
        for(int n:arr){
            xor_sum.push_back(prev);
            prev = prev^n;
        }
        xor_sum.push_back(prev);
        int res=0; // 找i<k arr[i]^..arr[k]=0,res+=(k-i)
        for(int i=0;i<arr.size();++i){
            for(int j=i+1;j<arr.size();++j){
                if((xor_sum[j+1]^xor_sum[i])==0){
                    res+=(j-i);
                    // cout << i<<","<<j<<endl;
                }
            }
        }
        return res;
    }
};