#include <bits/stdc++.h>

using namespace std;
string a,b;
int k,q;
string cong(string a,string b)
{
    string c="";
    int i,s,nho=0;
    if (a.length()<b.length())
        a.insert(0,b.length()-a.length(),'0');
    else
        b.insert(0,a.length()-b.length(),'0');
    c=a;
    for (i=a.length()-1;i>=0;i--)
    {
        s=(a[i]-48)+(b[i]-48)+nho;
        nho=s/10;
        s=s%10;
        c[i]=char(s+48);
    }
    if (nho!=0)
        c=char(nho+48)+c;
    return c;
}
int main()
{
    freopen("ALICEADD.INP","r",stdin);
    freopen("ALICEADD.OUT","w",stdout);
    cin>>q;
    for (k=1;k<=q;k++)
    {
        cin>>a;
        cin>>b;
        cout<<cong(a,b)<<endl;
    }
    return 0;
}
