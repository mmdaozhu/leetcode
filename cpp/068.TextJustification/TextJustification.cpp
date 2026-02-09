/*
解题思路：
    贪心算法
*/

// O(n)
// Runtime Beats 100.00%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        int start = 0;
        // 表示当前行已经填充的字符长度
        int count = 0;
        std::vector<std::string> results;
        for (int i = 0; i < words.size(); i++) {
            if (count + words[i].size() + (i - start) > maxWidth) {
                int total_space = maxWidth - count;
                int gaps = i - start - 1;
                std::string line;
                if (gaps == 0) {
                    line += words[start];
                    line += std::string(total_space, ' ');
                } else {
                    int space_per_gap = total_space / gaps;
                    int extra_spaces = total_space % gaps;
                    for (int j = start; j < i; j++) {
                        line += words[j];
                        if (j < i - 1) {
                            line += std::string(space_per_gap + (j - start < extra_spaces ? 1 : 0), ' ');
                        }
                    }
                }
                results.push_back(line);
                start = i;
                count = words[i].size();
            } else {
                count += words[i].size();
            }
        }

        // 处理最后一行，左对齐
        std::string last_line;
        for (int i = start; i < words.size(); i++) {
            if (i > start) last_line += ' ';
            last_line += words[i];
        }
        last_line += std::string(maxWidth - last_line.size(), ' ');
        results.push_back(last_line);

        return results;
    }
};

void test1() {
    std::vector<std::string> words{"This", "is", "an", "example", "of", "text", "justification."};
    Solution s;
    std::vector<std::string> result{"This    is    an", "example  of text", "justification.  "};
    assert(s.fullJustify(words, 16) == result);
}

void test2() {
    std::vector<std::string> words{"What", "must", "be", "acknowledgment", "shall", "be"};
    Solution s;
    std::vector<std::string> result{"What   must   be", "acknowledgment  ", "shall be        "};
    assert(s.fullJustify(words, 16) == result);
}

void test3() {
    std::vector<std::string> words{"Science", "is", "what",       "we",   "understand", "well",
                                   "enough",  "to", "explain",    "to",   "a",          "computer.",
                                   "Art",     "is", "everything", "else", "we",         "do"};
    Solution s;
    std::vector<std::string> result{"Science  is  what we", "understand      well", "enough to explain to",
                                    "a  computer.  Art is", "everything else we",   "do                  "};
    assert(s.fullJustify(words, 20) == result);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}