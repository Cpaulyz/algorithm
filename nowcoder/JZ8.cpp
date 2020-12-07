//https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <vector>
using namespace std;
class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        for(int i= 2; i<=number; ++i){
            dp.push_back(dp[i-1]+dp[i-2]);
        }
        return dp[number];
    }
};
