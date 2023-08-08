#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
private:
    stack<int> staIn;
    stack<int> staOut;

    void transfer(stack<int> stac) {
        while(!staIn.empty()) {
            staOut.push(staIn.top());
            staIn.pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        staIn.push(x);
    }
    
    int pop() {
        if(staOut.empty()) {
            transfer(staIn);
        }
        int ret = staOut.top();
        staOut.pop();
        return ret;
    }
    
    int peek() {
        if(staOut.empty()) {
            transfer(staIn);
        }
        return staOut.top();
    }
    
    bool empty() {
        return staIn.empty() && staOut.empty();
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