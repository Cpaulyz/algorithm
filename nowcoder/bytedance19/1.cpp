//
// Created by admin on 2021/2/23.
//

using namespace std;
#include <vector>
#include <string>
#include <iostream>
class Solution{
public:
    string validate(string s){
        string res = "";
        string tmp = "";
        char nowc = ' ';
        int prevCount = 0,count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]!=nowc){
                for (int j = 0; j < count; ++j) {
                    res += nowc;
                }
                nowc = s[i];
                prevCount = count;
                count = 1;
            }else{
                count++;
                if(prevCount>=2&&count>=2){
                    count--;
                }else if(count>=3){
                    count--;
                }
            }
        }
        for (int j = 0; j < count; ++j) {
            res += nowc;
        }
        return res;
    }
};

int main(){
    Solution s;
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        cout << s.validate(str) << endl;
    }
}