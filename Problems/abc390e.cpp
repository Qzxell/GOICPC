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

const int N = 5e3 + 1;
int n,x;
vector<pair<ii,int>> v(N);
int vt,a,c;
int memo[4][N][N];

int dp(int ty, int k, int j){
	if(k < 0)return 0;
	if(memo[ty][k][j] != -1)return memo[ty][k][j];
	if(v[k].fi.fi != ty) return memo[ty][k][j] = dp(ty,k-1,j);
	int ret = dp(ty,k-1,j);
	if(v[k].se <= j)ret = max(ret, dp(ty,k-1,j-v[k].se)+v[k].fi.se);
	return memo[ty][k][j] = ret;
}
void so(int test){
	cin >> n >> x;
	f(i,0,n){
		cin >> vt >> a >> c;
		v[i].fi = {vt,a};
		v[i].se = c;
	}
	f(i,0,4)
		f(j,0,N)
			f(k,0,N)
				memo[i][j][k] = -1;
	int wa = dp(3,n-1,x);
	wa = dp(1,n-1,x);
	wa = dp(2,n-1,x);

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
