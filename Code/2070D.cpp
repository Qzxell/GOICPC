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

const int mod = 998244353;
void so(int test){
	int n;
	cin >> n;
	vi adj[n+1];
	vi v(n+1,0);
	f(i,2,n+1){
		int x;
		cin >> x;
		adj[x].pb(i);
	}
	queue<ii> qu;
	qu.push({1,0});
	while(!qu.empty()){
		ii cur = qu.front();
		int u = cur.fi; int mand = cur.se;
		qu.pop();
		for(int v : adj[u]){
			qu.push({v,mand+1});
		}
		v[mand] ++;
	}
	ll co = 1;
	ll ans = 1;
	f(i,1,n+1){
		ll va = (v[i]*co)%mod;
		ans = (ans+va)%mod;
		co  = ((v[i]-1)*co)%mod;
	}
	cout << ans << ln;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
