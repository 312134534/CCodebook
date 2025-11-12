#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> suffix_array(const string& s) {
    ll n = s.size();
    vector<ll> sa(n), rk(n), tmp(n);

    for (ll i = 0; i < n; ++i) {
        sa[i] = i;
        rk[i] = s[i] - 'a';
    }

    for (ll k = 1; k < n; k *= 2) {
        auto cmp = [&](ll ri, ll li) {
            if (rk[ri] != rk[li]) return rk[ri] < rk[li];
            ll x = (ri + k < n) ? rk[ri + k] : -1;
            ll y = (li + k < n) ? rk[li + k] : -1;
            return x < y;
        };

        sort(sa.begin(), sa.end(), cmp);

        tmp[sa[0]] = 0;
        for (ll i = 1; i < n; ++i) {
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }
        rk = tmp;
    }

    return sa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    vector<ll> sa = suffix_array(s);
    ll n = s.size();

    ll k; cin >> k;
    for (ll i = 0; i < k; ++i) {
        string tar; cin >> tar;
        ll m = tar.size();

        ll l = 0, r = n - 1;
        while (l <= r) {
            ll mid = l + (r - l)/2;
            if (s.substr(sa[mid], m) < tar) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << (s.substr(sa[l], m) == tar ? "YES" : "NO") << '\n';
    }

    return 0;
}
