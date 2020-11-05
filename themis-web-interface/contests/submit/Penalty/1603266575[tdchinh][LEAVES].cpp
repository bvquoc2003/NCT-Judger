#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,s,a[100001],b[100001],t,u;
int main()
{
    FastIO;
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
            {
                cin >> a[i];
                b[i] = a[i];
            }
    sort(b+1,b+n+1);
    for (int i = 1; i <= n; i++)
    {
        if (t + b[i] <= s)
            {
                t += b[i];
                u = i;
            }
        else
            break;
    }
    t = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i*u + a[i];
    }
    sort(a+1,a+n+1);
    cout << u << " ";
    for (int i = 1; i <= u; i++)
        t += a[i];
        cout << t;
    return 0;
}
