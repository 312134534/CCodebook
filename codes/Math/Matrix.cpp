#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int n, m;                // n 行, m 列
    vector<vector<long long>> a;
    static const long long MOD = 1e9+7; // 如果題目需要取模，可以改這裡

    Matrix(int n, int m, bool ident = false): n(n), m(m) {
        a.assign(n, vector<long long>(m, 0));
        if(ident) { // 單位矩陣
            for(int i=0; i<min(n,m); i++) a[i][i] = 1;
        }
    }

    // 輸出矩陣
    void print() const {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) cout << a[i][j] << " ";
            cout << "\n";
        }
    }

    // 矩陣乘法
    Matrix operator*(const Matrix& o) const {
        assert(m == o.n);
        Matrix res(n, o.m);
        for(int i=0; i<n; i++) {
            for(int k=0; k<m; k++) if(a[i][k]) {
                for(int j=0; j<o.m; j++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    // 矩陣加法
    Matrix operator+(const Matrix& o) const {
        assert(n == o.n && m == o.m);
        Matrix res(n, m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res.a[i][j] = (a[i][j] + o.a[i][j]) % MOD;
            }
        }
        return res;
    }

    // 矩陣快速冪 (n×n 方陣才能做)
    Matrix pow(long long exp) const {
        assert(n == m);
        Matrix res(n, n, true), base = *this;
        while(exp > 0) {
            if(exp & 1) res = res * base;
            base = base * base;
            exp >>= 1;
        }
        return res;
    }
};
