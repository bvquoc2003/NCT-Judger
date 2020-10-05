#include <bits/stdc++.h>

using namespace std;

int a[500005], b[500005];
int n;
int C[500005];
int L[500005];
void SubTrau() {
    int j=0;
    int dem=0;
    int c=0;
    int res=0;
    for (int i=1;i<=n;i++) {
        int j=1;
        int k=i;
        int dem=0;
        while (j<=n) {
            if (a[j]==b[k]) {
                dem++;
            }
            j++;
            k++;
            if (k>n) k=1;
        }
        if (dem>res) {
            res=dem;
            c=i-1;
        }
    }
    printf("%d %d", c, res);
}
void SubAc() {
    int k=0;
    int res=0;
    for (int i=1;i<=n;i++) {
        if (i<=C[a[i]]) {
            int kk=C[a[i]]-i;
            L[kk]++;
        }
        else {
            int kk=n-i+C[a[i]];
            L[kk]++;
        }
    }
    //for (int i=1;i<=n;i++) cout<<L[i]<<" ";
    for (int i=0;i<=n;i++) {
        if (L[i]>res) {
            res=L[i];
            k=i;
        }
    }
    printf("%d %d", k, res);
}
int32_t main() {
    freopen("WRESTLING.INP","r",stdin);
    freopen("WRESTLING.OUT","w",stdout);
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    for (int i=1;i<=n;i++) {
        scanf("%d", &b[i]);
        C[b[i]]=i;
    }
    //  if (n<=1000) {
    //      SubTrau();
    //      return 0;
    //  }    
    SubAc();
}