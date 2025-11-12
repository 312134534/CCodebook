// define a DSU first

ll v, e; cin >> v >> e;  // the number of vertices and edges

vector<pll> edges;
rep (e) {
	ll x, y; cin >> x >> y;  // bidirectional edge (x, y)
	if (fit_some_condition) join(x, y);
	else edges.pb(pll(x, y));
}

vector<vector<ll>> adj;  // undirected graph
for (const pll& edge : edges) {
	ll x = find_root(edge.ff), y = find_root(edge.ss);
	adj[x].pb(y);
	adj[y].pb(x);
}
