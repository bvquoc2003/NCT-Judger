#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="PAINT";
int n,m,a[1005][1005],res;
int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld", &n, &m);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j)   scanf("%lld", &a[i][j]);
    }
    res=m*n;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j)   if(a[i][j]==0)  --res;
    }
    for(int i=0;i<=n;++i) {
        for(int j=0;j<=m;++j) {
            res+=(abs(a[i][j]-a[i+1][j]));
            res+=(abs(a[i][j]-a[i][j+1]));
        }
    }
    printf("%lld", res);
    return 0;
}
