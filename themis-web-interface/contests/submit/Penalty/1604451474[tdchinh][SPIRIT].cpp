#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
int a,b,c,s,x,y,z;
int main()
{
    FastIO;
    freopen("SPIRIT.INP","r",stdin);
    freopen("SPIRIT.OUT","w",stdout);
    cin >> a >> b >> c;
    if (a % c == 0)
    {
        x = a;
    }
    else
        x = (a/c+1)*c;
    if (b % c == 0)
    {
        y = b;
    }
    else
        y = (b/c)*c;
    if ((b-a)%c == 0)
    {
        cout << (b-a)/2 + 1;
        exit(0);
    }
    if (x >= y)
    {
        if ((b-a)%2 != 0)
        cout << (b-a)/2 + 1;
        else
            cout << (b-a)/2 ;
        exit(0);
    }
    z = (y - x)/c;
    if (((x/c+1)*c - x) % 2 != 0)
    s = s + ( ( (x/c+1)*c - x)/2+1)*z;
    else
        s = s + ( ( (x/c+1)*c - x)/2)*z;

    s = s + (x-a)/2;
    s = s + (b-y)/2+1;
        cout << s << endl;
    return 0;
}
