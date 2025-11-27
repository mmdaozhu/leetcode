// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i = s.length() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int len = 0;

        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        return len;
    }
};

void test1() {
    std::string str = "Hello World";
    Solution s;
    assert(s.lengthOfLastWord(str) == 5);
}

void test2() {
    std::string str = "   fly me   to   the moon  ";
    Solution s;
    assert(s.lengthOfLastWord(str) == 4);
}

void test3() {
    std::string str = "luffy is still joyboy";
    Solution s;
    assert(s.lengthOfLastWord(str) == 6);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}