// https://leetcode-cn.com/problems/remove-duplicate-letters/
// Created by admin on 2020/12/23.
//
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char,int> map;
        unordered_map<char,int> hasAdd;
        vector<char> v;
        for (int i = 0; i < s.size(); ++i) {
            map[s.at(i)]+=1;
        }
        for (int i = 0; i < s.size(); ++i) {
            if(v.empty()){
                v.push_back(s.at(i));
                hasAdd[s.at(i)]++;
            }else{
                if(hasAdd[s.at(i)]>0) {
                    map[s.at(i)]--;
                    continue;
                }
                else{
                    while (v.back()>=s.at(i)&&map[v.back()]>1){
                        map[v.back()]--;
                        hasAdd[v.back()]--;
                        v.pop_back();
                        if(v.empty()){
                            break;
                        }
                    }
                    v.push_back(s.at(i));
                    hasAdd[s.at(i)]++;
                }
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            res += v.at(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.removeDuplicateLetters("cbacdcbac");
}