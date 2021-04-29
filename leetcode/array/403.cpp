// https://leetcode-cn.com/problems/frog-jump/
// Created by admin on 2021/4/29.
// dp[i][j]表示可以从stones[j]跳到stones[i]
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1){
            return false;
        }
        unordered_map<int,int> stone_map; // 存储V:index
        for (int i = 0; i < stones.size(); ++i) {
            stone_map[stones[i]]=i;
        }
        vector<vector<bool>> dp(stones.size(),vector<bool>(stones.size(),false));
        dp[1][0] = true;
        for (int i = 2; i <  stones.size(); ++i) {
            for (int j = i-1; j >=0 ; --j) {
                int diff = stones[i]-stones[j];
                for (int offset = -1; offset <= 1; ++offset) {
                    int tmp = stones[j]-diff+offset;
                    if(stone_map.count(tmp)!=0&&dp[j][stone_map[tmp]]){
                        dp[i][j]=true;
                        break;
                    }
                }
                if(diff>stones[j]){
                    break; // 剪枝
                }
            }
        }
        for(bool b:dp[stones.size()-1]){
            if(b){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> v{0,1,3,5,6,8,12,17};
//    vector<int> v{0,2};
    s.canCross(v);

}