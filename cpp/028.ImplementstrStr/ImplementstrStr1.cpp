// O(n+m)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// KMP
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        std::vector<int> next = get_nexts(needle);
        int n = haystack.size();
        int m = needle.size();
        // j 是 needle 字符串的索引
        // sadbutsad
        // sad
        int j = 0;
        for (int i = 0; i < n; i++) {
            // 如果不匹配，则跳到 next[j-1] 位置继续比较
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1] + 1;
            }

            if (haystack[i] == needle[j]) {
                j++;
            }
            // 如果 j 达到 needle 的长度，说明匹配成功，返回结果
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }

    std::vector<int> get_nexts(const std::string& needle) {
        std::vector<int> next(needle.size(), 0);

        next[0] = -1;
        // k 是好前缀的前缀子串长度
        int k = -1;
        for (int i = 1; i < needle.size(); i++) {
            while (k != -1 && needle[k + 1] != needle[i]) {
                k = next[k];
            }
            if (needle[k + 1] == needle[i]) {
                ++k;
            }
            next[i] = k;
        }
        return next;
    }
};

void test1() {
    Solution s;
    assert(s.strStr("sadbutsad", "sad") == 0);
}

void test2() {
    Solution s;
    assert(s.strStr("leetcode", "leeto") == -1);
}

int main() {
    test1();
    test2();
    return 0;
}