// O(n*L) L = 每层平均字符串长度（逐渐增长）
// Runtime Beats 28.78%

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string result = "1";
        for (int i = 1; i < n; i++) {
            std::string next;
            int count = 1;
            for (int j = 0; j < result.length() - 1; j++) {
                if (result[j] != result[j + 1]) {
                    next += std::to_string(count);
                    next += result[j];
                    count = 1;
                } else {
                    count++;
                }
            }
            next += std::to_string(count);
            next += result[result.length() - 1];
            result = next;
        }

        return result;
    }
};

void test1() {
    Solution s;
    assert(s.countAndSay(4) == "1211");
}

void test2() {
    Solution s;
    assert(s.countAndSay(1) == "1");
}

int main() {
    test1();
    test2();
    return 0;
}