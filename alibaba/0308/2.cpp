//
// Created by admin on 2021/3/8.
//


using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
class Solution{
    long long res;
    vector<int> people;
    vector<int> money;
public:
    int findNumsOfPlan(int n,int p,vector<int>& a,vector<int>& b){
        res = 0;
        people = a;
        money = b;
        vector<int> use(a.size());
        backtrace(n,p,use,0,0,0);
        return res;
    }

    void backtrace(int n,int p,vector<int>& use,int hasMoney,int usePeople,int start){
        if(hasMoney>=p){
            res++;
            res = res%((long long)1e9+7);
        }
        for (int i = start; i < people.size(); ++i) {
            if(usePeople+people[i]<=n&&use[i]==0){
                use[i] = 1;
                backtrace(n,p,use,hasMoney+money[i],usePeople+people[i],i+1);
                use[i] = 0;
            }else{
                break;
            }
        }
    }
};


int main(){
    int t;
    cin >> t;
    Solution s;
    for (int i = 0; i < t; ++i) {
        int m,n,p;
        cin >> m >> n>>p;
        vector<int> a;
        vector<int> b;
        int tmp;
        for (int j = 0; j < m; ++j) {
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int j = 0; j < m; ++j) {
            cin >> tmp;
            b.push_back(tmp);
        }
        cout << s.findNumsOfPlan(n,p,a,b) << endl;
    }
}