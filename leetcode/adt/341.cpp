// https://leetcode-cn.com/problems/flatten-nested-list-iterator/
// Created by admin on 2021/3/23.
//
using namespace std;
#include <vector>

class NestedInteger {
public:
    int integer;
    bool isInt;
    vector <NestedInteger> list;
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger(){
        return isInt;
    }
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger(){
        return integer;
    }
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector <NestedInteger> &getList(){
        return list;
    }
};

class NestedIterator {
    vector<int> nums;
    int ptr;
public:
    NestedIterator(vector <NestedInteger> &nestedList) {
        dfs(nestedList);
        ptr = 0;
    }

    void dfs(const vector <NestedInteger> &nestedList){
        for (auto list:nestedList){
            if(list.isInteger()){
                nums.push_back(list.getInteger());
            }else{
                dfs(list.getList());
            }
        }
    }

    int next() {
        return nums[ptr++];
    }

    bool hasNext() {
        return ptr<nums.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main(){
    NestedInteger n1 = NestedInteger();
    n1.isInt= true;
    n1.integer=1;
    NestedInteger n2 = NestedInteger();
    n2.isInt = true;
    n2.integer=2;
    NestedInteger n3 = NestedInteger();
    n3.isInt= false;
    n3.list=vector<NestedInteger>{n1,n2};
    NestedInteger n4 = NestedInteger();
    n4.isInt= true;
    n4.integer=3;
    vector<NestedInteger> v{n3,n4};
    NestedIterator i(v);
    while (i.hasNext()){
        int res = i.next();
    }

}