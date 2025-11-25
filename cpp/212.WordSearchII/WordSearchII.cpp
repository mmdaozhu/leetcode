/*
解题思路：
    Trie
    深度优先遍历
*/

#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <vector>

struct TrieNode {
    TrieNode(char c) : value(c), isword(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }
    char value;
    bool isword;
    TrieNode* children[26];
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode('\0')) {}

    ~Trie() {
        if (root) {
            delete root;
        }
    }

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        TrieNode* pnode = root;
        for (const auto& w : word) {
            if (pnode->children[w - 'a'] == nullptr) {
                pnode->children[w - 'a'] = new TrieNode(w);
            }
            pnode = pnode->children[w - 'a'];
        }
        pnode->isword = true;
    }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        TrieNode* pnode = root;
        for (const auto& w : word) {
            if (pnode->children[w - 'a'] == nullptr) {
                return false;
            }
            pnode = pnode->children[w - 'a'];
        }
        return pnode->isword;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        TrieNode* pnode = root;
        for (const auto& w : prefix) {
            if (pnode->children[w - 'a'] == nullptr) {
                return false;
            }
            pnode = pnode->children[w - 'a'];
        }
        return true;
    }

    TrieNode* Root() { return root; }

private:
    TrieNode* root;
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        if (board.empty() || board[0].empty()) {
            return {};
        }
        if (words.empty()) {
            return {};
        }

        Trie trie;
        for (const auto& word : words) {
            trie.insert(word);
        }

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::string first(1, board[i][j]);
                if (trie.startsWith(first)) {
                    DFS(board, i, j, "", trie.Root());
                }
            }
        }

        std::vector<std::string> results(set.begin(), set.end());
        return results;
    }

    void DFS(std::vector<std::vector<char>>& board, int i, int j, std::string cur_word, const TrieNode* cur_node) {
        cur_word += board[i][j];
        cur_node = cur_node->children[board[i][j] - 'a'];
        if (cur_node->isword) {
            set.insert(cur_word);
        }

        char temp = board[i][j];
        board[i][j] = '#';
        for (int count = 0; count < 4; count++) {
            auto x = i + dx[count];
            auto y = j + dy[count];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (board[x][y] != '#' && cur_node->children[board[x][y] - 'a']) {
                    DFS(board, x, y, cur_word, cur_node);
                }
            }
        }
        board[i][j] = temp;
    }

private:
    std::set<std::string> set;
    std::vector<int> dx{-1, 1, 0, 0};
    std::vector<int> dy{0, 0, -1, 1};
    int m;
    int n;
};

void test1() {
    std::vector<std::vector<char>> board{
        {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    std::vector<std::string> words = {"oath", "pea", "eat", "rain"};
    std::vector<std::string> results = {"eat", "oath"};
    Solution s;
    assert(s.findWords(board, words) == results);
}

void test2() {
    std::vector<std::vector<char>> board{{'a', 'b'}, {'c', 'd'}};
    std::vector<std::string> words = {"abcb"};
    std::vector<std::string> results;
    Solution s;
    assert(s.findWords(board, words) == results);
}

int main() {
    test1();
    test2();
    return 0;
}