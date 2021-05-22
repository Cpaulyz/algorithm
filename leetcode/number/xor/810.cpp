// https://leetcode-cn.com/problems/chalkboard-xor-game/submissions/
// Created by admin on 2021/5/22.
// 硬模拟，但更好的解法是数学解法
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        unordered_map<int,int> map;
        int sum = 0;
        for(int n:nums){
            map[n]++;
            sum ^= n;
        }
        bool alice= true;
        bool die= true;
        for (int i = 0; i < nums.size(); ++i) {

            // cout << i;
            // cout << " sum:" <<sum;
            // cout << " isalice:" <<alice;
            if(sum==0){
                if(alice){
                    return true;
                }else{
                    return false;
                }
            }
            die = true;
            for(auto it = map.begin();it!=map.end();it++){
                if(it->first!=sum){
                    // cout<< " pick:"<< it->first<<endl;
                    map[it->first]--;
                    sum ^= it->first;
                    if(map[it->first]==0){
                        map.erase(it->first);
                    }
                    die = false;
                    break;
                }
            }
            if (die){
                if(alice)
                    return false;
                else
                    return true;
            }
            alice = !alice;
        }
        return false;
    }
};