// O(N*KlogK)
// Runtime Beats 77.69%

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        std::vector<std::vector<std::string>> results;
        for (const auto& str : strs) {
            auto t = str;
            std::sort(t.begin(), t.end());

            auto it = map.find(t);
            if (it != map.end()) {
                it->second.push_back(str);
            } else {
                map.insert({t, std::vector<std::string>{str}});
            }
        }

        for (const auto& [k, v] : map) {
            results.push_back(v);
        }

        return results;
    }
};

void test1() {
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> results{{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
    Solution s;
    assert(s.groupAnagrams(strs) == results);
}

void test2() {
    std::vector<std::string> strs{""};
    std::vector<std::vector<std::string>> results{{""}};
    Solution s;
    assert(s.groupAnagrams(strs) == results);
}

void test3() {
    std::vector<std::string> strs{"a"};
    std::vector<std::vector<std::string>> results{{"a"}};
    Solution s;
    assert(s.groupAnagrams(strs) == results);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}