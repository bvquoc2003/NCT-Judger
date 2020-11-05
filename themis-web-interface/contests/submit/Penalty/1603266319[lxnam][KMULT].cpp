#include <bits/stdc++.h>

using namespace std;
int i,n,a[10005],s,k;
string q;
int tao(int ad)
{
    if (ad==1) q='+'+q;
    else q='-'+q;
}
int tinh(int b,int dau,int s)
{
    if (dau==1)
        s=s+a[b];
    if (dau==0)
        s=s-a[b];
    if (b==n)
    {
        if (s%k==0)
            return 1;
        else return 0;
    }
    for (int p=0;p<=1;p++)
        if (tinh(b+1,p,s)==1)
        {
            tao(p);
            return 1;
        }
    return 0;
}
int main()
{
    freopen("KMULT.INP","r",stdin);
    freopen("KMULT.OUT","w",stdout);
    scanf("%d%d", &n, &k);
    for (i=1;i<=n;i++)
        scanf("%d", &a[i]);
    /*tinh(1,1,s);
    if (q.length()>0)
    {
        //printf("1\n");
        //printf("%s", q.c_str());
        cout<<"-";
    }
    else printf("0");*/
    cout<<0;
    return 0;
}
