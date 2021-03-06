#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define make_flush  cout << flush; //    fflush(stdout);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repa(i,n) for(auto i: n)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};


#define mt 100010
#define mod

pii seg[4*mt];
int arr[mt];

void build(int node,int l,int r)
{
    if(l == r)
    {
        seg[node]= {arr[l],arr[l]};
        return;
    }
    int b=node << 1;
    int mid=(l+r)>>1;
    build(b,l,mid);
    build(b|1,mid+1,r);
    seg[node].fs = min(seg[b].fs,seg[b|1].fs);
    seg[node].sc = max(seg[b].sc,seg[b|1].sc);
}


#define REMOVE_REDUNDANT
typedef double T;
const T EPS = 1e-7;
struct PT
{
    T x, y;
    PT() {}
    PT(T x, T y) : x(x), y(y) {}
    bool operator<(const PT &rhs) const
    {
        return make_pair(y,x) < make_pair(rhs.y,rhs.x);
    }
    bool operator==(const PT &rhs) const
    {
        return make_pair(y,x) == make_pair(rhs.y,rhs.x);
    }
};
T cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}
T area2(PT a, PT b, PT c)
{
    return cross(a,b) + cross(b,c) + cross(c,a);
}

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c)
{
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts)
{
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> up, dn;
    for (int i = 0; i < pts.size(); i++)
    {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
#ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++)
    {
        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1]))
    {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
#endif
}

vector<PT>ans;
int ml,mr;

pii solve(int node,int l,int r)
{
    if(l>mr || r<ml)
    return {inf,-inf};
    if(l>=ml && r<=mr)
    return seg[node];
    int b=node<<1;
    int mid=(l+r)>>1;
    pii ret1=solve(b,l,mid);
    pii ret2=solve(b|1,mid+1,r);
    pii ret;
    ret.fs=min(ret1.fs,ret2.fs);
    ret.sc=max(ret1.sc,ret2.sc);
    return ret;
}

pair<dd,dd>myp;

int main ()
{
    cffi;
    int i,j,test,n,t=1;
    cin>>test;
    ll mans,a,b;
    while(test--)
    {
        cin>>n;
        rep1(i,n)
        cin>>arr[i];
        build(1,1,n);
        mr=n;
        mans=0;
        clr(ans);
        rep1(i,n-1)
        {
            ml=i+1;
            myp=solve(1,1,n);
            ans.pb({arr[i],myp.fs});
            ans.pb({arr[i],myp.sc});
        }
        ConvexHull(ans);
        a=0;
        b=0;

        rep(i,sz(ans)-1)
        {
            a+=(ans[i].x*ans[i+1].y);
            b+=(ans[i].y*ans[i+1].x);
        }
        n=sz(ans);
        a+=(ans[n-1].x*ans[0].y);
        b+=(ans[n-1].y*ans[0].x);

        mans=abs(a-b);

        deb(mans);
    }

    return 0;
}










