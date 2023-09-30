#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>

class MyQueue {
private:
    std::stack<int> stackIn_;
    std::stack<int> stackOut_;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stackIn_.push(x);
    }
    
    int pop() {
        if (!stackOut_.empty()) {
            int tmp = stackOut_.top();
            stackOut_.pop();
            return tmp;
        } else {
            while (!stackIn_.empty()) {
                stackOut_.push(stackIn_.top());
                stackIn_.pop();
            }
        
            int top = stackOut_.top();
            stackOut_.pop();
            return top;
        }
    }
    
    int peek() {
        if (!stackOut_.empty()) {
            int tmp = stackOut_.top();
            stackOut_.pop();
            return tmp;
        } else {
            while (!stackIn_.empty()) {
                stackOut_.push(stackIn_.top());
                stackIn_.pop();
            }

            return stackOut_.top();
        }
    }
    
    bool empty() {
        return stackIn_.empty() && stackOut_.empty();
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

// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false


void test1() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2); 
    int top = myQueue.peek();
    std::cout << "top:" << top << ", expected:" << 1 << std::endl;
    int out = myQueue.pop();
    std::cout << "out:" << out << ", expected:" << 1 << std::endl;

    std::cout << std::boolalpha;
    std::cout << myQueue.empty() << ", expected:" << false << std::endl;
}

/*
["MyQueue","push","push","push","push","pop","push","pop","pop","pop","pop"]
[[],[1],[2],[3],[4],[],[5],[],[],[],[]]
Expected: [null,null,null,null,null,1,null,2,3,4,5]
*/

void test2() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2); 
    myQueue.push(3); 
    myQueue.push(4); 
    
    int popResult = myQueue.pop();
    std::cout << "popResult:" << popResult << ", expected:" << 1 << std::endl;
    
    myQueue.push(5);

    popResult = myQueue.pop();
    std::cout << "popResult:" << popResult << ", expected:" << 2 << std::endl;
    
    popResult = myQueue.pop();
    std::cout << "popResult:" << popResult << ", expected:" << 3 << std::endl;
    
    popResult = myQueue.pop();
    std::cout << "popResult:" << popResult << ", expected:" << 4 << std::endl;
    
    popResult = myQueue.pop();
    std::cout << "popResult:" << popResult << ", expected:" << 5 << std::endl;
}

int main() {
    test1();
    test2();
    return 0;
}