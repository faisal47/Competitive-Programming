#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}



#define fop   freopen("csmall.txt","r",stdin);freopen("csmallout.txt","w",stdout);

#define mt 32
#define mod

int dp[mt][mt],ans;
vec_<int>v;
map<int,int>ma;
int mot;

int solve(int pos,int sum)
{
    if(sum < 0)
        return 0;
    if(sum == 0)
        return 1;
    if(pos >= sz(v))
        return 0;
    int &ret=dp[pos][sum];
    if(ret != -1)
        return ret;
    ret=0;
    ret=solve(pos+1,sum-v[pos]);
    if(ret)
        return ret;
    ret=solve(pos+1,sum);
    if(ret)
        return ret;
    return ret;
}

bool okay2()
{
    ms(dp,-1);
    int i;
    for(i=1; i<=mot; i++)
    {
        if(!solve(0,i))
        return 0;
    }
    return 1;
}

bool okay()
{
    if(okay2())
        return 1;
    int i;
    for(i=1; i<=mot; i++)
    {
        if(ma.find(i) == ma.end())
        {
            ma[i]=1;
            v.pb(i);
            ans++;
            return 0;
        }
    }
    return 0;
}

int main ()
{
    fop;
    cffi;
    int i,j,test,t=1,d;
    cin>>test;
    while(test--)
    {
        clr(v);
        clr(ma);
        cin>>d>>d>>mot;
        v.resize(d);
        rep(i,d)
        {
            cin>>v[i];
            ma[v[i]]=1;
        }
        bool ret;
        ans=0;
        while(1)
        {
            ret=okay();
            if(ret)
            {
                cout<<"Case #"<<t++<<": "<<ans<<endl;
                break;
            }
        }
    }
    return 0;
}

