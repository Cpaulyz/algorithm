// https://leetcode-cn.com/problems/number-of-atoms/
// Created by admin on 2021/7/5.
// 栈+哈希表

using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>*> map_stack;
        unordered_map<string,int>* curr_map = new unordered_map<string,int>();
        map_stack.push(curr_map); // init
        string curr_atoms = ""; // 当前元素
        int curr_nums = 0; // 当前计数
        int index = 0;
        while (index<formula.size()) {
            if(formula[index]=='('){ // 加栈
                curr_map = new unordered_map<string,int>();
                map_stack.push(curr_map);
                index++;
            }else if(formula[index]==')'){ // 出栈，乘n
                index++;
                int num = getInt(formula,index);
                map_stack.pop();
                unordered_map<string,int>* tmp = curr_map;
                curr_map = map_stack.top();
                for(auto item:*tmp){
                    (*curr_map)[item.first] += item.second*num;
                }
            }else{ // 顺序提取
                string atom = getAtom(formula,index);
                int num = getInt(formula,index);
                (*curr_map)[atom] += num;
            }
        }
        return trans(curr_map);
    }

    // 提取数字
    int getInt(string& s,int& index){
        int res = 0;
        while(s[index]<='9'&&s[index]>='0'){
            res = res*10+s[index]-'0';
            index++;
        }
        return res>0?res:1;
    }

    // 提取元素
    string getAtom(string& s,int& index){
        if(s[index]>'Z'||s[index]<'A'){
            return "";
        }
        string res = string(1,s[index++]); // 把大写提出来
        while(s[index]<='z'&&s[index]>='a'){
            res += string(1,s[index]);
            index++;
        }
        return res;
    }

    // 打印
    string trans(unordered_map<string,int>* map){
        string res = "";
        vector<string> keyset;
        for (auto item:(*map)){
            keyset.push_back(item.first);
        }
        sort(keyset.begin(),keyset.end());
        for(auto key:keyset){
            int cnt = (*map)[key];
            res +=key+(cnt>1?to_string(cnt):"");
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.countOfAtoms("(Cm39)5(Ga28Sb45Rb8)20(Bk13Fr29As)45");
}