#include<bits/stdc++.h>
using namespace std;
const int N=2010;
typedef long long ll;
ll tot[N][N];
char mp[N][N];


int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",mp[i]+1);

    }
    ll bas=0;
    for(int i=1;i<=n;i++)
    {
        int st= -1,las=-1;
        int ff=1;
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]=='B')
            {
                if(st==-1) st=j;
                las=j;

            } 
            if(las-st+1>k)
            {
                ff=0;
                break;

            }

        } 
        if(st==-1)
        {
            bas++;

        }
        else if(ff)
        {
            for(int h=max(1,i-k+1);h<=i;h++)
            {
                for(int f=max(1,las-k+1);f<=st;f++)
                {
                    tot[h][f]++;

                }

            }

        }

    } 
    for(int i=1;i<=n;i++)
    {
        int st=-1,las=-1;
        int ff=1;
        for(int j=1;j<=n;j++)
        {
            if(mp[j][i]=='B')
            {
                if(st==-1) st=j;
                las=j;

            } 
            if(las-st+1>k)
            {
                ff=0;
                break;

            }

        } 
        if(st==-1)
        {
            bas++;

        }
        else if(ff)
        {
            for(int f=max(1,las-k+1);f<=st;f++)
            {
                for(int h=max(1,i-k+1);h<=i;h++)
                {
                    tot[f][h]++;

                }

            }

        }

    }
    ll ans=bas;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans=max(ans,tot[i][j]+bas);

        }

    }
    printf("%lld\n",ans); 

} 
