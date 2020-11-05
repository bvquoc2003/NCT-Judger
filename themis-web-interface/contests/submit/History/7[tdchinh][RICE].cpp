#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,t,s,x[100001],a[100001];
int main()
{
    FastIO;
    freopen("RICE.INP","r",stdin);
    freopen("RICE.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> a[i];
        s = s + a[i];
        if (i != 1)
        t = t + (x[i] - x[i-1]);
    }
    s = (s - t)/n;
    cout << s;
    return 0;
}
