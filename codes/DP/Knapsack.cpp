// 0/1 knapsack

const ll INF = 9e18;

ll n, wmx; cin >> n >> wmx;
vector<ll> w(n + 1); for (ll i = 1; i <= n; ++i) cin >> w[i];
vector<ll> v(n + 1); for (ll i = 1; i <= n; ++i) cin >> v[i];

vector<ll> dp(wmx + 1, -INF); dp[0] = 0;
for (ll i = 1; i <= n; ++i) {
	for (ll j = wmx; j >= w[i]; --j) {  
		dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	}
}

ll mx = dp[0];
for (ll j = 1; j <= wmx; ++j) {
	mx = max(mx, dp[j]);
}
cout << mx << '\n';

// ------------------------------

// Unbounded
// just change the inner for loop to the following line
// for (ll j = w[i]; j <= wmx; ++j) ...
