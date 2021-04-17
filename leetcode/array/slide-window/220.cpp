// https://leetcode-cn.com/problems/contains-duplicate-iii/
// Created by admin on 2021/4/17.
// 滑动窗口，精髓在于这桶排序，极妙！
using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int,int> buckets;
        for (int i = 0; i < nums.size(); ++i) {
            int bucket = getBucket(nums[i],t);
            if(buckets.count(bucket)>0){
                return true;
            }else{
                if(buckets.count(bucket-1)>0&&abs(buckets[bucket-1]-nums[i])<=t){
                    return true;
                }
                if(buckets.count(bucket+1)>0&&abs(buckets[bucket+1]-nums[i])<=t){
                    return true;
                }
            }
            buckets[bucket]=nums[i];
            if(i>=k){
                buckets.erase(getBucket(nums[i-k],t));
            }
        }
        return false;
    }
    int getBucket(int n,int t){
        // n = x*(t+1)+p,求n
        if(n>=0){
            return n/(t+1);
        }else{
            if(n%(t+1)==0){
                return n/(t+1);
            } else{
                return n/(t+1)-1;
            }
        }
    }
};