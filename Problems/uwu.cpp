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

const int mod = 1e9 + 7;

int fp(int b,int exp){
	int re = 1;
	while(exp){
		if(exp&1)re = (re*1ll*b)%mod;
		exp >>= 1;
		b = (b*1ll*b)%mod;
	}
	return re;
}

void so(int test){
	int n,k;
	cin >> n>>k;
	vi adj[n+1];
	vi bla(n+1,0);
	f(i,0,n-1){
		int u,v,c;
		cin >> u >> v >> c;
		if(c == 0){
			adj[u].pb(v);
			adj[v].pb(u);
			bla[u] = bla[v] = 1;
		}
	}
	queue<int> qu;
	vi vis(n+1,0);
	vi gru(n+1,0);
	int co = 1;
	auto bfs = [&](int x){
		qu.push(x);	
		while(!qu.empty()){
			int fr = qu.front();qu.pop();
			vis[fr] = 1;
			gru[co]++;
			for(auto v : adj[fr])if(!vis[v]){
				qu.push(v);
			}
		}
	};
	f(i,1,n+1)if(!vis[i] and bla[i]){
		bfs(i);
		co++;
	}
	ll ans = fp(n,k);
	ll acu = 0;

	f(i,1,n+1)if(gru[i]){
		acu = (fp(gru[i],k) +0ll+ acu)%mod;	
		ans = (ans +0ll+ gru[i])%mod;
	}
	cout << (ans - acu - n+ mod + mod + mod)%mod << ln;
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
