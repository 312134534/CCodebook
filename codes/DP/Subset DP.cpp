for (ll s = 1; s < (1LL << n); ++s) {
	for (ll sbs = s; sbs > 0; sbs = ((sbs - 1) & s)) {
		ll c = s - sbs;  // ll c = sbs^s;  // this one is equivalent
	}
}
// O(3^n), n <= 16
// sbs 是降序的 s 的子集
// c 是升序的 s 的子集
