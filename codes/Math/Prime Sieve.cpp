// Sieve of Eratosthenes
ll MAXN;
vector<ll> spf(MAXN + 1, -1);
spf[0] = -2; spf[1] = -2;
for (ll i = 2; i*i <= MAXN; ++i) {
    if (spf[i] == -1) {
        for (ll j = i*i; j <= MAXN; j += i) {
            if (spf[j] == -1) {
                spf[j] = i;
            }
        }
    }
}
