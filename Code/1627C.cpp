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

void so(int test){
	int n;
	cin >> n;
	vi adj[n+1];
	vii ed(n);
	f(i,0,n-1){
		int u,v;
		if(u > v)swap(u,v);
		cin >> u>> v;
		ed[i] = {u,v};
		adj[u].pb(v);
		adj[v].pb(u);
	}
	f(i,1,n+1) if(sz(adj[i]) > 2){
		cout << -1 << ln;
		return;
	}
	queue<int> qu;
	vector<bool> vis(n+1,0);
	vi val(n+2,0);
	auto BFS = [&](int root){
		qu.push(root);
		int c = 1;
		val[root] = c++;
		while(!qu.empty()){
			int k = qu.front();
			vis[k] = 1;
			qu.pop();
			for( auto to : adj[k])if(!vis[to]){
				qu.push(to);
				val[to] = c++;
			}
		}
	};
	f(i,1,n+1)if(sz(adj[i]) == 1){
		BFS(i);
		break;
	}
	f(i,0,n-1){
		ii meh = ed[i];
		int vu = val[meh.fi];
		int vv = val[meh.se];
		if( min(vu,vv)&1)cout << 2;
		else cout << 5;
		cout << ' ';

	}
	cout << ln;
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
