#include <bits/stdc++.h>

using namespace std;

int a[10005];
int n, k;
int x[10005],ok = 0;
int s;
void Try(int i) {
    for (int j=-1;j<=1;j+=2)
        if (ok == 0) {
        x[i]=j;
        s+=a[i]*j;
        if (i==n) {
            if (s%k==0) {
                ok=1;
            }
        } else Try(i+1);
        s-=a[i]*j;
    }
}
int main()
{
    freopen("KMULT.INP","r",stdin);
    freopen("KMULT.OUT","w",stdout);
    scanf("%d%d", &n, &k);
    for (int i=1;i<=n;i++) scanf("%d", &a[i]);
    s=a[1];
    Try(2);
    if (ok == 1) {
        cout<<1<<endl;
        for (int i=2;i<=n;i++)
            if (x[i]>0) cout<<"+";
        else cout<<"-";
    } else cout<<0;
    return 0;
}
