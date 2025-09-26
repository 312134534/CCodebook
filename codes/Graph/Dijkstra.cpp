int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	const ll INF = 1e18;

	ll n, m; cin >> n >> m;
	vector<vector<pll>> adj(n + 1);
	rep (m) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].pb(pll(w, v));
	}

	vector<ll> dis(n + 1, INF);
	priority_queue<pll, vector<pll>, greater<pll>> pq;

	dis[1] = 0;
	pq.push(pll(0, 1));
	while (not pq.empty()) {
		auto [uw, u] = pq.top(); pq.pop();

		if (uw > dis[u]) continue;

		for (auto [w, v] : adj[u]) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push(pll(dis[v], v));
			}
		}
	}
}
