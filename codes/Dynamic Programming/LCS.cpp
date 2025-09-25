//最常公共子序列

for(int i=1;i<=s1.size();i++){
    for(int j=1;j<=s2.size();j++){
        if(s1[i-1]==s2[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}
