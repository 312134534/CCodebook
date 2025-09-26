int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n, m; cin >> n >> m;
	vector<ll> indeg(n + 1, 0);
	vector<vector<ll>> adj(n + 1);
	rep (m) {
		ll u, v; cin >> u >> v;
		adj[u].pb(v);
		indeg[v] += 1;
	}

	vector<ll> res; res.reserve(n);
	queue<ll> q;  // you can use any pool data structure here
	for (ll u = 1; u <= n; ++u) {
		if (indeg[u] == 0) {
			q.push(u);
			res.pb(u);
		}
	}
	while (not q.empty()) {
		ll u = q.front(); q.pop();
		for (ll v : adj[u]) {
			indeg[v] -= 1;
			if (indeg[v] == 0) {
				q.push(v);
				res.pb(v);
			}
		}
	}

	// if (res.size() < n) // there exists a directed cycle

	return 0;
}
