#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="FIVESET";
const int nmax=1e5+5;
int n,w1,w2,a[nmax],res=0;
int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld%lld%lld", &n, &w1, &w2);
    for(int i=1;i<=n;++i)   scanf("%lld", &a[i]);
    sort(a+1,a+1+n,greater<int>());
    int i=2,j=n;
    for(int k=1;k<=5;++k) {
        if(k==3) {
            res+=a[1];
            continue;
        }
        if(k==1 || k==5) {
            if(w1*a[i]>w1*a[j]) {
                res+=(w1*a[i]);
                ++i;
            }
            else {
                res+=(w1*a[j]);
                --j;
            }
            continue;
        }
        if(k==2 || k==4) {
            if(w2*a[i]>w2*a[j]) {
                res+=(w2*a[i]);
                ++i;
            }
            else {
                res+=(w2*a[j]);
                --j;
            }
        }
    }
    printf("%lld", res);
    return 0;
}
