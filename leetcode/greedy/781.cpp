// https://leetcode-cn.com/problems/rabbits-in-forest/
// Created by admin on 2021/4/4.
// 贪心

using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> map;
        int res = 0;
        for(int a:answers){
            if(map[a]==0){
                res++;
                res+=a;
                map[a] = 1;
            }else if(map[a]<=a){
                map[a] = map[a]+1;
            }else{
                res++;
                res+=a;
                map[a] = 1;
            }
        }
        return res;
    }
};