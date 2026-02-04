/*
解题思路：
    动态规划
    dp[i] = s 的前 i 个字符（s[0..i-1]）的解码方式数

    1）单字符解码：
        如果 s[i-1] 在 '1' ~ '9' 之间，
        则可以将 s[i-1] 单独解码，
        解码方式数可以从 dp[i-1] 转移过来：
            dp[i] += dp[i-1]

    2）双字符解码：
        如果 s[i-2..i-1] 组成的两位数在 10 ~ 26 之间，
        则可以将这两个字符一起解码，
        解码方式数可以从 dp[i-2] 转移过来：
            dp[i] += dp[i-2]
*/

// O(n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty()) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }
        std::vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= s.length(); i++) {
            // 单字符
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // 双字符
            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
};

void test1() {
    std::string str = "12";
    Solution s;
    assert(s.numDecodings(str) == 2);
}

void test2() {
    std::string str = "226";
    Solution s;
    assert(s.numDecodings(str) == 3);
}

void test3() {
    std::string str = "06";
    Solution s;
    assert(s.numDecodings(str) == 0);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}