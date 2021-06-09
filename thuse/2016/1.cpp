// https://blog.csdn.net/da_kao_la/article/details/82416299
// Created by admin on 2021/6/8.
//  从控制台输入一个合法数字，打印其立方
//• 例如
//• 输入123456789
//• 输出1881676371789154860897069
//• 基本编码能力、消耗时间
using namespace std;
#include <vector>
#include <iostream>

class  Solution{
public:
    string multi(string s1,string s2) {
        vector<int> res(s1.size() + s2.size(), 0);
        for (int i = 0; i < s1.size(); ++i) {
            for (int j = 0; j < s2.size(); ++j) {
                int tmp = (s1[s1.size() - 1 - i] - '0') * (s2[s2.size() - 1 - j] - '0');
                add(res, i + j, tmp);
            }
        }


        string strRes="";
        int i;
        for (i = res.size() - 1; res[i] == 0; --i);
        while (i >= 0){
            strRes += to_string(res[i]);
            i--;
        }
        return strRes;
    }

    void add(vector<int>& res,int index,int n){
        res[index] += n;
        int record = 0;
        while (res[index]>=10){
            record = res[index] / 10;
            res[index] = res[index] % 10;
            res[index+1] += record;
            index++;
        }
    }
};


int main(){
    string a;
    cin >> a;
    Solution s;
    string res = s.multi(a,a);
    res = s.multi(res,a);
    cout << res;
}