
/*
解题思路：
    回溯
*/

// O(3⁴)
// Runtime Beats 100%

#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> path;
        backtrace(s, 0, path);
        return results;
    }

    void backtrace(std::string s, int start, std::vector<std::string>& path) {
        if (path.size() == 4) {
            if (start == s.length()) {
                std::string ip = path[0];
                for (int i = 1; i < path.size(); i++) {
                    ip += "." + path[i];
                }
                results.push_back(ip);
            }
            return;
        }

        int remain = s.length() - start;
        int need = 4 - path.size();
        if (remain < need || remain > need * 3) {
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (start + len > s.length()) {
                break;
            }

            std::string part = s.substr(start, len);
            if (part.size() > 1 && part[0] == '0') {
                break;
            }

            int num = stoi(part);
            if (num > 255) {
                break;
            }
            path.push_back(part);
            backtrace(s, start + len, path);
            path.pop_back();
        }
    }

private:
    std::vector<std::string> results;
};

void test1() {
    std::string str = "25525511135";
    Solution s;
    std::vector<std::string> results{"255.255.11.135", "255.255.111.35"};
    assert(s.restoreIpAddresses(str) == results);
}

void test2() {
    std::string str = "0000";
    Solution s;
    std::vector<std::string> results{"0.0.0.0"};
    assert(s.restoreIpAddresses(str) == results);
}

void test3() {
    std::string str = "101023";
    Solution s;
    std::vector<std::string> results{"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
    assert(s.restoreIpAddresses(str) == results);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}