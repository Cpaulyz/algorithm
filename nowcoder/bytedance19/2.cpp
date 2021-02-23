//
// Created by admin on 2021/2/23.
//
using namespace std;

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int find(vector<int> build, int D) {
        int left = 0, right = 2;
        int diff = 0;
        long long sum = 0;
        diff = build[1] - build[0];
        while (right < build.size()) {
            diff = diff + build[right] - build[right - 1];
            while (diff > D) {
                diff = diff + build[left] - build[left + 1];
                left++;
            }
            if (diff <= D && (right - left) >= 2) {
                sum += count(right - left);
                sum = sum % 99997867;
            }
            right++;
        }
        return sum % 99997867;
    }

    long long count(long long len) {
        return len * (len - 1) / 2  % 99997867;
    }
};

int main(){
    Solution s;
    int n,d;
    cin >> n;
    cin >> d;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << s.find(v,d)<<endl;
}