#include <bits/stdc++.h>
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
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz(a) (int)a.size()
#define ll long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};

#define mt
#define mod
int maxi,tp;
map<pii,int>blocked;
map<pii,int>flag;

int bfs()
{
    queue<pii>q;
    q.push(mp(0,0));
    pii u,v;
    int i,ret=0,d;
    u=mp(0,0);
    flag[u]=0;

    while(!q.empty())
    {
        u=q.front();q.pop();
        d=flag[u];
        if(u.fs < 0 && u.fs<-(tp+2))
            continue;
        if(u.sc>0 && u.sc>tp+2)
            continue;
        if(u.sc<0 && u.sc<-(tp+2))
            continue;

        for(i=0;i<4;i++)
        {
            v=u;
            v.fs+=X[i];
            v.sc+=Y[i];
            if(!flag[v] && !blocked[v] && d+1<=maxi)
            {
                q.push(v);
                flag[v]=d+1;
                ret=max(ret,v.fs);
            }
        }
    }

    return ret;
}

class TheGridDivTwo {
public:
	int find(vector <int> x, vector <int> y, int k) {
		clr(flag);
		clr(blocked);
		tp=sz(x);
		int i;
		maxi=k;
		for(i=0;i<sz(x);i++)
            blocked[mp(x[i],y[i])]=1;
        return bfs();
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	TheGridDivTwo *obj;
	int answer;
	obj = new TheGridDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;

	{
	// ----- test 0 -----
	int t0[] = {1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-2,-1,0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {-1,0,0,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,-1,1,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 9;
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0.clear() /*{}*/;
	p1.clear() /*{}*/;
	p2 = 1000;
	p3 = 1000;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 47;
	p3 = 31;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// John is standing at the origin of an infinite two-dimensional grid.
// He is going to move along this grid.
// During each second he can either stay where he is or he can move by one unit in one of the four cardinal directions (north, south, east, or west).
// Some of the grid points are blocked.
// John is not allowed to move to a blocked grid point.
//
//
// You are given the coordinates of the blocked grid points as vector <int>s x and y.
// For each valid i, the grid point that is x[i] units east and y[i] units north of the origin is blocked.
// You are also given an int k.
// Compute and return the maximal possible x-coordinate of a point John can reach in k seconds.
//
//
// DEFINITION
// Class:TheGridDivTwo
// Method:find
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int find(vector <int> x, vector <int> y, int k)
//
//
// CONSTRAINTS
// -x will contain between 0 and 47 elements, inclusive.
// -x and y will contain the same number of elements.
// -Each element of x will be between -1,000 and 1,000, inclusive.
// -Each element of y will be between -1,000 and 1,000, inclusive.
// -All pairs (x[i], y[i]) will be distinct.
// -Each pair (x[i], y[i]) will be different from (0, 0).
// -k will be between 1 and 1,000, inclusive.
//
//
// EXAMPLES
//
// 0)
// {1,1,1,1}
// {-2,-1,0,1}
// 4
//
// Returns: 2
//
// The optimal strategy is to move two times north to (0, 2) and then two times east to (2,2).
//
//
// 1)
// {-1, 0, 0, 1}
// {0, -1, 1, 0}
// 9
//
// Returns: 0
//
// John can not make any moves.
//
// 2)
// {}
// {}
// 1000
//
// Returns: 1000
//
//
//
// 3)
// {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}
// {0,-1,1,-2,2,-3,3,-4,4,-5,5}
// 47
//
// Returns: 31
//
//
//
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!