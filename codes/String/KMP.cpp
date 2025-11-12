#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template<class T> using vec = vector<T>;
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define rep(n) for (ll _ = 1; _ <= n; ++_)

// --------------------------------------------------

vector<ll> LPS(const string& s) {  // 0-indexed
    ll n = s.size();
    if (n == 0) return {};
    vector<ll> lps(n); lps[0] = 0;
    for (ll i = 1, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) j = lps[j - 1];
        if (s[i] == s[j]) j += 1;
        lps[i] = j;
    }
    return lps;
}

ll KMP(const string& s, const string& t) {  // 0-indexed
    vector<ll> lps = LPS(t);
    ll n = s.size(), m = t.size();
    if (n < m) return 0;
    ll i = 0, j = 0, cnt = 0;
    while (i < n) {
        if (s[i] == t[j]) {
            i += 1;
            j += 1;
        } else if (j > 0) {
            j = lps[j - 1];
        } else if (j == 0) {
            i += 1;
        }
        if (j == m) {
            // s[i - m to i - 1] == t
            cnt += 1;
            j = lps[j - 1];
        }
    }
    return cnt;  // the number of matching substrings
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    cout << KMP(s, t) << endl;

    return 0;
}
