#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ll long long
#define ln  '\n'
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int N =11;
vector<pair<int,ll>> adj[N];
ll ans;

bool enc(int mask,int pos){return ((mask>>pos)&1);}

bool cont(ll mask){
	int c =0;
	f(i,0,63)if((mask>>i)&1)c++;
	return c;
}
	int n,m;

void back(int  &mask,int node,ll xx){
	mask |= (1<<node);
	ll ret = xx;
	if(node == n)ans = min(ans,xx);

	for(auto [to,w]:adj[node])if(!enc(mask,to)){
		back(mask,to,xx^w);
	}
	mask &= ~(1<<node);
}

void so(int test){
	cin >> n >>m;
	ans = (1ll<<62);
	ll ga=ans;
	f(i,0,m){
		ll u,v,w;
		cin >> u >>v >>w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	int mass = 0;
	back(mass,1,0);
	cout << ans ;
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
