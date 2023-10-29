#include "../../utils/print_tools.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue myQueue;
        for (int i = 0; i < k; i++) {
            myQueue.push(nums[i]);
        }

        vector<int> result;
        result.push_back(myQueue.front());

        for (int i = k; i < nums.size(); i++) {
            myQueue.pop(nums[i-k]);
            myQueue.push(nums[i]);
            result.push_back(myQueue.front());
        }
        return result;
    }
private:
    class MyQueue {
    public:
        deque<int> dQueue; // 从大到小

        void push(int value) {
            while (!dQueue.empty() && value > dQueue.back()) {
                dQueue.pop_back();
            }
            dQueue.push_back(value);
        }

        void pop(int value) {
            if (!dQueue.empty() && dQueue.front() == value) {
                dQueue.pop_front();
            }
        }

        int front() {
            return dQueue.front();
        }
    };
};

void test1() {
    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k = 3;

    Solution sn;
    vector<int> result = sn.maxSlidingWindow(nums, k);
    print(result);
    std::cout << ", expected:[3,3,5,5,6,7]" << std::endl;
}

void test2() {
    vector<int> nums {1};
    int k = 1;

    Solution sn;
    vector<int> result = sn.maxSlidingWindow(nums, k);
    print(result);
    std::cout << ", expected:[1]" << std::endl;
}


int main() {
//    test1();
    test2();
    return 0;
}