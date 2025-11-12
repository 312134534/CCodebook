#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define pb push_back

ll n, t = 0, sccCnt = 0, sccIdx = 0;
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

    ll x, y; cin >> x >> y;
    n = 2*y;
    inStack.resize(n + 1);
    in.resize(n + 1, -1);
    low.resize(n + 1);
    scc.resize(n + 1);
    adj.resize(n + 1);
    for (ll i = 1; i <= x; ++i) {
        char c1, c2;
        ll a, b;
        cin >> c1 >> a >> c2 >> b;

        if (c1 == '+') {
            adj[a + y].pb((c2 == '+' ? b : b + y));
        } else {
            adj[a].pb((c2 == '+' ? b : b + y));
        }

        if (c2 == '+') {
            adj[b + y].pb((c1 == '+' ? a : a + y));
        } else {
            adj[b].pb((c1 == '+' ? a : a + y));
        }
    }
    for (ll u = 1; u <= n; ++u) {
        if (in[u] != -1) continue;
        dfs(u);
    }

    bool valid = true;
    string s = "";
    for (ll u = 1; u <= y; ++u) {
        if (scc[u] == scc[u + y]) {
            valid = false;
            break;
        } else if (scc[u] < scc[u + y]) {
            s += "+ ";
        } else {
            s += "- ";
        }
    }

    cout << (valid ? s : "IMPOSSIBLE") << '\n';

    return 0;
}
