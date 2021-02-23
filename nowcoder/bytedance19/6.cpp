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
    int getCoin(int n) {
//      1
//    100/
//  10000
//1000000
        int sum = 0;
        sum += n/64;
        n = n%64;
        sum += n/16;
        n = n%16;
        sum += n/4;
        n = n%4;
        sum += n;
        return sum;
    }

};

int main(){
    Solution s;
    int n;
    cin >> n;
    cout<< s.getCoin(1024-n)<<endl;
}