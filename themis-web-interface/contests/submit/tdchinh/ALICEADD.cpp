#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
int t;
string a,b;
string Congxau(string a, string b)
{
 string c;
 long n1=a.length(),n2=b.length(),i,nho=0,Tong;
 if(n1>n2) b.insert(0,n1-n2,'0');
 if(n1<n2) a.insert(0,n2-n1,'0');
 c=a;
 for(i=a.length()-1;i>=0;i--)
 {
 Tong=(a[i]-48)+(b[i]-48)+nho;
 nho=Tong/10;
 Tong=Tong%10;
 c[i]=char(Tong+48);
 }
 if(nho>0)c=char(nho+48)+c;
 return c;
}

int main()
{
    FastIO;
    freopen("ALICEADD.INP","r",stdin);
    freopen("ALICEADD.OUT","w",stdout);
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> a >> b;
        cout << Congxau(a,b) << endl;
    }
    return 0;
}
