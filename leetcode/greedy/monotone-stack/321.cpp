// https://leetcode-cn.com/problems/create-maximum-number/
// Created by admin on 2020/12/23.
/**
 * 思路：
 * 1.单调栈问题（同402）
 * 2.合并子序列（需要往前看，情况比较多）
 * 3.比较vector，留大的
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        for (int i = 0; i <= k; ++i) {
            int len1 = i;
            int len2 = k-i;
            if(len1>nums1.size()||len2>nums2.size()){
                continue;
            }
            vector<int> sub1 = selectN(nums1,len1);
            vector<int> sub2 = selectN(nums2,len2);
            // merge and compare
            vector<int> tmpRes = merge(sub1,sub2);
            if(res.empty()||cmp(res,tmpRes)==1){
                res = tmpRes;
            }
        }
        return res;
    }

    int cmp(vector<int>& nums1, vector<int>& nums2){ // num1 < num2 then return 1
        for (int i = 0; i < nums1.size(); ++i) {
            if(nums1[i]<nums2[i]) {
                return 1;
            }else if(nums1[i]>nums2[i]){
                return 0;
            }
        }
        return 0;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;
        int index1 = 0,index2 = 0;
        while (index1<nums1.size()&&index2<nums2.size()){
            if(cmpItem(nums1,index1,nums2,index2)>0){
                res.push_back(nums1[index1++]);
            }else{
                res.push_back(nums2[index2++]);
            }
        }
        while (index1<nums1.size()){
            res.push_back(nums1[index1++]);
        }
        while (index2<nums2.size()){
            res.push_back(nums2[index2++]);
        }
        return res;
    }

    int cmpItem(vector<int>& one, int index1, vector<int>& two, int index2) {
        int x = one.size(), y = two.size();
        while (index1 < x && index2 < y) {
            int tag = one[index1++] - two[index2++];
            if (tag != 0) return tag;
        }
        return (x - index1) - (y - index2); // 返回后面元素多的
    }

    vector<int> selectN(vector<int>& v,int N){
        int k = v.size()-N;
        int rm = 0;
        vector<int> s;
        for (int i = 0; i < v.size(); ++i) {
            if(s.empty()||rm==k){
                s.push_back(v.at(i));
            }else{
                while (s.back()<v.at(i)){
                    s.pop_back();
                    rm++;
                    if(rm==k||s.empty()){
                        break;
                    }
                }
                s.push_back(v.at(i));
            }
        }
        vector<int> res;
        for (int i = 0; i < N; ++i) {
            res.push_back(s[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> a{6,7};
    vector<int> b{6,0,4};
    vector<int> tmp = s.maxNumber(b,a,5);
    for (int i = 0; i < tmp.size(); ++i) {
        cout<<tmp[i]<<endl;
    }
}