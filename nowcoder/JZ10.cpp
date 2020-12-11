//https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// Created by admin on 2020/12/7.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rectCover(int number) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);
        for(int i = 3;i<=number ;++i){
            dp.push_back(dp[i-1]+dp[i-2]);
        }
        return dp[number];
    }
};

int main(){
    Solution s;
    cout << s.rectCover(3);
}