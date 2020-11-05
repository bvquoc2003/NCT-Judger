#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,a,b,t,k,sn[333345],z,s;
int main()
{
    FastIO;
    freopen("DMT.INP","r",stdin);
    freopen("DMT.OUT","w",stdout);
    n = 333345;
    for (int i = 2; i <= n; i++)
        sn[i] = 1;
    for (int i = 2; i*i <= n; i++)
    {
        if (sn[i] == 1)
        {
            for (int j = i*i; j <= n; j = j + i)
            {
                sn[j] = 0;
            }
        }
    }
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        s = 0;
        for (int j = 2; j <= n; j++)
        {
            if (sn[j] == 1 && j != 3)
            {
                z = j*j*9;
                if (z >= a && z <= b)
                    s++;
                if (z > b)
                {
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
