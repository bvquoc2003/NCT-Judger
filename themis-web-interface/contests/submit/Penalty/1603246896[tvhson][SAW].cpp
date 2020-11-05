#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
int a[100005];
int Max;
int s[1000005];
int32_t main() {
    freopen("SAW.INP","r",stdin);
    freopen("SAW.OUT","w",stdout);
    scanf("%lld%lld", &n, &k);
    for (int i=1;i<=n;i++) {
        scanf("%lld", &a[i]);
        Max=max(Max, a[i]);
    }
    sort(a+1, a+n+1);
    for (int i=1;i<=Max;i++) {
        int h=lower_bound(a+1,a+n+1,i)-a;
        s[i]=s[i-1]+(n-h+1);
    }
    // for (int i=1;i<=Max;i++) cout<<s[i]<<endl;

    while (k--) {
        int x;
        scanf("%lld", &x);
        int h=upper_bound(s+1,s+Max+1,s[Max]-x)-s;
        cout<<h-1<<" ";
    }
}
