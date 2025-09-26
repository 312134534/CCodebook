ll cc;
vector<ll> djs, sz;
ll find(ll u) {
    if (u == djs[u]) return u;
    return djs[u] = find(djs[u]);
}
void join(ll u, ll v) {
    u = find(u);
    v = find(v);
    if (u == v) return;  // don't forgot this line
    if (sz[u] < sz[v]) swap(u, v);
    djs[v] = u;
    sz[u] += sz[v];
    cc -= 1;
}
void init(ll n) {
    djs.clear(); djs.resize(n + 1);
    for (ll i = 1; i <= n; ++i) djs[i] = i;
    sz.clear(); sz.resize(n + 1, 1);
    cc = n;
}
