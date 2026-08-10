/*
解题思路：
    动态规划
    dp[i][j] = s[i...j] 是否是回文串

    dp[i][j] = s[i]==s[j] && dp[i+1][j-1]

    1）如果 s[i] != s[j]
        dp[i][j] = false

    2）如果 s[i] == s[j]
       分两种情况：

       （1）j-i<=2
           dp[i][j] = true

       （2）否则
           dp[i][j] = dp[i+1][j-1];
*/

// O(n*n)
// Runtime Beats 20.75%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) {
            return "";
        }
        int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        int start = 0;
        int max_len = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j]) {
                    if (j - i + 1 > max_len) {
                        max_len = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};

void test1() {
    Solution s;
    assert(s.longestPalindrome("babad") == "aba");
}

void test2() {
    Solution s;
    assert(s.longestPalindrome("cbbd") == "bb");
}

int main() {
    test1();
    test2();
    return 0;
}