// http://bailian.openjudge.cn/dsj2017xly/A/
// Created by admin on 2021/5/18.
//

using namespace std;
#include <algorithm>
#include <vector>
#include <iostream>

struct Pair{
    int x;
    int y;
    Pair(int x,int y):x(x),y(y){}
};
bool cmp(Pair* a,Pair* b);
int distance(Pair* a,Pair* b);
Pair* base;

int  main(){
    int tmpa,tmpb;
    int n;
    cin >> tmpa >> tmpb;
    base = new Pair(tmpa,tmpb);
    vector<Pair*> list;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmpa >> tmpb;
        list.push_back(new Pair(tmpa,tmpb));
    }
    sort(list.begin(),list.end(),cmp);
    cout<<"("<<list[0]->x<<","<<list[0]->y<<")";
    for (int i = 1; i < n; ++i) {
        cout<<", ("<<list[i]->x<<","<<list[i]->y<<")";
    }
    cout<<endl;
}

bool cmp(Pair* a,Pair* b){
    int diff = distance(a,base)-distance(b,base);
    if(diff==0){
        diff = a->x-b->x;
        if(diff==0){
            diff = a->y-b->y;
        }
    }
    return diff<0;
}

int distance(Pair* a,Pair* b){
    return (a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y);
}