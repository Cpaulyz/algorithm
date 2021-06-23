// https://leetcode-cn.com/problems/throne-inheritance/
// Created by admin on 2021/6/23.
// 其实就是造n叉树+前序遍历

using namespace  std;
#include <vector>
#include <string>
#include <unordered_map>

struct people{
    string name;
    bool dead;
    vector<people*> sons;
    people(string n):name(n),dead(false){};
};

class ThroneInheritance {
    people* king;
    unordered_map<string,people*> people_map;

public:
    ThroneInheritance(string kingName) {
        king = new people(kingName);
        people_map[kingName] = king;
    }

    void birth(string parentName, string childName) {
        people* chi = new people(childName);
        people_map[childName] = chi;
        people_map[parentName]->sons.push_back(chi);
    }

    void death(string name) {
        people_map[name]->dead = true;
    }

    vector<string> getInheritanceOrder() {
        vector<string> res;
        successor(res,king);
        return res;
    }

    void successor(vector<string>& curOrder,people* curPeople){
        if(!curPeople->dead){
            curOrder.push_back(curPeople->name);
        }
        for (people* son:curPeople->sons){
            successor(curOrder,son);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */