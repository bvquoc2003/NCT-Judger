#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
struct kaka{
    int a,b,c;
};
kaka s[100005];
long long n,kt[100005],t,x,y,d[100005],k;
bool cmp(const kaka &g, const kaka &h)
{
    if (g.a == h.a)
        return g.b < h.b;
    return g.a<h.a;
}
int main()
{
    FastIO;
    freopen("COBOX2.INP","r",stdin);
    freopen("COBOX2.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].a >> s[i].b;
        s[i].c = i;
    }
    sort(s+1,s+n+1,cmp);
    for (int i = 1; i <= n; i++)
    {
        if (kt[i] == 0)
        {
            x = s[i].a;
            y = s[i].b;
        for (int j = i+1; j <= n; j++)
        {
            if (kt[j] == 0 && x < s[j].a && y < s[j].b)
            {
                kt[j] = 1;
                x = s[j].a;
                y = s[j].b;
            }
        }
        kt[i] = 1;
        t++;
        }
    }
    cout << t << endl;
    for (int i = 1; i <= n; i++)
        kt[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (kt[i] == 0)
        {
            x = s[i].a;
            y = s[i].b;
         k = 1;
         d[k] = s[i].c;
        for (int j = i+1; j <= n; j++)
        {
            if (kt[j] == 0 && x < s[j].a && y < s[j].b)
            {
                kt[j] = 1;
                x = s[j].a;
                y = s[j].b;
                k++;
                d[k] = s[j].c;
            }
        }
        cout << k << " ";
        for (int i = k; i >= 1; i--)
            cout << d[i] << " ";
        cout << endl;
        kt[i] = 1;
        }
    }
    return 0;
}
