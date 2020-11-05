#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
unsigned long long n,s,a[100001],b[100001],t,u,x,tong,z;
int cnp(int t, int p)
{
    if (p < t)
        return 1;
    tong = 0;
    int k = (t+p)/2;
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i] + i*k;
    }
    sort(b+1,b+n+1);
    for (int i = 1; i <= k; i++)
    {
        tong = tong + b[i];
    }
    if (tong <= s)
    {
        x = k;
        z = tong;
        cnp(k+1,p);
    }
    else
        cnp(t,k-1);
}
int main()
{
    FastIO;
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);
    scanf("%lld%lld",&n,&s);
    for (int i = 1; i <= n; i++)
            scanf("%lld",&a[i]);
    cnp(0,n);
    if (x == 0)
        printf("0");
    else
    printf("%lld %lld",x,z);
    return 0;
}
