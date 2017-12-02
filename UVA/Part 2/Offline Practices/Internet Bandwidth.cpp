#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%I64d",&a)
#define scll2(a,b) scanf("%I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define mt 105<<1
using namespace std;
int dist[mt][mt],s,e,flag[mt],res,flow,i,s1,v,par[mt];
vec_<int>adj[mt];
void make_edge(int a,int b,int cost)
{
    if(dist[a][b]!=0)
    {
        dist[a][b]+=cost;
        return;
    }
    adj[a].pb(b);
    dist[a][b]=cost;
}
queue<int>q;
bool has_path()
{
    while(!q.empty())q.pop();
    q.push(s);
    ms(flag,0);
    par[s]=-1;
    flag[s]=1;
    while(!q.empty())
    {
        s1=q.front();q.pop();
        for(i=0;i<sz(adj[s1]);i++)
        {
            v=adj[s1][i];
            if(!flag[v] && dist[s1][v]>0)
            {
                par[v]=s1;
                if(v==e)return true;
                flag[v]=1;
                q.push(v);
            }
        }
    }
    return false;
}
void visit_path(int e1)
{
    if(par[e1]==-1)return;
    int v1=par[e1];
    flow=min(flow,dist[v1][e1]);
    visit_path(v1);
    dist[v1][e1]-=flow;
    dist[e1][v1]+=flow;
}
int max_flow()
{
    res=0;
    while(has_path())
    {
        flow=inf;
        visit_path(e);
        res+=flow;
    }
    return res;
}
int main ()
{
    int j,n,m,t=1,mot;
//    sci1(test);
    while(sci1(n)==1 && n)
    {
//        sci1(n);
        mot=(n<<1)+2;
        for(i=1;i<=mot;i++)
        {
            clr(adj[i]);
            for(j=1;j<=mot;j++)
            dist[i][j]=0;
        }
        sci3(s,e,m);
        for(i=1;i<=n;i++)
        {
            make_edge(i,i+n,inf);
            make_edge(i+n,i,0);
        }
        while(m--)
        {
            sci3(i,j,mot);
            make_edge(i+n,j,mot);
            make_edge(j,i+n,0);
            make_edge(j+n,i,mot);
            make_edge(i,j+n,0);
        }
        printf("Network %d\n",t++);
        printf("The bandwidth is %d.\n\n",max_flow());
    }
    return 0;
}

