// https://leetcode-cn.com/problems/decode-ways/
// Created by admin on 2021/4/21.
// dp，可优化空间复杂度，只用三个
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,1);
        if(s[0]=='0'){
            return 0;
        }else{
            dp[1]=1;
        }
        for(int i=1;i<s.size();++i){
            if(s[i]=='0'){
                if(s[i-1]=='2'||s[i-1]=='1'){
                    dp[i+1]=dp[i-1];
                }else{
                    return 0;
                }
            }else{
                dp[i+1]=dp[i];
                if(s[i-1]=='1'){
                    dp[i+1]+=dp[i-1];
                }else if(s[i-1]=='2'&&s[i]<='6'){
                    dp[i+1]+=dp[i-1];
                }
            }
        }
        return dp[s.size()];
    }
};
