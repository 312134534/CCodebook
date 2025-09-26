ll LISLength(const vector<ll>& arr) {
    vector<ll> d;
    for (ll x : arr) {
        auto it = lower_bound(d.begin(), d.end(), x); 
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    return d.size();
}

// find LIS sequence
for (ll i = 0; i < num.size(); ++i){
    if(lis.empty() || lis.back() < num[i]){
        lis.push_back(num[i]);
        dp[i] = lis.size();
    }
    else{
        auto iter = lower_bound(all(lis),num[i]);
        dp[i] = iter - lis.begin() + 1;
        *iter = num[i];
    }
}
ll length = lis.size();
for (ll i = num.size() - 1; i>=0; --i){
    if(dp[i] == length){
        ans.push_back(num[i]);
        length -= 1;
    }
}
