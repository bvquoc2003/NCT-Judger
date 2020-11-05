#include <bits/stdc++.h>

using namespace std;

int n;
typedef pair<int, int> ii;
ii a[1005];
int32_t main() {
    freopen("SUBSEQ.INP","r",stdin);
    freopen("SUBSEQ.OUT","w",stdout);
    scanf("%d", &n);
    int S=0;
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i].first);
        a[i].second=i;
        S+=a[i].first;
    }
    sort(a+1,a+n+1);
    int s=0;
    int res=0;
    for (int i=n;i>=1;i--) {
        s+=a[i].first;
        if (s-a[i].first<=S/2) {
            res=i;
        }
    }
    printf("%d\n", n-res+1);
    for (int i=res;i<=n;i++) printf("%d ", a[i].second);
}