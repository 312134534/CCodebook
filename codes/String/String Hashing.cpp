#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define pb push_back

class strHash {
private:
    const ll m1 = 1e9 + 7, m2 = 1e9 + 9, p = 239017;
    ll n;
    string s;
    vector<ll> h1, h2, p1, p2;
public:
    strHash(const string& _s) {
        n = _s.size();
        s = _s;

        h1.resize(n); h1[0] = s[0];
        h2.resize(n); h2[0] = s[0];
        for (ll i = 1; i < n; ++i) {
            h1[i] = (h1[i - 1]*p%m1 + s[i])%m1;
            h2[i] = (h2[i - 1]*p%m2 + s[i])%m2;
        }

        p1.resize(n); p1[0] = 1;
        p2.resize(n); p2[0] = 1;
        for (ll i = 1; i < n; ++i) {
            p1[i] = p1[i - 1]*p%m1;
            p2[i] = p2[i - 1]*p%m2;
        }
    }
    pll hash(ll l, ll r) const {  // [l, r]
        if (l == 0) return pll(h1[r], h2[r]);
        return pll(
            ((h1[r] - h1[l - 1]*p1[r - l + 1]%m1)%m1 + m1)%m1,
            ((h2[r] - h2[l - 1]*p2[r - l + 1]%m2)%m2 + m2)%m2
        );
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2; cin >> s1 >> s2;
    ll n = s1.size(), m = s2.size();

    if (n < m) {
        cout << 0 << '\n';
        return 0;
    }

    ll cnt = 0;
    strHash sh1(s1), sh2(s2);
    pll tarHash = sh2.hash(0, m - 1);
    for (ll i = 0; i < n - m + 1; ++i) {
        if (sh1.hash(i, i + m - 1) == tarHash) cnt += 1;
    }
    cout << cnt << '\n';

    return 0;
}
