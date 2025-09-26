void merge(vector<int>& arr, ll l, ll r, ll x, ll y) {
	ll left = l;
	vector<ll> tmp; tmp.reserve(y - l + 1);
	while (l <= r and x <= y) {
		if (arr[l] <= arr[x]) {
			tmp.push_back(arr[l++]);
		}
		else {
			tmp.push_back(arr[x++]);
		}
	}
	while (l <= r) {
		tmp.push_back(arr[l++]);
	}
	while (x <= y) {
		tmp.push_back(arr[x++]);
	}
	for (ll i = left; i <= y; ++i) {
		arr[i] = tmp[i - left];
	}
}
ll mergeSort(vector<ll>& arr, ll l, ll r) {
    if (l == r) return 0;
    ll mid = l + (r - l)/2;
    ll lcnt = mergeSort(arr, l, mid);
    ll rcnt = mergeSort(arr, mid + 1, r);

	// ---------- main logic ----------
    ll cnt = lcnt + rcnt;
    ll a = l, b = mid, c = mid + 1, d = r;  // c is the current checking position
    while (a <= b) {
        while (c <= d and arr[a] > arr[c]) c += 1;
        cnt += c - (mid + 1);
        a += 1;
    }
    // --------------------------------------------------

    merge(arr, l, mid, mid + 1, r);

    return cnt;
}
