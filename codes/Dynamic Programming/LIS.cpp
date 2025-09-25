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
// LIS + 找出實際序列
for(int i=0;i<num.size();i++){
    if(lis.empty()||lis.back()<num[i]){
        lis.push_back(num[i]);
        dp[i]=lis.size();
    }
    else{
        auto iter=lower_bound(all(lis),num[i]);
        dp[i]=iter-lis.begin()+1;
        *iter=num[i];
    }
}
int length=lis.size();
for(int i=num.size()-1;i>=0;i--){
    if(dp[i]==length){
        ans.push_back(num[i]);
        length--;
    }
}
