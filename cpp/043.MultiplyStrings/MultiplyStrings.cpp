/*
解题思路：
    模拟小学的乘法

      1 2 3
    ×   4 5
    ----------
      6 1 5
    4 9 2
    ----------
    5 5 3 5

    在数组中，位置 i + j + 1 放个位，i + j 放十位。
*/

// O(n*m)
// Runtime Beats 58.71%

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n1 = num1.size();
        int n2 = num2.size();
        int n3 = n1 + n2;
        std::vector<int> result(n3, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        std::string ans;
        for (int num : result) {
            if (!(ans.empty() && num == 0)) {
                ans.push_back(num + '0');
            }
        }
        return ans.empty() ? "0" : ans;
    }
};

void test1() {
    Solution s;
    assert(s.multiply("2", "3") == "6");
}

void test2() {
    Solution s;
    assert(s.multiply("123", "456") == "56088");
}

int main() {
    test1();
    test2();
    return 0;
}