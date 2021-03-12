// https://leetcode-cn.com/problems/basic-calculator-ii/
// Created by admin on 2021/3/11.
// 哨兵+双栈
using namespace std;
#include <string>
#include <stack>

class Solution {
public:
    int calculate(string s) {
        s = s+"+"; // 哨兵
        stack<char> ops;
        stack<long> nums;
        int tmp = 0;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '-':
                case '*':
                case '/':
                case '+': {
                    while (!ops.empty() && priority(ops.top()) >= priority(s[i])) {
                        long n = nums.top();
                        nums.pop();
                        char op = ops.top();
                        ops.pop();
                        tmp = cal(n,tmp,op);
                    }
                    nums.push(tmp);
                    tmp = 0;
                    ops.push(s[i]);
                }
                case ' ':
                    break;
                default: {
                    tmp = 10 * tmp + s[i] - '0';
                    break;
                }
            }
        }
        return nums.top();
    }

    int priority(char c){
        if(c=='+'||c=='-'){
            return 1;
        }else if(c=='*'||c=='/'){
            return 2;
        }
        return 0;
    }

    long cal(long n1,long n2,char op){
        switch (op) {
            case '+':
                return n1+n2;
            case '-':
                return n1-n2;
            case '*':
                return n1*n2;
            case '/':
                return n1/n2;
        }
        return 0;
    }
};

int main(){
    Solution s;
    s.calculate("3+2*2");
}