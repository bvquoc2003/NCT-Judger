#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int x[200005], y[200005];
int l[200005], r[200005];
int32_t main() {
    freopen("VISIT.INP","r",stdin);
    freopen("VISIT.OUT","w",stdout);
    scanf("%lld", &n);
    l[0]=1; r[0]=1;
    for (int i=1;i<=n;i++) {
        scanf("%lld%lld", &l[i], &r[i]);
        y[i]=x[i-1]+(r[i]-l[i])+abs(l[i-1]-l[i]);
        y[i]=min(y[i], y[i-1]+(r[i]-l[i])+abs(r[i-1]-l[i]));
        x[i]=x[i-1]+r[i]-l[i]+abs(l[i-1]-r[i]);
        x[i]=min(x[i], y[i-1]+r[i]-l[i]+abs(r[i-1]-r[i]));
        // cout<<x[i]<<" "<<y[i]<<endl;
    }
    int res=n-r[n]+y[n]+n-1;
    res=min(res, n-l[n]+x[n]+n-1);
    printf("%lld", res);
}