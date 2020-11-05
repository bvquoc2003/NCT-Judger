#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="SAW";
const int nmax=1e5+5;
int n,m,k,h[nmax],mx=0;

bool check(int mid) {
    int s=0;
    for(int i=1;i<=n;++i) {
        if(h[i]<=mid) continue;
        s+=(h[i]-mid);
    }
    if(s>=m) return true;
    else return false;
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld", &n, &k);
    for(int i=1;i<=n;++i) {
        scanf("%lld", &h[i]);
        mx=max(mx,h[i]);
    }
    for(int j=1;j<=k;++j) {
        scanf("%lld", &m);
        int r=mx,l=0;
        int res=0;
        while(l<=r) {
            int mid=(l+r)/2;
            if(check(mid)) {
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%lld ", res);
    }
    return 0;
}
