// https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp;
        dp.push_back(1);
        for(int i = 1;i<=number ;++i){
            dp.push_back(0);
            for(int j = 0;j<i;++j){
                dp[i] += dp[j];
            }
        } 
        return dp[number];
    }
};

int main(){
    Solution s;
    cout << s.jumpFloorII(3) <<endl;
}