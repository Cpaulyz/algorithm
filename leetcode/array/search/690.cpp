//https://leetcode-cn.com/problems/employee-importance/
// Created by admin on 2021/5/4.
// BFS

using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        unordered_map<int,Employee*> emap;
        for(Employee* e:employees){
            emap[e->id] = e;
        }
        queue<Employee*> earray;
        earray.push(emap[id]);
        while (!earray.empty()){
            Employee* tmp = earray.front();
            earray.pop();
            res+=tmp->importance;
            for(int i:tmp->subordinates){
                earray.push(emap[i]);
            }
        }
        return res;
    }
};