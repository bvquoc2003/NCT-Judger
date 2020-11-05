#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr) ; cout.tie(nullptr)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define endl "\n"
using namespace std;
long long m,n,a[1001][1001],s,t;
int main()
{
    FastIO;
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    scanf("%lld%lld",&n, &m);
    FOR(i,1,n)
        FOR(j,1,m)
            a[i][j] = 0;
    FOR(i,1,n)
        FOR(j,1,m)
            scanf("%lld",&a[i][j]);
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            s = a[i][j]*4+1;
            s = s - min(a[i][j],a[i-1][j]);
            s = s - min(a[i][j],a[i][j-1]);
            s = s - min(a[i][j],a[i+1][j]);
            s = s - min(a[i][j],a[i][j+1]);
            if (a[i][j] == 0)
                s--;
            t = t + s;
        }
    }
    printf("%lld",t);
    return 0;
}
