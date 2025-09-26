void dfs(ll u, ll pa = -1) {
    low[u] = in[u] = ++t;
    for (ll v : adj[u]) {
        if (v == pa) continue;
        if (in[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > in[u]) "edge (u, v) is bridge"  // find bridge
        } else if (in[v] < in[u]) {
            low[u] = min(low[u], in[v]);
        }
    }
}
