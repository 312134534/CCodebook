#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline ll flg(ll x) {
    return 63 - __builtin_clzll(x);
}

inline bool isOnBit(ll x, ll i) {
    return ((1LL << i) & x) > 0;
}

ll n, q, lgn;
vector<vector<ll>> blf;

void init() {
    blf[0][1] = -1;
    for (ll u = 2; u <= n; ++u) cin >> blf[0][u];

    for (ll h = 1; h <= lgn; ++h) {
        for (ll u = 1; u <= n; ++u) {
            ll nt = blf[h - 1][u];
            blf[h][u] = nt == -1 ? -1 : blf[h - 1][nt];
        }
    }
}
ll query(ll u, ll step) {
    ll cur = u;
    for (ll i = 30; i >= 0; --i) {
        if (isOnBit(step, i)) {
            cur = blf[i][cur];
            if (cur == -1) return -1;
        }
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    lgn = flg(n);
    blf.resize(lgn + 1, vector<ll>(n + 1));
    init();

    while (q--) {
        ll u, step; cin >> u >> step;
        cout << query(u, step) << '\n';
    }

    return 0;
}
