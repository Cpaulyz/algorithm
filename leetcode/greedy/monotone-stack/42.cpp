// https://leetcode-cn.com/problems/trapping-rain-water/
// Created by admin on 2021/2/23.
//

using namespace std;

#include <vector>
#include <stack>

struct Node {
    int pos;
    int height;

    Node(int pos, int height) {
        this->pos = pos;
        this->height = height;
    }
};

class Solution {
public:
    int trap(vector<int> &height) {
        if(height.size()==0){
            return 0;
        }
        int sum=0;
        stack <Node> down; // 单调减栈
        for (int i = 0; i < height.size(); ++i) {
            int tmp = 0;
            while ((!down.empty()) && down.top().height < height[i]) {
                tmp = down.top().pos;
                down.pop();
            }
            if (down.empty()) { // 出现新高
                for (int j = tmp; j < i; ++j) {
                    sum += height[tmp] - height[j];
                }
            }
            down.push(Node(i, height[i]));
        }
        Node prev = down.top();
        down.pop();
        while (!down.empty()){
            Node tmp = down.top();
            for (int i = tmp.pos+1; i < prev.pos; ++i) {
                sum+= prev.height - height[i];
            }
            down.pop();
            prev = tmp;
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> a{0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(a);
}