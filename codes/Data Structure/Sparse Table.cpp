// if the max size of arr is 200000
vector<ll> arr;

// ------------------------------

// Sparse Table
const ll lgmx = 17;  // floor(log2(200000))
ll rmq[lgmx + 1][200000 + 1];
void init(ll n) {  // O(nlogn)
    for (ll i = 1; i <= n; ++i) rmq[0][i] = arr[i];
    for (ll h = 1; h <= lgmx; ++h)
        for (ll i = 1; i + (1 << h) - 1 <= n; ++i)
            rmq[h][i] = min(rmq[h - 1][i], rmq[h - 1][i + (1 << (h - 1))]);
}
ll flg(ull x) {return 63 - __builtin_clzll(x);}
ll query(ll l, ll r) {  // O(1)
    ll h = flg(r - l + 1);
    return min(rmq[h][l], rmq[h][r - (1 << h) + 1]);
}

// ------------------------------

// initialize the array
ll n; cin >> n;
arr.resize(n + 1);
for (ll i = 1; i <= n; ++i) cin >> arr[i];

// initialize the sparse table
init(n);
