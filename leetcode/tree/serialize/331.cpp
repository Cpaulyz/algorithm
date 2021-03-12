// https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Created by admin on 2021/3/12.
// 从右往左遍历，遇到就#入栈，遇到数字，判断栈里元素是否≥2
// 如果是就出栈两个再入栈，否则直接返回false
// 状态压缩一下，不用栈也可以，拿一个数字存就可
// 最后栈元素（即foundNum）应该==1
using namespace std;
#include <string>
#include <vector>
class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder = ","+preorder;
        int foundNode = 0;
        bool isNum = false;
        for (int i = preorder.size()-1; i >=0; --i) {
            if(preorder[i]==','){
                if(isNum){
                    if(foundNode>=2){
                        foundNode--; // -2+1
                    }else{
                        return false;
                    }
                }
            }else if(preorder[i]=='#'){
                isNum = false;
                foundNode++;
            }else{ // number
                isNum = true;
            }
        }
        return foundNode==1;
    }
};