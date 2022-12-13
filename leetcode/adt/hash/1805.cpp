// https://leetcode.cn/problems/number-of-different-integers-in-a-string/
// Created by 陈彦泽 on 2022/12/6.
// 遍历+hashset，可以用双指针优化

using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> set = unordered_set<string>();
        string tmp = "";
        bool remain =false;
        for (char c:word) {
            if(c<='9'&&c>='0'){
                if(c!='0'||tmp.size()!=0){
                    tmp = tmp + c;
                }
                remain = true;
            }else if(remain){
                set.insert(tmp);
                tmp = "";
                remain = false;
            }
        }
        if(remain){
            set.insert(tmp);
        }
        return set.size();
    }
};

int main(){
    string in;
    cin >> in;
    Solution s;
    cout << s.numDifferentIntegers(in) << endl;
}