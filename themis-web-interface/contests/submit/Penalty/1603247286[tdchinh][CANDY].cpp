#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ft first
#define sc second
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define endl "\n"
using namespace std;
long long n,a[1000001],s,t;
int main()
{
    FastIO;
    freopen("CANDY.INP","r",stdin);
    freopen("CANDY.OUT","w",stdout);
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
            s = s + a[i];
        }
    s = s/n;
    FOR(i,1,n)
    {
        if (a[i] > s)
            t = t + a[i] - s;
    }
    printf("%lld",t);
    return 0;
}
