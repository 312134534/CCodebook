#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define pb push_back

ll n, m, t = 0, sccCnt = 0, sccIdx = 0;
stack<ll> stk;
vector<bool> inStack;
vector<ll> in, low, scc;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    inStack.resize(n + 1);
    in.resize(n + 1, -1);
    low.resize(n + 1);
    scc.resize(n + 1);
    adj.resize(n + 1);
    for (ll i = 1; i <= m; ++i) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    for (ll u = 1; u <= n; ++u) {
        if (in[u] != -1) continue;
        dfs(u);
    }

    cout << sccCnt << '\n';
    for (ll u = 1; u <= n; ++u) {
        cout << scc[u] << ' ';
    } cout << '\n';

    return 0;
}
