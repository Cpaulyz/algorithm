// https://leetcode-cn.com/problems/valid-number/
// Created by admin on 2021/6/17.
// 编译原理的状态机

using namespace std;

#include <vector>
#include <iostream>

class Solution {
    string s;
    int pos;
public:
    bool isNumber(string s) {
        this->s = s;
        pos = 0;
        checkSign();
        if (checkPoint()>0){
            if (checkInt() ==0){
                return false;
            }
        }else if(checkInt()>0){
            checkPoint();
            checkInt();
        }else{
            return false;
        }
        // 到E部分了
        if(checkE()>0){
            checkSign();
            if (checkInt()==0){
                return false;
            }
        }
        return pos==s.size();
    }

    int checkInt() {
        int res = 0;
        while (pos < s.size()) {
            if (s[pos] <= '9' && s[pos] >= '0') {
                pos++;
                res ++ ;
            } else {
                break;
            }
        }
        return res;
    }

    int checkE(){
        if (s[pos] == 'e' || s[pos] == 'E') {
            pos ++;
            return 1;
        }else{
            return 0;
        }
    }

    int checkSign(){
        if (s[pos] == '+' || s[pos] == '-') {
            pos ++;
            return 1;
        }else{
            return 0;
        }
    }

    int checkPoint(){
        if (s[pos] == '.') {
            pos ++;
            return 1;
        }else{
            return 0;
        }
    }
};

int main(){
    Solution s;
    s.isNumber("3.");
}