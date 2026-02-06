/*
解题思路：
    动态规划
    dp(i，j) = 是否可以用s1 的前 i 个字符 + s2 的前 j 个字符组成 s3 的前 i+j 个字符
    dp(i, j) = (dp(i-1, j) && s1[i-1] == s3[i+j-1]) || (dp(i, j-1) && s2[j-1] == s3[i+j-1])
*/

// O(n*m)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int n = s1.size();
        int m = s2.size();
        if (n + m != s3.size()) {
            return false;
        }
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = true;
                }

                if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[n][m];
    }
};

void test1() {
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbcbcac";
    Solution s;
    assert(s.isInterleave(s1, s2, s3) == true);
}

void test2() {
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbbaccc";
    Solution s;
    assert(s.isInterleave(s1, s2, s3) == false);
}

void test3() {
    std::string s1 = "";
    std::string s2 = "";
    std::string s3 = "";
    Solution s;
    assert(s.isInterleave(s1, s2, s3) == true);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}