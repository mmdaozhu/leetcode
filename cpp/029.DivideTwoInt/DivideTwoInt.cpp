// O((log n)²)
// Runtime Beats 100.00%

#include <cassert>
#include <climits>
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool flag = (dividend > 0) == (divisor > 0);
        long long dvd = std::abs((long long)dividend);
        long long dvs = std::abs((long long)divisor);

        long long n = 0;
        long long total = dvd;
        while (total - dvs >= 0) {
            int i = 0;
            while ((dvs << (i + 1)) <= total) {
                i++;
            }

            total -= (dvs << i);
            n += (1LL << i);
        }

        long long result = flag ? n : -n;
        if (result > INT_MAX) {
            return INT_MAX;
        }
        return (int)result;
    }
};

void test1() {
    Solution s;
    assert(s.divide(10, 3) == 3);
}

void test2() {
    Solution s;
    assert(s.divide(7, -3) == -2);
}

int main() {
    test1();
    test2();
    return 0;
}