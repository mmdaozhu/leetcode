#include <cassert>
#include <iostream>
#include <string>
#include <vector>

/*
解体思路：
    动态规划

    dp[i][j] = d[i-1][j-1] (w1[i]==w2[j])
    dp[i][j] = min{dp[i-1][j],dp[i][j-1],dp[i-1][j-1]} + 1 (w1[i]!=w2[j])
    (word1前i个字符->word2前j个字符 最少步数)

时间复杂度分析：O(n*m)
*/

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size();
        int n = word2.size();
        std::cout << n;

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