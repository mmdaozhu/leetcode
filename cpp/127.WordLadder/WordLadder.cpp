/*
解题思路：
    算法：BFS
    在set中找考察字符串的相邻字符串（只有一个字符不同），并加入队列中。
    依次考察队列中的字符串。

时间复杂度分析：O(n)

优化：
    1.IsChangeOneTime()函数中count大于1时直接返回。
    2.之前使用std::unordered_set<std::string> visited来保存访问过的字符串，现在在dict中删除。
*/

#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        auto depth = 0;
        std::queue<std::string> queue;
        queue.push(beginWord);
        while (!queue.empty()) {
            depth++;

            int size = queue.size();
            for (int i = 0; i < size; i++) {
                std::string node = queue.front();
                queue.pop();

                if (node == endWord) {
                    return depth;
                }

                for (auto it = dict.begin(); it != dict.end();) {
                    if (IsChangeOneTime(node, *it)) {
                        queue.push(*it);
                        dict.erase(it++);
                    } else {
                        it++;
                    }
                }
            }
        }
        return 0;
    }

    bool IsChangeOneTime(const std::string& left, const std::string& right) {
        auto count = 0;
        for (int i = 0; i < left.length(); i++) {
            if (left[i] != right[i]) {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return count == 1;
    }
};

void test1() {
    std::string beginWord = "hit";
    std::string endWord = "cog";

    std::vector<std::string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    assert(s.ladderLength(beginWord, endWord, wordList) == 5);
}

void test2() {
    std::string beginWord = "hit";
    std::string endWord = "cog";

    std::vector<std::string> wordList{"hot", "dot", "dog", "lot", "log"};
    Solution s;
    assert(s.ladderLength(beginWord, endWord, wordList) == 0);
}

int main() {
    test1();
    test2();
    return 0;
}