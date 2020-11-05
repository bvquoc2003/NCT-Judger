#include <bits/stdc++.h>

using namespace std;
string s,a,q;
long long i,j,vt,u,v,bien=0,h,n,k,dem;
int main()
{
    freopen("STRALT.INP","r",stdin);
    freopen("STRALT.OUT","w",stdout);
    cin>>s;
    n=s.length()-1;cout<<(int)'['<<endl;
    for (h=0;h<=n;h++)
    {
        i=h;
        if ((int)s[i]<=122 && (int)s[i]>=97)
        {
            k++;
            q[k]=s[i];
        }
        else{
        //if ((int)s[i]==91)
        //{
            for (j=i+2;j<=n;j++)
            {
                if ((int)s[j]<97 || (int)s[j]>122)
                {
                    v=j;
                    bien=1;
                    break;
                }
            }
            if (bien==0) continue;
            bien=0;
            if ((int)s[v]==(int)'*')
            {
                h=v+1;
                for (j=i+1;j<=v-1;j++)
                {
                    a[j]=s[j];
                    k++;
                    q[k]=s[j];
                }
                for (j=v-2;j>=i+1;j--)
                {
                    k++;
                    q[k]=a[j];
                }
            }
            else {
                h=v;
                for (j=i+2;j<=v-1;j++)
                {
                    a[j]=s[j];
                    k++;
                    q[k]=s[j];
                }
                for (j=v-1;j>=i+2;j--)
                {
                    k++;
                    q[k]=s[j];
                }
            }
            dem++;
        }/*
        else
        {
            cout<<(int)s[i]-48<<endl;
            for (j=i+2;j<=n;j++)
                if ((int)s[j]<48 || (int)s[j]>57)
                {
                    vt=j;
                    h=j;
                    break;
                }
            for (j=1;j<=(int)s[i]-48;j++)
                for (u=i+2;u<vt;u++)
                {
                    k++;
                    q[k]=s[u];
                }
            dem++;
        }
        }*/
    }
    cout<<dem<<" "<<endl;
    for (i=1;i<=k;i++)
        cout<<q[i];
    return 0;
}
