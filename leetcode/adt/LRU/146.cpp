// https://leetcode-cn.com/problems/lru-cache/
// Created by admin on 2021/2/23.
// 哈希+双向链表 实现一个LRU
using namespace std;

#include <vector>
#include <unordered_map>

struct node {
    int key;
    int value;
    node *next;
    node *prev;

    node(int key, int value) {
        this->key = key;
        this->value = value;
        next = prev = NULL;
    }
};

class LRUCache {
    unordered_map<int, node *> map;
    node *head;
    node *tail;
    int size;
    int capacity;
public:
    LRUCache(int capacity) {
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->prev = tail->next = NULL;
        head->next = tail;
        tail->prev = head;
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int key) {
        node *n = map[key];
        if (n == NULL) {
            return -1;
        } else {
            if (n->prev != NULL) {
                n->prev->next = n->next;
            }
            if (n->next != NULL) {
                n->next->prev = n->prev;
            }
            n->prev = head;
            n->next = head->next;
            head->next->prev = n;
            head->next = n;
            return n->value;
        }
    }

    void put(int key, int value) {
        node *n = new node(key, value);
        n->value = value;
        node *oldNode = map[key];
        if (oldNode == NULL) {
            oldNode = new node(key, value);
            map[key] = oldNode;
            size++;
        } else {
            oldNode->value = value;
            oldNode->prev->next = oldNode->next;
            oldNode->next->prev = oldNode->prev;
        }
        oldNode->prev = head;
        oldNode->next = head->next;
        head->next->prev = oldNode;
        head->next = oldNode;
        // capacity
        while (size > capacity) {
            map[tail->prev->key] = NULL;
            tail->prev = tail->prev->prev;
            tail->prev->next = tail;
            size--;
        }
    }
};

int main() {
    LRUCache lruCache(2);
    lruCache.put(2, 1);
    lruCache.put(1, 1);
    lruCache.put(4, 1);
    lruCache.put(2, 3);
    lruCache.get(1);
    lruCache.get(2);
}