#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="BONUS";
const int nmax=1e5+5;
int n,k,a[nmax],s=0;
int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld", &n, &k);
    for(int i=1;i<=n;++i) {
        scanf("%lld", a[i]);
        s+=a[i];
    }

    return 0;
}
