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
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
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


#define mt
#define mod

struct maan
{
    string arr;
    int num;
};

vec_<maan>ans;

multiset<int>ms;

void go1()
{
    if(sz(ms) == 0)
    {
        ans.pb({"insert",1});
        return;
    }
    auto it = ms.begin();
    ms.erase(it);
}

void go2(int num)
{
    for(auto it=ms.begin();it!=ms.end();)
    {
        if((*it)<num)
            {
                ms.erase(it++);
                ans.pb({"removeMin",0});
            }
        else
            break;
    }
    if(sz(ms) == 0)
    {
        ms.insert(num);
        ans.pb({"insert",num});
        return;
    }
    auto it=ms.begin();
    if((*it) != num)
    {
        ms.insert(num);
        ans.pb({"insert",num});
    }
}

int main ()
{
    cffi;
    int i,j,test,n,t=1,num;
    string arr;
    cin>>n;
    while(n--)
    {
        cin>>arr;
        if(arr  == "removeMin")
        {
            num=0;
            go1();
            ans.pb({arr,num});
            continue;
        }
        cin>>num;
        if(arr == "insert")
        {
            ans.pb({arr,num});
            ms.insert(num);
            continue;
        }
        go2(num);
        ans.pb({arr,num});
    }

    deb(sz(ans));
    repa(val,ans)
    {
        if(val.arr == "removeMin")
        {
            deb(val.arr);
            continue;
        }
        deb(val.arr,val.num);
    }

    return 0;
}