vector<ll> djs, sz;
ll find(ll u) {
    if (u == djs[u]) return u;
    return djs[u] = find(djs[u]);
}
void join(ll u, ll v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    djs[v] = u;
    sz[u] += sz[v];
}
void init(ll n) {
    djs.clear(); djs.resize(n + 1);
    for (ll i = 1; i <= n; ++i) djs[i] = i;
    sz.clear(); sz.resize(n + 1, 1);
}

class Edge{
public:
    ll u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	// nodes are 1-indexed
	// edges are 0-indexed

    ll n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
    }
    sort(all(edges), [](const Edge& e1, const Edge e2) -> bool {
        return e1.w < e2.w;
    });
    init(n);

    ll mstCost = 0, mstEdgesCnt = 0;
    for (const auto& [u, v, w] : edges) {
        if (find(u) == find(v)) continue;
        join(u, v);
        mstCost += w;
        mstEdgesCnt += 1;
        if (mstEdgesCnt == n - 1) break;
    }

    // if (mstEdgesCnt < n - 1) // the graph is disconnected (MST D.N.E.)

    return 0;
}
