#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,k,a[100001],b[100001],c[100001],kt[100001];
int main()
{
    FastIO;
    freopen("NETCARD.INP","r",stdin);
    freopen("NETCARD.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= k ; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if (c[i] == 1)
        {
            kt[a[i]] = 1;
            kt[b[i]] = 1;
        }
    }

    for (int i = 1; i <= k; i++)
    {
        if (c[i] == 0 && kt[a[i]] == 1)
              kt[b[i]] = 3;
        if (c[i] == 0 && kt[b[i]] == 1)
              kt[a[i]] = 3;
    }
    for (int i = 1; i <= n;i++)
    {
        if (kt[i] == 0)
            kt[i] = 2;
        if (kt[i] == 0)
            kt[i] = 2;
    }

    for (int i = 1; i <= n; i++)
        if (kt[i] == 3)
        cout << 0 << " ";
    else
        cout << kt[i] << " ";
    return 0;
}
