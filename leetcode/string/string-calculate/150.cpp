// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
// Created by admin on 2021/3/21.
// 逆波兰表达式求值
using namespace std;
#include <string>
#include <stack>
#include <vector>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string str:tokens){
            if(str.size()>1){
                s.push(stoi(str));
                continue;
            }
            switch(str[0]){
                case '+':{
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    s.push(a+b);
                    break;
                }
                case '-':{
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    s.push(b-a);
                    break;
                }
                case '*':{
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    s.push(b*a);
                    break;
                }
                case '/':{
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    s.push(b/a);
                    break;
                }
                default:{
                    s.push(stoi(str));
                    break;
                }
            }
        }
        return s.top();
    }
};

int main(){
    vector<string> v{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    s.evalRPN(v);
}