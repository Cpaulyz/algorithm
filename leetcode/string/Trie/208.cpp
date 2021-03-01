// https://leetcode-cn.com/problems/implement-trie-prefix-tree/
// Created by admin on 2021/3/1.
// 字典树
using namespace std;
#include <vector>
#include <string>
struct Node{
    bool isWord;
    Node* child[26]= {NULL};
    Node(){
        isWord = false;
    }
};
class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* n = root;
        for (int i = 0; i < word.size(); ++i) {
            if(n->child[word[i]-'a']==NULL){
                n->child[word[i]-'a']=new Node();
            }
            n = n->child[word[i]-'a'];
        }
        n->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* n = root;
        for (int i = 0; i < word.size(); ++i) {
            if(n->child[word[i]-'a']==NULL){
                return false;
            }
            n = n->child[word[i]-'a'];
        }
        return n->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* n = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if(n->child[prefix[i]-'a']==NULL){
                return false;
            }
            n = n->child[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */