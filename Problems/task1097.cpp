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
vi v(N);
ll memo[N][N][2];

ll dp(int estd,int l,int r){
	if(memo[l][r][estd] != -1)return memo[l][r][estd];
	if(l == r){
		if(estd)return memo[l][r][estd] = v[l];
		else return 0;
	}
	if(estd){
		return memo[l][r][estd] = max(v[l] + dp(estd^1,l+1,r),v[r] + dp(estd^1,l,r-1));
	}else{
		return memo[l][r][estd] = min(dp(estd^1,l+1,r),dp(estd^1,l,r-1));
	}
}
void so(int test){
	memset(memo, -1 ,sizeof(memo));
	int n;
	cin >> n;
	f(i,0,n)cin >> v[i];
	ll ans = dp(1,0,n-1);
	cout << ans;

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
