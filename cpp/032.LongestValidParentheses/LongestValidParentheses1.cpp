/*
解题思路：
    动态规划
    dp[i] = 以 s[i] 结尾的最长有效括号长度
    必须以第 i 个字符作为结尾
    dp[0] = 0


    1）如果 s[i] 是 '('
        dp[i] = 0

    2）如果 s[i] 是 ')'
       分两种情况：

       （1）s[i-1] 是 '('，对应的情况是 ()
           dp[i] = dp[i-2] + 2

       （2）s[i-1] 是 ')'

           当前 ')' 可能匹配前面有效括号之后的 '('

           找匹配位置：
           i - dp[i-1] - 1

           如果这里是 '('：

           dp[i−1]              中间的长度
           2                    当前一对括号
           dp[i−dp[i−1]−2]      前面可能还有连续有效括号
           dp[i] = dp[i−1] + 2 + dp[i−dp[i−1]−2]
*/

// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int n = s.size();
        std::vector<int> dp(n, 0);

        int result = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    // 1. ()
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else {
                    // 2. (())
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;

                        // 前面还有一段有效括号
                        if (i - dp[i - 1] - 2 >= 0) {
                            dp[i] += dp[i - dp[i - 1] - 2];
                        }
                    }
                }
            }
            result = std::max(result, dp[i]);
        }

        return result;
    }
};

void test1() {
    std::string s = "(()";
    Solution solution;
    assert(solution.longestValidParentheses(s) == 2);
}

void test2() {
    std::string s = ")()())";
    Solution solution;
    assert(solution.longestValidParentheses(s) == 4);
}

void test3() {
    std::string s = "";
    Solution solution;
    assert(solution.longestValidParentheses(s) == 0);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}