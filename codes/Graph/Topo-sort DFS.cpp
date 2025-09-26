ll v;
vector<ll> topo;
vector<bool> vis;
vector<vector<ll>> adj(v + 1);
void dfs(ll node) {
	vis[node] = true;
	for (ll neighbor : adj[node]) {
		if (vis[neighbor]) continue;
		dfs(neighbor);
	}
	topo.pb(node);
}

reverse(topo.begin(), topo.end());
