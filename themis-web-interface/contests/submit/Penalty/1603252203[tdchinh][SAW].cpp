#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,t,h[100008],m[100008],k,s;
int main()
{
    FastIO;
    freopen("SAW.INP","r",stdin);
    freopen("SAW.OUT","w",stdout);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int j = 1; j <= t; j++)
        cin >> m[j];
    sort(h+1,h+n+1,greater<int>());
    for (int i = 1; i <= t ; i++)
    {
        s = 0;
        k = 2;
        while(s < m[i])
        {
            s = s + (h[k-1] - h[k])*(k-1);
            if (s >= m[i])
            {
                s = s - m[i];
                s = s / (k-1);
                cout << h[k] + s << " ";
                break;
            }
            k++;
        }
    }
    return 0;
}
