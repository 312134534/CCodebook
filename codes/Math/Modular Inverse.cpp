// extend Euclidean
pll extgcd(ll a, ll b) {
    if (b == 0) return pll(1, 0);
    pll p = extgcd(m, a%b);
    ll x = p.ff, y = p.ss;
    return pll(y, x - y*(a/b));
}
extgcd(a, MOD).ff  // the modular inverse
(extgcd(a, MOD).ff%MOD + MOD)%MOD  // if you want to ensure that it is non-negative

// fast exponentiation (make sure that MOD is a prime number)
fastPow(a, MOD - 2)  // the modular inverse
