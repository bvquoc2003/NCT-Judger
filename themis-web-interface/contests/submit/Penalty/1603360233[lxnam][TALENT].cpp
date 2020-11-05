#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int s[100005];
pair <int, int> a[100005];
int sw[100005];
int Search(int x) {
    int l=1, r=n;
    int res=n+1;
    while (l<=r) {
        int mid=(l+r)/2;
        if (a[mid].first>=x) {
            res=mid;
            r=mid-1;
        } else l=mid+1;
    }
    return res;
}
int32_t main() {
    freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    scanf("%lld%lld", &n, &m);
    for (int i=1;i<=n;i++) scanf("%lld", &a[i].first);
    for (int i=1;i<=n;i++) {
        scanf("%lld", &a[i].second);
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) {
        s[i]=s[i-1]+(a[i].first*a[i].second);
        sw[i]=sw[i-1]+a[i].second;
    }
    while (m--) {
        int p, ans=0;
        scanf("%lld", &p);
        int k=Search(p);
        ans+=s[n]-s[k-1]-(sw[n]-sw[k-1])*p;
        ans+=-(s[k-1])+(sw[k-1])*p;
        printf("%lld\n", ans);
    }
}
