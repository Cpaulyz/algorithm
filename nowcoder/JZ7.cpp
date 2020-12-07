// https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&&tqId=11160&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        for(int i = 2;i<=n;++i){
            res.push_back(res[i-1]+res[i-2]);
        }
        return res[n];
    }
};