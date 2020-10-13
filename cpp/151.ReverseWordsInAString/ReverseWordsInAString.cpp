#include <cassert>
#include <iostream>
#include <string>

/*
解体思路：
     ****the*sky**is*blue**
     1.**eulb*si**yks*eht**** (swap)
     2.**eulb*si**yks*eht**** (swap,[0,6))
     3.blue***si**yks*eht**** (swap,[5,9))
     4.blue*is****yks*eht**** (swap,[8,14))
     5.blue*is*sky****eht**** (swap,[12,18))
     6.blue*is*sky*the******* (remove *)
     7.blue*is*sky*the

时间复杂度分析：O(n)
*/

class Solution {
public:
    std::string reverseWords(std::string s) {
        for (size_t i = 0; i < s.size() / 2; i++) {
            std::swap(s[i], s[s.size() - i - 1]);
        }
        int start(0);
        int end(-2);
        bool inWord(false);
        for (size_t i = 0; i <= s.size(); i++) {
            if (i != s.size() && s[i] != ' ') {
                inWord = true;
            }
            if (inWord && (i == s.size() || s[i] == ' ')) {
                inWord = false;
                start = end;
                while (start > 0 && s[start] == ' ') {
                    start--;
                }
                start += 2;
                end = i;
                for (int k = 0; k < (end - start) / 2; k++) {
                    std::swap(s[k + start], s[end - k - 1]);
                }
            }
        }
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        return s;
    }
};

void test1() {
    std::string input = "the sky is blue";
    std::string result = "blue is sky the";
    Solution s;
    assert(result == s.reverseWords(input));
}

void test2() {
    std::string input = "  hello world!  ";
    std::string result = "world! hello";
    Solution s;
    assert(result == s.reverseWords(input));
}

void test3() {
    std::string input = "a good   example";
    std::string result = "example good a";
    Solution s;
    assert(result == s.reverseWords(input));
}

void test4() {
    std::string input = "    the sky  is blue  ";
    std::string result = "blue is sky the";
    Solution s;
    assert(result == s.reverseWords(input));
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}