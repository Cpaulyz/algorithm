// https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/
// Created by admin on 2021/2/1.
// 字段树模板题

using namespace std;
#include <string>
struct Trie {
    bool isWord;
    Trie* children[26];
    Trie() {
        isWord = false;
        for (auto& child : children) {
            child = nullptr;
        }
    }
};

class WordDictionary {
public:
    Trie* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        Trie* r = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word.at(i);
            if(r->children[c-'a']== nullptr){
                r->children[c-'a']=new Trie();
            }
            r = r->children[c-'a'];
        }
        r->isWord= true;
    }

    bool search(string word) {
        return match(word,root,0);
    }

    bool match(string word,Trie* r,int index){
        if(r== nullptr){
            return false;
        }
        if(index==word.size()-1){
            return r->isWord;
        }
        if(word.at(index)=='.'){
            bool tmp = false;
            for (int i = 0; i < 26; ++i) {
                tmp = match(word,r->children[i],index+1);
                if(tmp == true){
                    break;
                }
            }
            return tmp;
        }else{
            char c = word.at(index);
            return match(word,r->children[c-'a'],index+1);
        }
    }
};