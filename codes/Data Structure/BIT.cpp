inline ll lowbit(ll x) {
    return x & -x;
}

ll n;
vector<ll> a, bit;

void add(ll pos, ll val) {
    for (ll i = pos; i <= n; i += lowbit(i)) {
        bit[i] += val;
    }
}

void init() {
    for (ll i = 1; i <= n; ++i) {
        add(i, a[i]);
    }
}

ll query(ll pos) {  // [1, pos]
    ll sum = 0;
    for (ll i = pos; i >= 1; i -= lowbit(i)) {
        sum += bit[i];
    }
    return sum;
}
