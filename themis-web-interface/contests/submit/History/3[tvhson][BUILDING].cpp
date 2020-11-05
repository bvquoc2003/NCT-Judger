#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1005][1005];
int L[1005][1005], U[1005][1005], D[1005][1005], R[1005][1005];
int32_t main() {
    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","w",stdout);
    scanf("%d%d", &n ,&m);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            scanf("%d", &a[i][j]);
            L[i][j]=max(a[i][j], L[i][j-1]);
            U[i][j]=max(a[i][j], U[i-1][j]);
        }
    }
    for (int i=n;i>=1;i--) {
        for (int j=m;j>=1;j--) {
            R[i][j]=max(a[i][j], R[i][j+1]);
            D[i][j]=max(a[i][j], D[i+1][j]);
        }
    }
    int res=0;
    for (int i=2;i<n;i++) {
        for (int j=2;j<m;j++) {
            int Min=min(L[i][j-1],min(R[i][j+1], min(U[i-1][j], D[i+1][j])));
            if (a[i][j]<Min) res++;
        }
    }
    printf("%d", res);
}