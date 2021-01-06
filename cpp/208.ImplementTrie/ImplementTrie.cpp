
#include <cassert>
#include <iostream>
#include <string>

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

private:
    TrieNode* root;
};

void test1() {
    Trie trie;
    trie.insert("apple");
    assert(trie.search("apple") == true);    // returns true
    assert(trie.search("app") == false);     // returns false
    assert(trie.startsWith("app") == true);  // returns true
    trie.insert("app");
    assert(trie.search("app") == true);
}

int main() {
    test1();
    return 0;
}