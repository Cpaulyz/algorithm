// https://leetcode-cn.com/problems/remove-k-digits/
// Created by admin on 2020/12/23.
// 本包解析：https://leetcode-cn.com/problems/remove-duplicate-letters/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-4/
// 贪心，从左到右扫描，每次加入元素的时候要出栈直到栈顶小于等于当前元素
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        int rm = 0;
        vector<char> s;
        for (int i = 0; i < num.size(); ++i) {
            if(s.empty()||rm==k){
                s.push_back(num.at(i));
            }else{
                while (s.back()>num.at(i)){
                    s.pop_back();
                    rm++;
                    if(rm==k||s.empty()){
                        break;
                    }
                }
                s.push_back(num.at(i));
            }
        }
        string str = "";
        for (int i = 0; i < num.size() - k; ++i) {
            if(str.compare("")==0&&s.at(i)=='0'){ // 去除前导零
                continue;
            }
            str += s.at(i);
        }
        if(str.compare("")==0){
            str += "0"; // 防止返回空串
        }
        return str;
    }
};

int main(){
    Solution s;
    cout << s.removeKdigits("10200",1);
}