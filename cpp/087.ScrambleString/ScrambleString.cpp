/*
解题思路：
    动态规划
    dp[i][j][len] 表示：s1 从 i 开始长度为 len 的子串，是否可以通过扰乱得到 s2 从 j 开始长度为 len 的子串
    对于长度 len，尝试每个可能的切分点 k（1..len-1）：

*/

// O(n*n*n*n)
// Runtime Beats 50.72%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isScramble(std::string s1, std::string s2) {
        int n = s1.length();
        if (n != s2.length()) {
            return false;
        }

        if (s1 == s2) {
            return true;
        }

        std::vector<std::vector<std::vector<bool>>> dp(
            n, std::vector<std::vector<bool>>(n, std::vector<bool>(n + 1, false)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    for (int k = 1; k < len; k++) {
                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }

                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};

void test1() {
    std::string s1 = "great";
    std::string s2 = "rgeat";
    Solution s;
    assert(s.isScramble(s1, s2));
}

void test2() {
    std::string s1 = "abcde";
    std::string s2 = "caebd";
    Solution s;
    assert(!s.isScramble(s1, s2));
}

void test3() {
    std::string s1 = "a";
    std::string s2 = "a";
    Solution s;
    assert(s.isScramble(s1, s2));
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}