//
// Created by admin on 2021/5/23.
//

using namespace std;
#include <vector>
#include <string>
#include <iostream>

int main(){
    string  in;
    getline(cin,in);
    vector<string> res;
    int pre = 0;
//    string res = "";
    bool token = false;
    int i;
    for (i = 0; i < in.size(); ++i) {
        if(in.at(i)==' '){
            if(token){
                res.push_back(in.substr(pre,i-pre));
//                res = in.substr(pre,i-pre)+res;
//                res = " "+res;
                token = false;
            }
        }else{
            if(!token){
                token = true;
                pre = i;
            }
        }
    }
    if(token){
        res.push_back(in.substr(pre,i-pre));
    }
    for (int j = res.size()-1; j >=0 ; --j) {
        if(j!=res.size()-1){
            cout << " ";
        }
        cout << res[j];
    }
    cout<< endl;

}