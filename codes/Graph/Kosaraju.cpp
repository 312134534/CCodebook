#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define rep(n) for (ll _ = 1; _ <= n; ++_)

ll V, E;

stack<ll> stk;
vector<bool> vis;
vector<vector<ll>> adj;
void dfs1(ll u) {
    vis[u] = true;
    for (ll v : adj[u]) {
        if (vis[v]) continue;
        dfs1(v);
    }
    stk.push(u);
}

ll sccCnt;
vector<ll> scc;
vector<vector<ll>> radj;
void dfs2(ll u, ll sccIdx) {
    scc[u] = sccIdx;
    for (ll v : radj[u]) {
        if (scc[v] != -1) continue;
        dfs2(v, sccIdx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    vis.resize(V + 1, false);
    adj.resize(V + 1);
    radj.resize(V + 1);
    rep (E) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        radj[y].pb(x);
    }

    for (ll u = 1; u <= V; ++u) {
        if (vis[u]) continue;
        dfs1(u);
    }

    sccCnt = 0;
    scc.resize(V + 1, -1);
    while (not stk.empty()) {
        ll u = stk.top(); stk.pop();
        if (scc[u] != -1) continue;
        dfs2(u, ++sccCnt);
    }

    cout << sccCnt << '\n';
    for (ll i = 1; i <= V; ++i) {
        cout << scc[i] << ' ';
    } cout << '\n';
    
    return 0;
}
