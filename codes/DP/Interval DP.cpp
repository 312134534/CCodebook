ll n;  // the length of the array

vector<ll> a(n + 1);

vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

for (ll i = 1; i <= n; ++i) {
	dp[i][i] = "initial value";  // length 1 interval [i, i]
}
for (ll len = 2; len <= n; ++len) {  // loop through all length from 2 to n
	for (ll l = 1; l <= n - len + 1; ++l) {
		ll r = l + len - 1;
		
		dp[l][r] = ...;  // interval [l, r]
	}
}

dp[1][n]  // the answer (interval [1, n])
