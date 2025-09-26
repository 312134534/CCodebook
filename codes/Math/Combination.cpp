ll MAXN;

vector<ll> fact;  // factorial
vector<ll> invs;  // modular inverse
void init() {
    fact.resize(MAXN + 1, 1);
    invs.resize(MAXN + 1, 1);
    for (ll i = 2; i <= MAXN; ++i) {
        fact[i] = (fact[i - 1]*i)%MOD;
        invs[i] = fastPow(fact[i], MOD - 2);
    }
}

inline ll C(ll n, ll k) {
	return fact[n]*invs[k]%MOD*invs[n - k]%MOD
}
