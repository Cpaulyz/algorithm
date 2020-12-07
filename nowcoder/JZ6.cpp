// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&&tqId=11159&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size()-1;
        while (true)
        {
            if(right-left == 0){
                return rotateArray[left];
            }else if(right-left == 1){
                return min(rotateArray[left],rotateArray[right]);
            }else if(right-left == 2){
                return min(rotateArray[left],rotateArray[(left+right)/2],rotateArray[right]);
            }
            if(rotateArray[(left+right)/2] > rotateArray[right]){
                left = (left+right)/2;
            }else{
                right = (left+right)/2;
            }
        }
    }
};