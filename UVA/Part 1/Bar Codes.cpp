#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define sz 55
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
using namespace std;
ll dp[sz][sz];
ll n;
ll mot(ll a,ll b)
{
    if(a==0 && b==0)
    return 1;
    else if(a<=0 || b<=0)
    return 0;
    if(dp[a][b]!=-1)
    return dp[a][b];
    ll x=0;
    for(ll i=1;i<=n;i++)
    x+=mot(a-i,b-1);
    return dp[a][b]=x;
}
int main ()
{
    ll i,j;
    while(cin>>i>>j>>n)
    {
        ms(dp,-1);
        cout<<mot(i,j)<<endl;
    }
    return 0;
}
