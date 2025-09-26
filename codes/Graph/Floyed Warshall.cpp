int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> m;
	mtx.clear(); mtx.resize(n + 1, vector<ll>(n + 1, INF));
	for (ll i = 1; i <= n; ++i) mtx[i][i] = 0;
	rep (m) {
		ll x, y, w; cin >> x >> y >> w;
		mtx[x][y] = min(mtx[x][y], w);
		mtx[y][x] = min(mtx[y][x], w);
	}  // "min" is used to prevent the multiple edges

	for (ll k = 1; k <= n; ++k) {
		for (ll i = 1; i <= n; ++i) {
			for (ll j = 1; j <= n; ++j) {
				mtx[i][j] = min(mtx[i][j], mtx[i][k] + mtx[k][j]);
			}
		}
	}
}
