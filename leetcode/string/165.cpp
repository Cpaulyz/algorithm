// https://leetcode-cn.com/problems/compare-version-numbers/
// Created by admin on 2021/3/8.
//
using namespace std;
#include <string>
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0,index2 = 0;
        int num1 = 0, num2 =0;
        while (index1<version1.size()||index2<version2.size()){
            num1 = num2 = 0;
            while (index1<version1.size()){
                if(version1[index1]!='.'){
                    num1= num1*10 + version1[index1] - '0';
                    index1++;
                }else{
                    index1++;
                    break;
                }
            }
            while (index2<version2.size()){
                if(version2[index2]!='.'){
                    num2= num2*10 + version2[index2] - '0';
                    index2++;
                }else{
                    index2++;
                    break;
                }
            }
            if(num1>num2){
                return 1;
            }else if(num1 < num2){
                return -1;
            }
        }
        return 0;
    }
};