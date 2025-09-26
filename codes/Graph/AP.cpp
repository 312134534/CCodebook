void dfs(ll u, ll pa = -1) {
    ll ch = 0;  // 紀錄子節點樹
    low[u] = in[u] = ++t;
    for (ll v : adj[u]) {
        if (v == pa) continue;
        if (in[v] == -1) {
            ch += 1;  // 子節點數加一
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (pa != -1 and low[v] >= in[u]) "u is AP"  // find AP
        } else if (in[v] < in[u]) {
            low[u] = min(low[u], in[v]);
        }
    }
    if (pa == -1 and ch >= 2) "u is AP" // root 額外判斷
}
