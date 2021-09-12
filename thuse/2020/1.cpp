// https://my.oschina.net/u/4347922/blog/4601907
// Created by 陈彦泽 on 2021/9/11.
//
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        vector<int> tmp = dp(root);
        cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
        return min(min(tmp[0],tmp[1]),tmp[2]+1);
    }


    // [0]: 该节点没有监控，但被监视到了
    // [1]：该节点有监控
    // [2]：该节点没有监控，且没有被监视到
    vector<int> dp(TreeNode* node){
        vector<int> res(3,0);
        if(node==nullptr){
            res[1]=res[2]=999999;
            return res;
        }
        vector<int> l = dp(node->left);
        vector<int> r = dp(node->right);
        res[1] = 1 + min(min(l[0],l[1]),l[2])+ min(min(r[0],r[1]),r[2]);
        res[0] = min(min(l[0]+r[1],l[1]+r[0]),l[1]+r[1]);
        res[2] = l[0]+r[0];
        return res;
    }
};