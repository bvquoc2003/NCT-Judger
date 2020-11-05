#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
unsigned long long n,t,q,a,b,c,s;
int main()
{
    FastIO;
    freopen("CNTDIV.INP","r",stdin);
    freopen("CNTDIV.OUT","w",stdout);
    cin >> q;
    while (q > 0)
    {
        q--;
        s = 0;
        cin >> n;
        t = n*(n+1)*(n+2);
        cout << t << endl;
        a = n;
        b = n+1;
        c  = n+2;
        cout << a << " " << b << " " << c << endl;
        if (a*a < t && t % (a*a) != 0)
            s++;
            cout << s << endl;
        if (b*b < t && t % (b*b) != 0)
            s++;
            cout << s << endl;
        if (c*c < t && t % (c*c) != 0)
            s++;
            cout << s << endl;
        if (a*a * b < t && t % (a*a * b)!= 0)
            s++;
            cout << s << endl;
        if (a*a * c < t && t % (a*a * c)!= 0)
            s++;
            cout << s << endl;
        if (b*b * a < t && t % (b*b * a)!= 0)
            s++;
            cout << s << endl;
        if (b*b* c < t && t % (b*b * c)!= 0)
            s++;
            cout << s << endl;
        if (c*c * a < t && t % (c*c * a)!= 0)
            s++;
            cout << s << endl;
        if (c*c * b < t && t % (c*c * b)!= 0)
            s++;
            cout << s << endl;
        if (a*a * b*b < t && t % (a*a * b*b)!= 0)
            s++;
            cout << s << endl;
        if (a*a* c*c < t && t % (a*a * c*c)!= 0)
            s++;
        if (c*c * b*b < t && t % (c*c * b*b)!= 0)
            s++;
            cout << s << endl;
        if (a*a * b*b  * c*c< t && t % (a*a * b*b * c*c) != 0)
            s++;
            cout << s << endl;
    }
    return 0;
}
