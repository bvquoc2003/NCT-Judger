#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="CANDY";
const int nmax=1e6+5;
int n,a[nmax],l=INT_MAX,r=0,k,res=0;

bool check(int mid) {
    int s=0;
    for(int i=1;i<=n;++i) {
        s+=(a[i]-mid);
    }
    if(s>=0) return true;
    else return false;
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld", &n);
    for(int i=1;i<=n;++i) {
        scanf("%lld", &a[i]);
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    while(l<=r) {
        int mid=(l+r)/2;
        if(!check(mid))  r=mid-1;
        else {
            l=mid+1;
            k=mid;
        }
    }
    for(int i=1;i<=n;++i)   res+=max((int)0,a[i]-k);
    printf("%lld", res);
    return 0;
}
