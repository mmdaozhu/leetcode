#include <cassert>
#include <iostream>
#include <vector>

/*
解体思路：
    因为vector是顺序存储的，做reverse直接用索引替换就好了。

时间复杂度分析：O(n)
*/

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (size_t i = 0; i < s.size() / 2; i++) {
            std::swap(s[i], s[s.size() - i - 1]);
        }
    }
};

void test1() {
    std::vector<char> string{'h', 'e', 'l', 'l', 'o'};
    std::vector<char> result{'o', 'l', 'l', 'e', 'h'};
    Solution s;
    s.reverseString(string);
    assert(result == string);
}

void test2() {
    std::vector<char> string{'H', 'a', 'n', 'n', 'a', 'h'};
    std::vector<char> result{'h', 'a', 'n', 'n', 'a', 'H'};
    Solution s;
    s.reverseString(string);
    assert(result == string);
}

int main() {
    test1();
    test2();
    return 0;
}