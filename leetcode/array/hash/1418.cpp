// https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/
// Created by admin on 2021/7/6.
// 一顿哈希+排序。。


using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>
bool cmp(vector<int>* a,vector<int>* b);

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string,int> food;
        vector<string> header;
        header.push_back("Table");
        unordered_map<string,vector<int>*> table_index;
        vector<vector<int>*> raw_res;
        int index = 1;
        for(vector<string> order:orders){
            if(food.count(order[2])==0){
                header.push_back(order[2]);
                food[order[2]] = index++;
                cout << order[2] <<  " index " << food[order[2]]<< endl;
            }
        }
        for(vector<string> order:orders){
            cout << order[1] << " add " << order[2] << endl;
            if(table_index.count(order[1])==0){
                vector<int>* tmp = new vector<int>(index);
                (*tmp)[0] = stoi(order[1]);
                raw_res.push_back(tmp);
                table_index[order[1]] = tmp;
            }
            (*table_index[order[1]])[food[order[2]]] ++;
        }
        sort(raw_res.begin(),raw_res.end(),cmp);
        sort(header.begin()+1,header.end());
        vector<vector<string>> res;
        res.push_back(header);
        for(auto row:raw_res){
            vector<string> tmp;
            tmp.push_back(to_string((*row)[0]));
            for (int i = 1; i < header.size(); ++i) {
                tmp.push_back(to_string((*row)[food[header[i]]]));
            }
            res.push_back(tmp);
        }
        return res;
    }
};


bool cmp(vector<int>* a,vector<int>* b){
    return (*a)[0] < (*b)[0];
}