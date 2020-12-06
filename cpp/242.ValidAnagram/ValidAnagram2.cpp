/*
解体思路：
    排序

时间复杂度分析：O(nlogn)
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
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