// CSES Range Updates and Sums
// 1. Increase each value in range [a,b] by x.
// 2. Set each value in range [a,b] to x.
// 3. Calculate the sum of values in range [a,b].

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define lson 2*n + 1
#define rson 2*n + 2

class Node {
public:
    ll val;
    ll setVal;
    ll addVal;
    bool isSet;
};

ll sz, q;
vector<ll> a;
vector<Node> nds;

void build(ll l, ll r, ll n = 0) {
    if (l == r) {
        nds[n].val = a[l];
        nds[n].setVal = 0;
        nds[n].addVal = 0;
        nds[n].isSet = false;
        return;
    }
    ll mid = l + (r - l)/2;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    nds[n].val = nds[lson].val + nds[rson].val;
}

void push(ll l, ll r, ll n) {
    ll mid = l + (r - l)/2;

    if (nds[n].isSet) {
        
        nds[lson].val = nds[n].setVal*(mid - l + 1);
        nds[lson].setVal = nds[n].setVal;
        nds[lson].addVal = 0;
        nds[lson].isSet = true;

        nds[rson].val = nds[n].setVal*(r - (mid + 1) + 1);
        nds[rson].setVal = nds[n].setVal;
        nds[rson].addVal = 0;
        nds[rson].isSet = true;

        nds[n].isSet = false;
    }

    nds[lson].val += nds[n].addVal*(mid - l + 1);
    nds[lson].addVal += nds[n].addVal;

    nds[rson].val += nds[n].addVal*(r - (mid + 1) + 1);
    nds[rson].addVal += nds[n].addVal;

    nds[n].addVal = 0;
}

void setVal(ll x, ll y, ll val, ll l, ll r, ll n = 0) {
    if (l == x and r == y) {
        nds[n].val = val*(y - x + 1);
        nds[n].setVal = val;
        nds[n].addVal = 0;
        nds[n].isSet = true;
        return;
    }
    push(l, r, n);
    ll mid = l + (r - l)/2;
    if (y <= mid) {
        setVal(x, y, val, l, mid, lson);
    } else if (x >= mid + 1) {
        setVal(x, y, val, mid + 1, r, rson);
    } else {
        setVal(x, mid, val, l, mid, lson);
        setVal(mid + 1, y, val, mid + 1, r, rson);
    }
    nds[n].val = nds[lson].val + nds[rson].val;
}

void addVal(ll x, ll y, ll val, ll l, ll r, ll n = 0) {
    if (l == x and r == y) {
        nds[n].val += val*(y - x + 1);
        nds[n].addVal += val;
        return;
    }
    push(l, r, n);
    ll mid = l + (r - l)/2;
    if (y <= mid) {
        addVal(x, y, val, l, mid, lson);
    } else if (x >= mid + 1) {
        addVal(x, y, val, mid + 1, r, rson);
    } else {
        addVal(x, mid, val, l, mid, lson);
        addVal(mid + 1, y, val, mid + 1, r, rson);
    }
    nds[n].val = nds[lson].val + nds[rson].val;
}

ll query(ll x, ll y, ll l, ll r, ll n = 0) {
    if (l == x and r == y) return nds[n].val;
    push(l, r, n);
    ll mid = l + (r - l)/2;
    if (y <= mid) {
        return query(x, y, l, mid, lson);
    } else if (x >= mid + 1) {
        return query(x, y, mid + 1, r, rson);
    } else {
        ll a = query(x, mid, l, mid, lson);
        ll b = query(mid + 1, y, mid + 1, r, rson);
        return a + b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> sz >> q;

    a.resize(sz + 1);
    for (ll i = 1; i <= sz; ++i) cin >> a[i];

    nds.resize(4*sz);
    build(1, sz);

    while (q--) {
        ll act; cin >> act;
        if (act == 1) {
            ll l, r, val; cin >> l >> r >> val;
            addVal(l, r, val, 1, sz);
        } else if (act == 2) {
            ll l, r, val; cin >> l >> r >> val;
            setVal(l, r, val, 1, sz);
        } else if (act == 3) {
            ll l, r; cin >> l >> r;
            cout << query(l, r, 1, sz) << '\n';
        }
    }

    return 0;
}
