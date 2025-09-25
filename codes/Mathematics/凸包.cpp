#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define F first
#define S second

using namespace std;

template<typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b){
    return mp(a.F - b.F, a.S - b.S);
}

template<typename T>
T cross(pair<T, T> a, pair<T, T> b){
    return a.F * b.S - a.S * b.F;
}

template<typename T>
vector<pair<T, T>> getConvexHull(vector<pair<T, T>>& pnts){

    int n = pnts.size();
    sort(pnts.begin(), pnts.end());

    vector<pair<T, T>> hull;

    for(int i = 0; i < 2; i++){
        int t = hull.size();
        for(pair<T, T> pnt : pnts){
            while(hull.size() - t >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
                hull.pop_back();
            hull.pb(pnt);
        }
        hull.pop_back();
        reverse(pnts.begin(), pnts.end());
    }

    return hull;
}