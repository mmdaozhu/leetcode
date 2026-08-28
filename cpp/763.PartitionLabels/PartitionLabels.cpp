/*
解题思路：
    贪心算法
    先记录每个字符最后出现的位置，再扫描字符串，用 end 不断扩张当前区间；
    当 i == end 时，就找到了一个合法的最短 partition。
*/

// O(n)
// Runtime Beats 32.02%

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            auto it = map.find(s[i]);
            if (it == map.end()) {
                map[s[i]] = i;
            } else {
                it->second = i;
            }
        }

        std::vector<int> result;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = std::max(end, map[s[i]]);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};

void test1() {
    std::string str = "ababcbacadefegdehijhklij";
    std::vector<int> result{9, 7, 8};
    Solution s;
    assert(s.partitionLabels(str) == result);
}

void test2() {
    std::string str = "eccbbbbdec";
    std::vector<int> result{10};
    Solution s;
    assert(s.partitionLabels(str) == result);
}

int main() {
    test1();
    test2();
    return 0;
}