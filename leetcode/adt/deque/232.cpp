// https://leetcode-cn.com/problems/implement-queue-using-stacks/
// Created by admin on 2021/3/5.
//

using namespace std;
#include <stack>

class MyQueue {
private:
    stack<int> s1; // in
    stack<int> s2; // out
    int size;
private:
    void in2out(){
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue():size(0),s1(),s2() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        size++;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()){
            in2out();
        }
        int res = s2.top();
        s2.pop();
        size--;
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()){
            in2out();
        }
        int res = s2.top();
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue *myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue->peek(); // return 1
    myQueue->pop(); // return 1, queue is [2]
    myQueue->empty(); // return false
}