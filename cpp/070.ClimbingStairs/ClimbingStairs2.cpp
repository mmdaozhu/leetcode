/*
解体思路：
    f(n) = f(n-1) + f(n-2)
    f(3) = f(2) + f(1)
    f(2) = 2
    f(1) = 1
    转换成斐波那契数列求和问题

    利用矩阵相乘优化算法

    [f(n)  ] = [1 1] * [f(n-1) ]
    [f(n-1 ]   [1 0]   [f(n-2) ]

时间复杂度分析：O(log(n))
*/

#include <cassert>
#include <iostream>

class Matrix {
public:
    friend Matrix operator*(const Matrix& x1, const Matrix& x2);
    Matrix(int i, int j, int k, int l) : a11(i), a12(j), a21(k), a22(l) {}

    void print() {
        std::cout << "a11: " << a11 << std::endl;
        std::cout << "a12: " << a12 << std::endl;
        std::cout << "a21: " << a21 << std::endl;
        std::cout << "a22: " << a22 << std::endl;
    }

    int A11() { return a11; }
    int A12() { return a12; }

private:
    int a11;
    int a12;
    int a21;
    int a22;
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

void test3() {
    Solution s;
    assert(s.climbStairs(4) == 5);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}