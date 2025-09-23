#include <bits/stdc++.h>
using namespace std;


const int M = 1e9 + 7;
const int N = 2000005;
vector<int> fact(N), invfact(N);

int qpow(int a, int b){
    int res=1;
    while(b > 0){
        if(b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

void dofact(){
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % M;
    }

    invfact[N - 1] = qpow(fact[N - 1], M - 2);
    for(int i = N - 1; i > 0; i--) invfact[i - 1] = invfact[i] * i % M;
}

int C(int n,int m){
    return fact[n] * invfact[m] % M * invfact[n - m] % M;
}

void solve() {
    
}

signed main() {
    // FIO;
    int t_t = 1;
    // cin >> t_t;
    while (t_t--)
    {
        solve();
    }
}
