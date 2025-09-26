// CSES: String Matching
// Given a string and a pattern, your task is to count
// the number of positions where the pattern occurs in the string.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<ll> z_value(const string& s) {
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; ++i) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] += 1;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s1, s2; cin >> s1 >> s2;
    ll n = s1.size(), m = s2.size();
 
    ll cnt = 0;
    string s = s2 + "$" + s1;
    vector<ll> z = z_value(s);
    for (ll i = m; i < s.size(); ++i) {
        if (z[i] == m) cnt += 1;
    }
    cout << cnt << '\n';
 
    return 0;
}

// ==================================================
// ==================================================

// CSES: Finding Borders
// A border of a string is a prefix that is also a suffix of
// the string but not the whole string. For example,
// the borders of abcababcab are ab and abcab.
// Your task is to find all border lengths of a given string.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
 
vector<ll> z_value(const string& s) {
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; ++i) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] += 1;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s; cin >> s;
    ll n = s.size();
 
    vector<ll> z = z_value(s), res;
    for (ll i = 1; i < n; ++i) {
        if (i + z[i] == n) res.pb(z[i]);
    }
    sort(res.begin(), res.end());
    for (ll x : res) {
        cout << x << ' ';
    } cout << '\n';
 
    return 0;
}

// ==================================================
// ==================================================

// CSES: Finding Periods
// A period of a string is a prefix that can be used to generate
// the whole string by repeating the prefix. The last repetition
// may be partial. For example, the periods of abcabca are abc, abcabc and abcabca.
// Your task is to find all period lengths of a string.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
 
vector<ll> z_value(const string& s) {
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; ++i) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] += 1;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s; cin >> s;
    ll n = s.size();
 
    vector<ll> z = z_value(s), res;
    for (ll i = 1; i < n; ++i) {
        if (i + z[i] == n) res.pb(i);
    }
    sort(res.begin(), res.end());
    for (ll x : res) {
        cout << x << ' ';
    } cout << n << '\n';
 
    return 0;
}
