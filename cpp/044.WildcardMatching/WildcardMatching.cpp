/*
解题思路：
    动态规划
    dp(i,j) 表示 s[0..i-1] 和 p[0..j-1] 是否匹配
    dp(i,j) =

    1）如果 p[j-1] 是普通字符或 '?'
       （'?' 可以匹配任意一个字符）

       若 s[i-1] == p[j-1] 或 p[j-1] == '?'
       则：
            dp(i, j) = dp(i-1, j-1)

       否则：
            dp(i, j) = false


    2）如果 p[j-1] 是 '*'
       '*' 作用于 p[j-2]，表示 p[j-2] 出现 0 次或多次

       分两种情况：

       （1）'*' 表示 0 次
           dp[i][j - 1]

       （2）'*' 表示 >= 1 次
           dp[i - 1][j]
*/

// O(m*n)
// Runtime Beats 100%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*' && dp[0][j - 1]) {
                dp[0][j] = true;
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                } else {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};

void test1() {
    std::string s = "aa";
    std::string p = "a";
    Solution solution;
    assert(!solution.isMatch(s, p));
}

void test2() {
    std::string s = "aa";
    std::string p = "*";
    Solution solution;
    assert(solution.isMatch(s, p));
}

void test3() {
    std::string s = "cb";
    std::string p = "?a";
    Solution solution;
    assert(!solution.isMatch(s, p));
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}