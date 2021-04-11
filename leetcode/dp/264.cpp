// https://leetcode-cn.com/problems/ugly-number-ii/submissions/
// Created by admin on 2021/4/11.
// dp 很妙！！

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.push_back(1);
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;++i){
            int n2=dp[p2]*2;
            int n3=dp[p3]*3;
            int n5=dp[p5]*5;
            int tmp = min(min(n2,n3),n5);
            if(tmp==n2){
                p2++;
            }
            if(tmp==n3){
                p3++;
            }
            if(tmp==n5){
                p5++;
            }
            dp.push_back(tmp);
            // cout << tmp << endl;
            // cout << "p2：" << p2<<endl;
            // cout << "p3：" << p3<<endl;
            // cout << "p5：" << p5<<endl;
        }
        return dp.back();
    }
};