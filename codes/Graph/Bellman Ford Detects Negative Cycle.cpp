#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define ff first
#define ss second
#define pb push_back
#define rep(n) for (ll _ = 1; _ <= n; ++_)

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	const ll INF = 5e12 + 1000;

	ll n, m; cin >> n >> m;
	vector<ll> dis(n + 1, INF);
	vector<vector<pll>> adj(n + 1);
	rep (m) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].pb(pll(w, v));
	}
	for (ll i = 1; i <= n; ++i) {
		adj[0].pb(pll(0, i));
	}

	dis[0] = 0;
	rep (n - 1) {
		bool updated = false;
		for (ll u = 0; u <= n; ++u) {
			for (const auto& [w, v] : adj[u]) {
				if (dis[u] < INF and dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					updated = true;
				}
			}
		}
		if (not updated) break;
	}

	bool hasNegativeCycle = false;
	for (ll u = 0; not hasNegativeCycle and u <= n; ++u) {
		for (const auto& [w, v] : adj[u]) {
			if (dis[u] < INF and dis[u] + w < dis[v]) {
				hasNegativeCycle = true;
				break;
			}
		}
	}

	return 0;
}
