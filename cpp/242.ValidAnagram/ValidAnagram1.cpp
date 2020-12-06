/*
解体思路：
    使用unordered_map

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> map_s;
        for (const auto& c : s) {
            if (map_s.find(c) != map_s.end()) {
                map_s[c]++;
            } else {
                map_s[c] = 1;
            }
        }

        std::unordered_map<char, int> map_t;
        for (const auto& c : t) {
            if (map_t.find(c) != map_t.end()) {
                map_t[c]++;
            } else {
                map_t[c] = 1;
            }
        }

        return map_s == map_t;
    }
};

void test1() {
    std::string s = "anagram";
    std::string t = "nagaram";
    Solution solution;
    assert(solution.isAnagram(s, t) == true);
}

void test2() {
    std::string s = "rat";
    std::string t = "car";
    Solution solution;
    assert(solution.isAnagram(s, t) == false);
}

int main() {
    test1();
    return 0;
}