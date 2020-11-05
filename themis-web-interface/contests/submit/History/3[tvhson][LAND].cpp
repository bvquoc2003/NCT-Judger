#include <bits/stdc++.h>

using namespace std;

int n, x, y, z;
int top_a, top_b;
int A[105], a[1005];
int B[105], b[1005];
int dp[1005][1005];
int32_t main()
{
    freopen("LAND.INP","r",stdin);
    freopen("LAND.OUT","w",stdout);
    scanf("%d%d%d%d", &n, &x, &y, &z);
    for (int i=1;i<=n;i++)
        scanf("%d%d", &A[i], &B[i]);
    for (int i=1;i<=n;i++) {
        int xe=A[i];
        while (xe!=0) {
            top_a++;
            a[top_a]=i;
            xe--;
        }
    }
    for (int i=1;i<=n;i++) {
        int xe=B[i];
        while (xe!=0) {
            top_b++;
            b[top_b]=i;
            xe--; 
        }
    }
    
    for (int i=0;i<=top_a;i++) dp[i][0]=i*y;
    for (int i=0;i<=top_b;i++) dp[0][i]=i*x;
    for (int i=1;i<=top_a;i++) {
        for (int j=1;j<=top_b;j++) {
            dp[i][j]=min(y+dp[i-1][j],min(x+dp[i][j-1],dp[i-1][j-1]+z*(abs(a[i]-b[j]))));
        }
    }

    cout<<dp[top_a][top_b];
    return 0;
}
