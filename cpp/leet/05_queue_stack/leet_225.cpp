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
#include <queue>
#include <unordered_map>

class MyStack {
private:
    std::queue<int> queueA_;
    std::queue<int> queueB_;
public:
    MyStack() {
    }
    
    void push(int x) {
       if (!queueA_.empty() && queueB_.empty()) {
           queueA_.push(x);
           return ;
       }

       if (!queueB_.empty() && queueA_.empty()) {
           queueB_.push(x);
           return ;
       }

       queueA_.push(x);
    }
    
    int pop() {
        int tmp = -1;
        if (!queueA_.empty() && queueB_.empty()) {
            while (queueA_.size() != 1) {
                queueB_.push(queueA_.front());
                queueA_.pop();
            }
            tmp = queueA_.front();
            queueA_.pop();
        } else if (!queueB_.empty() && queueA_.empty()) {
            while(queueB_.size() != 1) {
                queueA_.push(queueB_.front());
                queueB_.pop();
            }
            tmp = queueB_.front();
            queueB_.pop();
        }
        return tmp;
    }
    
    int top() {
        if (!queueA_.empty()) {
            return queueA_.back();
        }

        if (!queueB_.empty()) {
            return queueB_.back();
        }

        return -1;
    }
    
    bool empty() {
        return queueA_.empty() && queueB_.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


/*
输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
*/

void test1() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2); 

    int top = myStack.top();
    std::cout << "top:" << top << ", expected:" << 2 << std::endl;
    
    int out = myStack.pop();
    std::cout << "out:" << out << ", expected:" << 2 << std::endl;

    std::cout << std::boolalpha;
    std::cout << myStack.empty() << ", expected:" << false << std::endl;
}

int main() {
    test1();
    // test2();
    return 0;
}