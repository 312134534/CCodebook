// ----- O(n log n) LIS -----
int LIS_length(const vector<int>& a) {
    vector<int> d; 
    for (int x : a) {
        auto it = lower_bound(d.begin(), d.end(), x); 
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    return (int)d.size();
}
