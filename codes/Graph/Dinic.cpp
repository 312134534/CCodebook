#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
constexpr ll INF = 1e18;

struct Node {
    ll nd, pvIdx, cap;
    Node(ll _nd, ll _pvIdx, ll _cap) : nd(_nd), pvIdx(_pvIdx), cap(_cap) {}
};

ll n, m, st, en;
vector<ll> level, iter;
vector<vector<Node>> adj;

void bfs() {
    level.clear(); level.resize(n + 1, -1);
    level[st] = 0;

    queue<ll> q; q.push(st);
    while (not q.empty()) {
        ll sz = q.size();
        for (ll _ = 1; _ <= sz; ++_) {
            ll u = q.front(); q.pop();
            for (const Node& v : adj[u]) {
                if (v.cap > 0 and level[v.nd] == -1) {
                    level[v.nd] = level[u] + 1;
                    q.push(v.nd);
                }
            }
        }
    }
}

ll dfs(ll u, ll flow) {
    if (u == en) return flow;
    for (ll& i = iter[u]; i < adj[u].size(); ++i) {
        Node& v = adj[u][i];
        if (v.cap > 0 and level[v.nd] == level[u] + 1) {
            ll fw = dfs(v.nd, min(flow, v.cap));
            if (fw > 0) {
                v.cap -= fw;
                adj[v.nd][v.pvIdx].cap += fw;
                return fw;
            }
        }
    }
    return 0;  // for compile warning
}

ll maxFlow() {
    ll res = 0;
    while (true) {
        bfs();
        if (level[en] == -1) break;

        ll cur;
        iter.clear(); iter.resize(n + 1);
        while ((cur = dfs(st, INF)) > 0) {
            res += cur;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.clear(); adj.resize(n + 1);
    for (ll i = 1; i <= m; ++i) {
        ll u, v, cap; cin >> u >> v >> cap;
        adj[u].pb(Node(v, adj[v].size(), cap));
        adj[v].pb(Node(u, adj[u].size() - 1, 0));
    }
    st = 1;
    en = n;
    cout << maxFlow() << '\n';

    return 0;
}
