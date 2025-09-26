// pts = {p0, p1, ... pn-1}, 0-based
// the points in pts should be distinct
vector<vec> convexHull(const vector<vec> &_pts) {
    vector<vec> pts = _pts;
    sort(pts.begin(), pts.end());

    ll n = pts.size();
    vector<vec> hull(1, pts[0]);
    for (ll i = 1; i < n; ++i) {
        while (hull.size() >= 2 &&
               ori(hull[hull.size() - 2], hull.back(), pts[i]) < 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    ll m = hull.size();
    for (ll i = n - 2; i >= 0; --i) {
        while (hull.size() - m + 1 >= 2 &&
               ori(hull[hull.size() - 2], hull.back(), pts[i]) < 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
    hull.pop_back();

    return hull;
}
