// Use binary lifting

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

inline ll flg(ll x) {
    return 63 - __builtin_clzll(x);
}

inline bool isOnBit(ll x, ll i) {
    return ((1LL << i) & x) > 0;
}

ll n, q, lgn;
vector<ll> d;
vector<vector<ll>> blf, adj;

void init() {
    blf[0][1] = -1;
    for (ll u = 2; u <= n; ++u) {
        ll v; cin >> v;
        blf[0][u] = v;
        adj[v].pb(u);
    }

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

void dfs(ll u, ll dn) {
    d[u] = dn;
    for (ll v : adj[u]) {
        dfs(v, dn + 1);
    }
}

ll lca(ll u, ll v) {
    if (d[u] > d[v]) swap(u, v);
    if (d[u] < d[v]) v = query(v, d[v] - d[u]);
    if (u == v) return u;
    for (ll h = lgn; h >= 0; --h) {
        ll ntu = blf[h][u];
        ll ntv = blf[h][v];
        if (ntu == -1 or ntv == -1 or ntu == ntv) continue;
        u = ntu;
        v = ntv;
    }
    return blf[0][u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    lgn = flg(n);
    d.resize(n + 1);
    blf.resize(lgn + 1, vector<ll>(n + 1));
    adj.resize(n + 1);
    init();
    dfs(1, 0);

    while (q--) {
        ll u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}
