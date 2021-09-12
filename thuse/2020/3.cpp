// http://poj.org/problem?id=1179
// Created by 陈彦泽 on 2021/9/11.
// 区间dp
/*
给一串共N个数字排成一环，数字间有边，边上有乘号或者加号，去掉一条边之后，将两边数字按照边上算符可以合并成一新的个数字，可以递归地删除边最终得到一个数字，求第一次去掉哪一条边能获得最大数字?
例子
1 + 2
X   X
4 + 5
第一次删除12 中间的+号有：2 X 5 + 4 X 1，再分别删掉 第二个、第一个、第三个得到最大值18
N <= 50
*/


using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>

class Main{
public:
    int getMaxResult(vector<int> numbers,vector<char> operands){
        // dp[i][j][0] 表示 [i..j]最小的计算结果
        // dp[i][j][1] 表示 [i..j]最小的计算结果
        vector<vector<vector<int> > > dp(numbers.size(), vector<vector<int> >(numbers.size(),vector<int>(2,0)));
        // init
        for (int i = 0; i < numbers.size(); ++i) {
            for (int j = i+1; j < numbers.size(); ++j) {
                dp[i][j][0] = 9999999;
                dp[i][j][1] = -9999999;
            }
        }
        for (int i = 0; i < numbers.size(); ++i) {
            dp[i][i][0]=dp[i][i][1] = numbers[i];
        }
        for (int i = 0; i < numbers.size() - 1; ++i) {
            if(operands[i]=='t'){
                dp[i][i+1][0] = dp[i][i+1][1] = numbers[i]+numbers[i+1];
            }else{
                dp[i][i+1][0] = dp[i][i+1][1] = numbers[i]*numbers[i+1];
            }
        }
        // dp
        for (int gap = 2; gap < numbers.size(); ++gap) {
            for (int i = 0; i < numbers.size()-gap; ++i) {
                // calculate for dp[i][i+gap]
                for (int mid = 0; mid < gap; ++mid) {
                    vector<int> tmp = cal(dp[i][i+mid][1],dp[i][i+mid][0],dp[i+mid+1][i+gap][1],dp[i+mid+1][i+gap][0],operands[i+mid]);
                    dp[i][i+gap][0] = min(dp[i][i+gap][0], tmp[0]);
                    dp[i][i+gap][1] = max(dp[i][i+gap][1], tmp[1]);
                }
            }
        }
        return dp[0][numbers.size()-1][1];
    }

    void run(){
        int n;
        cin >> n;
        vector<int> nums;
        vector<char> ops;
        for (int i = 0; i < n; ++i) {
            int num;
            char c;
            cin >> c >> num;
            nums.push_back(num);
            ops.push_back(c);
        }
        int res = -999999;
        vector<int> resEdge;
        for (int i = 0; i < n; ++i) {
            vector<int> numbers;
            vector<char> operands;
            for (int j = 0; j < n; ++j) {
                numbers.push_back(nums[(j+i)%n]);
                operands.push_back(ops[(j+i+1)%n]);
            }
            int tmp = getMaxResult(numbers,operands);
            if(tmp>res){
                res = tmp;
                resEdge.clear();
                resEdge.push_back(i+1);
            }else if(tmp==res){
                resEdge.push_back(i+1);
            }
        }
        cout << res << endl;
        for (int i = 0; i < resEdge.size(); ++i) {
            cout << resEdge[i];
            if(i!=resEdge.size()-1){
                cout << " ";
            }else{
                cout << endl;
            }
        }
    }
private:
    // 0是最小，1是最大
    vector<int> cal(int a_max,int a_min,int b_max,int b_min,char op){
        if(op=='t'){
            return vector<int>({a_min+b_min,a_max+b_max});
        }else {
            int a,b,c,d;
            a = a_min*b_min;
            b = a_max*b_max;
            c = a_min*b_max;
            d = a_max*b_min;
            return vector<int>({min(min(a,b), min(c,d)),max(max(a,b), max(c,d))});
        }
    }
};

int main(){
    Main main;
    main.run();
}