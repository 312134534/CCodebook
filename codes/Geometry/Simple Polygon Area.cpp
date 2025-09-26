// pts = {p0, p1, ... pn-1, p0}, 0-based
// for simple polygon area
ll shoelace2(const vector<vec> &pts) {
    ll n = pts.size() - 2, res = 0;
    for (ll i = 0; i <= n; ++i) {
        res += pts[i].x * pts[i + 1].y;
        res -= pts[i].y * pts[i + 1].x;
    }
    return abs(res);
}
