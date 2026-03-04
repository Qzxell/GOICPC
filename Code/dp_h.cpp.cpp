#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

int h,w;
const int N = 1e3 + 2;
const int mod = 1e9 + 7;
int memo[N][N];
string grid[N];

ll dp(int x,int y){
	if(x < 0 or y < 0 )return 0;
	if(memo[x][y] != -1) return memo[x][y];
	if(grid[x][y] == '#') return memo[x][y] = 0;
	return memo[x][y] = (dp(x-1,y) + dp(x,y-1))%mod;
}
void so(int test){
	cin >> h >> w;
	f(i,0,h)cin >> grid[i];
	f(i,0,h)cout << grid[i] << ln;
	f(i,0,h+1){
		f(j,0,w+1)memo[i][j] =-1;
	}
	memo[0][0] = 1;

	int ans = dp(h-1,w-1);
	cout << ans << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
