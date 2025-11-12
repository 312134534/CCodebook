// 輸出無權二分圖最大匹配的邊數量和選到的邊

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
constexpr ll INF = 1e18;

struct Node {
    ll nd, pvIdx, cap;
    Node(ll _nd, ll _pvIdx, ll _cap) : nd(_nd), pvIdx(_pvIdx), cap(_cap) {}
};

ll n1, n2, n, m, st, en;
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

    cin >> n1 >> n2 >> m;
    n = n1 + n2 + 2;
    st = n1 + n2 + 1;
    en = n1 + n2 + 2;
    adj.clear(); adj.resize(n + 1);
    for (ll i = 1; i <= m; ++i) {
        ll u, v; cin >> u >> v; v += n1;
        adj[u].pb(Node(v, adj[v].size(), 1));
        adj[v].pb(Node(u, adj[u].size() - 1, 0));
    }
    m += n1 + n2;
    for (ll i = 1; i <= n1; ++i) {
        adj[st].pb(Node(i, adj[i].size(), 1));
        adj[i].pb(Node(st, adj[st].size() - 1, 0));
    }
    for (ll i = n1 + 1; i <= n1 + n2; ++i) {
        adj[i].pb(Node(en, adj[en].size(), 1));
        adj[en].pb(Node(i, adj[i].size() - 1, 0));
    }
    cout << maxFlow() << '\n';
    for (ll u = 1; u <= n1; ++u) {
        for (const Node& v : adj[u]) {
            if (v.nd != st and v.cap == 0) {
                cout << u << ' ' << v.nd - n1 << '\n';
            }
        }
    }

    return 0;
}
