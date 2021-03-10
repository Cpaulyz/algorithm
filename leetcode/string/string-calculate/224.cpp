// https://leetcode-cn.com/problems/basic-calculator/
// Created by admin on 2021/3/10.
// 双栈
using namespace std;

#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int calculate(string s) {
        stack<long> nums;
        stack<char> ops;
        ops.push('+');
        long tmp = 0; // 当前数的值
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(': {
                    ops.push('(');
                    break;
                }
                case ')': {
                    nums.push(tmp);
                    // 出栈操作，直到(
                    long num = 0;
                    while (ops.top()!='('){
                        tmp = nums.top();
                        int op = ops.top()=='-'?-1:1;
                        ops.pop();
                        nums.pop();
                        num += op*tmp;
                    }
                    num+=nums.top();
                    tmp = num;
                    nums.pop();
                    ops.pop();
                    break;
                }
                case '+': {
                    nums.push(tmp);
                    tmp = 0;
                    ops.push('+');
                    break;
                }
                case '-': {
                    nums.push(tmp);
                    tmp = 0;
                    ops.push('-');
                    break;
                }
                case ' ':
                    break;
                default: {
                    tmp = tmp*10 + s[i]-'0';
                    break;
                }
            }
        }
        nums.push(tmp);
        long res = 0;
        while (!ops.empty()){
            tmp = nums.top();
            int op = ops.top()=='-'?-1:1;
            ops.pop();
            res += op*tmp;
            nums.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    s.calculate("2-1 + 2");
}