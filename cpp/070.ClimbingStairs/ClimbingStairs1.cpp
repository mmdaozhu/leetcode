/*
解题思路：
    动态规划
    dp[i]：走到第 i 阶的方法数
    dp[i] = dp[i-1] + dp[i-2]
    原因很直观：
        最后一步走 1 阶 → 从 i-1
        最后一步走 2 阶 → 从 i-2
    初始条件：
        dp[0] = 1
        dp[1] = 1

    转换成斐波那契数列求和问题
    利用矩阵相乘优化算法
    [f(n)  ] = [1 1] * [f(n-1) ]
    [f(n-1 ]   [1 0]   [f(n-2) ]
*/

#include <cassert>
#include <iostream>

class Matrix {
public:
    friend Matrix operator*(const Matrix& x1, const Matrix& x2);
    Matrix(int i, int j, int k, int l) : a11(i), a12(j), a21(k), a22(l) {}

    int A11() {
        return a11;
    }
    int A12() {
        return a12;
    }

private:
    int a11{};
    int a12{};
    int a21{};
    int a22{};
};

Matrix operator*(const Matrix& x1, const Matrix& x2) {
    return Matrix(x1.a11 * x2.a11 + x1.a12 * x2.a21, x1.a11 * x2.a12 + x1.a12 * x2.a22,
                  x1.a21 * x2.a11 + x1.a22 * x2.a21, x1.a21 * x2.a12 + x1.a22 * x2.a22);
}

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }

        Matrix result = pow(Matrix(1, 1, 1, 0), n - 2);
        return result.A11() * 2 + result.A12() * 1;
    }

    Matrix pow(const Matrix& x, int n) {
        if (n == 1) {
            return x;
        }

        if (n & 1) {
            return x * pow(x * x, n / 2);
        } else {
            return pow(x * x, n / 2);
        }
    }
};

void test1() {
    Solution s;
    assert(s.climbStairs(2) == 2);
}

void test2() {
    Solution s;
    assert(s.climbStairs(3) == 3);
}

int main() {
    test1();
    test2();
    return 0;
}