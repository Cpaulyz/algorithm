//
// Created by admin on 2021/3/8.
//

using namespace std;
#include <iostream>
#include <vector>

class Solution{
public:
    int find(int k,vector<int>& nums){
        int cnt = 0;
        int pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] != pre+1){
                cnt += nums[i] - pre -1;
            }
            if(cnt>=k){
                return nums[i] - (cnt-k+1);
            }
            pre = nums[i];
        }
        return nums[nums.size()-1]+(k-cnt);
    }
};

int main(){
    int n;
    cin >> n;
    Solution s;
    for (int i = 0; i < n; ++i) {
        int m,k;
        cin >> m;
        cin >> k;
        vector<int> nums;
        for (int j = 0; j < m; ++j) {
            int tmp;
            cin>>tmp;
            nums.push_back(tmp);
        }
        cout << s.find(k,nums) << endl;
    }
}