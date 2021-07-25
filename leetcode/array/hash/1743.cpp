// https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/
// Created by admin on 2021/7/25.
// 哈希链表

using namespace std;
#include <unordered_map>
#include <vector>

struct Node{
    int n;
    Node* neighbor[2];
    int neighborCnt;
    Node(int num):n(num),neighborCnt(0){neighbor[0]=neighbor[1]=nullptr;}
};
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,Node*> nodes;
        // 创建链表
        for (int i = 0; i < adjacentPairs.size(); ++i) {
            if(nodes.count(adjacentPairs[i][0])==0){
                nodes[adjacentPairs[i][0]] = new Node(adjacentPairs[i][0]);
            }
            if(nodes.count(adjacentPairs[i][1])==0){
                nodes[adjacentPairs[i][1]] = new Node(adjacentPairs[i][1]);
            }
            Node* first = nodes[adjacentPairs[i][0]];
            Node* second = nodes[adjacentPairs[i][1]];
            first->neighbor[first->neighborCnt++] = second;
            second->neighbor[second->neighborCnt++] = first;
        }
        // 找头节点
        vector<int> res;
        for(auto pair:nodes){
            if(pair.second->neighborCnt==1){
                createResult(pair.second,res);
                break;
            }
        }
        return res;
    }

    void createResult(Node* head, vector<int>&res){
        res.push_back(head->n);
        int prev = head->n;
        head = head->neighbor[0];
        while(head->neighborCnt>1){
            res.push_back(head->n);
            if(head->neighbor[0]->n!=prev){
                prev = head->n;
                head = head->neighbor[0];
            }else{
                prev = head->n;
                head = head->neighbor[1];
            }
        }
        res.push_back(head->n);
    }


};