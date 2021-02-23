//
// Created by admin on 2021/2/23.
//

using namespace std;

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int find(vector<vector<string>> arr) {
        unordered_map<string,int> map;
        int left=0, right = 0;
        int maxLen = 0;
        while (right<arr.size()){
            for(string s:arr[right++]){
                map[s]++;
            }
            while (!valid(map,right-left)){
                for(string s:arr[left++]){
                    map[s]--;
                }
            }
            maxLen = max(maxLen,right-left);
        }
        return maxLen;
    }
    bool valid(unordered_map<string,int>& map,int n){
        for(auto &it:map){
            if(it.second==n){
                return true;
            }
        }
        return false;
    }

};

int main(){
    Solution s;
    int n,d;
    cin >> n;
    cin >> d;
    for (int i = 0; i < n; ++i) {
        vector<vector<string>> v;
        for (int j = 0; j < d; ++j) {
            int tmp;
            vector<string> tmpv;
            cin >> tmp;
            for (int k = 0; k < tmp; ++k) {
                int a,b;
                cin >> a;
                cin >> b;
                tmpv.push_back(to_string(a)+"#"+to_string(b));
            }
            v.push_back(tmpv);
        }
        cout << s.find(v) << endl;
    }
}