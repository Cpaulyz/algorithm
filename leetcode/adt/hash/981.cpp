// https://leetcode-cn.com/problems/time-based-key-value-store/
// Created by admin on 2021/7/10.
// 哈希套数组+二分查找

using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>
struct TimeValue{
    int timeStamp;
    string value;
    TimeValue(int t,string v):timeStamp(t),value(v){};
};
class TimeMap {
private:
    unordered_map<string,vector<TimeValue*>> map;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        map = unordered_map<string,vector<TimeValue*>>();
    }

    void set(string key, string value, int timestamp) {
        if(map.count(key)==0){
            map[key] = vector<TimeValue*>();
        }
        map[key].push_back(new TimeValue(timestamp,value));
    }

    string get(string key, int timestamp) {
        if(map.count(key)==0 || map[key][0]->timeStamp>timestamp){
            return "";
        }
        int left=0,right=map[key].size()-1;
        while(left<right){
            int mid = left+(right-left+1)/2;
            if(map[key][mid]->timeStamp==timestamp){
                return map[key][mid]->value;
            }else if(map[key][mid]->timeStamp>timestamp){
                right = mid-1;
            }else if(map[key][mid]->timeStamp<timestamp){
                left = mid;
            }
        }
        return map[key][left]->value;
    }
};

int main(){
    TimeMap kv;
    kv.set("foo", "bar", 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1
    cout << kv.get("foo", 1) << endl;  // 输出 "bar
    cout <<kv.get("foo", 3)<< endl; // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）  
    kv.set("foo", "bar2", 4);
    cout <<kv.get("foo", 4)<< endl; // 输出 "bar2"
    cout <<kv.get("foo", 5)<< endl; // 输出 "bar2"
}
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */