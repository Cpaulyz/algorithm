// https://leetcode-cn.com/problems/flipping-an-image/submissions/
// Created by admin on 2021/2/24.
// 直接遍历

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0;i<A.size();++i){
            for(int j = 0; j<(A[0].size()+1)/2;++j){
                int t = A[i][j]^1;
                A[i][j] = A[i][A[0].size()-1-j]^1;
                A[i][A[0].size()-1-j] = t;
            }
        }
        return A;
    }
};