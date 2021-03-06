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
#define sz(a) a.size()
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
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

#define mt
#define mod


class ForgetfulAddition {
public:
	int minNumber(string arr) {
        int a=0,b,ans=inf,i;
        for(i=1;i<sz(arr);i++)
        {
            a=(a*10)+(arr[i-1]-'0');

            b=toInt(arr.substr(i));
//            deb(a,b);

            ans=min(ans,a+b);
        }
        return ans;

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	ForgetfulAddition *obj;
	int answer;
	obj = new ForgetfulAddition();
	clock_t startTime = clock();
	answer = obj->minNumber(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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

	string p0;
	int p1;

	{
	// ----- test 0 -----
	p0 = "22";
	p1 = 4;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "123";
	p1 = 15;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "1289";
	p1 = 101;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "31415926";
	p1 = 9067;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = "98765";
	p1 = 863;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// Alice had two positive integers, a and b.
// She typed the expression "a+b" into her computer, but the '+' key malfunctioned.
// For example, instead of "128+9" the computer's screen now shows "1289".
//
//
//
// Later, Bob saw the string on the screen.
// He knows that the '+' sign is missing but he does not know where it belongs.
// He now wonders what is the smallest possible result of Alice's original expression.
//
//
//
// For example, if Bob sees the string "1289", Alice's expression is either "128+9" or "12+89" or "1+289".
// These expressions evaluate to 137, 101, and 290.
// The smallest of those three results is 101.
//
//
//
// You are given a string expression that contains the expression on Alice's screen.
// Compute and return the smallest possible result after inserting the missing plus sign
//
//
// DEFINITION
// Class:ForgetfulAddition
// Method:minNumber
// Parameters:string
// Returns:int
// Method signature:int minNumber(string expression)
//
//
// CONSTRAINTS
// -expression will contain between 2 and 8 characters, inclusive.
// -Each character of expression will be between '1' and '9'.
//
//
// EXAMPLES
//
// 0)
// "22"
//
// Returns: 4
//
// The only possible expression Alice could have typed is "2+2". Thus, Bob knows this evaluates to 4.
//
// 1)
// "123"
//
// Returns: 15
//
// The expression Alice has typed could have been "1+23" or "12+3". Of these two, the second is smaller, thus Bob will get the answer 15.
//
// 2)
// "1289"
//
// Returns: 101
//
// This is the example from the problem statement.
//
// 3)
// "31415926"
//
// Returns: 9067
//
//
//
// 4)
// "98765"
//
// Returns: 863
//
//
//
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
