// https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/
// Created by admin on 2021/2/26.
//
using namespace std;

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
        vector<int> res;
//        vector<int> wordMap(words.size());
        unordered_map<int,int> wordMap;
        for (int i = 0; i < words.size(); ++i) {
            int tmp = 0;
            for (char c:words[i]) {
                tmp |= 1 << (c - 'a');
            }
            wordMap[tmp]+=1;
        }
        for (int i = 0; i < puzzles.size(); ++i) {
            res.push_back(helper(wordMap, puzzles[i]));
        }
        return res;
    }
    // 100101

    int helper(unordered_map<int,int> &wordMap, string& puzzle) {
        int res = 0;
        int first = 1<<(puzzle[0]-'a');
        int puzzleMap = 0;
        for (int i = 1; i < puzzle.size(); ++i) {
            int c= puzzle[i];
            puzzleMap |= 1 << (c - 'a');
        }
        int subSet = puzzleMap;
        res+=wordMap[first];
        while (subSet!=0){
            int h = first|subSet;
            res+=wordMap[h];
            subSet = (subSet-1)&puzzleMap;
        }
        return res;
    }
};
int main(){
    vector<string> w{"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> p{"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    Solution s;
    s.findNumOfValidWords(w,p);
}