// https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&&tqId=11183&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = array[0];
        vector<int> pd;
        pd.push_back(array[0]);
        for(int i = 1;i < array.size();++i){
            int maxtemp;
            if(pd[i-1]<0){
                maxtemp = array[i];
                pd.push_back(array[i]);
            }else{
                maxtemp = array[i]+pd[i-1];
                pd.push_back(array[i]+pd[i-1]);
            }
            if(maxtemp>max){
                max = maxtemp;
            }
        }
        return max;
    }
};

int main(){
    vector<int> vect{1,-2,3,10,-4,7,2,-5};
    Solution s;
    cout << s.FindGreatestSumOfSubArray(vect) <<endl;
}