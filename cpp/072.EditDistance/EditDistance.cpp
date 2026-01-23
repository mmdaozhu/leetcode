/*
解题思路：
    动态规划
    dp[i][j] 表示将 word1[0..i-1] 转换为 word2[0..j-1] 的最少操作次数。
    对于每一对 (i,j)，有三种操作可以考虑：
    Insert: dp[i][j-1] + 1
    我们已经知道把 word1 的前 i 个字符变成 word2 的前 j-1 个字符需要 dp[i][j-1] 步。
    此时 word1 的前 i 个已经搞定了 word2 的前 j-1 个，但 word2 还多出一个字符 word2[j]。
    因此，我们需要在 word1 的末尾插入一个和 word2[j] 一样的字符。

    Delete: dp[i-1][j] + 1
    Replace: dp[i-1][j-1] + (word1[i-1] != word2[j-1] ? 1 : 0)
*/

// O(m*n)
// Runtime Beats 61.99%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size();
        int n = word2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j < n + 1; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        return dp[m][n];
    }
};

void test1() {
    std::string word1 = "horse";
    std::string word2 = "ros";
    Solution s;
    assert(s.minDistance(word1, word2) == 3);
}

void test2() {
    std::string word1 = "intention";
    std::string word2 = "execution";
    Solution s;
    assert(s.minDistance(word1, word2) == 5);
}

int main() {
    test1();
    test2();
    return 0;
}