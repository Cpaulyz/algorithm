// https://leetcode-cn.com/problems/contiguous-array/
// Created by admin on 2021/6/3.
// 前缀和+哈希

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 前缀 表示 1比0多x个 1:+1  0:-1
        vector<int> pre(nums.size());
        // <pre,position>
        unordered_map<int,int> map;
        int res = 0;
        pre[0] = nums[0]==1?1:-1;
        map[pre[0]] = 0;
        for(int i=1;i<nums.size();++i){
            pre[i] = nums[i]==1?1:-1;
            pre[i] += pre[i-1];
            // cout <<  "pre"<< i << ":" << pre[i] << endl;
            if(pre[i]==0){
                res = i+1;
            }else if(map.count(pre[i])==0){
                map[pre[i]] = i;
            }else{
                // cout << map[pre[i]] << "-" << i << endl;
                res = max(res,i-map[pre[i]]);
            }
        }
        return res;
    }
};