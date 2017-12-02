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
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

#define mt
#define mod


class PeacefulLine {
public:
	string makeLine(vector <int> arr) {
	    int cnt[30];
	    ms(cnt,0);
	    int maxi=0,i;
	    for(i=0;i<sz(arr);i++)
            cnt[arr[i]]++;
        for(i=1;i<=25;i++)
            maxi=max(maxi,cnt[i]);
        maxi=maxi+maxi-1;

		if(maxi <= sz(arr))
            return "possible";
        return "impossible";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	PeacefulLine *obj;
	string answer;
	obj = new PeacefulLine();
	clock_t startTime = clock();
	answer = obj->makeLine(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	string p1;

	{
	// ----- test 0 -----
	int t0[] = {1,2,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	int t0[] = {1,1,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "impossible";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	int t0[] = {1,1,2,2,3,3,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	int t0[] = {3,3,3,3,13,13,13,13};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	int t0[] = {3,7,7,7,3,7,7,7,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "impossible";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	int t0[] = {25,12,3,25,25,12,12,12,12,3,25};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	int t0[] = {3,3,3,3,13,13,13,13,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "possible";
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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
//
// A teacher is trying to arrange a group of students into a line.
// The teacher knows that whenever she places two students with the same age next to each other, they will talk and disturb everyone.
// She wants to avoid that.
//
//
//
// You are given a vector <int> x.
// Each element of x is the age of one of the students.
//
//
//
// Determine whether it is possible for the teacher to arrange the students in a line so that there are no disturbances.
// If it can be done, return "possible" (quotes for clarity).
// If there will always be some pair of adjacent students with the same age, return "impossible".
// Note that the return value is case-sensitive.
//
//
// DEFINITION
// Class:PeacefulLine
// Method:makeLine
// Parameters:vector <int>
// Returns:string
// Method signature:string makeLine(vector <int> x)
//
//
// CONSTRAINTS
// -x will have between 1 and 25 elements, inclusive.
// -Each element of x will be between 1 and 25, inclusive.
//
//
// EXAMPLES
//
// 0)
// {1,2,3,4}
//
// Returns: "possible"
//
// In this case, no two students have the same age so any order works.
//
// 1)
// {1,1,1,2}
//
// Returns: "impossible"
//
// Regardless of which order we choose, two of the 1s will always be adjacent.
//
// 2)
// {1,1,2,2,3,3,4,4}
//
// Returns: "possible"
//
// One example of a peaceful line is {1,2,3,4,1,2,3,4}
//
// 3)
// {3,3,3,3,13,13,13,13}
//
// Returns: "possible"
//
//
//
// 4)
// {3,7,7,7,3,7,7,7,3}
//
// Returns: "impossible"
//
//
//
// 5)
// {25,12,3,25,25,12,12,12,12,3,25}
//
// Returns: "possible"
//
//
//
// 6)
// {3,3,3,3,13,13,13,13,3}
//
// Returns: "possible"
//
//
//
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
