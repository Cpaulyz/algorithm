//https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/
// Created by admin on 2021/3/12.
//

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
    unordered_map<int,int> count;
public:
    bool isPossible(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }
        return backtrace(nums,0);
    }

    bool backtrace(vector<int>& nums,int part){
        // 终止条件
        bool end = true;
        for (int i = 0; i < nums.size(); ++i) {
            if(count[nums[i]]!=0){
                end = false;
                break;
            }
        }
        if(end) return part>=2;
        // backtrace
        bool res = false;
        for (int i = 0; i < nums.size()-2; ++i) {
            if(i!=0&&nums[i]==nums[i-1]){
                continue; // 避免重复计算
            }else if(count[nums[i]]*count[nums[i+1]]*count[nums[i+2]]!=0){
                // 保证后面有三位可以分割
                int tmp = i+3;
                count[nums[i]]--;
                count[nums[i+1]]--;
                count[nums[i+2]]--;
                res |= backtrace(nums,part+1);
                if(res) return res;
                while (tmp<nums.size()){
                    if(count[nums[tmp]]!=0){
                        count[nums[tmp]]--;
                        res |= backtrace(nums,part+1);
                        if(res) return res;
                    }else{
                        break;
                    }
                    tmp++;
                }
                for (int j = i; j <tmp ; ++j) {
                    count[nums[j]]++;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> v{1,2,3,3,4,5};
    s.isPossible(v);
}