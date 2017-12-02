#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int col[11][11][111], done[11][11], n, m;
string grid[11];

void dfs(int x, int y, char dir)
{
    if(col[x][y][dir])
        return;
    col[x][y][dir] = 1;
    done[x][y] = 1;
    if(dir == 'U')
    {
        if(x-1 >= 0 && grid[x-1][y] != '*')
            dfs(x-1, y, dir);
        else
            dfs(x, y, 'R');
    }
    if(dir == 'R')
    {
        if(y + 1 < m && grid[x][y+1] != '*')
            dfs(x, y+1, dir);
        else
            dfs(x, y, 'D');
    }
    if(dir == 'D')
    {
        if(x+1 < n && grid[x+1][y] != '*')
            dfs(x+1, y, dir);
        else
            dfs(x, y, 'L');
    }
    if(dir == 'L')
    {
        if(y-1 >= 0 && grid[x][y-1] != '*')
            dfs(x, y-1, dir);
        else
            dfs(x, y, 'U');
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int x, y, i, j;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> grid[i];
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] != '.' && grid[i][j] != '*')
                x = i, y = j;
        }
    }
    dfs(x, y, grid[x][y]);
    int res = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            res += done[i][j];
    cout << res;
    return 0;
}