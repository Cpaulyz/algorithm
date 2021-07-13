//
// Created by admin on 2021/7/12.
//


using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i;
        for(i=0;i<citations.size();++i){
            if(citations[citations.size()-1-i]<i+1){
                break;
            }
        }
        return i;
    }
};