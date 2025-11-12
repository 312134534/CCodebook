#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define pb push_back

ll n, m, t = 0, sccCnt = 0, sccIdx = 0;
stack<ll> stk;
vector<bool> inStack;
vector<ll> in, low, scc, val;
vector<vector<ll>> adj;
void dfs(ll u) {
    low[u] = in[u] = ++t;
    stk.push(u);
    inStack[u] = true;
    for (ll v : adj[u]) {
        if (in[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if (in[u] == low[u]) {
        sccCnt += 1;
        sccIdx += 1;
        ll cur;
        do {
            cur = stk.top(); stk.pop();
            inStack[cur] = false;
            scc[cur] = sccIdx;
        } while (cur != u);
    }
}

vector<bool> vis2;
vector<ll> val2, dp2;
vector<vector<ll>> adj2;
void dfs2(ll u) {
    vis2[u] = true;
    for (ll v : adj2[u]) {
        if (not vis2[v]) dfs2(v);
        dp2[u] = max(dp2[u], val2[u] + dp2[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    inStack.resize(n + 1);
    in.resize(n + 1, -1);
    low.resize(n + 1);
    scc.resize(n + 1);
    val.resize(n + 1);
    adj.resize(n + 1);
    for (ll u = 1; u <= n; ++u) cin >> val[u];
    for (ll i = 1; i <= m; ++i) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    for (ll u = 1; u <= n; ++u) {
        if (in[u] != -1) continue;
        dfs(u);
    }

    vis2.resize(sccCnt + 1);
    val2.resize(sccCnt + 1);
    dp2.resize(sccCnt + 1);
    adj2.resize(sccCnt + 1);
    for (ll u = 1; u <= n; ++u) {
        val2[scc[u]] += val[u];
        for (ll v : adj[u]) {
            if (scc[v] == scc[u]) continue;
            adj2[scc[u]].pb(scc[v]);
        }
    }
    for (ll u = 1; u <= sccCnt; ++u) {
        dp2[u] = val2[u];
    }

    for (ll u = 1; u <= sccCnt; ++u) {
        if (vis2[u]) continue;
        dfs2(u);
    }

    cout << *max_element(dp2.begin() + 1, dp2.end()) << '\n';

    return 0;
}
