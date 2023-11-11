#include "../../utils/print_tools.h"


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(), 0);

        stack<int> largeIdxStack;
        largeIdxStack.push(0);

        for (int i = 1; i < temperatures.size(); i++) {
            while (!largeIdxStack.empty() && temperatures[i] > temperatures[largeIdxStack.top()]) {
                int top = largeIdxStack.top();
                largeIdxStack.pop();
                results[top] = i - top;
            }
            largeIdxStack.push(i);
        }
        return results;
    }
};

//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        vector<int> results(temperatures.size(), 0);
//
//        for (int i = 0; i < temperatures.size(); i++) {
//            for (int j = i + 1; j < temperatures.size(); j++) {
//                if (temperatures[j] > temperatures[i]) {
//                    results[i] = j - i;
//                    break;
//                }
//            }
//        }
//        return results;
//    }
//};

void test1() {
    vector<int> temperatures {73,74,75,71,69,72,76,73};

    Solution sn;
    vector<int> results = sn.dailyTemperatures(temperatures);
    print(results);
    std::cout << ", expected:[1,1,4,2,1,1,0,0]" << std::endl;
}

void test2() {
    vector<int> temperatures {30,40,50,60};

    Solution sn;
    vector<int> results = sn.dailyTemperatures(temperatures);
    print(results);
    std::cout << ", expected:[1,1,1,0]" << std::endl;
}

void test3() {
    vector<int> temperatures {30,60,90};

    Solution sn;
    vector<int> results = sn.dailyTemperatures(temperatures);
    print(results);
    std::cout << ", expected:[1,1,0]" << std::endl;
}


int main() {
    test1();
    test2();
    test3();
    return 0;
}