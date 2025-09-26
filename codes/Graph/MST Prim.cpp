int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr ll INF = 1e18;

    ll n, m; cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    rep (m) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].pb(pll(w, v));
        adj[v].pb(pll(w, u));
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<bool> vis(n + 1, false);
    vector<ll> curw(n + 1, INF);

    pq.push(pll(0, 1));
    curw[1] = 0;

    ll mstCost = 0, mstEdgesCnt = 0;
    while (mstEdgesCnt < n - 1) {
        if (pq.empty()) {
            // the graph is disconnected (MST D.N.E.)
            return 0;
        }

        auto [uw, u] = pq.top(); pq.pop();

        if (uw > curw[u]) continue;

        vis[u] = true;
        mstCost += uw;
        mstEdgesCnt += (u == 1 ? 0 : 1);

        for (const auto& [w, v] : adj[u]) {
            if (not vis[v] and w < curw[v]) {
                pq.push(pll(w, v));
                curw[v] = w;
            }
        }
    }

	return 0;
}
