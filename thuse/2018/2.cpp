// https://blog.csdn.net/da_kao_la/article/details/82717930
// Created by 陈彦泽 on 2021/9/10.
// 遍历模拟即可

using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>

/**
输入一个任意长度的数字序列，如果将数字序列的每一位看做一个单独的数字，则每个序列都可以看做是由数字0~9组成的一个排列。输出比输入序列大的最小排列，如果这样的序列不存在，则输出输入序列。
示例：
Input
123
Output
132
*/

class Solution{
public:
    string Arrange(string input){
        // 12183812831
        // 逆向遍历，找到第一个非递增的x，在x前插入比x大的最小数。
        vector<int> memo;
        memo.push_back(input[input.size()-1]);
        for (int i = input.size()-2; i >=0; --i) {
            if(input[i]>=memo.back()){
                memo.push_back(input[i]);
            }else{
                // insert
                int index = upper_bound(memo.begin(),memo.end(),input[i])-memo.begin();
                string res = input.substr(0,i);
                res += string(1,memo[index]);
                res += string(1,input[i]);
                for (int j = 0; j < memo.size(); ++j) {
                    if(j!=index){
                        res += string(1,memo[j]);
                    }
                }
                return res;
            }
        }
        return input;
    }
};

int main(){
    string input;
    cin >> input;
    Solution s;
    cout << s.Arrange(input) << endl;
}