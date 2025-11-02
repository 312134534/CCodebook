#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(c) (c).begin(), (c).end()

void solve() {
    int n, k, L, R;
    cin >> n >> k >> L >> R;
    vector<int> uni(n);
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> uni[i];
        vec[i] = uni[i];
    }
    sort(all(uni));
    uni.resize(unique(all(uni)) - uni.begin());
    vector<int> f_low(uni.size(), 0);
    vector<int> f_up(uni.size(), 0);
    for (int i = 0; i < n; i++) {
        vec[i] = lower_bound(all(uni), vec[i]) - uni.begin();
    }
    int l = -1, r = 0;
    int cl = 0, cr = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (r < n && cr <= k) {
            if (f_up[vec[r]] == 0) {
                if (cr == k) break;
                cr++;
            }
            f_up[vec[r++]]++;
        }
        while (l + 1 < n && cl < k) {
            if (f_low[vec[l + 1]] == 0) {
                cl++;
            }
            f_low[vec[l + 1]]++;
            l++;
        }
        if (cl == k) {
            res += max(min(r, i + R) - max(l, i + L - 1), 0LL);
        }
        f_low[vec[i]]--;
        f_up[vec[i]]--;
        if (f_low[vec[i]] == 0) cl--; 
        if (f_up[vec[i]] == 0) cr--; 
    }

    cout << res << '\n';
}
