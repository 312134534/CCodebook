ll n; cin >> n;
string s; cin >> s; s = " " + s;
ll m; cin >> m;
string t; cin >> t; t = " " + t;

vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
for (ll i = 1; i <= n; ++i) {
	for (ll j = 1; j <= m; ++j) {
		if (s[i] == t[j]) {
			dp[i][j] = dp[i - 1][j - 1] + 1;
		}
		else {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}

cout << dp[n][m] << '\n';  // the length of LCS
