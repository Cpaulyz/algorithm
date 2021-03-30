//https://leetcode-cn.com/problems/search-a-2d-matrix/
// Created by admin on 2021/3/30.
// 两次二分查找

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up=0,down = matrix.size()-1;
        while(up<down){
            int mid = up+(down-up+1)/2;
            if(matrix[mid][0]<=target){
                up = mid;
            }else{
                down=mid-1;
            }
        }
        cout << up <<endl;
        // now up is row
        int left=0,right=matrix[0].size()-1;
        while(left<right){
            int mid = left+(right-left+1)/2;
            cout << matrix[up][mid] <<endl;
            if(matrix[up][mid]==target){
                return true;
            }else if(matrix[up][mid]>target){
                right = mid-1;
            }else if(matrix[up][mid]<target){
                left = mid+1;
            }
        }
        return matrix[up][right]==target;;
    }
};