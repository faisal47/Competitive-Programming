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


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define mt 200010
#define MAX 200010
#define LOGMAX 20
#define mod

int stable[MAX][LOGMAX],n,arr[mt];

void preprocess()
{
    int i, j;
    for(i = 0; i < n; i++) stable[i][0] = arr[i];
    for(j = 1; (1<<j) <= n; j++)
    {
        for(i = 0; i + (1<<j) - 1 < n; i++)
            stable[i][j] = min(stable[i][j-1], stable[i+(1<<(j-1))][j-1]);
    }
}

struct maans
{
    int num,rng;
};

vec_<maans>v;
maans temp;

int query(int ind1,int ind2)
{
    int lg = log2(ind2-ind1+1);
    return min(stable[ind1][lg], stable[ind2-(1<<lg)+1][lg]);
}

int bs1(int ind)
{
    int num=arr[ind];
    int ret=ind;
    int l=0,r=ind,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(query(mid,ind) >= num)
        {
            ret=min(ret,mid);
            r=mid-1;
        }
        else
            l=mid+1;

    }
    return ret;
}

int bs2(int ind)
{
    int num=arr[ind];
    int ret=ind;
    int l=ind,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(query(ind,mid) >= num)
        {
            ret=max(ret,mid);
            l=mid+1;
        }
        else
            r=mid-1;

    }
    return ret;
}

void pre2()
{
    int i,bam,dan;
    for(i=0; i<n; i++)
    {
        bam=bs1(i);
        dan=bs2(i);
        temp.num=arr[i];
        temp.rng=dan-bam+1;
        v.pb(temp);
    }
}

bool comp(maans a,maans b)
{
    if(a.rng == b.rng)
        return a.num>b.num;
    return a.rng > b.rng;
}

int ans[mt];

int main ()
{
    cffi;
    int i,j;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    preprocess();
    pre2();
    sort(all(v),comp);

    int maxi=0;

    for(i=0; i<sz(v); i++)
    {
//        deb(v[i].num,v[i].rng);
        ans[v[i].rng]=max(ans[v[i].rng],v[i].num);
    }
    for(i=n-1; i>=1; i--)
        ans[i]=max(ans[i],ans[i+1]);

    for(i=1; i<=n; i++)
        cout<<ans[i]<<" ";

    return 0;
}