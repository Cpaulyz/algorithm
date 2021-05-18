// https://leetcode-cn.com/problems/decode-xored-permutation/
// Created by admin on 2021/5/11.
// 根据奇数条件，异或得到一个数，然后就很简单了

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int> res;
        int tmp = 0;
        int prev = 0;
        for(int n:encoded){
            prev ^= n;
            tmp ^= prev;
        }
        for(int i=1;i<=encoded.size()+1;++i){
            tmp ^= i;
        }
        res.push_back(tmp);
        for(int n:encoded){
            tmp ^= n;
            res.push_back(tmp);
        }
        return res;
    }
};