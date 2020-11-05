#include <bits/stdc++.h>

using namespace std;

int n;
int c[5005];
int dp[5005][5005][2];
int main()
{
    freopen("FLOODFILL.INP","r",stdin);
    freopen("FLOODFILL.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    n=unique(c+1,c+n+1)-c-1;
    for (int L=n;L>=1;L--) {
        dp[L][L][1]=dp[L][L][2]=0;
        for (int R=L+1;R<=n;R++) {
            dp[L][R][1] = min(dp[L+1][R][1]+(c[L]!=c[L+1]), dp[L+1][R][2]+(c[L]!=c[R]));
            dp[L][R][2] = min(dp[L][R-1][1]+(c[L]!=c[R]), dp[L][R-1][2]+(c[R-1]!=c[R]));
        }
    }
    cout<<min(dp[1][n][1],dp[1][n][2]);
    return 0;
}
