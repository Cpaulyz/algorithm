// https://leetcode-cn.com/problems/spiral-matrix/
// Created by admin on 2021/3/6.
//
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int i=0,j=0;
        res.push_back(matrix[0][0]);
        matrix[0][0] = 999;
        while (true){
            int found = 0;
            while (true){
                j++;
                if(j==matrix[0].size()){
                    j--;
                    break;
                }else if(matrix[i][j]==999){
                    j--;
                    break;
                }
                res.push_back(matrix[i][j]);
                found = 1;
                matrix[i][j] = 999;
            }
            while (true){
                i++;
                if(i==matrix.size()){
                    i--;
                    break;
                }else if(matrix[i][j]==999){
                    i--;
                    break;
                }
                res.push_back(matrix[i][j]);
                found = 1;
                matrix[i][j] = 999;
            }
            while (true){
                j--;
                if(j==-1){
                    j++;
                    break;
                }else if(matrix[i][j]==999){
                    j++;
                    break;
                }
                res.push_back(matrix[i][j]);
                found = 1;
                matrix[i][j] = 999;
            }
            while (true){
                i--;
                if(i==-1){
                    i++;
                    break;
                }else if(matrix[i][j]==999){
                    i++;
                    break;
                }
                res.push_back(matrix[i][j]);
                found = 1;
                matrix[i][j] = 999;
            }
            if(found==0){
                return res;
            }
        }
    }
};