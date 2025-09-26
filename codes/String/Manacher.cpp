// CSES: Longest Palindrome
// Given a string, your task is to determine the longest
// palindromic substring of the string. For example,
// the longest palindrome in aybabtu is bab.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string t, s = "^#"; cin >> t;
    ll n = t.size(), m = 2*n + 3;
    for (ll i = 0; i < n; ++i) {
        s += t[i];
        s += (i == n - 1 ? "#$" : "#");
    }
    
    ll c = 1;
    vector<ll> p(m); p[1] = 0;
    for (ll i = 2; i <= m - 3; ++i) {
        if (i < c + p[c]) p[i] = min(p[c - (i - c)], (c + p[c]) - i);
        while (i + p[i] + 1 < m &&
               i - p[i] - 1 >= 0 &&
               s[i - p[i] - 1] == s[i + p[i] + 1]) p[i] += 1;
        if (i + p[i] > c + p[c]) c = i;
    }
 
    ll j = 2;
    for (ll i = 3; i <= m - 3; ++i) {
        if (p[i] > p[j]) j = i;
    }
 
    for (ll i = j - p[j] + 1; i <= j + p[j] - 1; i += 2) {
        cout << s[i];
    } cout << '\n';
 
    return 0;
}

// ==================================================
// ==================================================

// CSES: All Palindromes
// Given a string, calculate for each position the length
// of the longest palindrome that ends at that position.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll n, m;
string ori_s, s;
vector<ll> p, rt, dp;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> ori_s;
    n = ori_s.size();
    m = 2*n + 3;
    s = "^#";
    for (ll i = 0; i < n; ++i) {
        s += ori_s[i];
        s += (i == n - 1 ? "#$" : "#");
    }
 
    ll c = 0;
    p.resize(m);
    for (ll i = 2; i <= m - 3; ++i) {
        if (i < c + p[c]) p[i] = min(p[c - (i - c)], (c + p[c]) - i);
        while (i - p[i] - 1 >= 0 &&
               i + p[i] + 1 < m &&
               s[i - p[i] - 1] == s[i + p[i] + 1]) p[i] += 1;
        if (i + p[i] > c + p[c]) c = i;
    }
 
    rt.resize(n, 1);
    for (ll i = 2; i <= m - 3; ++i) {
        ll y = ((i + p[i] - 1) - 2)/2;
        if (s[i] == '#') {
            ll x = ((i + 1) - 2)/2;
            rt[y] = max(rt[y], (y - x + 1)*2);
        } else {
            ll x = (i - 2)/2;
            rt[y] = max(rt[y], (y - x)*2 + 1);
        }
    }
 
    dp.resize(n); dp[n - 1] = rt[n - 1];
    for (ll i = n - 2; i >= 0; --i) {
        dp[i] = max(rt[i], dp[i + 1] - 2);
    }
 
    for (ll x : dp) {
        cout << x << ' ';
    } cout << '\n';
 
    return 0;
}
