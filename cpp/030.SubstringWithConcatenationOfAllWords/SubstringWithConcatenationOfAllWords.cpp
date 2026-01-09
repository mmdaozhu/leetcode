/*
解题思路：
    滑动窗口 + 哈希
*/

// O(n)
// Runtime Beats 31.89%

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        if (words.empty()) {
            return {};
        }

        std::vector<int> results;
        std::unordered_map<std::string, int> need;
        for (const auto& word : words) {
            auto it = need.find(word);
            if (it == need.end()) {
                need.insert({word, 1});
            } else {
                it->second++;
            }
        }

        int word_len = words[0].size();
        for (int i = 0; i < word_len; i++) {
            std::unordered_map<std::string, int> windows;
            int left = i;
            int right = i;
            int count = 0;

            while (right + word_len <= s.size()) {
                auto word = s.substr(right, word_len);
                right += word_len;
                if (need.count(word) != 0) {
                    auto it = windows.find(word);
                    if (it == windows.end()) {
                        windows.insert({word, 1});
                    } else {
                        it->second++;
                    }

                    count++;

                    while (windows[word] > need[word]) {
                        auto left_word = s.substr(left, word_len);
                        windows[left_word]--;
                        left += word_len;
                        count--;
                    }

                    if (count == words.size()) {
                        results.push_back(left);
                    }

                } else {
                    left = right;
                    windows.clear();
                    count = 0;
                }
            }
        }

        return results;
    }
};

void test1() {
    std::string str = "barfoothefoobarman";
    std::vector<std::string> words{"foo", "bar"};
    std::vector<int> results{0, 9};
    Solution s;
    assert(s.findSubstring(str, words) == results);
}

void test2() {
    std::string str = "wordgoodgoodgoodbestword";
    std::vector<std::string> words{"word", "good", "best", "word"};
    std::vector<int> results;
    Solution s;
    assert(s.findSubstring(str, words) == results);
}

void test3() {
    std::string str = "barfoofoobarthefoobarman";
    std::vector<std::string> words{"bar", "foo", "the"};
    std::vector<int> results{6, 9, 12};
    Solution s;
    assert(s.findSubstring(str, words) == results);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
