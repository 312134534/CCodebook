ll fastPow(ll b, ll e) {
	b = b%MOD;
	ll res = 1;
	while (e > 0) {
		if (e%2 == 1) res = (res*b)%MOD;
		b = (b*b)%MOD;
		e /= 2;
	}
	return res;
}
