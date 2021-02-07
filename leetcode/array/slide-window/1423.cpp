// https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
// Created by admin on 2021/2/7.
// 逆向，求剩余元素的最小情况

using namespace std;
#include <vector>

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int minDelete = 0;
        int tmpDelete = 0;
        int left = 0,right = cardPoints.size()-k;
        for (int i = 0; i < right; ++i) {
            tmpDelete += cardPoints[i];
            sum += cardPoints[i];
        }
        minDelete = tmpDelete;
        while (right<cardPoints.size()){
            tmpDelete-=cardPoints[left];
            tmpDelete+=cardPoints[right];
            sum+=cardPoints[right];
            right++;
            left++;
            if(tmpDelete<minDelete){
                minDelete = tmpDelete;
            }
        }
        return sum-minDelete;
    }
};


int main(){
    Solution s;
    vector<int> c{1,2,3,4,5,6,1};
    s.maxScore(c,3);
}