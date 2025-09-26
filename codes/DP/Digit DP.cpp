string num;

ll dp[the max len of num + 1][2][2][...];
memset(dp, -1, sizeof(dp));

ll count(ll pos, bool tight, bool leadingZero, ...) {
    if (dp[pos][tight][leadingZero][...] != -1) {
        return dp[pos][tight][leadingZero][...];
    }

    if (base-case) {  // e.g. pos == num.size() or other base case condition
	    // do something
    }

    ll res = 0;
    ll up = (tight ? num[pos] - '0' : 9);
    for (ll d = 0; d <= up; ++d) {
        res += count(
            pos + 1,
            tight and (d == num[pos] - '0'),
            leadingZero and (d == 0),
            ...
        );
    }

    return dp[pos][tight][leadingZero][...] = res;
}

count(0, true, true, ...)  // the answer

// ==================================================
// ==================================================

// AtCoder ABC154E
// Find the number of integers between 1 and N (inclusive)
// that contains exactly K non-zero digits when written in base ten.
// 1 <= N <= 10^100, 1 <= K <= 3

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll k;
string num;

ll dp[102][2][4];

ll count(ll pos, bool tight, ll cnt) {
    if (dp[pos][tight][cnt] != -1) {
        return dp[pos][tight][cnt];
    }

    if (cnt == 0) return dp[pos][tight][cnt] = 1;
    else if (pos == num.size()) return dp[pos][tight][cnt] = 0;

    ll res = 0;
    ll up = (tight ? num[pos] - '0' : 9);
    for (ll d = 0; d <= up; ++d) {
        res += count(
            pos + 1,
            tight and (d == num[pos] - '0'),
            cnt + (d == 0 ? 0 : -1)
        );
    }

    return dp[pos][tight][cnt] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num >> k;

    memset(dp, -1, sizeof(dp));

    cout << count(0, true, k) << '\n';

    return 0;
}
