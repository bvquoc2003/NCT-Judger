#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
struct kaka{
    long long a,b,c;
};
kaka d[1000006];
long long n,k,l[1000006],maxz;
bool cmd(const kaka &g, const kaka &h)
{
    return g.b < h.b;
}
int main()
{
    FastIO;
    freopen("FACILITY.INP","r",stdin);
    freopen("FACILITY.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i].a >> d[i].b >> d[i].c;
        d[i].b = d[i].b + d[i].a + k - 1;
    }
    sort(d+1,d+n+1,cmd);
    for (int i = 1; i <= n; i++)
    {
        l[i] = d[i].c;
        for (int j = 1; j < i; j++)
        {
            if (d[i].a > d[j].b && l[i] < l[j] + d[i].c)
                l[i] = l[j] + d[i].c;
        }
    }
    for (int i = 1; i <= n; i++)
        if (maxz < l[i])
        maxz = l[i];
    cout << maxz;
    return 0;
}
